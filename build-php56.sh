#!/usr/bin/env bash
#
# build-php56.sh — build PHP 5.6.40 for NGM on Debian trixie / AlmaLinux 10
#
# Production prefix:
#   /opt/ngm/php/5.6
#
# Private runtime dependencies:
#   OpenSSL 3.5.7: /opt/ngm/php/openssl-3.5
#   curl 8.21.0:   /opt/ngm/php/curl-gnutls (GnuTLS backend)
#   libmcrypt:     /opt/ngm/php/libmcrypt
#
# Compatibility/security fixes belong in the tracked PHP source. This script
# does not rewrite PHP C sources at build time.
#
# Recommended first production-parity validation:
#   PREFIX=/opt/ngm/php/5.6-openssl35-candidate FORCE=1 ./build-php56.sh
#
# Live rebuild after candidate verification:
#   FORCE=1 ./build-php56.sh
#
# FORCE_DEPS=1 also rebuilds the shared private OpenSSL/curl/libmcrypt prefixes.
# RUN_REGRESSION_TESTS=0 skips the post-build regression suite.
# ENABLE_LEGACY_PROVIDER=0 disables the private OpenSSL legacy provider.

set -Eeuo pipefail

REPO_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

PHP_SERIES="5.6"
PHP_RELEASE="5.6.40"
PHP_GIT_URL="${PHP_GIT_URL:-https://github.com/chrismfz/php56.git}"
PHP_GIT_REF="${PHP_GIT_REF:-main}"

NGM_ROOT="${NGM_ROOT:-/opt/ngm/php}"
PREFIX="${PREFIX:-${NGM_ROOT}/${PHP_SERIES}}"
BUILD_ROOT="${BUILD_ROOT:-/usr/local/src/ngm-php56-build}"
SRC_DIR="${BUILD_ROOT}/php-${PHP_RELEASE}"

OPENSSL_VERSION="${OPENSSL_VERSION:-3.5.7}"
OPENSSL_PREFIX="${OPENSSL_PREFIX:-${NGM_ROOT}/openssl-3.5}"
CURL_VERSION="${CURL_VERSION:-8.21.0}"
CURL_PREFIX="${CURL_PREFIX:-${NGM_ROOT}/curl-gnutls}"
MCRYPT_VERSION="${MCRYPT_VERSION:-2.5.8}"
MCRYPT_PREFIX="${MCRYPT_PREFIX:-${NGM_ROOT}/libmcrypt}"

JOBS="${JOBS:-$(nproc 2>/dev/null || echo 2)}"
FORCE="${FORCE:-0}"
FORCE_DEPS="${FORCE_DEPS:-0}"
RUN_REGRESSION_TESTS="${RUN_REGRESSION_TESTS:-1}"
ENABLE_LEGACY_PROVIDER="${ENABLE_LEGACY_PROVIDER:-1}"

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

fetch() {
  local url="$1" dest="$2"
  if [ -s "$dest" ]; then
    log "cached $(basename "$dest")"
    return
  fi
  log "download ${url}"
  curl -fL --retry 3 --retry-delay 2 --connect-timeout 20 -o "${dest}.part" "$url"
  mv -f "${dest}.part" "$dest"
}

find_libdir() {
  local prefix="$1" pattern="$2" dir
  for dir in "${prefix}/lib64" "${prefix}/lib"; do
    if compgen -G "${dir}/${pattern}" >/dev/null 2>&1; then
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

install_deps() {
  if command -v dnf >/dev/null 2>&1; then
    log "installing Alma/RHEL build dependencies"
    dnf install -y 'dnf-command(config-manager)' || true
    dnf config-manager --set-enabled crb 2>/dev/null || true
    dnf install -y epel-release 2>/dev/null || true
    dnf install -y \
      gcc gcc-c++ make ca-certificates curl git patch pkgconf-pkg-config \
      perl perl-FindBin perl-IPC-Cmd perl-File-Compare perl-Data-Dumper \
      m4 tar gzip bzip2 xz \
      libxml2-devel gnutls-devel nettle-devel libjpeg-turbo-devel libpng-devel \
      freetype-devel bzip2-devel readline-devel libxslt-devel gmp-devel \
      sqlite-devel zlib-devel gettext-devel libxcrypt-devel
  elif command -v apt-get >/dev/null 2>&1; then
    log "installing Debian build dependencies"
    export DEBIAN_FRONTEND=noninteractive
    apt-get update -y
    apt-get install -y --no-install-recommends \
      build-essential ca-certificates curl git patch pkg-config perl m4 \
      tar gzip bzip2 xz-utils libxml2-dev libgnutls28-dev nettle-dev \
      libjpeg-dev libpng-dev libfreetype6-dev libbz2-dev libreadline-dev \
      libxslt1-dev libgmp-dev libsqlite3-dev zlib1g-dev libgettextpo-dev \
      libcrypt-dev
  else
    die "unsupported package manager; expected dnf or apt-get."
  fi
}

build_openssl() {
  local tarball="${BUILD_ROOT}/openssl-${OPENSSL_VERSION}.tar.gz" libdir=""
  mkdir -p "$BUILD_ROOT"

  # Keep the matching source tarball even if OpenSSL is already installed;
  # provisioning openssl.cnf uses the source release's canonical config.
  fetch "https://www.openssl.org/source/openssl-${OPENSSL_VERSION}.tar.gz" "$tarball"

  libdir="$(find_libdir "$OPENSSL_PREFIX" 'libssl.so.3' || true)"
  if [ -n "$libdir" ] && [ -x "${OPENSSL_PREFIX}/bin/openssl" ] && [ "$FORCE_DEPS" != "1" ]; then
    if LD_LIBRARY_PATH="$libdir" "${OPENSSL_PREFIX}/bin/openssl" version 2>/dev/null | grep -Fq "OpenSSL ${OPENSSL_VERSION}"; then
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

  find_libdir "$OPENSSL_PREFIX" 'libssl.so.3' >/dev/null || \
    die "OpenSSL installed, but libssl.so.3 was not found under ${OPENSSL_PREFIX}."
}

provision_openssl_runtime_files() {
  local tarball="${BUILD_ROOT}/openssl-${OPENSSL_VERSION}.tar.gz" ca_bundle
  local tmp_config openssl_libdir providers modules_dir=""

  install -d -m 755 "${OPENSSL_PREFIX}/certs"
  install -d -m 700 "${OPENSSL_PREFIX}/private"

  if [ ! -s "${OPENSSL_PREFIX}/openssl.cnf" ]; then
    [ -s "$tarball" ] || die "OpenSSL source tarball missing; cannot provision openssl.cnf."
    log "installing OpenSSL ${OPENSSL_VERSION} configuration"
    tar -xOf "$tarball" "openssl-${OPENSSL_VERSION}/apps/openssl.cnf" > "${OPENSSL_PREFIX}/openssl.cnf"
  fi

  # The private OpenSSL tree is dedicated to the maintained legacy PHP builds.
  # Enable the legacy provider here for application compatibility without
  # weakening the host/system OpenSSL configuration or global TLS SECLEVEL.
  tmp_config="${OPENSSL_PREFIX}/openssl.cnf.tmp.$$"
  awk '
    /^# BEGIN NGM OPENSSL35 LEGACY PROVIDER$/ { skip=1; next }
    /^# END NGM OPENSSL35 LEGACY PROVIDER$/   { skip=0; next }
    !skip { print }
  ' "${OPENSSL_PREFIX}/openssl.cnf" > "$tmp_config"

  if [ "$ENABLE_LEGACY_PROVIDER" = "1" ]; then
    cat >> "$tmp_config" <<'EOF'

# BEGIN NGM OPENSSL35 LEGACY PROVIDER
# Compatibility policy for isolated legacy PHP runtimes only.
[openssl_init]
providers = ngm_provider_sect

[ngm_provider_sect]
default = ngm_default_sect
legacy = ngm_legacy_sect

[ngm_default_sect]
activate = 1

[ngm_legacy_sect]
activate = 1
# END NGM OPENSSL35 LEGACY PROVIDER
EOF
  else
    log "OpenSSL legacy provider compatibility disabled"
  fi

  mv -f "$tmp_config" "${OPENSSL_PREFIX}/openssl.cnf"
  chmod 644 "${OPENSSL_PREFIX}/openssl.cnf"

  ca_bundle="$(find_ca_bundle)" || die "could not locate the system CA bundle."
  ln -sfn "$ca_bundle" "${OPENSSL_PREFIX}/cert.pem"

  [ -r "${OPENSSL_PREFIX}/openssl.cnf" ] || die "OpenSSL configuration is not readable."
  [ -r "${OPENSSL_PREFIX}/cert.pem" ] || die "OpenSSL CA bundle link is not readable."

  if [ "$ENABLE_LEGACY_PROVIDER" = "1" ]; then
    for modules_dir in "${OPENSSL_PREFIX}/lib64/ossl-modules" "${OPENSSL_PREFIX}/lib/ossl-modules"; do
      [ -e "${modules_dir}/legacy.so" ] && break
      modules_dir=""
    done
    [ -n "$modules_dir" ] || die "OpenSSL legacy provider module was not found."

    openssl_libdir="$(find_libdir "$OPENSSL_PREFIX" 'libssl.so.3')" || die "private OpenSSL library directory not found."
    providers="$(OPENSSL_CONF="${OPENSSL_PREFIX}/openssl.cnf" OPENSSL_MODULES="$modules_dir" LD_LIBRARY_PATH="$openssl_libdir" "${OPENSSL_PREFIX}/bin/openssl" list -providers)"
    grep -Eq '^[[:space:]]+default$' <<<"$providers" || die "private OpenSSL default provider did not load."
    grep -Eq '^[[:space:]]+legacy$' <<<"$providers" || die "private OpenSSL legacy provider did not load."
    log "private OpenSSL default + legacy providers enabled"
  fi
}

build_curl() {
  local existing_lib="" ca_bundle
  existing_lib="$(find_libdir "$CURL_PREFIX" 'libcurl.so.4*' || true)"

  if [ -n "$existing_lib" ] && \
     [ -x "${CURL_PREFIX}/bin/curl-config" ] && \
     "${CURL_PREFIX}/bin/curl-config" --version 2>/dev/null | grep -Fq "libcurl ${CURL_VERSION}" && \
     "${CURL_PREFIX}/bin/curl-config" --ssl-backends 2>/dev/null | grep -qi 'GnuTLS' && \
     [ "$FORCE_DEPS" != "1" ]; then
    log "curl ${CURL_VERSION} (GnuTLS) already at ${CURL_PREFIX}"
    return
  fi

  ca_bundle="$(find_ca_bundle)" || die "could not locate the system CA bundle."
  fetch "https://curl.se/download/curl-${CURL_VERSION}.tar.xz" "${BUILD_ROOT}/curl-${CURL_VERSION}.tar.xz"
  rm -rf "${BUILD_ROOT}/curl-${CURL_VERSION}"
  tar -xJf "${BUILD_ROOT}/curl-${CURL_VERSION}.tar.xz" -C "$BUILD_ROOT"

  pushd "${BUILD_ROOT}/curl-${CURL_VERSION}" >/dev/null
    log "building curl ${CURL_VERSION} with GnuTLS -> ${CURL_PREFIX}"
    CFLAGS="-O2 -fPIC" ./configure \
      --prefix="${CURL_PREFIX}" \
      --enable-shared --disable-static \
      --with-gnutls --without-openssl \
      --with-zlib --with-ca-bundle="${ca_bundle}" \
      --without-libpsl --without-libidn2 --without-brotli --without-zstd \
      --without-nghttp2 --without-nghttp3 --without-ngtcp2 --without-quiche \
      --without-libssh2 --without-libssh --disable-ldap --disable-ldaps
    make -j"$JOBS"
    make install
  popd >/dev/null

  "${CURL_PREFIX}/bin/curl-config" --ssl-backends 2>/dev/null | grep -qi 'GnuTLS' || \
    die "private curl was not built with GnuTLS."
}

build_libmcrypt() {
  local existing_lib=""
  existing_lib="$(find_libdir "$MCRYPT_PREFIX" 'libmcrypt.so*' || true)"
  if [ -n "$existing_lib" ] && [ "$FORCE_DEPS" != "1" ]; then
    log "libmcrypt already at ${MCRYPT_PREFIX}"
    return
  fi

  fetch \
    "https://sourceforge.net/projects/mcrypt/files/Libmcrypt/${MCRYPT_VERSION}/libmcrypt-${MCRYPT_VERSION}.tar.gz/download" \
    "${BUILD_ROOT}/libmcrypt-${MCRYPT_VERSION}.tar.gz"
  rm -rf "${BUILD_ROOT}/libmcrypt-${MCRYPT_VERSION}"
  tar -xzf "${BUILD_ROOT}/libmcrypt-${MCRYPT_VERSION}.tar.gz" -C "$BUILD_ROOT"

  pushd "${BUILD_ROOT}/libmcrypt-${MCRYPT_VERSION}" >/dev/null
    log "building libmcrypt ${MCRYPT_VERSION} -> ${MCRYPT_PREFIX}"
    CFLAGS="-O2 -fPIC -fcommon -Wno-error=implicit-function-declaration -Wno-error=implicit-int" \
    CPPFLAGS="-D_DEFAULT_SOURCE" \
      ./configure --prefix="${MCRYPT_PREFIX}" --disable-posix-threads
    make -j"$JOBS"
    make install
  popd >/dev/null
}

fetch_php_source() {
  if [ ! -d "${SRC_DIR}/.git" ]; then
    rm -rf "$SRC_DIR"
    mkdir -p "$SRC_DIR"
    git -C "$SRC_DIR" init -q
    git -C "$SRC_DIR" remote add origin "$PHP_GIT_URL"
  else
    git -C "$SRC_DIR" remote set-url origin "$PHP_GIT_URL"
  fi

  log "fetching ${PHP_GIT_URL} @ ${PHP_GIT_REF}"
  git -C "$SRC_DIR" fetch --depth 1 origin "$PHP_GIT_REF"
  git -C "$SRC_DIR" checkout -q -f --detach FETCH_HEAD
  git -C "$SRC_DIR" clean -q -f -d -x

  [ -x "${SRC_DIR}/configure" ] || chmod +x "${SRC_DIR}/configure" 2>/dev/null || true
  [ -x "${SRC_DIR}/configure" ] || die "tracked pre-generated configure is missing."

  # Do not regenerate parser/scanner output with modern host tools.
  touch \
    "${SRC_DIR}/Zend/zend_language_parser.c" \
    "${SRC_DIR}/Zend/zend_language_parser.h" \
    "${SRC_DIR}/Zend/zend_language_scanner.c" \
    "${SRC_DIR}/Zend/zend_ini_parser.c" \
    "${SRC_DIR}/Zend/zend_ini_parser.h" \
    "${SRC_DIR}/Zend/zend_ini_scanner.c" 2>/dev/null || true
}

build_php() {
  local openssl_libdir curl_libdir mcrypt_libdir openssl_pc_prefix

  if [ -x "${PREFIX}/sbin/php-fpm" ] && [ "$FORCE" != "1" ]; then
    die "PHP ${PHP_SERIES} already exists at ${PREFIX}/sbin/php-fpm (use FORCE=1 to rebuild)."
  fi

  openssl_libdir="$(find_libdir "$OPENSSL_PREFIX" 'libssl.so.3')" || die "private OpenSSL library directory not found."
  curl_libdir="$(find_libdir "$CURL_PREFIX" 'libcurl.so.4*')" || die "private curl library directory not found."
  mcrypt_libdir="$(find_libdir "$MCRYPT_PREFIX" 'libmcrypt.so*')" || die "private libmcrypt library directory not found."

  export PATH="${CURL_PREFIX}/bin:${PATH}"
  export PKG_CONFIG_PATH="${openssl_libdir}/pkgconfig:${curl_libdir}/pkgconfig:${mcrypt_libdir}/pkgconfig:${PKG_CONFIG_PATH:-}"
  export LD_LIBRARY_PATH="${openssl_libdir}:${curl_libdir}:${mcrypt_libdir}:${LD_LIBRARY_PATH:-}"
  export CFLAGS="-O2 -fPIC -fcommon -Wno-error=incompatible-pointer-types -Wno-error=implicit-function-declaration -Wno-error=implicit-int -Wno-error=int-conversion ${CFLAGS:-}"
  export CPPFLAGS="-D_DEFAULT_SOURCE -I${OPENSSL_PREFIX}/include -I${CURL_PREFIX}/include -I${MCRYPT_PREFIX}/include ${CPPFLAGS:-}"
  export LDFLAGS="-L${openssl_libdir} -L${curl_libdir} -L${mcrypt_libdir} -Wl,-rpath,${openssl_libdir} -Wl,-rpath,${curl_libdir} -Wl,-rpath,${mcrypt_libdir} ${LDFLAGS:-}"

  pkg-config --exists openssl || die "private OpenSSL pkg-config metadata not found."
  openssl_pc_prefix="$(pkg-config --variable=prefix openssl)"
  [ "$openssl_pc_prefix" = "$OPENSSL_PREFIX" ] || \
    die "pkg-config resolved OpenSSL from ${openssl_pc_prefix}, expected ${OPENSSL_PREFIX}."

  pushd "$SRC_DIR" >/dev/null
    log "configure PHP ${PHP_RELEASE} -> ${PREFIX}"
    # --with-openssl intentionally has no explicit prefix: PHP 5.6 then uses
    # pkg-config, which correctly resolves the private OpenSSL lib64 install.
    ./configure \
      --prefix="${PREFIX}" \
      --exec-prefix="${PREFIX}" \
      --with-config-file-path="${PREFIX}/etc" \
      --with-config-file-scan-dir="${PREFIX}/etc/conf.d" \
      --enable-fpm \
      --with-fpm-user="${FPM_USER}" \
      --with-fpm-group="${FPM_GROUP}" \
      --with-openssl \
      --with-zlib \
      --enable-pdo \
      --enable-opcache \
      --enable-mbstring \
      --enable-bcmath \
      --enable-calendar \
      --enable-exif \
      --enable-ftp \
      --enable-pcntl \
      --enable-shmop \
      --enable-soap \
      --enable-sockets \
      --enable-sysvmsg --enable-sysvsem --enable-sysvshm \
      --enable-zip \
      --with-bz2 \
      --with-curl="${CURL_PREFIX}" \
      --with-gd --with-jpeg-dir=/usr --with-png-dir=/usr --with-freetype-dir=/usr \
      --with-gettext \
      --with-gmp \
      --with-iconv \
      --with-mcrypt="${MCRYPT_PREFIX}" \
      --with-mhash \
      --with-mysql=mysqlnd \
      --with-mysqli=mysqlnd \
      --with-pdo-mysql=mysqlnd \
      --with-readline \
      --with-xsl \
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
  local php_bin="${PREFIX}/bin/php" fpm_bin="${PREFIX}/sbin/php-fpm"
  local openssl_libdir curl_libdir modules module actual_version openssl_text
  local curl_version curl_tls ldd_text

  [ -x "$php_bin" ] || die "expected CLI binary missing: ${php_bin}"
  [ -x "$fpm_bin" ] || die "expected FPM binary missing: ${fpm_bin}"

  actual_version="$("$php_bin" -n -r 'echo PHP_VERSION;' 2>/dev/null)"
  [ "$actual_version" = "$PHP_RELEASE" ] || die "built PHP reports ${actual_version}, expected ${PHP_RELEASE}."

  openssl_text="$("$php_bin" -n -r 'echo OPENSSL_VERSION_TEXT;' 2>/dev/null)"
  case "$openssl_text" in
    *"OpenSSL ${OPENSSL_VERSION}"*) ;;
    *) die "PHP loaded an unexpected OpenSSL: ${openssl_text:-unknown}" ;;
  esac

  modules="$("$php_bin" -n -m 2>/dev/null)"
  for module in openssl curl gd mbstring mcrypt mysql mysqli PDO pdo_mysql zip; do
    grep -Fxq "$module" <<<"$modules" || die "expected PHP module missing: ${module}"
  done

  curl_version="$("$php_bin" -n -r '$v=curl_version(); echo $v["version"];' 2>/dev/null)"
  curl_tls="$("$php_bin" -n -r '$v=curl_version(); echo $v["ssl_version"];' 2>/dev/null)"
  [ "$curl_version" = "$CURL_VERSION" ] || die "PHP loaded libcurl ${curl_version:-unknown}, expected ${CURL_VERSION}."
  case "$curl_tls" in
    *GnuTLS*) ;;
    *) die "PHP's libcurl uses an unexpected TLS backend: ${curl_tls:-unknown}" ;;
  esac

  openssl_libdir="$(find_libdir "$OPENSSL_PREFIX" 'libssl.so.3')"
  curl_libdir="$(find_libdir "$CURL_PREFIX" 'libcurl.so.4*')"
  ldd_text="$(ldd "$php_bin" 2>/dev/null)"

  grep -F "libssl.so.3 => ${openssl_libdir}/" <<<"$ldd_text" >/dev/null || \
    die "PHP is not loading private libssl.so.3 from ${openssl_libdir}."
  grep -F "libcrypto.so.3 => ${openssl_libdir}/" <<<"$ldd_text" >/dev/null || \
    die "PHP is not loading private libcrypto.so.3 from ${openssl_libdir}."
  grep -F "libcurl.so.4 => ${curl_libdir}/" <<<"$ldd_text" >/dev/null || \
    die "PHP is not loading private libcurl from ${curl_libdir}."

  if grep -Eq 'lib(ssl|crypto)\.so\.1\.1([[:space:]]|$)' <<<"$ldd_text"; then
    printf '%s\n' "$ldd_text" | grep -E 'lib(curl|ssl|crypto)\.so' >&2 || true
    die "OpenSSL 1.1 is also loaded; refusing a mixed-ABI PHP build."
  fi

  log "testing OpenSSL HTTPS stream"
  "$php_bin" -n -r '$d=file_get_contents("https://example.com/"); var_dump($d !== false); if ($d === false) exit(1);'

  log "testing private curl/GnuTLS HTTPS"
  "$php_bin" -n -r '
    $c=curl_init("https://example.com/");
    curl_setopt($c,CURLOPT_RETURNTRANSFER,true);
    curl_setopt($c,CURLOPT_TIMEOUT,15);
    $d=curl_exec($c);
    if ($d === false) { fwrite(STDERR,curl_error($c)."\n"); exit(1); }
    curl_close($c);
  '

  if [ -f "${PREFIX}/etc/php-fpm.conf" ]; then
    log "testing FPM configuration"
    "$fpm_bin" -t
  else
    warn "FPM binary built, but no active php-fpm.conf was produced."
  fi

  log "installed: $("$php_bin" -n -v | sed -n '1p')"
  log "OpenSSL: ${openssl_text}"
  log "libcurl: ${curl_version} (${curl_tls})"
  log "dynamic TLS libraries:"
  printf '%s\n' "$ldd_text" | grep -E 'lib(curl|ssl|crypto|gnutls)\.so' | sed 's/^/    /'

  if [ "$ENABLE_LEGACY_PROVIDER" = "1" ]; then
    log "testing installed OpenSSL legacy provider through default PHP config"
    "$php_bin" -n -r '$d=openssl_digest("abc","md4"); var_dump($d === "a448017aaf21d8525fc10ae87aa6729d"); if ($d !== "a448017aaf21d8525fc10ae87aa6729d") exit(1);'
  fi
}

run_regression_tests() {
  local test

  if [ "$RUN_REGRESSION_TESTS" != "1" ]; then
    log "post-build regression suite disabled"
    return
  fi

  for test in \
    test-openssl35-dev.sh \
    test-openssl35-legacy.sh; do
    [ -r "${REPO_DIR}/${test}" ] || die "required regression test missing: ${REPO_DIR}/${test}"
    log "running ${test} against ${PREFIX}"
    PHP_PREFIX="$PREFIX" OPENSSL_PREFIX="$OPENSSL_PREFIX" bash "${REPO_DIR}/${test}"
  done

  log "all PHP ${PHP_SERIES} production regression suites passed"
}

main() {
  need_root
  mkdir -p "$BUILD_ROOT" "$NGM_ROOT"
  install_deps
  build_openssl
  provision_openssl_runtime_files
  build_curl
  build_libmcrypt
  fetch_php_source
  build_php
  verify
  run_regression_tests
}

main "$@"
