/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         ini_parse
#define yylex           ini_lex
#define yyerror         ini_error
#define yydebug         ini_debug
#define yynerrs         ini_nerrs

/* First part of user prologue.  */
#line 1 "Zend/zend_ini_parser.y"

/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) 1998-2016 Zend Technologies Ltd. (http://www.zend.com) |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.zend.com/license/2_00.txt.                                |
   | If you did not receive a copy of the Zend license and are unable to  |
   | obtain it through the world-wide-web, please send a note to          |
   | license@zend.com so we can mail you a copy immediately.              |
   +----------------------------------------------------------------------+
   | Authors: Zeev Suraski <zeev@zend.com>                                |
   |          Jani Taskinen <jani@php.net>                                |
   +----------------------------------------------------------------------+
*/

/* $Id$ */

#define DEBUG_CFG_PARSER 0

#include "zend.h"
#include "zend_API.h"
#include "zend_ini.h"
#include "zend_constants.h"
#include "zend_ini_scanner.h"
#include "zend_extensions.h"

#ifdef PHP_WIN32
#include "win32/syslog.h"
#endif

#define YYERROR_VERBOSE
#define YYSTYPE zval

#ifdef ZTS
#define YYPARSE_PARAM tsrm_ls
#define YYLEX_PARAM tsrm_ls
int ini_parse(void *arg);
#else
int ini_parse(void);
#endif

#define ZEND_INI_PARSER_CB	(CG(ini_parser_param))->ini_parser_cb
#define ZEND_INI_PARSER_ARG	(CG(ini_parser_param))->arg

/* {{{ zend_ini_do_op()
*/
static void zend_ini_do_op(char type, zval *result, zval *op1, zval *op2)
{
	int i_result;
	int i_op1, i_op2;
	char str_result[MAX_LENGTH_OF_LONG+1];

	i_op1 = atoi(Z_STRVAL_P(op1));
	free(Z_STRVAL_P(op1));
	if (op2) {
		i_op2 = atoi(Z_STRVAL_P(op2));
		free(Z_STRVAL_P(op2));
	} else {
		i_op2 = 0;
	}

	switch (type) {
		case '|':
			i_result = i_op1 | i_op2;
			break;
		case '&':
			i_result = i_op1 & i_op2;
			break;
		case '^':
			i_result = i_op1 ^ i_op2;
			break;
		case '~':
			i_result = ~i_op1;
			break;
		case '!':
			i_result = !i_op1;
			break;
		default:
			i_result = 0;
			break;
	}

	Z_STRLEN_P(result) = zend_sprintf(str_result, "%d", i_result);
	Z_STRVAL_P(result) = (char *) malloc(Z_STRLEN_P(result)+1);
	memcpy(Z_STRVAL_P(result), str_result, Z_STRLEN_P(result));
	Z_STRVAL_P(result)[Z_STRLEN_P(result)] = 0;
	Z_TYPE_P(result) = IS_STRING;
}
/* }}} */

/* {{{ zend_ini_init_string()
*/
static void zend_ini_init_string(zval *result)
{
	Z_STRVAL_P(result) = malloc(1);
	Z_STRVAL_P(result)[0] = 0;
	Z_STRLEN_P(result) = 0;
	Z_TYPE_P(result) = IS_STRING;
}
/* }}} */

/* {{{ zend_ini_add_string()
*/
static void zend_ini_add_string(zval *result, zval *op1, zval *op2)
{
	int length;

	if (Z_TYPE_P(op1) != IS_STRING) {
		zval copy;
		MAKE_COPY_ZVAL(&op1, &copy);
		convert_to_string(&copy);
		Z_STRVAL_P(op1) = zend_strndup(Z_STRVAL(copy), Z_STRLEN(copy));
		Z_STRLEN_P(op1) = Z_STRLEN(copy);
		zval_dtor(&copy);
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2);

	Z_STRVAL_P(result) = (char *) realloc(Z_STRVAL_P(op1), length+1);
	memcpy(Z_STRVAL_P(result)+Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[length] = 0;
	Z_STRLEN_P(result) = length;
	Z_TYPE_P(result) = IS_STRING;
}
/* }}} */

/* {{{ zend_ini_get_constant()
*/
static void zend_ini_get_constant(zval *result, zval *name TSRMLS_DC)
{
	zval z_constant;

	/* If name contains ':' it is not a constant. Bug #26893. */
	if (!memchr(Z_STRVAL_P(name), ':', Z_STRLEN_P(name))
		   	&& zend_get_constant(Z_STRVAL_P(name), Z_STRLEN_P(name), &z_constant TSRMLS_CC)) {
		/* z_constant is emalloc()'d */
		convert_to_string(&z_constant);
		Z_STRVAL_P(result) = zend_strndup(Z_STRVAL(z_constant), Z_STRLEN(z_constant));
		Z_STRLEN_P(result) = Z_STRLEN(z_constant);
		Z_TYPE_P(result) = Z_TYPE(z_constant);
		zval_dtor(&z_constant);
		free(Z_STRVAL_P(name));
	} else {
		*result = *name;
	}
}
/* }}} */

/* {{{ zend_ini_get_var()
*/
static void zend_ini_get_var(zval *result, zval *name TSRMLS_DC)
{
	zval curval;
	char *envvar;

	/* Fetch configuration option value */
	if (zend_get_configuration_directive(Z_STRVAL_P(name), Z_STRLEN_P(name)+1, &curval) == SUCCESS) {
		Z_STRVAL_P(result) = zend_strndup(Z_STRVAL(curval), Z_STRLEN(curval));
		Z_STRLEN_P(result) = Z_STRLEN(curval);
	/* ..or if not found, try ENV */
	} else if ((envvar = zend_getenv(Z_STRVAL_P(name), Z_STRLEN_P(name) TSRMLS_CC)) != NULL ||
			   (envvar = getenv(Z_STRVAL_P(name))) != NULL) {
		Z_STRVAL_P(result) = strdup(envvar);
		Z_STRLEN_P(result) = strlen(envvar);
	} else {
		zend_ini_init_string(result);
	}
}
/* }}} */

/* {{{ ini_error()
*/
static void ini_error(char *msg)
{
	char *error_buf;
	int error_buf_len;
	char *currently_parsed_filename;
	TSRMLS_FETCH();

	currently_parsed_filename = zend_ini_scanner_get_filename(TSRMLS_C);
	if (currently_parsed_filename) {
		error_buf_len = 128 + strlen(msg) + strlen(currently_parsed_filename); /* should be more than enough */
		error_buf = (char *) emalloc(error_buf_len);

		sprintf(error_buf, "%s in %s on line %d\n", msg, currently_parsed_filename, zend_ini_scanner_get_lineno(TSRMLS_C));
	} else {
		error_buf = estrdup("Invalid configuration directive\n");
	}

	if (CG(ini_parser_unbuffered_errors)) {
#ifdef PHP_WIN32
		syslog(LOG_ALERT, "PHP: %s (%s)", error_buf, GetCommandLine());
#endif
		fprintf(stderr, "PHP:  %s", error_buf);
	} else {
		zend_error(E_WARNING, "%s", error_buf);
	}
	efree(error_buf);
}
/* }}} */

/* {{{ zend_parse_ini_file()
*/
ZEND_API int zend_parse_ini_file(zend_file_handle *fh, zend_bool unbuffered_errors, int scanner_mode, zend_ini_parser_cb_t ini_parser_cb, void *arg TSRMLS_DC)
{
	int retval;
	zend_ini_parser_param ini_parser_param;

	ini_parser_param.ini_parser_cb = ini_parser_cb;
	ini_parser_param.arg = arg;
	CG(ini_parser_param) = &ini_parser_param;

	if (zend_ini_open_file_for_scanning(fh, scanner_mode TSRMLS_CC) == FAILURE) {
		return FAILURE;
	}

	CG(ini_parser_unbuffered_errors) = unbuffered_errors;
	retval = ini_parse(TSRMLS_C);
	zend_file_handle_dtor(fh TSRMLS_CC);

	shutdown_ini_scanner(TSRMLS_C);

	if (retval == 0) {
		return SUCCESS;
	} else {
		return FAILURE;
	}
}
/* }}} */

/* {{{ zend_parse_ini_string()
*/
ZEND_API int zend_parse_ini_string(char *str, zend_bool unbuffered_errors, int scanner_mode, zend_ini_parser_cb_t ini_parser_cb, void *arg TSRMLS_DC)
{
	int retval;
	zend_ini_parser_param ini_parser_param;

	ini_parser_param.ini_parser_cb = ini_parser_cb;
	ini_parser_param.arg = arg;
	CG(ini_parser_param) = &ini_parser_param;

	if (zend_ini_prepare_string_for_scanning(str, scanner_mode TSRMLS_CC) == FAILURE) {
		return FAILURE;
	}

	CG(ini_parser_unbuffered_errors) = unbuffered_errors;
	retval = ini_parse(TSRMLS_C);

	shutdown_ini_scanner(TSRMLS_C);

	if (retval == 0) {
		return SUCCESS;
	} else {
		return FAILURE;
	}
}
/* }}} */


#line 341 "Zend/zend_ini_parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "zend_ini_parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TC_SECTION = 3,                 /* TC_SECTION  */
  YYSYMBOL_TC_RAW = 4,                     /* TC_RAW  */
  YYSYMBOL_TC_CONSTANT = 5,                /* TC_CONSTANT  */
  YYSYMBOL_TC_NUMBER = 6,                  /* TC_NUMBER  */
  YYSYMBOL_TC_STRING = 7,                  /* TC_STRING  */
  YYSYMBOL_TC_WHITESPACE = 8,              /* TC_WHITESPACE  */
  YYSYMBOL_TC_LABEL = 9,                   /* TC_LABEL  */
  YYSYMBOL_TC_OFFSET = 10,                 /* TC_OFFSET  */
  YYSYMBOL_TC_DOLLAR_CURLY = 11,           /* TC_DOLLAR_CURLY  */
  YYSYMBOL_TC_VARNAME = 12,                /* TC_VARNAME  */
  YYSYMBOL_TC_QUOTED_STRING = 13,          /* TC_QUOTED_STRING  */
  YYSYMBOL_BOOL_TRUE = 14,                 /* BOOL_TRUE  */
  YYSYMBOL_BOOL_FALSE = 15,                /* BOOL_FALSE  */
  YYSYMBOL_NULL_NULL = 16,                 /* NULL_NULL  */
  YYSYMBOL_END_OF_LINE = 17,               /* END_OF_LINE  */
  YYSYMBOL_18_ = 18,                       /* '='  */
  YYSYMBOL_19_ = 19,                       /* ':'  */
  YYSYMBOL_20_ = 20,                       /* ','  */
  YYSYMBOL_21_ = 21,                       /* '.'  */
  YYSYMBOL_22_ = 22,                       /* '"'  */
  YYSYMBOL_23_ = 23,                       /* '\''  */
  YYSYMBOL_24_ = 24,                       /* '^'  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '-'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '*'  */
  YYSYMBOL_29_ = 29,                       /* '%'  */
  YYSYMBOL_30_ = 30,                       /* '$'  */
  YYSYMBOL_31_ = 31,                       /* '~'  */
  YYSYMBOL_32_ = 32,                       /* '<'  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '?'  */
  YYSYMBOL_35_ = 35,                       /* '@'  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* '|'  */
  YYSYMBOL_39_ = 39,                       /* '&'  */
  YYSYMBOL_40_ = 40,                       /* '!'  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_statement_list = 45,            /* statement_list  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_section_string_or_value = 47,   /* section_string_or_value  */
  YYSYMBOL_string_or_value = 48,           /* string_or_value  */
  YYSYMBOL_option_offset = 49,             /* option_offset  */
  YYSYMBOL_encapsed_list = 50,             /* encapsed_list  */
  YYSYMBOL_var_string_list_section = 51,   /* var_string_list_section  */
  YYSYMBOL_var_string_list = 52,           /* var_string_list  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_cfg_var_ref = 54,               /* cfg_var_ref  */
  YYSYMBOL_constant_literal = 55,          /* constant_literal  */
  YYSYMBOL_constant_string = 56            /* constant_string  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   123

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  72

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   272


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,    22,     2,    30,    29,    39,    23,
      42,    43,    28,    25,    20,    26,    21,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    19,     2,
      32,    18,    33,    34,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    24,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,    38,    37,    31,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   291,   291,   292,   296,   303,   311,   324,   325,   329,
     330,   334,   335,   336,   337,   338,   342,   343,   347,   348,
     349,   353,   354,   355,   356,   357,   358,   362,   363,   364,
     365,   366,   367,   371,   372,   373,   374,   375,   376,   377,
     381,   385,   386,   387,   388,   389,   393,   394,   395,   396,
     397
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TC_SECTION", "TC_RAW",
  "TC_CONSTANT", "TC_NUMBER", "TC_STRING", "TC_WHITESPACE", "TC_LABEL",
  "TC_OFFSET", "TC_DOLLAR_CURLY", "TC_VARNAME", "TC_QUOTED_STRING",
  "BOOL_TRUE", "BOOL_FALSE", "NULL_NULL", "END_OF_LINE", "'='", "':'",
  "','", "'.'", "'\"'", "'\\''", "'^'", "'+'", "'-'", "'/'", "'*'", "'%'",
  "'$'", "'~'", "'<'", "'>'", "'?'", "'@'", "'{'", "'}'", "'|'", "'&'",
  "'!'", "']'", "'('", "')'", "$accept", "statement_list", "statement",
  "section_string_or_value", "string_or_value", "option_offset",
  "encapsed_list", "var_string_list_section", "var_string_list", "expr",
  "cfg_var_ref", "constant_literal", "constant_string", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -25,     9,   -25,    73,   -17,    81,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,    15,   -25,   -20,    93,   -25,   -25,     0,
     -25,   -25,   -25,   -25,   -25,   -25,   -12,   101,   -25,   -25,
      -7,    36,   -25,   -25,   -25,   -25,   -25,   -25,   -25,   -25,
      28,    28,    28,   -25,   101,    -1,    40,    30,   -25,   -25,
     -25,   -25,   -25,   -25,   -25,    80,   -25,   -25,    33,    28,
      28,    28,   -25,     0,   100,   -25,   -25,   -25,   -25,   -25,
     -25,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     1,    10,     7,    17,     8,     2,    42,    41,
      43,    44,    45,     0,    20,     0,     9,    21,    22,     0,
      47,    46,    48,    49,    50,    20,     0,    16,    27,    28,
       0,     0,     4,    20,    24,    25,    12,    13,    14,    15,
       0,     0,     0,     5,    33,    11,     0,     0,    20,    30,
      31,    40,    19,    23,    18,     0,    37,    38,     0,     0,
       0,     0,    29,     0,     0,    26,    39,    36,    34,    35,
       6,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,   -25,    -9,   -25,   -23,   -25,    50,     4,
      -3,    44,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     7,    15,    43,    26,    31,    16,    44,    45,
      28,    18,    29
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,    19,    46,    50,    20,    21,    22,    23,    24,     2,
      55,    13,     3,    34,    36,    37,    38,    39,     4,     5,
      50,    32,    25,    59,    49,    64,     6,    30,    54,    47,
      51,    40,    20,    21,    22,    23,    24,    60,    61,    13,
      41,    49,    42,    54,    56,    57,    58,    13,    63,    52,
      25,    13,    54,    52,    70,    27,     0,    59,    53,    40,
      35,    54,    62,    67,    68,    69,     0,     0,    41,     0,
      42,    60,    61,     0,     0,     0,    66,     8,     9,    10,
      11,    12,     0,     0,    13,    20,    21,    22,    23,    24,
       0,    13,    13,    52,     0,    14,     0,     8,     9,    10,
      11,    12,    65,    25,    13,    20,    21,    22,    23,    24,
       0,    13,    13,    52,     0,    33,     0,     0,     0,     0,
       0,     0,    71,    48
};

static const yytype_int8 yycheck[] =
{
       3,    18,    25,    27,     4,     5,     6,     7,     8,     0,
      33,    11,     3,    16,    14,    15,    16,    17,     9,    10,
      44,    41,    22,    24,    27,    48,    17,    12,    31,    41,
      37,    31,     4,     5,     6,     7,     8,    38,    39,    11,
      40,    44,    42,    46,    40,    41,    42,    11,    18,    13,
      22,    11,    55,    13,    63,     5,    -1,    24,    22,    31,
      16,    64,    22,    59,    60,    61,    -1,    -1,    40,    -1,
      42,    38,    39,    -1,    -1,    -1,    43,     4,     5,     6,
       7,     8,    -1,    -1,    11,     4,     5,     6,     7,     8,
      -1,    11,    11,    13,    -1,    22,    -1,     4,     5,     6,
       7,     8,    22,    22,    11,     4,     5,     6,     7,     8,
      -1,    11,    11,    13,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    22,    22
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,     0,     3,     9,    10,    17,    46,     4,     5,
       6,     7,     8,    11,    22,    47,    51,    54,    55,    18,
       4,     5,     6,     7,     8,    22,    49,    52,    54,    56,
      12,    50,    41,    22,    54,    55,    14,    15,    16,    17,
      31,    40,    42,    48,    52,    53,    50,    41,    22,    54,
      56,    37,    13,    22,    54,    50,    53,    53,    53,    24,
      38,    39,    22,    18,    50,    22,    43,    53,    53,    53,
      48,    22
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    46,    46,    46,    47,
      47,    48,    48,    48,    48,    48,    49,    49,    50,    50,
      50,    51,    51,    51,    51,    51,    51,    52,    52,    52,
      52,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      54,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     3,     5,     1,     1,     1,
       0,     1,     1,     1,     1,     1,     1,     0,     2,     2,
       0,     1,     1,     3,     2,     2,     4,     1,     1,     3,
       2,     2,     4,     1,     3,     3,     3,     2,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* statement: TC_SECTION section_string_or_value ']'  */
#line 296 "Zend/zend_ini_parser.y"
                                                       {
#if DEBUG_CFG_PARSER
			printf("SECTION: [%s]\n", Z_STRVAL(yyvsp[-1]));
#endif
			ZEND_INI_PARSER_CB(&yyvsp[-1], NULL, NULL, ZEND_INI_PARSER_SECTION, ZEND_INI_PARSER_ARG TSRMLS_CC);
			free(Z_STRVAL(yyvsp[-1]));
		}
#line 1454 "Zend/zend_ini_parser.c"
    break;

  case 5: /* statement: TC_LABEL '=' string_or_value  */
#line 303 "Zend/zend_ini_parser.y"
                                             {
#if DEBUG_CFG_PARSER
			printf("NORMAL: '%s' = '%s'\n", Z_STRVAL(yyvsp[-2]), Z_STRVAL(yyvsp[0]));
#endif
			ZEND_INI_PARSER_CB(&yyvsp[-2], &yyvsp[0], NULL, ZEND_INI_PARSER_ENTRY, ZEND_INI_PARSER_ARG TSRMLS_CC);
			free(Z_STRVAL(yyvsp[-2]));
			zval_internal_dtor(&yyvsp[0]);
		}
#line 1467 "Zend/zend_ini_parser.c"
    break;

  case 6: /* statement: TC_OFFSET option_offset ']' '=' string_or_value  */
#line 311 "Zend/zend_ini_parser.y"
                                                                {
#if DEBUG_CFG_PARSER
			printf("OFFSET: '%s'[%s] = '%s'\n", Z_STRVAL(yyvsp[-4]), Z_STRVAL(yyvsp[-3]), Z_STRVAL(yyvsp[0]));
#endif
			ZEND_INI_PARSER_CB(&yyvsp[-4], &yyvsp[0], &yyvsp[-3], ZEND_INI_PARSER_POP_ENTRY, ZEND_INI_PARSER_ARG TSRMLS_CC);
			free(Z_STRVAL(yyvsp[-4]));
			if (Z_TYPE(yyvsp[-3]) == IS_STRING) {
				free(Z_STRVAL(yyvsp[-3]));
			} else {
				zval_dtor(&yyvsp[-3]);
			}
			zval_internal_dtor(&yyvsp[0]);
		}
#line 1485 "Zend/zend_ini_parser.c"
    break;

  case 7: /* statement: TC_LABEL  */
#line 324 "Zend/zend_ini_parser.y"
                                { ZEND_INI_PARSER_CB(&yyvsp[0], NULL, NULL, ZEND_INI_PARSER_ENTRY, ZEND_INI_PARSER_ARG TSRMLS_CC); free(Z_STRVAL(yyvsp[0])); }
#line 1491 "Zend/zend_ini_parser.c"
    break;

  case 9: /* section_string_or_value: var_string_list_section  */
#line 329 "Zend/zend_ini_parser.y"
                                                        { yyval = yyvsp[0]; }
#line 1497 "Zend/zend_ini_parser.c"
    break;

  case 10: /* section_string_or_value: %empty  */
#line 330 "Zend/zend_ini_parser.y"
                                                                        { zend_ini_init_string(&yyval); }
#line 1503 "Zend/zend_ini_parser.c"
    break;

  case 11: /* string_or_value: expr  */
#line 334 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; }
#line 1509 "Zend/zend_ini_parser.c"
    break;

  case 12: /* string_or_value: BOOL_TRUE  */
#line 335 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; }
#line 1515 "Zend/zend_ini_parser.c"
    break;

  case 13: /* string_or_value: BOOL_FALSE  */
#line 336 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; }
#line 1521 "Zend/zend_ini_parser.c"
    break;

  case 14: /* string_or_value: NULL_NULL  */
#line 337 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; }
#line 1527 "Zend/zend_ini_parser.c"
    break;

  case 15: /* string_or_value: END_OF_LINE  */
#line 338 "Zend/zend_ini_parser.y"
                                                                        { zend_ini_init_string(&yyval); }
#line 1533 "Zend/zend_ini_parser.c"
    break;

  case 16: /* option_offset: var_string_list  */
#line 342 "Zend/zend_ini_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 1539 "Zend/zend_ini_parser.c"
    break;

  case 17: /* option_offset: %empty  */
#line 343 "Zend/zend_ini_parser.y"
                                                                        { zend_ini_init_string(&yyval); }
#line 1545 "Zend/zend_ini_parser.c"
    break;

  case 18: /* encapsed_list: encapsed_list cfg_var_ref  */
#line 347 "Zend/zend_ini_parser.y"
                                                        { zend_ini_add_string(&yyval, &yyvsp[-1], &yyvsp[0]); free(Z_STRVAL(yyvsp[0])); }
#line 1551 "Zend/zend_ini_parser.c"
    break;

  case 19: /* encapsed_list: encapsed_list TC_QUOTED_STRING  */
#line 348 "Zend/zend_ini_parser.y"
                                                { zend_ini_add_string(&yyval, &yyvsp[-1], &yyvsp[0]); free(Z_STRVAL(yyvsp[0])); }
#line 1557 "Zend/zend_ini_parser.c"
    break;

  case 20: /* encapsed_list: %empty  */
#line 349 "Zend/zend_ini_parser.y"
                                                                        { zend_ini_init_string(&yyval); }
#line 1563 "Zend/zend_ini_parser.c"
    break;

  case 21: /* var_string_list_section: cfg_var_ref  */
#line 353 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; }
#line 1569 "Zend/zend_ini_parser.c"
    break;

  case 22: /* var_string_list_section: constant_literal  */
#line 354 "Zend/zend_ini_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 1575 "Zend/zend_ini_parser.c"
    break;

  case 23: /* var_string_list_section: '"' encapsed_list '"'  */
#line 355 "Zend/zend_ini_parser.y"
                                                        { yyval = yyvsp[-1]; }
#line 1581 "Zend/zend_ini_parser.c"
    break;

  case 24: /* var_string_list_section: var_string_list_section cfg_var_ref  */
#line 356 "Zend/zend_ini_parser.y"
                                                        { zend_ini_add_string(&yyval, &yyvsp[-1], &yyvsp[0]); free(Z_STRVAL(yyvsp[0])); }
#line 1587 "Zend/zend_ini_parser.c"
    break;

  case 25: /* var_string_list_section: var_string_list_section constant_literal  */
#line 357 "Zend/zend_ini_parser.y"
                                                                { zend_ini_add_string(&yyval, &yyvsp[-1], &yyvsp[0]); free(Z_STRVAL(yyvsp[0])); }
#line 1593 "Zend/zend_ini_parser.c"
    break;

  case 26: /* var_string_list_section: var_string_list_section '"' encapsed_list '"'  */
#line 358 "Zend/zend_ini_parser.y"
                                                               { zend_ini_add_string(&yyval, &yyvsp[-3], &yyvsp[-1]); free(Z_STRVAL(yyvsp[-1])); }
#line 1599 "Zend/zend_ini_parser.c"
    break;

  case 27: /* var_string_list: cfg_var_ref  */
#line 362 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; }
#line 1605 "Zend/zend_ini_parser.c"
    break;

  case 28: /* var_string_list: constant_string  */
#line 363 "Zend/zend_ini_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 1611 "Zend/zend_ini_parser.c"
    break;

  case 29: /* var_string_list: '"' encapsed_list '"'  */
#line 364 "Zend/zend_ini_parser.y"
                                                        { yyval = yyvsp[-1]; }
#line 1617 "Zend/zend_ini_parser.c"
    break;

  case 30: /* var_string_list: var_string_list cfg_var_ref  */
#line 365 "Zend/zend_ini_parser.y"
                                                { zend_ini_add_string(&yyval, &yyvsp[-1], &yyvsp[0]); free(Z_STRVAL(yyvsp[0])); }
#line 1623 "Zend/zend_ini_parser.c"
    break;

  case 31: /* var_string_list: var_string_list constant_string  */
#line 366 "Zend/zend_ini_parser.y"
                                                { zend_ini_add_string(&yyval, &yyvsp[-1], &yyvsp[0]); free(Z_STRVAL(yyvsp[0])); }
#line 1629 "Zend/zend_ini_parser.c"
    break;

  case 32: /* var_string_list: var_string_list '"' encapsed_list '"'  */
#line 367 "Zend/zend_ini_parser.y"
                                                       { zend_ini_add_string(&yyval, &yyvsp[-3], &yyvsp[-1]); free(Z_STRVAL(yyvsp[-1])); }
#line 1635 "Zend/zend_ini_parser.c"
    break;

  case 33: /* expr: var_string_list  */
#line 371 "Zend/zend_ini_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 1641 "Zend/zend_ini_parser.c"
    break;

  case 34: /* expr: expr '|' expr  */
#line 372 "Zend/zend_ini_parser.y"
                                                                { zend_ini_do_op('|', &yyval, &yyvsp[-2], &yyvsp[0]); }
#line 1647 "Zend/zend_ini_parser.c"
    break;

  case 35: /* expr: expr '&' expr  */
#line 373 "Zend/zend_ini_parser.y"
                                                                { zend_ini_do_op('&', &yyval, &yyvsp[-2], &yyvsp[0]); }
#line 1653 "Zend/zend_ini_parser.c"
    break;

  case 36: /* expr: expr '^' expr  */
#line 374 "Zend/zend_ini_parser.y"
                                                                { zend_ini_do_op('^', &yyval, &yyvsp[-2], &yyvsp[0]); }
#line 1659 "Zend/zend_ini_parser.c"
    break;

  case 37: /* expr: '~' expr  */
#line 375 "Zend/zend_ini_parser.y"
                                                                        { zend_ini_do_op('~', &yyval, &yyvsp[0], NULL); }
#line 1665 "Zend/zend_ini_parser.c"
    break;

  case 38: /* expr: '!' expr  */
#line 376 "Zend/zend_ini_parser.y"
                                                                        { zend_ini_do_op('!', &yyval, &yyvsp[0], NULL); }
#line 1671 "Zend/zend_ini_parser.c"
    break;

  case 39: /* expr: '(' expr ')'  */
#line 377 "Zend/zend_ini_parser.y"
                                                                { yyval = yyvsp[-1]; }
#line 1677 "Zend/zend_ini_parser.c"
    break;

  case 40: /* cfg_var_ref: TC_DOLLAR_CURLY TC_VARNAME '}'  */
#line 381 "Zend/zend_ini_parser.y"
                                                { zend_ini_get_var(&yyval, &yyvsp[-1] TSRMLS_CC); free(Z_STRVAL(yyvsp[-1])); }
#line 1683 "Zend/zend_ini_parser.c"
    break;

  case 41: /* constant_literal: TC_CONSTANT  */
#line 385 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; }
#line 1689 "Zend/zend_ini_parser.c"
    break;

  case 42: /* constant_literal: TC_RAW  */
#line 386 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; /*printf("TC_RAW: '%s'\n", Z_STRVAL($1));*/ }
#line 1695 "Zend/zend_ini_parser.c"
    break;

  case 43: /* constant_literal: TC_NUMBER  */
#line 387 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; /*printf("TC_NUMBER: '%s'\n", Z_STRVAL($1));*/ }
#line 1701 "Zend/zend_ini_parser.c"
    break;

  case 44: /* constant_literal: TC_STRING  */
#line 388 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; /*printf("TC_STRING: '%s'\n", Z_STRVAL($1));*/ }
#line 1707 "Zend/zend_ini_parser.c"
    break;

  case 45: /* constant_literal: TC_WHITESPACE  */
#line 389 "Zend/zend_ini_parser.y"
                                                                { yyval = yyvsp[0]; /*printf("TC_WHITESPACE: '%s'\n", Z_STRVAL($1));*/ }
#line 1713 "Zend/zend_ini_parser.c"
    break;

  case 46: /* constant_string: TC_CONSTANT  */
#line 393 "Zend/zend_ini_parser.y"
                                                                        { zend_ini_get_constant(&yyval, &yyvsp[0] TSRMLS_CC); }
#line 1719 "Zend/zend_ini_parser.c"
    break;

  case 47: /* constant_string: TC_RAW  */
#line 394 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; /*printf("TC_RAW: '%s'\n", Z_STRVAL($1));*/ }
#line 1725 "Zend/zend_ini_parser.c"
    break;

  case 48: /* constant_string: TC_NUMBER  */
#line 395 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; /*printf("TC_NUMBER: '%s'\n", Z_STRVAL($1));*/ }
#line 1731 "Zend/zend_ini_parser.c"
    break;

  case 49: /* constant_string: TC_STRING  */
#line 396 "Zend/zend_ini_parser.y"
                                                                        { yyval = yyvsp[0]; /*printf("TC_STRING: '%s'\n", Z_STRVAL($1));*/ }
#line 1737 "Zend/zend_ini_parser.c"
    break;

  case 50: /* constant_string: TC_WHITESPACE  */
#line 397 "Zend/zend_ini_parser.y"
                                                                { yyval = yyvsp[0]; /*printf("TC_WHITESPACE: '%s'\n", Z_STRVAL($1));*/ }
#line 1743 "Zend/zend_ini_parser.c"
    break;


#line 1747 "Zend/zend_ini_parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

