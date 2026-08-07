#!/usr/bin/env bash
# Experimental PHP 5.6.40 + OpenSSL 3.5 LTS build.
#
# This is intentionally isolated from the normal PHP 5.6 installation:
#   PHP:     /opt/ngm/php/5.6-openssl35-dev
#   OpenSSL: /opt/ngm/php/openssl-3.5
#
# It builds a clean copy of the current repository HEAD and does not modify the
# checked-out PHP sources. The first goal is compile/runtime discovery against
# OpenSSL 3.5; once stable, compatibility changes can be materialized in source.

set -Eeuo pipefail

OPENSSL_VERSION="${OPENSSL_VERSION:-3.5.7}"
NGM_ROOT="${NGM_ROOT:-/opt/ngm/php}"
OPENSSL_PREFIX="${OPENSSL_PREFIX:-${NGM_ROOT}/openssl-3.5}"
PREFIX="${PREFIX:-${NGM_ROOT}/5.6-openssl35-dev}"
BUILD_ROOT="${BUILD_ROOT:-/usr/local/src/ngm-php56-openssl35}"
SRC_DIR="${BUILD_ROOT}/php-5.6.40"
JOBS="${JOBS:-$(nproc 2>/dev/null || echo 2)}"
FORCE="${FORCE:-0}"
FORCE_DEPS="${FORCE_DEPS:-0}"

REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

FPM_USER="${FPM_USER:-nobody}"
if getent group nogroup >/dev/null 2>&1; then
  FPM_GROUP="${FPM_GROUP:-nogroup}"
else
  FPM_GROUP="${FPM_GROUP:-nobody}"
fi

log()  { printf '\033[1;34m==>\033[0m %s\n' "$*"; }
warn() { printf '\033[1;33mWARN:\033[0m %s\n' "$*" >&2; }
die()  { printf '\033[1;31mERROR:\033[0m %s\n' "$*" >&2; exit 1; }

on_error() {
  local rc=$?
  printf '\033[1;31mERROR:\033[0m command failed at line %s (exit %s): %s\n' \
    "${BASH_LINENO[0]:-?}" "$rc" "${BASH_COMMAND:-?}" >&2
  exit "$rc"
}
trap on_error ERR

need_root() {
  [ "$(id -u)" -eq 0 ] || die "run as root."
}

install_deps() {
  if command -v dnf >/dev/null 2>&1; then
    log "installing Alma/RHEL build dependencies"
    dnf install -y \
      gcc gcc-c++ make ca-certificates curl git patch pkgconf-pkg-config \
      perl perl-FindBin perl-IPC-Cmd perl-File-Compare perl-Data-Dumper \
      tar gzip zlib-devel libxml2-devel
  elif command -v apt-get >/dev/null 2>&1; then
    log "installing Debian build dependencies"
    export DEBIAN_FRONTEND=noninteractive
    apt-get update -y
    apt-get install -y --no-install-recommends \
      build-essential ca-certificates curl git patch pkg-config perl \
      tar gzip zlib1g-dev libxml2-dev
  else
    die "unsupported package manager; expected dnf or apt-get."
  fi
}

find_openssl_libdir() {
  local dir
  for dir in "${OPENSSL_PREFIX}/lib64" "${OPENSSL_PREFIX}/lib"; do
    if [ -e "${dir}/libssl.so.3" ]; then
      printf '%s\n' "$dir"
      return 0
    fi
  done
  return 1
}

find_ca_bundle() {
  local file
  for file in \
    /etc/pki/tls/certs/ca-bundle.crt \
    /etc/ssl/certs/ca-certificates.crt \
    /etc/ssl/ca-bundle.pem; do
    if [ -s "$file" ]; then
      printf '%s\n' "$file"
      return 0
    fi
  done
  return 1
}

build_openssl() {
  local libdir="" tarball="${BUILD_ROOT}/openssl-${OPENSSL_VERSION}.tar.gz"
  mkdir -p "$BUILD_ROOT"

  # Keep the source tarball available even when OpenSSL itself is already built;
  # the standalone install uses it to provision the matching openssl.cnf.
  if [ ! -s "$tarball" ]; then
    log "downloading OpenSSL ${OPENSSL_VERSION}"
    curl -fL --retry 3 --retry-delay 2 \
      -o "${tarball}.part" \
      "https://www.openssl.org/source/openssl-${OPENSSL_VERSION}.tar.gz"
    mv -f "${tarball}.part" "$tarball"
  fi

  libdir="$(find_openssl_libdir || true)"
  if [ -n "$libdir" ] && [ "$FORCE_DEPS" != "1" ]; then
    if "${OPENSSL_PREFIX}/bin/openssl" version 2>/dev/null | grep -Fq "OpenSSL ${OPENSSL_VERSION}"; then
      log "OpenSSL ${OPENSSL_VERSION} already at ${OPENSSL_PREFIX}"
      return
    fi
  fi

  rm -rf "${BUILD_ROOT}/openssl-${OPENSSL_VERSION}"
  tar -xzf "$tarball" -C "$BUILD_ROOT"

  pushd "${BUILD_ROOT}/openssl-${OPENSSL_VERSION}" >/dev/null
    log "building OpenSSL ${OPENSSL_VERSION} -> ${OPENSSL_PREFIX}"
    ./config \
      --prefix="${OPENSSL_PREFIX}" \
      --openssldir="${OPENSSL_PREFIX}" \
      shared zlib -fPIC
    make -j"$JOBS"
    make install_sw
  popd >/dev/null

  find_openssl_libdir >/dev/null || die "libssl.so.3 was not installed under ${OPENSSL_PREFIX}."
}

provision_openssl_runtime_files() {
  local tarball="${BUILD_ROOT}/openssl-${OPENSSL_VERSION}.tar.gz" ca_bundle

  install -d -m 755 "${OPENSSL_PREFIX}/certs"
  install -d -m 700 "${OPENSSL_PREFIX}/private"

  if [ ! -s "${OPENSSL_PREFIX}/openssl.cnf" ]; then
    [ -s "$tarball" ] || die "OpenSSL source tarball missing; cannot provision openssl.cnf."
    log "installing OpenSSL ${OPENSSL_VERSION} configuration"
    tar -xOf "$tarball" "openssl-${OPENSSL_VERSION}/apps/openssl.cnf" > "${OPENSSL_PREFIX}/openssl.cnf"
    chmod 644 "${OPENSSL_PREFIX}/openssl.cnf"
  fi

  ca_bundle="$(find_ca_bundle)" || die "could not locate the system CA bundle."
  ln -sfn "$ca_bundle" "${OPENSSL_PREFIX}/cert.pem"

  [ -r "${OPENSSL_PREFIX}/openssl.cnf" ] || die "OpenSSL configuration is not readable."
  [ -r "${OPENSSL_PREFIX}/cert.pem" ] || die "OpenSSL CA bundle link is not readable."

  log "OpenSSL config: ${OPENSSL_PREFIX}/openssl.cnf"
  log "OpenSSL CA bundle: ${OPENSSL_PREFIX}/cert.pem -> ${ca_bundle}"
}

prepare_php_source() {
  [ -d "${REPO_DIR}/.git" ] || die "run this script from a git checkout of chrismfz/php56."
  mkdir -p "$BUILD_ROOT"
  rm -rf "$SRC_DIR"
  mkdir -p "$SRC_DIR"

  log "exporting clean PHP 5.6 source from repository HEAD"
  git -C "$REPO_DIR" archive HEAD | tar -x -C "$SRC_DIR"

  [ -x "${SRC_DIR}/configure" ] || chmod +x "${SRC_DIR}/configure" 2>/dev/null || true
  [ -x "${SRC_DIR}/configure" ] || die "pre-generated configure is missing from repository HEAD."

  touch \
    "${SRC_DIR}/Zend/zend_language_parser.c" \
    "${SRC_DIR}/Zend/zend_language_parser.h" \
    "${SRC_DIR}/Zend/zend_language_scanner.c" \
    "${SRC_DIR}/Zend/zend_ini_parser.c" \
    "${SRC_DIR}/Zend/zend_ini_parser.h" \
    "${SRC_DIR}/Zend/zend_ini_scanner.c" 2>/dev/null || true

}

build_php() {
  local openssl_libdir openssl_pc_prefix
  openssl_libdir="$(find_openssl_libdir)" || die "private OpenSSL library directory not found."

  if [ -x "${PREFIX}/bin/php" ] && [ "$FORCE" != "1" ]; then
    die "development PHP already exists at ${PREFIX}; use FORCE=1 to rebuild."
  fi

  export CPPFLAGS="-D_DEFAULT_SOURCE -I${OPENSSL_PREFIX}/include ${CPPFLAGS:-}"
  export CFLAGS="-O2 -fPIC -fcommon -Wno-error=incompatible-pointer-types -Wno-error=implicit-function-declaration -Wno-error=implicit-int -Wno-error=int-conversion ${CFLAGS:-}"
  export LDFLAGS="-L${openssl_libdir} -Wl,-rpath,${openssl_libdir} ${LDFLAGS:-}"
  export PKG_CONFIG_PATH="${openssl_libdir}/pkgconfig:${PKG_CONFIG_PATH:-}"
  export LD_LIBRARY_PATH="${openssl_libdir}:${LD_LIBRARY_PATH:-}"

  pkg-config --exists openssl || die "private OpenSSL pkg-config metadata was not found in ${openssl_libdir}/pkgconfig."
  openssl_pc_prefix="$(pkg-config --variable=prefix openssl)"
  [ "$openssl_pc_prefix" = "$OPENSSL_PREFIX" ] || \
    die "pkg-config resolved OpenSSL from ${openssl_pc_prefix}, expected ${OPENSSL_PREFIX}."
  log "pkg-config OpenSSL: $(pkg-config --modversion openssl) from ${openssl_pc_prefix}"

  pushd "$SRC_DIR" >/dev/null
    log "configuring minimal PHP 5.6.40 OpenSSL 3.5 probe -> ${PREFIX}"
    # Passing --with-openssl without an explicit directory deliberately selects
    # PHP 5.6's pkg-config path. Its legacy explicit-prefix detector only checks
    # $prefix/$PHP_LIBDIR and therefore misses OpenSSL installed into lib64.
    ./configure \
      --prefix="${PREFIX}" \
      --exec-prefix="${PREFIX}" \
      --with-config-file-path="${PREFIX}/etc" \
      --with-config-file-scan-dir="${PREFIX}/etc/conf.d" \
      --disable-all \
      --enable-cli \
      --enable-fpm \
      --with-fpm-user="${FPM_USER}" \
      --with-fpm-group="${FPM_GROUP}" \
      --with-openssl \
      --with-zlib \
      --enable-hash \
      --enable-json \
      --enable-filter \
      --enable-session \
      --without-pear

    log "make -j${JOBS}"
    make -j"$JOBS"
    make install

    install -d "${PREFIX}/etc" "${PREFIX}/etc/conf.d"
    if [ ! -f "${PREFIX}/etc/php.ini" ]; then
      cp php.ini-production "${PREFIX}/etc/php.ini"
    fi

    if [ ! -f "${PREFIX}/etc/php-fpm.conf" ]; then
      if [ -f "${PREFIX}/etc/php-fpm.conf.default" ]; then
        cp "${PREFIX}/etc/php-fpm.conf.default" "${PREFIX}/etc/php-fpm.conf"
      elif [ -f sapi/fpm/php-fpm.conf ]; then
        cp sapi/fpm/php-fpm.conf "${PREFIX}/etc/php-fpm.conf"
      fi
    fi

    if [ -d "${PREFIX}/etc/php-fpm.d" ] && [ ! -f "${PREFIX}/etc/php-fpm.d/www.conf" ]; then
      if [ -f "${PREFIX}/etc/php-fpm.d/www.conf.default" ]; then
        cp "${PREFIX}/etc/php-fpm.d/www.conf.default" "${PREFIX}/etc/php-fpm.d/www.conf"
      elif [ -f sapi/fpm/www.conf ]; then
        cp sapi/fpm/www.conf "${PREFIX}/etc/php-fpm.d/www.conf"
      fi
    fi
  popd >/dev/null
}

verify() {
  local php="${PREFIX}/bin/php"
  local fpm="${PREFIX}/sbin/php-fpm"
  local openssl_libdir ldd_text
  openssl_libdir="$(find_openssl_libdir)"

  [ -x "$php" ] || die "PHP CLI missing after install."
  [ -x "$fpm" ] || die "PHP-FPM missing after install."

  log "PHP: $("$php" -n -v | sed -n '1p')"
  log "OpenSSL: $("$php" -n -r 'echo OPENSSL_VERSION_TEXT;' 2>/dev/null)"

  "$php" -n -r 'if (strpos(OPENSSL_VERSION_TEXT, "OpenSSL 3.5.") !== 0) { fwrite(STDERR, OPENSSL_VERSION_TEXT); exit(1); }'

  ldd_text="$(ldd "$php" 2>/dev/null)"
  printf '%s\n' "$ldd_text" | grep -F "libssl.so.3 => ${openssl_libdir}/" >/dev/null || \
    die "PHP is not loading private libssl.so.3 from ${openssl_libdir}."
  printf '%s\n' "$ldd_text" | grep -F "libcrypto.so.3 => ${openssl_libdir}/" >/dev/null || \
    die "PHP is not loading private libcrypto.so.3 from ${openssl_libdir}."
  if printf '%s\n' "$ldd_text" | grep -q 'libssl.so.1.1'; then
    die "OpenSSL 1.1 is also loaded in the development PHP process."
  fi

  log "testing HTTPS stream wrapper"
  "$php" -n -r '$d=file_get_contents("https://example.com/"); var_dump($d !== false); if ($d === false) exit(1);'

  log "testing RSA SHA-256 sign/verify"
  "$php" -n -r '
    $k=openssl_pkey_new(array("private_key_bits"=>2048,"private_key_type"=>OPENSSL_KEYTYPE_RSA));
    if ($k === false) { while ($e=openssl_error_string()) fwrite(STDERR,$e."\n"); exit(2); }
    $ok=openssl_sign("php56-openssl35",$sig,$k,OPENSSL_ALGO_SHA256);
    $d=openssl_pkey_get_details($k);
    $pub=openssl_pkey_get_public($d["key"]);
    $v=openssl_verify("php56-openssl35",$sig,$pub,OPENSSL_ALGO_SHA256);
    var_dump($ok,$v);
    if (!$ok || $v !== 1) exit(3);
  '

  if [ -f "${PREFIX}/etc/php-fpm.conf" ]; then
    log "testing FPM configuration"
    "$fpm" -t
  else
    warn "FPM binary built, but no active php-fpm.conf was produced."
  fi

  log "dynamic OpenSSL libraries:"
  printf '%s\n' "$ldd_text" | grep -E 'lib(ssl|crypto)\.so' | sed 's/^/    /'

  cat <<EOF

OpenSSL 3.5 development probe completed successfully.
PHP prefix:     ${PREFIX}
OpenSSL prefix: ${OPENSSL_PREFIX}
EOF
}

main() {
  need_root
  install_deps
  mkdir -p "$BUILD_ROOT" "$NGM_ROOT"
  build_openssl
  provision_openssl_runtime_files
  prepare_php_source
  build_php
  verify
}

main "$@"
