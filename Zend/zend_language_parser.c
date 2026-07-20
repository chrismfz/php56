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
#define yyparse         zendparse
#define yylex           zendlex
#define yyerror         zenderror
#define yydebug         zenddebug
#define yynerrs         zendnerrs

/* First part of user prologue.  */
#line 1 "Zend/zend_language_parser.y"

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
   | Authors: Andi Gutmans <andi@zend.com>                                |
   |          Zeev Suraski <zeev@zend.com>                                |
   +----------------------------------------------------------------------+
*/

/* $Id$ */

/*
 * LALR shift/reduce conflicts and how they are resolved:
 *
 * - 2 shift/reduce conflicts due to the dangling elseif/else ambiguity. Solved by shift.
 *
 */


#include "zend_compile.h"
#include "zend.h"
#include "zend_list.h"
#include "zend_globals.h"
#include "zend_API.h"
#include "zend_constants.h"

#define YYSIZE_T size_t
#define yytnamerr zend_yytnamerr
static YYSIZE_T zend_yytnamerr(char*, const char*);

#define YYERROR_VERBOSE
#define YYSTYPE znode


#line 122 "Zend/zend_language_parser.c"

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

#include "zend_language_parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_INCLUDE = 3,                  /* "include (T_INCLUDE)"  */
  YYSYMBOL_T_INCLUDE_ONCE = 4,             /* "include_once (T_INCLUDE_ONCE)"  */
  YYSYMBOL_T_EVAL = 5,                     /* "eval (T_EVAL)"  */
  YYSYMBOL_T_REQUIRE = 6,                  /* "require (T_REQUIRE)"  */
  YYSYMBOL_T_REQUIRE_ONCE = 7,             /* "require_once (T_REQUIRE_ONCE)"  */
  YYSYMBOL_8_ = 8,                         /* ','  */
  YYSYMBOL_T_LOGICAL_OR = 9,               /* "or (T_LOGICAL_OR)"  */
  YYSYMBOL_T_LOGICAL_XOR = 10,             /* "xor (T_LOGICAL_XOR)"  */
  YYSYMBOL_T_LOGICAL_AND = 11,             /* "and (T_LOGICAL_AND)"  */
  YYSYMBOL_T_PRINT = 12,                   /* "print (T_PRINT)"  */
  YYSYMBOL_T_YIELD = 13,                   /* "yield (T_YIELD)"  */
  YYSYMBOL_14_ = 14,                       /* '='  */
  YYSYMBOL_T_PLUS_EQUAL = 15,              /* "+= (T_PLUS_EQUAL)"  */
  YYSYMBOL_T_MINUS_EQUAL = 16,             /* "-= (T_MINUS_EQUAL)"  */
  YYSYMBOL_T_MUL_EQUAL = 17,               /* "*= (T_MUL_EQUAL)"  */
  YYSYMBOL_T_DIV_EQUAL = 18,               /* "/= (T_DIV_EQUAL)"  */
  YYSYMBOL_T_CONCAT_EQUAL = 19,            /* ".= (T_CONCAT_EQUAL)"  */
  YYSYMBOL_T_MOD_EQUAL = 20,               /* "%= (T_MOD_EQUAL)"  */
  YYSYMBOL_T_AND_EQUAL = 21,               /* "&= (T_AND_EQUAL)"  */
  YYSYMBOL_T_OR_EQUAL = 22,                /* "|= (T_OR_EQUAL)"  */
  YYSYMBOL_T_XOR_EQUAL = 23,               /* "^= (T_XOR_EQUAL)"  */
  YYSYMBOL_T_SL_EQUAL = 24,                /* "<<= (T_SL_EQUAL)"  */
  YYSYMBOL_T_SR_EQUAL = 25,                /* ">>= (T_SR_EQUAL)"  */
  YYSYMBOL_26_ = 26,                       /* '?'  */
  YYSYMBOL_27_ = 27,                       /* ':'  */
  YYSYMBOL_T_BOOLEAN_OR = 28,              /* "|| (T_BOOLEAN_OR)"  */
  YYSYMBOL_T_BOOLEAN_AND = 29,             /* "&& (T_BOOLEAN_AND)"  */
  YYSYMBOL_30_ = 30,                       /* '|'  */
  YYSYMBOL_31_ = 31,                       /* '^'  */
  YYSYMBOL_32_ = 32,                       /* '&'  */
  YYSYMBOL_T_IS_EQUAL = 33,                /* "== (T_IS_EQUAL)"  */
  YYSYMBOL_T_IS_NOT_EQUAL = 34,            /* "!= (T_IS_NOT_EQUAL)"  */
  YYSYMBOL_T_IS_IDENTICAL = 35,            /* "=== (T_IS_IDENTICAL)"  */
  YYSYMBOL_T_IS_NOT_IDENTICAL = 36,        /* "!== (T_IS_NOT_IDENTICAL)"  */
  YYSYMBOL_37_ = 37,                       /* '<'  */
  YYSYMBOL_38_ = 38,                       /* '>'  */
  YYSYMBOL_T_IS_SMALLER_OR_EQUAL = 39,     /* "<= (T_IS_SMALLER_OR_EQUAL)"  */
  YYSYMBOL_T_IS_GREATER_OR_EQUAL = 40,     /* ">= (T_IS_GREATER_OR_EQUAL)"  */
  YYSYMBOL_T_SL = 41,                      /* "<< (T_SL)"  */
  YYSYMBOL_T_SR = 42,                      /* ">> (T_SR)"  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '/'  */
  YYSYMBOL_48_ = 48,                       /* '%'  */
  YYSYMBOL_49_ = 49,                       /* '!'  */
  YYSYMBOL_T_INSTANCEOF = 50,              /* "instanceof (T_INSTANCEOF)"  */
  YYSYMBOL_51_ = 51,                       /* '~'  */
  YYSYMBOL_52_ = 52,                       /* '@'  */
  YYSYMBOL_T_INC = 53,                     /* "++ (T_INC)"  */
  YYSYMBOL_T_DEC = 54,                     /* "-- (T_DEC)"  */
  YYSYMBOL_T_INT_CAST = 55,                /* "(int) (T_INT_CAST)"  */
  YYSYMBOL_T_DOUBLE_CAST = 56,             /* "(double) (T_DOUBLE_CAST)"  */
  YYSYMBOL_T_STRING_CAST = 57,             /* "(string) (T_STRING_CAST)"  */
  YYSYMBOL_T_ARRAY_CAST = 58,              /* "(array) (T_ARRAY_CAST)"  */
  YYSYMBOL_T_OBJECT_CAST = 59,             /* "(object) (T_OBJECT_CAST)"  */
  YYSYMBOL_T_BOOL_CAST = 60,               /* "(bool) (T_BOOL_CAST)"  */
  YYSYMBOL_T_UNSET_CAST = 61,              /* "(unset) (T_UNSET_CAST)"  */
  YYSYMBOL_62_ = 62,                       /* '['  */
  YYSYMBOL_T_NEW = 63,                     /* "new (T_NEW)"  */
  YYSYMBOL_T_CLONE = 64,                   /* "clone (T_CLONE)"  */
  YYSYMBOL_T_EXIT = 65,                    /* "exit (T_EXIT)"  */
  YYSYMBOL_T_IF = 66,                      /* "if (T_IF)"  */
  YYSYMBOL_T_ELSEIF = 67,                  /* "elseif (T_ELSEIF)"  */
  YYSYMBOL_T_ELSE = 68,                    /* "else (T_ELSE)"  */
  YYSYMBOL_T_ENDIF = 69,                   /* "endif (T_ENDIF)"  */
  YYSYMBOL_T_LNUMBER = 70,                 /* "integer number (T_LNUMBER)"  */
  YYSYMBOL_T_DNUMBER = 71,                 /* "floating-point number (T_DNUMBER)"  */
  YYSYMBOL_T_STRING = 72,                  /* "identifier (T_STRING)"  */
  YYSYMBOL_T_STRING_VARNAME = 73,          /* "variable name (T_STRING_VARNAME)"  */
  YYSYMBOL_T_VARIABLE = 74,                /* "variable (T_VARIABLE)"  */
  YYSYMBOL_T_NUM_STRING = 75,              /* "number (T_NUM_STRING)"  */
  YYSYMBOL_T_INLINE_HTML = 76,             /* T_INLINE_HTML  */
  YYSYMBOL_T_CHARACTER = 77,               /* T_CHARACTER  */
  YYSYMBOL_T_BAD_CHARACTER = 78,           /* T_BAD_CHARACTER  */
  YYSYMBOL_T_ENCAPSED_AND_WHITESPACE = 79, /* "quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)"  */
  YYSYMBOL_T_CONSTANT_ENCAPSED_STRING = 80, /* "quoted-string (T_CONSTANT_ENCAPSED_STRING)"  */
  YYSYMBOL_T_ECHO = 81,                    /* "echo (T_ECHO)"  */
  YYSYMBOL_T_DO = 82,                      /* "do (T_DO)"  */
  YYSYMBOL_T_WHILE = 83,                   /* "while (T_WHILE)"  */
  YYSYMBOL_T_ENDWHILE = 84,                /* "endwhile (T_ENDWHILE)"  */
  YYSYMBOL_T_FOR = 85,                     /* "for (T_FOR)"  */
  YYSYMBOL_T_ENDFOR = 86,                  /* "endfor (T_ENDFOR)"  */
  YYSYMBOL_T_FOREACH = 87,                 /* "foreach (T_FOREACH)"  */
  YYSYMBOL_T_ENDFOREACH = 88,              /* "endforeach (T_ENDFOREACH)"  */
  YYSYMBOL_T_DECLARE = 89,                 /* "declare (T_DECLARE)"  */
  YYSYMBOL_T_ENDDECLARE = 90,              /* "enddeclare (T_ENDDECLARE)"  */
  YYSYMBOL_T_AS = 91,                      /* "as (T_AS)"  */
  YYSYMBOL_T_SWITCH = 92,                  /* "switch (T_SWITCH)"  */
  YYSYMBOL_T_ENDSWITCH = 93,               /* "endswitch (T_ENDSWITCH)"  */
  YYSYMBOL_T_CASE = 94,                    /* "case (T_CASE)"  */
  YYSYMBOL_T_DEFAULT = 95,                 /* "default (T_DEFAULT)"  */
  YYSYMBOL_T_BREAK = 96,                   /* "break (T_BREAK)"  */
  YYSYMBOL_T_CONTINUE = 97,                /* "continue (T_CONTINUE)"  */
  YYSYMBOL_T_GOTO = 98,                    /* "goto (T_GOTO)"  */
  YYSYMBOL_T_FUNCTION = 99,                /* "function (T_FUNCTION)"  */
  YYSYMBOL_T_CONST = 100,                  /* "const (T_CONST)"  */
  YYSYMBOL_T_RETURN = 101,                 /* "return (T_RETURN)"  */
  YYSYMBOL_T_TRY = 102,                    /* "try (T_TRY)"  */
  YYSYMBOL_T_CATCH = 103,                  /* "catch (T_CATCH)"  */
  YYSYMBOL_T_FINALLY = 104,                /* "finally (T_FINALLY)"  */
  YYSYMBOL_T_THROW = 105,                  /* "throw (T_THROW)"  */
  YYSYMBOL_T_USE = 106,                    /* "use (T_USE)"  */
  YYSYMBOL_T_INSTEADOF = 107,              /* "insteadof (T_INSTEADOF)"  */
  YYSYMBOL_T_GLOBAL = 108,                 /* "global (T_GLOBAL)"  */
  YYSYMBOL_T_STATIC = 109,                 /* "static (T_STATIC)"  */
  YYSYMBOL_T_ABSTRACT = 110,               /* "abstract (T_ABSTRACT)"  */
  YYSYMBOL_T_FINAL = 111,                  /* "final (T_FINAL)"  */
  YYSYMBOL_T_PRIVATE = 112,                /* "private (T_PRIVATE)"  */
  YYSYMBOL_T_PROTECTED = 113,              /* "protected (T_PROTECTED)"  */
  YYSYMBOL_T_PUBLIC = 114,                 /* "public (T_PUBLIC)"  */
  YYSYMBOL_T_VAR = 115,                    /* "var (T_VAR)"  */
  YYSYMBOL_T_UNSET = 116,                  /* "unset (T_UNSET)"  */
  YYSYMBOL_T_ISSET = 117,                  /* "isset (T_ISSET)"  */
  YYSYMBOL_T_EMPTY = 118,                  /* "empty (T_EMPTY)"  */
  YYSYMBOL_T_HALT_COMPILER = 119,          /* "__halt_compiler (T_HALT_COMPILER)"  */
  YYSYMBOL_T_CLASS = 120,                  /* "class (T_CLASS)"  */
  YYSYMBOL_T_TRAIT = 121,                  /* "trait (T_TRAIT)"  */
  YYSYMBOL_T_INTERFACE = 122,              /* "interface (T_INTERFACE)"  */
  YYSYMBOL_T_EXTENDS = 123,                /* "extends (T_EXTENDS)"  */
  YYSYMBOL_T_IMPLEMENTS = 124,             /* "implements (T_IMPLEMENTS)"  */
  YYSYMBOL_T_OBJECT_OPERATOR = 125,        /* "-> (T_OBJECT_OPERATOR)"  */
  YYSYMBOL_T_DOUBLE_ARROW = 126,           /* "=> (T_DOUBLE_ARROW)"  */
  YYSYMBOL_T_LIST = 127,                   /* "list (T_LIST)"  */
  YYSYMBOL_T_ARRAY = 128,                  /* "array (T_ARRAY)"  */
  YYSYMBOL_T_CALLABLE = 129,               /* "callable (T_CALLABLE)"  */
  YYSYMBOL_T_CLASS_C = 130,                /* "__CLASS__ (T_CLASS_C)"  */
  YYSYMBOL_T_TRAIT_C = 131,                /* "__TRAIT__ (T_TRAIT_C)"  */
  YYSYMBOL_T_METHOD_C = 132,               /* "__METHOD__ (T_METHOD_C)"  */
  YYSYMBOL_T_FUNC_C = 133,                 /* "__FUNCTION__ (T_FUNC_C)"  */
  YYSYMBOL_T_LINE = 134,                   /* "__LINE__ (T_LINE)"  */
  YYSYMBOL_T_FILE = 135,                   /* "__FILE__ (T_FILE)"  */
  YYSYMBOL_T_COMMENT = 136,                /* "comment (T_COMMENT)"  */
  YYSYMBOL_T_DOC_COMMENT = 137,            /* "doc comment (T_DOC_COMMENT)"  */
  YYSYMBOL_T_OPEN_TAG = 138,               /* "open tag (T_OPEN_TAG)"  */
  YYSYMBOL_T_OPEN_TAG_WITH_ECHO = 139,     /* "open tag with echo (T_OPEN_TAG_WITH_ECHO)"  */
  YYSYMBOL_T_CLOSE_TAG = 140,              /* "close tag (T_CLOSE_TAG)"  */
  YYSYMBOL_T_WHITESPACE = 141,             /* "whitespace (T_WHITESPACE)"  */
  YYSYMBOL_T_START_HEREDOC = 142,          /* "heredoc start (T_START_HEREDOC)"  */
  YYSYMBOL_T_END_HEREDOC = 143,            /* "heredoc end (T_END_HEREDOC)"  */
  YYSYMBOL_T_DOLLAR_OPEN_CURLY_BRACES = 144, /* "${ (T_DOLLAR_OPEN_CURLY_BRACES)"  */
  YYSYMBOL_T_CURLY_OPEN = 145,             /* "{$ (T_CURLY_OPEN)"  */
  YYSYMBOL_T_PAAMAYIM_NEKUDOTAYIM = 146,   /* ":: (T_PAAMAYIM_NEKUDOTAYIM)"  */
  YYSYMBOL_T_NAMESPACE = 147,              /* "namespace (T_NAMESPACE)"  */
  YYSYMBOL_T_NS_C = 148,                   /* "__NAMESPACE__ (T_NS_C)"  */
  YYSYMBOL_T_DIR = 149,                    /* "__DIR__ (T_DIR)"  */
  YYSYMBOL_T_NS_SEPARATOR = 150,           /* "\\ (T_NS_SEPARATOR)"  */
  YYSYMBOL_T_ELLIPSIS = 151,               /* "... (T_ELLIPSIS)"  */
  YYSYMBOL_T_POW = 152,                    /* "** (T_POW)"  */
  YYSYMBOL_T_POW_EQUAL = 153,              /* "**= (T_POW_EQUAL)"  */
  YYSYMBOL_154_ = 154,                     /* '('  */
  YYSYMBOL_155_ = 155,                     /* ')'  */
  YYSYMBOL_156_ = 156,                     /* ';'  */
  YYSYMBOL_157_ = 157,                     /* '{'  */
  YYSYMBOL_158_ = 158,                     /* '}'  */
  YYSYMBOL_159_ = 159,                     /* '$'  */
  YYSYMBOL_160_ = 160,                     /* ']'  */
  YYSYMBOL_161_ = 161,                     /* '`'  */
  YYSYMBOL_162_ = 162,                     /* '"'  */
  YYSYMBOL_YYACCEPT = 163,                 /* $accept  */
  YYSYMBOL_start = 164,                    /* start  */
  YYSYMBOL_top_statement_list = 165,       /* top_statement_list  */
  YYSYMBOL_166_1 = 166,                    /* $@1  */
  YYSYMBOL_namespace_name = 167,           /* namespace_name  */
  YYSYMBOL_top_statement = 168,            /* top_statement  */
  YYSYMBOL_169_2 = 169,                    /* $@2  */
  YYSYMBOL_170_3 = 170,                    /* $@3  */
  YYSYMBOL_use_declarations = 171,         /* use_declarations  */
  YYSYMBOL_use_declaration = 172,          /* use_declaration  */
  YYSYMBOL_use_function_declarations = 173, /* use_function_declarations  */
  YYSYMBOL_use_function_declaration = 174, /* use_function_declaration  */
  YYSYMBOL_use_const_declarations = 175,   /* use_const_declarations  */
  YYSYMBOL_use_const_declaration = 176,    /* use_const_declaration  */
  YYSYMBOL_constant_declaration = 177,     /* constant_declaration  */
  YYSYMBOL_inner_statement_list = 178,     /* inner_statement_list  */
  YYSYMBOL_179_4 = 179,                    /* $@4  */
  YYSYMBOL_inner_statement = 180,          /* inner_statement  */
  YYSYMBOL_statement = 181,                /* statement  */
  YYSYMBOL_unticked_statement = 182,       /* unticked_statement  */
  YYSYMBOL_183_5 = 183,                    /* $@5  */
  YYSYMBOL_184_6 = 184,                    /* $@6  */
  YYSYMBOL_185_7 = 185,                    /* $@7  */
  YYSYMBOL_186_8 = 186,                    /* $@8  */
  YYSYMBOL_187_9 = 187,                    /* $@9  */
  YYSYMBOL_188_10 = 188,                   /* @10  */
  YYSYMBOL_189_11 = 189,                   /* $@11  */
  YYSYMBOL_190_12 = 190,                   /* $@12  */
  YYSYMBOL_191_13 = 191,                   /* $@13  */
  YYSYMBOL_192_14 = 192,                   /* $@14  */
  YYSYMBOL_193_15 = 193,                   /* $@15  */
  YYSYMBOL_194_16 = 194,                   /* $@16  */
  YYSYMBOL_195_17 = 195,                   /* $@17  */
  YYSYMBOL_196_18 = 196,                   /* $@18  */
  YYSYMBOL_197_19 = 197,                   /* $@19  */
  YYSYMBOL_198_20 = 198,                   /* $@20  */
  YYSYMBOL_199_21 = 199,                   /* $@21  */
  YYSYMBOL_200_22 = 200,                   /* $@22  */
  YYSYMBOL_201_23 = 201,                   /* $@23  */
  YYSYMBOL_catch_statement = 202,          /* catch_statement  */
  YYSYMBOL_203_24 = 203,                   /* $@24  */
  YYSYMBOL_204_25 = 204,                   /* $@25  */
  YYSYMBOL_205_26 = 205,                   /* $@26  */
  YYSYMBOL_206_27 = 206,                   /* $@27  */
  YYSYMBOL_finally_statement = 207,        /* finally_statement  */
  YYSYMBOL_208_28 = 208,                   /* $@28  */
  YYSYMBOL_additional_catches = 209,       /* additional_catches  */
  YYSYMBOL_non_empty_additional_catches = 210, /* non_empty_additional_catches  */
  YYSYMBOL_additional_catch = 211,         /* additional_catch  */
  YYSYMBOL_212_29 = 212,                   /* @29  */
  YYSYMBOL_213_30 = 213,                   /* $@30  */
  YYSYMBOL_unset_variables = 214,          /* unset_variables  */
  YYSYMBOL_unset_variable = 215,           /* unset_variable  */
  YYSYMBOL_function_declaration_statement = 216, /* function_declaration_statement  */
  YYSYMBOL_class_declaration_statement = 217, /* class_declaration_statement  */
  YYSYMBOL_is_reference = 218,             /* is_reference  */
  YYSYMBOL_is_variadic = 219,              /* is_variadic  */
  YYSYMBOL_unticked_function_declaration_statement = 220, /* unticked_function_declaration_statement  */
  YYSYMBOL_221_31 = 221,                   /* $@31  */
  YYSYMBOL_unticked_class_declaration_statement = 222, /* unticked_class_declaration_statement  */
  YYSYMBOL_223_32 = 223,                   /* $@32  */
  YYSYMBOL_224_33 = 224,                   /* $@33  */
  YYSYMBOL_class_entry_type = 225,         /* class_entry_type  */
  YYSYMBOL_extends_from = 226,             /* extends_from  */
  YYSYMBOL_interface_entry = 227,          /* interface_entry  */
  YYSYMBOL_interface_extends_list = 228,   /* interface_extends_list  */
  YYSYMBOL_implements_list = 229,          /* implements_list  */
  YYSYMBOL_interface_list = 230,           /* interface_list  */
  YYSYMBOL_foreach_optional_arg = 231,     /* foreach_optional_arg  */
  YYSYMBOL_foreach_variable = 232,         /* foreach_variable  */
  YYSYMBOL_233_34 = 233,                   /* $@34  */
  YYSYMBOL_for_statement = 234,            /* for_statement  */
  YYSYMBOL_foreach_statement = 235,        /* foreach_statement  */
  YYSYMBOL_declare_statement = 236,        /* declare_statement  */
  YYSYMBOL_declare_list = 237,             /* declare_list  */
  YYSYMBOL_switch_case_list = 238,         /* switch_case_list  */
  YYSYMBOL_case_list = 239,                /* case_list  */
  YYSYMBOL_240_35 = 240,                   /* $@35  */
  YYSYMBOL_241_36 = 241,                   /* $@36  */
  YYSYMBOL_case_separator = 242,           /* case_separator  */
  YYSYMBOL_while_statement = 243,          /* while_statement  */
  YYSYMBOL_elseif_list = 244,              /* elseif_list  */
  YYSYMBOL_245_37 = 245,                   /* $@37  */
  YYSYMBOL_new_elseif_list = 246,          /* new_elseif_list  */
  YYSYMBOL_247_38 = 247,                   /* $@38  */
  YYSYMBOL_else_single = 248,              /* else_single  */
  YYSYMBOL_new_else_single = 249,          /* new_else_single  */
  YYSYMBOL_parameter_list = 250,           /* parameter_list  */
  YYSYMBOL_non_empty_parameter_list = 251, /* non_empty_parameter_list  */
  YYSYMBOL_parameter = 252,                /* parameter  */
  YYSYMBOL_optional_class_type = 253,      /* optional_class_type  */
  YYSYMBOL_function_call_parameter_list = 254, /* function_call_parameter_list  */
  YYSYMBOL_non_empty_function_call_parameter_list = 255, /* non_empty_function_call_parameter_list  */
  YYSYMBOL_function_call_parameter = 256,  /* function_call_parameter  */
  YYSYMBOL_global_var_list = 257,          /* global_var_list  */
  YYSYMBOL_global_var = 258,               /* global_var  */
  YYSYMBOL_static_var_list = 259,          /* static_var_list  */
  YYSYMBOL_class_statement_list = 260,     /* class_statement_list  */
  YYSYMBOL_class_statement = 261,          /* class_statement  */
  YYSYMBOL_262_39 = 262,                   /* $@39  */
  YYSYMBOL_263_40 = 263,                   /* $@40  */
  YYSYMBOL_trait_use_statement = 264,      /* trait_use_statement  */
  YYSYMBOL_trait_list = 265,               /* trait_list  */
  YYSYMBOL_trait_adaptations = 266,        /* trait_adaptations  */
  YYSYMBOL_trait_adaptation_list = 267,    /* trait_adaptation_list  */
  YYSYMBOL_non_empty_trait_adaptation_list = 268, /* non_empty_trait_adaptation_list  */
  YYSYMBOL_trait_adaptation_statement = 269, /* trait_adaptation_statement  */
  YYSYMBOL_trait_precedence = 270,         /* trait_precedence  */
  YYSYMBOL_trait_reference_list = 271,     /* trait_reference_list  */
  YYSYMBOL_trait_method_reference = 272,   /* trait_method_reference  */
  YYSYMBOL_trait_method_reference_fully_qualified = 273, /* trait_method_reference_fully_qualified  */
  YYSYMBOL_trait_alias = 274,              /* trait_alias  */
  YYSYMBOL_trait_modifiers = 275,          /* trait_modifiers  */
  YYSYMBOL_method_body = 276,              /* method_body  */
  YYSYMBOL_variable_modifiers = 277,       /* variable_modifiers  */
  YYSYMBOL_method_modifiers = 278,         /* method_modifiers  */
  YYSYMBOL_non_empty_member_modifiers = 279, /* non_empty_member_modifiers  */
  YYSYMBOL_member_modifier = 280,          /* member_modifier  */
  YYSYMBOL_class_variable_declaration = 281, /* class_variable_declaration  */
  YYSYMBOL_class_constant_declaration = 282, /* class_constant_declaration  */
  YYSYMBOL_echo_expr_list = 283,           /* echo_expr_list  */
  YYSYMBOL_for_expr = 284,                 /* for_expr  */
  YYSYMBOL_non_empty_for_expr = 285,       /* non_empty_for_expr  */
  YYSYMBOL_286_41 = 286,                   /* $@41  */
  YYSYMBOL_chaining_method_or_property = 287, /* chaining_method_or_property  */
  YYSYMBOL_chaining_dereference = 288,     /* chaining_dereference  */
  YYSYMBOL_chaining_instance_call = 289,   /* chaining_instance_call  */
  YYSYMBOL_290_42 = 290,                   /* $@42  */
  YYSYMBOL_instance_call = 291,            /* instance_call  */
  YYSYMBOL_292_43 = 292,                   /* $@43  */
  YYSYMBOL_new_expr = 293,                 /* new_expr  */
  YYSYMBOL_294_44 = 294,                   /* $@44  */
  YYSYMBOL_expr_without_variable = 295,    /* expr_without_variable  */
  YYSYMBOL_296_45 = 296,                   /* $@45  */
  YYSYMBOL_297_46 = 297,                   /* $@46  */
  YYSYMBOL_298_47 = 298,                   /* $@47  */
  YYSYMBOL_299_48 = 299,                   /* $@48  */
  YYSYMBOL_300_49 = 300,                   /* $@49  */
  YYSYMBOL_301_50 = 301,                   /* $@50  */
  YYSYMBOL_302_51 = 302,                   /* @51  */
  YYSYMBOL_303_52 = 303,                   /* $@52  */
  YYSYMBOL_304_53 = 304,                   /* $@53  */
  YYSYMBOL_305_54 = 305,                   /* $@54  */
  YYSYMBOL_306_55 = 306,                   /* $@55  */
  YYSYMBOL_307_56 = 307,                   /* @56  */
  YYSYMBOL_308_57 = 308,                   /* @57  */
  YYSYMBOL_yield_expr = 309,               /* yield_expr  */
  YYSYMBOL_combined_scalar_offset = 310,   /* combined_scalar_offset  */
  YYSYMBOL_combined_scalar = 311,          /* combined_scalar  */
  YYSYMBOL_function = 312,                 /* function  */
  YYSYMBOL_lexical_vars = 313,             /* lexical_vars  */
  YYSYMBOL_lexical_var_list = 314,         /* lexical_var_list  */
  YYSYMBOL_function_call = 315,            /* function_call  */
  YYSYMBOL_316_58 = 316,                   /* @58  */
  YYSYMBOL_317_59 = 317,                   /* @59  */
  YYSYMBOL_318_60 = 318,                   /* @60  */
  YYSYMBOL_319_61 = 319,                   /* @61  */
  YYSYMBOL_320_62 = 320,                   /* $@62  */
  YYSYMBOL_321_63 = 321,                   /* $@63  */
  YYSYMBOL_322_64 = 322,                   /* $@64  */
  YYSYMBOL_323_65 = 323,                   /* $@65  */
  YYSYMBOL_class_name = 324,               /* class_name  */
  YYSYMBOL_fully_qualified_class_name = 325, /* fully_qualified_class_name  */
  YYSYMBOL_class_name_reference = 326,     /* class_name_reference  */
  YYSYMBOL_dynamic_class_name_reference = 327, /* dynamic_class_name_reference  */
  YYSYMBOL_328_66 = 328,                   /* $@66  */
  YYSYMBOL_329_67 = 329,                   /* $@67  */
  YYSYMBOL_dynamic_class_name_variable_properties = 330, /* dynamic_class_name_variable_properties  */
  YYSYMBOL_dynamic_class_name_variable_property = 331, /* dynamic_class_name_variable_property  */
  YYSYMBOL_exit_expr = 332,                /* exit_expr  */
  YYSYMBOL_backticks_expr = 333,           /* backticks_expr  */
  YYSYMBOL_ctor_arguments = 334,           /* ctor_arguments  */
  YYSYMBOL_common_scalar = 335,            /* common_scalar  */
  YYSYMBOL_static_class_constant = 336,    /* static_class_constant  */
  YYSYMBOL_static_scalar = 337,            /* static_scalar  */
  YYSYMBOL_static_scalar_value = 338,      /* static_scalar_value  */
  YYSYMBOL_static_operation = 339,         /* static_operation  */
  YYSYMBOL_general_constant = 340,         /* general_constant  */
  YYSYMBOL_scalar = 341,                   /* scalar  */
  YYSYMBOL_static_array_pair_list = 342,   /* static_array_pair_list  */
  YYSYMBOL_possible_comma = 343,           /* possible_comma  */
  YYSYMBOL_non_empty_static_array_pair_list = 344, /* non_empty_static_array_pair_list  */
  YYSYMBOL_expr = 345,                     /* expr  */
  YYSYMBOL_parenthesis_expr = 346,         /* parenthesis_expr  */
  YYSYMBOL_r_variable = 347,               /* r_variable  */
  YYSYMBOL_w_variable = 348,               /* w_variable  */
  YYSYMBOL_rw_variable = 349,              /* rw_variable  */
  YYSYMBOL_variable = 350,                 /* variable  */
  YYSYMBOL_351_68 = 351,                   /* $@68  */
  YYSYMBOL_352_69 = 352,                   /* $@69  */
  YYSYMBOL_variable_properties = 353,      /* variable_properties  */
  YYSYMBOL_variable_property = 354,        /* variable_property  */
  YYSYMBOL_355_70 = 355,                   /* $@70  */
  YYSYMBOL_array_method_dereference = 356, /* array_method_dereference  */
  YYSYMBOL_method = 357,                   /* method  */
  YYSYMBOL_358_71 = 358,                   /* @71  */
  YYSYMBOL_method_or_not = 359,            /* method_or_not  */
  YYSYMBOL_variable_without_objects = 360, /* variable_without_objects  */
  YYSYMBOL_static_member = 361,            /* static_member  */
  YYSYMBOL_variable_class_name = 362,      /* variable_class_name  */
  YYSYMBOL_array_function_dereference = 363, /* array_function_dereference  */
  YYSYMBOL_364_72 = 364,                   /* $@72  */
  YYSYMBOL_base_variable_with_function_calls = 365, /* base_variable_with_function_calls  */
  YYSYMBOL_base_variable = 366,            /* base_variable  */
  YYSYMBOL_reference_variable = 367,       /* reference_variable  */
  YYSYMBOL_compound_variable = 368,        /* compound_variable  */
  YYSYMBOL_dim_offset = 369,               /* dim_offset  */
  YYSYMBOL_object_property = 370,          /* object_property  */
  YYSYMBOL_371_73 = 371,                   /* $@73  */
  YYSYMBOL_object_dim_list = 372,          /* object_dim_list  */
  YYSYMBOL_variable_name = 373,            /* variable_name  */
  YYSYMBOL_simple_indirect_reference = 374, /* simple_indirect_reference  */
  YYSYMBOL_assignment_list = 375,          /* assignment_list  */
  YYSYMBOL_assignment_list_element = 376,  /* assignment_list_element  */
  YYSYMBOL_377_74 = 377,                   /* $@74  */
  YYSYMBOL_array_pair_list = 378,          /* array_pair_list  */
  YYSYMBOL_non_empty_array_pair_list = 379, /* non_empty_array_pair_list  */
  YYSYMBOL_encaps_list = 380,              /* encaps_list  */
  YYSYMBOL_encaps_var = 381,               /* encaps_var  */
  YYSYMBOL_382_75 = 382,                   /* $@75  */
  YYSYMBOL_encaps_var_offset = 383,        /* encaps_var_offset  */
  YYSYMBOL_internal_functions_in_yacc = 384, /* internal_functions_in_yacc  */
  YYSYMBOL_isset_variables = 385,          /* isset_variables  */
  YYSYMBOL_386_76 = 386,                   /* $@76  */
  YYSYMBOL_isset_variable = 387,           /* isset_variable  */
  YYSYMBOL_class_constant = 388,           /* class_constant  */
  YYSYMBOL_static_class_name_scalar = 389, /* static_class_name_scalar  */
  YYSYMBOL_class_name_scalar = 390         /* class_name_scalar  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   6353

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  163
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  228
/* YYNRULES -- Number of rules.  */
#define YYNRULES  594
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1097

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   389


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,   162,     2,   159,    48,    32,     2,
     154,   155,    46,    43,     8,    44,    45,    47,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    27,   156,
      37,    14,    38,    26,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,   160,    31,     2,   161,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   157,    30,   158,    51,     2,     2,     2,
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
       5,     6,     7,     9,    10,    11,    12,    13,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    28,
      29,    33,    34,    35,    36,    39,    40,    41,    42,    50,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   223,   223,   227,   227,   228,   232,   233,   237,   238,
     239,   240,   241,   242,   242,   244,   244,   246,   247,   248,
     249,   253,   254,   258,   259,   260,   261,   265,   266,   270,
     271,   272,   273,   277,   278,   282,   283,   284,   285,   289,
     290,   294,   294,   295,   300,   301,   302,   303,   308,   309,
     313,   314,   314,   314,   315,   315,   315,   316,   316,   316,
     317,   317,   317,   321,   323,   325,   318,   327,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   343,   344,   342,   347,   348,   346,   350,
     350,   351,   352,   353,   352,   355,   356,   360,   361,   362,
     363,   364,   361,   368,   369,   369,   373,   374,   378,   379,
     383,   383,   383,   387,   388,   392,   396,   400,   404,   405,
     409,   410,   414,   414,   421,   420,   427,   426,   436,   437,
     438,   439,   443,   444,   448,   451,   453,   456,   458,   462,
     463,   467,   468,   472,   473,   474,   474,   478,   479,   484,
     485,   490,   491,   496,   497,   502,   503,   504,   505,   510,
     511,   511,   512,   512,   517,   518,   523,   524,   529,   531,
     531,   535,   537,   537,   541,   543,   547,   549,   554,   555,
     560,   561,   565,   567,   573,   574,   575,   576,   581,   582,
     583,   588,   589,   593,   594,   595,   596,   600,   601,   606,
     607,   608,   613,   614,   615,   616,   622,   623,   628,   628,
     629,   630,   631,   631,   637,   641,   642,   646,   647,   650,
     652,   656,   657,   661,   662,   666,   670,   671,   675,   676,
     680,   684,   685,   689,   690,   694,   695,   699,   700,   704,
     705,   709,   710,   714,   715,   716,   717,   718,   719,   723,
     724,   725,   726,   730,   731,   735,   736,   741,   742,   746,
     746,   747,   751,   752,   756,   757,   761,   761,   762,   763,
     767,   768,   768,   773,   773,   777,   777,   778,   779,   780,
     780,   781,   782,   783,   784,   785,   786,   787,   788,   789,
     790,   791,   792,   793,   794,   795,   796,   797,   798,   798,
     799,   799,   800,   800,   801,   801,   802,   803,   804,   805,
     806,   807,   808,   809,   810,   811,   812,   813,   814,   815,
     816,   817,   818,   819,   820,   821,   822,   823,   824,   825,
     826,   827,   828,   829,   830,   830,   831,   832,   831,   834,
     834,   836,   837,   838,   839,   840,   841,   842,   843,   844,
     845,   845,   846,   847,   848,   849,   850,   851,   852,   852,
     855,   855,   861,   862,   863,   864,   868,   869,   870,   871,
     875,   876,   880,   883,   885,   889,   890,   891,   892,   896,
     896,   898,   898,   900,   900,   902,   902,   904,   904,   906,
     906,   908,   908,   910,   910,   915,   916,   917,   918,   922,
     923,   924,   930,   931,   936,   937,   936,   939,   944,   945,
     950,   954,   955,   956,   960,   961,   962,   967,   968,   973,
     974,   975,   976,   977,   978,   979,   980,   981,   982,   983,
     984,   988,   992,   996,   997,   998,   999,  1000,  1001,  1002,
    1003,  1004,  1005,  1009,  1010,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1045,  1046,  1047,  1048,
    1052,  1053,  1054,  1055,  1056,  1057,  1058,  1062,  1063,  1066,
    1068,  1072,  1073,  1074,  1075,  1079,  1080,  1084,  1085,  1090,
    1095,  1100,  1105,  1106,  1105,  1108,  1112,  1113,  1118,  1118,
    1122,  1123,  1127,  1127,  1132,  1133,  1134,  1138,  1139,  1143,
    1144,  1149,  1153,  1154,  1154,  1159,  1160,  1161,  1166,  1167,
    1168,  1172,  1173,  1174,  1179,  1180,  1184,  1185,  1190,  1191,
    1191,  1195,  1196,  1197,  1201,  1202,  1206,  1207,  1211,  1212,
    1217,  1218,  1218,  1219,  1224,  1225,  1229,  1230,  1231,  1232,
    1233,  1234,  1235,  1236,  1240,  1241,  1242,  1243,  1249,  1250,
    1250,  1251,  1252,  1253,  1254,  1259,  1260,  1261,  1266,  1267,
    1268,  1269,  1270,  1271,  1272,  1273,  1277,  1278,  1278,  1282,
    1283,  1287,  1288,  1292,  1296
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
  "\"end of file\"", "error", "\"invalid token\"",
  "\"include (T_INCLUDE)\"", "\"include_once (T_INCLUDE_ONCE)\"",
  "\"eval (T_EVAL)\"", "\"require (T_REQUIRE)\"",
  "\"require_once (T_REQUIRE_ONCE)\"", "','", "\"or (T_LOGICAL_OR)\"",
  "\"xor (T_LOGICAL_XOR)\"", "\"and (T_LOGICAL_AND)\"",
  "\"print (T_PRINT)\"", "\"yield (T_YIELD)\"", "'='",
  "\"+= (T_PLUS_EQUAL)\"", "\"-= (T_MINUS_EQUAL)\"",
  "\"*= (T_MUL_EQUAL)\"", "\"/= (T_DIV_EQUAL)\"",
  "\".= (T_CONCAT_EQUAL)\"", "\"%= (T_MOD_EQUAL)\"",
  "\"&= (T_AND_EQUAL)\"", "\"|= (T_OR_EQUAL)\"", "\"^= (T_XOR_EQUAL)\"",
  "\"<<= (T_SL_EQUAL)\"", "\">>= (T_SR_EQUAL)\"", "'?'", "':'",
  "\"|| (T_BOOLEAN_OR)\"", "\"&& (T_BOOLEAN_AND)\"", "'|'", "'^'", "'&'",
  "\"== (T_IS_EQUAL)\"", "\"!= (T_IS_NOT_EQUAL)\"",
  "\"=== (T_IS_IDENTICAL)\"", "\"!== (T_IS_NOT_IDENTICAL)\"", "'<'", "'>'",
  "\"<= (T_IS_SMALLER_OR_EQUAL)\"", "\">= (T_IS_GREATER_OR_EQUAL)\"",
  "\"<< (T_SL)\"", "\">> (T_SR)\"", "'+'", "'-'", "'.'", "'*'", "'/'",
  "'%'", "'!'", "\"instanceof (T_INSTANCEOF)\"", "'~'", "'@'",
  "\"++ (T_INC)\"", "\"-- (T_DEC)\"", "\"(int) (T_INT_CAST)\"",
  "\"(double) (T_DOUBLE_CAST)\"", "\"(string) (T_STRING_CAST)\"",
  "\"(array) (T_ARRAY_CAST)\"", "\"(object) (T_OBJECT_CAST)\"",
  "\"(bool) (T_BOOL_CAST)\"", "\"(unset) (T_UNSET_CAST)\"", "'['",
  "\"new (T_NEW)\"", "\"clone (T_CLONE)\"", "\"exit (T_EXIT)\"",
  "\"if (T_IF)\"", "\"elseif (T_ELSEIF)\"", "\"else (T_ELSE)\"",
  "\"endif (T_ENDIF)\"", "\"integer number (T_LNUMBER)\"",
  "\"floating-point number (T_DNUMBER)\"", "\"identifier (T_STRING)\"",
  "\"variable name (T_STRING_VARNAME)\"", "\"variable (T_VARIABLE)\"",
  "\"number (T_NUM_STRING)\"", "T_INLINE_HTML", "T_CHARACTER",
  "T_BAD_CHARACTER",
  "\"quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)\"",
  "\"quoted-string (T_CONSTANT_ENCAPSED_STRING)\"", "\"echo (T_ECHO)\"",
  "\"do (T_DO)\"", "\"while (T_WHILE)\"", "\"endwhile (T_ENDWHILE)\"",
  "\"for (T_FOR)\"", "\"endfor (T_ENDFOR)\"", "\"foreach (T_FOREACH)\"",
  "\"endforeach (T_ENDFOREACH)\"", "\"declare (T_DECLARE)\"",
  "\"enddeclare (T_ENDDECLARE)\"", "\"as (T_AS)\"",
  "\"switch (T_SWITCH)\"", "\"endswitch (T_ENDSWITCH)\"",
  "\"case (T_CASE)\"", "\"default (T_DEFAULT)\"", "\"break (T_BREAK)\"",
  "\"continue (T_CONTINUE)\"", "\"goto (T_GOTO)\"",
  "\"function (T_FUNCTION)\"", "\"const (T_CONST)\"",
  "\"return (T_RETURN)\"", "\"try (T_TRY)\"", "\"catch (T_CATCH)\"",
  "\"finally (T_FINALLY)\"", "\"throw (T_THROW)\"", "\"use (T_USE)\"",
  "\"insteadof (T_INSTEADOF)\"", "\"global (T_GLOBAL)\"",
  "\"static (T_STATIC)\"", "\"abstract (T_ABSTRACT)\"",
  "\"final (T_FINAL)\"", "\"private (T_PRIVATE)\"",
  "\"protected (T_PROTECTED)\"", "\"public (T_PUBLIC)\"",
  "\"var (T_VAR)\"", "\"unset (T_UNSET)\"", "\"isset (T_ISSET)\"",
  "\"empty (T_EMPTY)\"", "\"__halt_compiler (T_HALT_COMPILER)\"",
  "\"class (T_CLASS)\"", "\"trait (T_TRAIT)\"",
  "\"interface (T_INTERFACE)\"", "\"extends (T_EXTENDS)\"",
  "\"implements (T_IMPLEMENTS)\"", "\"-> (T_OBJECT_OPERATOR)\"",
  "\"=> (T_DOUBLE_ARROW)\"", "\"list (T_LIST)\"", "\"array (T_ARRAY)\"",
  "\"callable (T_CALLABLE)\"", "\"__CLASS__ (T_CLASS_C)\"",
  "\"__TRAIT__ (T_TRAIT_C)\"", "\"__METHOD__ (T_METHOD_C)\"",
  "\"__FUNCTION__ (T_FUNC_C)\"", "\"__LINE__ (T_LINE)\"",
  "\"__FILE__ (T_FILE)\"", "\"comment (T_COMMENT)\"",
  "\"doc comment (T_DOC_COMMENT)\"", "\"open tag (T_OPEN_TAG)\"",
  "\"open tag with echo (T_OPEN_TAG_WITH_ECHO)\"",
  "\"close tag (T_CLOSE_TAG)\"", "\"whitespace (T_WHITESPACE)\"",
  "\"heredoc start (T_START_HEREDOC)\"", "\"heredoc end (T_END_HEREDOC)\"",
  "\"${ (T_DOLLAR_OPEN_CURLY_BRACES)\"", "\"{$ (T_CURLY_OPEN)\"",
  "\":: (T_PAAMAYIM_NEKUDOTAYIM)\"", "\"namespace (T_NAMESPACE)\"",
  "\"__NAMESPACE__ (T_NS_C)\"", "\"__DIR__ (T_DIR)\"",
  "\"\\\\ (T_NS_SEPARATOR)\"", "\"... (T_ELLIPSIS)\"", "\"** (T_POW)\"",
  "\"**= (T_POW_EQUAL)\"", "'('", "')'", "';'", "'{'", "'}'", "'$'", "']'",
  "'`'", "'\"'", "$accept", "start", "top_statement_list", "$@1",
  "namespace_name", "top_statement", "$@2", "$@3", "use_declarations",
  "use_declaration", "use_function_declarations",
  "use_function_declaration", "use_const_declarations",
  "use_const_declaration", "constant_declaration", "inner_statement_list",
  "$@4", "inner_statement", "statement", "unticked_statement", "$@5",
  "$@6", "$@7", "$@8", "$@9", "@10", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23",
  "catch_statement", "$@24", "$@25", "$@26", "$@27", "finally_statement",
  "$@28", "additional_catches", "non_empty_additional_catches",
  "additional_catch", "@29", "$@30", "unset_variables", "unset_variable",
  "function_declaration_statement", "class_declaration_statement",
  "is_reference", "is_variadic", "unticked_function_declaration_statement",
  "$@31", "unticked_class_declaration_statement", "$@32", "$@33",
  "class_entry_type", "extends_from", "interface_entry",
  "interface_extends_list", "implements_list", "interface_list",
  "foreach_optional_arg", "foreach_variable", "$@34", "for_statement",
  "foreach_statement", "declare_statement", "declare_list",
  "switch_case_list", "case_list", "$@35", "$@36", "case_separator",
  "while_statement", "elseif_list", "$@37", "new_elseif_list", "$@38",
  "else_single", "new_else_single", "parameter_list",
  "non_empty_parameter_list", "parameter", "optional_class_type",
  "function_call_parameter_list", "non_empty_function_call_parameter_list",
  "function_call_parameter", "global_var_list", "global_var",
  "static_var_list", "class_statement_list", "class_statement", "$@39",
  "$@40", "trait_use_statement", "trait_list", "trait_adaptations",
  "trait_adaptation_list", "non_empty_trait_adaptation_list",
  "trait_adaptation_statement", "trait_precedence", "trait_reference_list",
  "trait_method_reference", "trait_method_reference_fully_qualified",
  "trait_alias", "trait_modifiers", "method_body", "variable_modifiers",
  "method_modifiers", "non_empty_member_modifiers", "member_modifier",
  "class_variable_declaration", "class_constant_declaration",
  "echo_expr_list", "for_expr", "non_empty_for_expr", "$@41",
  "chaining_method_or_property", "chaining_dereference",
  "chaining_instance_call", "$@42", "instance_call", "$@43", "new_expr",
  "$@44", "expr_without_variable", "$@45", "$@46", "$@47", "$@48", "$@49",
  "$@50", "@51", "$@52", "$@53", "$@54", "$@55", "@56", "@57",
  "yield_expr", "combined_scalar_offset", "combined_scalar", "function",
  "lexical_vars", "lexical_var_list", "function_call", "@58", "@59", "@60",
  "@61", "$@62", "$@63", "$@64", "$@65", "class_name",
  "fully_qualified_class_name", "class_name_reference",
  "dynamic_class_name_reference", "$@66", "$@67",
  "dynamic_class_name_variable_properties",
  "dynamic_class_name_variable_property", "exit_expr", "backticks_expr",
  "ctor_arguments", "common_scalar", "static_class_constant",
  "static_scalar", "static_scalar_value", "static_operation",
  "general_constant", "scalar", "static_array_pair_list", "possible_comma",
  "non_empty_static_array_pair_list", "expr", "parenthesis_expr",
  "r_variable", "w_variable", "rw_variable", "variable", "$@68", "$@69",
  "variable_properties", "variable_property", "$@70",
  "array_method_dereference", "method", "@71", "method_or_not",
  "variable_without_objects", "static_member", "variable_class_name",
  "array_function_dereference", "$@72",
  "base_variable_with_function_calls", "base_variable",
  "reference_variable", "compound_variable", "dim_offset",
  "object_property", "$@73", "object_dim_list", "variable_name",
  "simple_indirect_reference", "assignment_list",
  "assignment_list_element", "$@74", "array_pair_list",
  "non_empty_array_pair_list", "encaps_list", "encaps_var", "$@75",
  "encaps_var_offset", "internal_functions_in_yacc", "isset_variables",
  "$@76", "isset_variable", "class_constant", "static_class_name_scalar",
  "class_name_scalar", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-876)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-591)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -876,    72,    74,  -876,  2084,  4478,  4478,   -77,  4478,  4478,
    4478,  4478,  4478,  4478,  4478,  4478,  -876,   204,   204,  4478,
    4478,  4478,  4478,  4478,  4478,  4478,  3281,   362,  4478,   -58,
     -49,  -876,  -876,    80,  -876,  -876,  -876,    53,  4478,  -876,
    -876,   -29,   -26,  -876,   -49,  3414,  3547,    75,  -876,   174,
    3680,  -876,  4478,    -8,   -15,    15,   128,   140,   111,   114,
     127,   132,  -876,  -876,  -876,   137,   139,  -876,  -876,  -876,
    -876,  -876,  -876,   361,   -14,  -876,  -876,   198,  4611,  -876,
    -876,   143,   378,   388,   255,  -876,    11,  -876,  -876,  -876,
    -876,  -876,  -876,   231,   236,  -876,  -876,   185,   302,   313,
     348,   320,   247,  -876,   336,  -876,  5061,  -876,  -876,   369,
    1879,  -876,  -876,   258,   351,   285,  -876,   -20,  -876,    71,
    -876,  -876,  -876,  -876,  -876,   317,   280,   348,  5701,  5701,
    4478,  5701,  5701,  5989,    86,  5319,  1040,   293,   293,   -12,
     293,  4478,  -876,   282,   198,   -71,   304,  -876,  -876,   326,
    -876,   293,   293,   293,   293,   293,   293,   293,   204,  5362,
     300,   455,   346,   198,   363,   371,  -876,  -876,   374,   402,
      58,    71,  -876,  3813,  -876,  -876,  4611,   513,  -876,  4478,
      12,  5701,  2882,   -49,  4478,  4478,   390,  -876,  -876,  5103,
    -876,  5148,   397,   528,  -876,   399,  5701,  1736,   389,  5190,
     -11,    59,   198,   -18,    18,  -876,  -876,   215,    19,  -876,
     553,    21,   348,  -876,  -876,   204,  4478,  4478,   419,  -876,
    3281,   150,   274,  -876,  4744,   204,   391,  -876,   198,  -876,
     264,   261,   421,   422,  1977,   429,  4478,   -23,   428,   436,
     -23,   216,   518,   437,   520,  -876,   471,  -876,  -876,  4478,
    4478,  -876,   524,   535,   233,  4478,  -876,  4478,  -876,   571,
    -876,  -876,  4478,  4478,  4478,  4478,  4478,  4478,  4478,  4478,
    4478,  4478,  4478,  4478,  4478,  4478,  4478,  4478,  4478,  4478,
    4478,   362,  4478,  -876,  -876,  -876,  3946,  4478,  4478,  4478,
    4478,  4478,  4478,  4478,  4478,  4478,  4478,  4478,  4478,   437,
      14,  4478,  -876,  4478,  4478,   143,   -19,  -876,  5232,  4478,
     293,   198,   -56,   243,   243,  -876,  -876,  4079,  -876,  4212,
    -876,   198,   363,   126,   437,   126,  -876,     0,  -876,  -876,
    2882,  5701,   440,  4478,  -876,   521,  -876,   445,   597,  5701,
     516,  3082,   536,     1,  -876,  -876,  -876,  6199,  -876,  -876,
    -876,  -876,   198,   176,    22,  -876,   198,   186,    23,  -876,
     208,   538,   116,  -876,  4478,  -876,  -876,   -15,  -876,  6199,
     540,  -876,  -876,    36,  -876,  -876,    37,   202,    38,  -876,
     462,  1757,   470,   299,   463,  -876,   556,  -876,  -876,   568,
    1490,   474,  -876,  -876,  -876,   395,  -876,  -876,  -876,   437,
    -876,  -876,  -876,  -876,  2217,  1837,  -876,  -876,  -876,  3015,
    -876,   646,   199,  -876,   539,   504,   507,  -876,   514,  4478,
     517,  -876,  4478,   519,     0,  -876,    71,   525,  4478,  5837,
    4478,  -876,  4478,  4478,  4478,  2076,  3464,  3728,  3861,  3861,
    3861,  3861,  1416,  1416,  1416,  1416,   106,   106,    54,    54,
      54,   -12,   -12,   -12,  -876,   293,   200,  5989,  5989,  5989,
    5989,  5989,  5989,  5989,  5989,  5989,  5989,  5989,  5989,  5989,
    -876,   517,   522,  -876,   529,   243,   530,  2020,  -876,   141,
    1668,   -51,  -876,   204,  5701,   204,  5463,   363,  -876,  -876,
    -876,  -876,   243,  -876,  -876,  -876,  5701,  -876,  2350,  -876,
    -876,  -876,  -876,   658,    40,   523,   532,  -876,  6199,  6199,
    6199,  6199,  6199,  -876,   526,  -876,    51,   531,   198,  6199,
     -71,   546,  -876,  -876,  -876,  5760,  -876,  -876,   537,   294,
     602,   -11,  -876,   306,   606,    59,  -876,   621,  -876,  -876,
    4886,  -876,  -876,   684,   545,   204,   544,  -876,  -876,  -876,
    -876,  -876,   548,  -876,    41,  -876,  -876,    10,  -876,  4478,
    -876,  -876,   437,   547,  -876,  -876,   167,   549,  -876,  -876,
    -876,  -876,  -876,   204,  4478,  -876,    42,  -876,    44,   551,
     963,  6199,   557,   198,   363,  -876,   584,   199,   555,  -876,
    -876,   559,   314,   550,  4928,   437,   437,     0,  -876,  1139,
    5989,  4478,  5506,  6113,  6170,   362,  -876,   437,   437,  -876,
    -876,  -876,     7,  -876,  -876,  -876,  -876,  -876,  4345,  -876,
     360,  -876,   -49,  -876,  -876,  -876,  4478,  4478,   175,   175,
    6199,   642,  2483,  -876,   457,  -876,   238,   192,   192,     3,
       3,  5562,   558,   707,  6199,   573,   198,   -56,  5277,    -4,
    6199,  6199,  6199,  5862,  6199,  6199,  6199,  6199,  6199,  6199,
    6199,  6199,  6199,  6199,  6199,  6199,  6199,  6199,  6199,  6199,
    6199,  6199,  6199,  6199,  6199,  6199,  6199,   614,   648,  -876,
    -876,   649,  -876,  -876,  -876,  -876,  6199,   314,  -876,  -876,
    4478,  -876,   299,   710,  -876,  -876,  -876,   566,  1387,  -876,
    -876,   569,  -876,   189,   574,  -876,  5701,  3148,  -876,  -876,
    -876,   198,   363,   199,   575,   720,  -876,  -876,   314,  -876,
    -876,   578,   722,  -876,   348,  -876,  -876,  -876,  -876,  -876,
    6047,  -876,  -876,  -876,  -876,  -876,   585,  4478,  4478,   204,
    5701,  -876,  -876,   370,   586,   656,   587,  5701,   204,   590,
     615,  -876,   615,  -876,   734,  -876,  -876,  -876,   491,   594,
    4478,     6,   273,  -876,  6199,  -876,  6199,  -876,   596,   -51,
    -876,  -876,  -876,  5799,  5422,  6012,  6199,  5602,  6136,  6193,
    3331,  3596,   441,  3994,  3994,  3994,  3994,  1430,  1430,  1430,
    1430,   188,   188,   192,   192,   192,     3,     3,     3,  1701,
       3,   598,  -876,  -876,  -876,  -876,   599,  -876,   299,  -876,
    4478,  -876,   600,  -876,  4478,   243,   630,   195,  -876,  -876,
     604,  -876,   363,   720,  -876,   199,   683,   601,   657,   133,
     611,  4478,   437,   702,   703,   437,  -876,   607,  4970,  -876,
     641,   380,   -49,  2882,  -876,  -876,   612,  -876,  -876,  -876,
     175,   617,   619,  6199,   679,   622,  -876,  5019,  -876,  -876,
    -876,  -876,  5760,  5661,  -876,  6070,  6199,  -876,  -876,   666,
     657,    46,  5989,  -876,   620,  -876,  -876,  4478,   630,  -876,
     714,  -876,   709,   199,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,   317,   448,  -876,    31,   618,
     625,   628,  -876,  -876,   708,  6047,  -876,  4478,  4478,  -876,
     630,  -876,  -876,   243,  -876,   -49,   760,   719,  -876,  -876,
    -876,  4478,   299,  -876,  -876,  -876,  -876,   634,  -876,  -876,
    -876,  6199,  6070,   199,  -876,  -876,   643,  -876,  -876,   585,
     644,   630,  -876,   787,     9,  -876,   728,   348,  -876,   731,
    -876,  -876,    39,  -876,   791,   650,   651,  -876,  -876,   779,
    -876,   653,  2882,   660,    47,  2616,  2616,  -876,  -876,   405,
    5760,  -876,   661,  -876,  -876,  -876,  6199,   199,  -876,   244,
    -876,   803,    33,   747,   807,   672,   758,  -876,    48,   676,
    6199,  -876,  -876,  -876,   768,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,   444,   764,  -876,   681,  -876,  -876,   749,
     685,   244,  -876,   688,   754,   740,   692,   704,  6199,   777,
    -876,  -876,  6199,  -876,  -876,    49,  -876,  -876,  -876,  -876,
    2749,   765,   697,   699,  -876,  -876,  -876,  -876,   511,   199,
    -876,   786,  -876,   845,   706,  -876,   788,  -876,   386,  -876,
    -876,  -876,   705,  -876,  -876,   792,   793,   855,  -876,  -876,
    6199,   314,  -876,   781,  -876,   711,  -876,   199,  -876,   718,
     713,  -876,  -876,   368,  -876,   717,  -876,  -876,  -876,  -876,
     746,   804,  -876,   755,  -876,   804,  -876,   199,  -876,  -876,
     836,   762,  -876,   756,  -876,   757,  -876
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     3,     1,     0,     0,     0,     0,     0,     0,
       0,   357,     0,     0,     0,     0,   350,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   554,     0,     0,   411,
       0,   419,   420,     6,   480,   534,    80,   421,     0,    60,
      57,     0,     0,    89,     0,     0,     0,     0,   372,     0,
       0,    92,     0,     0,     0,   395,     0,     0,     0,     0,
       0,     0,   128,   130,   134,     0,     0,   486,   425,   426,
     427,   422,   423,     0,     0,   428,   424,     0,     0,    91,
      43,   546,   414,     0,   477,     4,     0,     8,    48,     9,
      10,   116,   117,     0,     0,   333,   496,     0,   353,   354,
     118,   527,     0,   483,   481,   352,     0,   332,   495,     0,
     499,   393,   530,     0,   526,   505,   525,   528,   533,     0,
     341,   476,   482,   357,     6,   395,     0,   118,   581,   582,
       0,   584,   585,   356,   496,     0,   499,   319,   320,   321,
     322,     0,   395,     0,     0,   379,     0,   295,   501,     0,
     297,   342,   343,   344,   345,   346,   347,   348,     0,   559,
       0,   489,     0,     0,   396,   402,   273,   403,     0,   407,
     528,     0,   281,     0,   349,   413,     0,    51,    49,   536,
       0,   256,     0,     0,   257,     0,     0,    67,    69,     0,
      71,     0,     0,     0,    73,   496,     0,   499,     0,     0,
       0,     0,     0,    23,     0,    22,   199,     0,     0,   198,
     204,     0,   118,   129,   131,     0,     0,     0,     0,   275,
     554,   568,     0,   430,     0,     0,     0,   566,     0,    15,
       0,   479,   333,     0,     0,    41,     0,   415,     0,   416,
       0,     0,     0,     0,     0,    20,   132,   126,    76,   536,
     536,   119,   358,     0,     0,   536,   302,     0,   304,   336,
     298,   300,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,   294,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,   502,   536,     0,   547,   529,   358,     0,     0,
     351,     0,   383,     0,     0,   563,   500,     0,   371,   490,
     555,     0,   398,     0,   417,     0,   404,   529,   412,    54,
       0,   537,     0,     0,    79,     0,    58,     0,   258,   261,
     496,   499,     0,     0,    70,    72,    96,     0,    74,    75,
      43,    95,     0,    29,     0,    28,     0,    35,     0,    34,
      25,     0,     0,    17,     0,   200,   499,     0,    77,     0,
       0,    78,   360,     0,   113,   115,   496,   499,     0,   586,
     496,   499,     0,   553,     0,   569,     0,   429,   567,   480,
       0,     0,   565,   485,   564,   478,     5,    12,    13,     0,
     334,   498,   497,    50,     0,     0,   355,   484,     7,     0,
     380,     0,     0,   124,   135,     0,     0,   122,     0,   536,
     591,   594,     0,   519,   517,   385,     0,     0,     0,   306,
       0,   339,     0,     0,     0,   307,   309,   308,   325,   326,
     323,   324,   327,   329,   328,   330,   317,   318,   311,   312,
     310,   313,   315,   316,   331,   314,     0,   277,   282,   283,
     284,   286,   287,   288,   289,   290,   291,   292,   293,   285,
     394,   592,   520,   389,     0,     0,     0,     0,   583,   496,
     499,   381,   544,     0,   558,     0,   557,   397,   519,   418,
     274,   520,     0,    43,    52,   368,   255,    61,     0,    63,
     259,    86,    83,     0,     0,   159,   159,    68,     0,     0,
       0,     0,   487,   421,     0,   441,     0,     0,     0,     0,
     435,     0,   433,   440,    40,   432,   442,   434,    41,    31,
       0,     0,    18,    37,     0,     0,    19,     0,    24,    21,
       0,   197,   205,   202,     0,     0,     0,   587,   578,   580,
     579,    11,     0,   550,     0,   549,   370,     0,   571,     0,
     572,   574,     0,     3,     5,   384,   270,     0,    42,    44,
      45,    46,   535,     0,     0,   188,     0,   191,   496,     0,
     499,     0,     0,     0,   399,   133,   137,     0,     0,   367,
     366,     0,   184,     0,     0,     0,     0,   518,   369,   303,
     305,     0,     0,   299,   301,     0,   278,     0,     0,   522,
     539,   503,   538,   543,   531,   532,   562,   561,     0,   405,
      41,   168,     0,    43,   166,    59,   257,     0,     0,     0,
       0,     0,     0,   159,     0,   159,     0,   473,   474,   450,
     451,   494,     0,   489,   487,     0,     0,   437,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,    30,
      27,     0,    36,    33,    26,   201,     0,   184,   114,    82,
       0,   551,   553,     0,   575,   577,   576,     0,     0,   382,
      16,     3,   335,     0,     0,   195,   196,     0,   189,   190,
      39,     0,   401,     0,     0,   136,   139,   207,   184,   185,
     186,     0,   178,   180,   118,   187,   524,   545,   388,   386,
     340,   337,   279,   392,   390,   540,   516,   536,     0,     0,
     556,   409,   171,   174,     0,    41,     0,   260,     0,     0,
     141,   143,   141,   153,     0,    43,   151,    90,     0,     0,
       0,     0,     0,   155,     0,   439,   490,   488,     0,   436,
     475,   431,   593,   460,   458,   459,     0,     0,   462,   461,
     452,   454,   453,   465,   466,   463,   464,   467,   468,   469,
     470,   455,   456,   444,   445,   457,   446,   448,   449,     0,
     447,     0,    93,    32,    38,   203,     0,   588,   553,   548,
       0,   570,     0,    14,   536,     0,   269,   268,   272,   263,
       0,   192,   400,   138,   207,     0,   239,     0,   373,   184,
     120,     0,   417,   515,   514,     0,   507,     0,     0,   560,
     406,   176,     0,     0,    53,    62,     0,    64,   144,   145,
       0,     0,     0,     0,    41,     0,   157,     0,   164,   165,
     162,   156,   493,   492,   438,   471,     0,   443,    98,   103,
     373,     0,   276,   573,     0,   508,   262,   536,     0,    47,
     239,   140,     0,     0,   246,   247,   248,   245,   244,   243,
     238,   127,   206,   211,   208,     0,   237,   241,     0,     0,
       0,     0,   181,   121,     0,   338,   280,   536,   536,   513,
     504,   541,   542,     0,   408,     0,     0,     0,   169,   175,
     167,   257,   553,   142,    87,    84,   154,     0,   158,   160,
      43,     0,   472,     0,   104,    94,     0,   552,   265,   516,
       0,   267,   125,     0,     0,   215,     0,   118,   242,     0,
     210,    43,     0,    43,   182,     0,     0,   506,   410,     0,
      43,     0,     0,     0,     0,     0,     0,   152,    43,    41,
     491,    99,     0,    43,   509,   264,     0,     0,   217,   219,
     214,   251,     0,     0,     0,    41,     0,   377,     0,    41,
       0,   510,   511,   172,    41,    56,   170,    65,   146,    43,
     149,    88,    85,    41,     0,    43,    41,   254,   216,     6,
       0,   220,   221,     0,     0,   229,     0,     0,     0,     0,
     209,   212,     0,   123,   378,     0,   374,   359,   183,    43,
       0,    41,     0,    41,   361,   218,   222,   223,   233,     0,
     224,     0,   252,   249,     0,   253,     0,   375,    41,    43,
     147,    66,     0,   100,   105,     0,   232,   225,   226,   230,
       0,   184,   376,    41,   150,     0,   231,     0,   250,     0,
       0,    43,   227,     0,   148,    41,   235,    43,   213,   101,
      41,   107,   236,     0,   102,   106,   108,     0,   109,   110,
       0,     0,   111,     0,    43,    41,   112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -876,  -876,  -378,  -876,   -17,  -876,  -876,  -876,  -876,   560,
    -876,   392,  -876,   384,  -876,   193,  -876,  -876,    -1,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -165,  -876,
    -876,  -876,   376,   541,   542,  -125,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,   211,   173,  -613,
    -876,  -876,   -40,  -876,  -876,  -876,  -474,  -876,  -876,    70,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -678,  -876,    99,
    -876,  -219,  -876,   225,  -876,   567,  -876,   109,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,   -76,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -875,  -876,  -876,
    -876,  -620,  -876,  -876,    61,  -876,  -876,  -876,  -876,  -876,
     858,  -876,    -3,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,   -67,  -876,  -876,     8,
      73,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,   226,  -314,  -267,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,   108,   933,  -876,  -299,  1308,  -876,  -876,  -876,   297,
     307,  -876,  1076,    -7,   735,  -470,   512,   920,  -876,  -876,
    -876,  -781,  -876,  -876,  -876,  -876,     5,  -247,  -876,   301,
    -876,  -876,  -876,   -22,    -2,  -876,  -131,  -488,  -876,  -876,
     265,    56,  -774,   257,  -876,   727,  -876,   489,  -129,  -876,
    -876,  -876,  -876,  -876,   262,  -876,  -876,  -876
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     4,    84,    85,   564,   396,   204,   205,
     354,   355,   358,   359,    86,   235,   404,   568,  1000,    88,
     330,   621,   493,   742,   183,   498,   182,   622,   626,   921,
    1030,   343,   629,   966,   628,   965,   186,   198,   869,   802,
     933,  1004,  1065,  1081,   935,   972,  1084,  1085,  1086,  1090,
    1093,   373,   374,    89,    90,   252,   904,    91,   591,    92,
     586,   414,    93,   413,    94,   588,   714,   715,   851,   750,
     922,  1051,  1001,   757,   504,   507,   634,   968,   930,   860,
     625,   743,   962,   841,  1029,   844,   917,   721,   722,   723,
     724,   489,   576,   577,   208,   209,   211,   826,   892,   946,
    1044,   893,   944,   980,  1010,  1011,  1012,  1013,  1057,  1014,
    1015,  1016,  1055,  1078,   894,   895,   896,   897,   982,   898,
     180,   337,   338,   627,   816,   817,   818,   878,   702,   703,
      95,   324,    96,   383,   832,   433,   434,   428,   430,   566,
     432,   831,   601,   141,   418,   544,    97,    98,    99,   127,
     901,   988,   101,   243,   562,   399,   596,   595,   608,   607,
     299,   102,   725,   166,   167,   492,   741,   840,   914,   174,
     238,   490,   103,   523,   524,   525,   526,   104,   105,   642,
     320,   643,   331,   107,   108,   315,   109,   110,   475,   736,
     910,   819,   939,   833,   834,   835,   836,   111,   112,   113,
     114,   253,   115,   116,   117,   118,   332,   611,   735,   612,
     613,   119,   554,   555,   808,   160,   161,   226,   227,   557,
     697,   120,   378,   690,   379,   121,   527,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     145,   145,   307,    87,   619,   169,   746,   423,   134,   806,
     164,   233,   100,   616,   454,   617,   752,   977,   563,   244,
     333,   948,   175,   177,   410,   170,   362,   367,   505,   370,
     531,   535,   636,   858,   871,   876,   203,   187,   281,   949,
     827,  1019,   303,   303,   545,  -590,   547,   195,   631,   692,
     707,   221,  -193,   472,   692,   692,  1025,   230,   124,   206,
     231,   124,   303,   212,   124,   675,   423,   472,   771,   737,
     542,   986,     3,   361,    -2,  -396,   488,   130,   491,   242,
     470,  1046,   694,   171,   695,   696,   471,   372,    35,   210,
    -398,   200,   201,   388,   242,  -397,   173,   394,   585,   242,
     278,   279,   280,   705,   281,   176,   233,   178,   388,   233,
     394,   388,   394,   987,    48,   179,   772,   306,   415,   416,
     303,   224,   225,  1047,   427,   184,  -521,   312,   185,   957,
     645,   124,   242,   212,  -517,  -518,   228,   304,   304,   352,
     282,   145,   202,   229,   207,    35,   322,   192,   964,   275,
     276,   277,   278,   279,   280,   676,   281,   304,   506,   758,
     876,   762,   859,  1056,   738,   978,   979,   245,   334,   327,
     474,   422,   476,    81,   363,   368,   336,   371,   532,   536,
     565,   335,   340,   353,   357,   360,   701,   950,   124,  1020,
     145,   546,  -590,   548,   223,   632,   693,   708,   145,  -193,
      35,   937,   998,  1026,  -521,   124,   282,   748,   145,   356,
    -589,   395,   385,   376,   380,   304,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   610,  -271,
     305,   669,   670,   671,   672,   673,   674,   923,   672,   673,
     674,  -362,  -362,   146,   146,   610,   193,   124,   213,    35,
     675,   814,   424,   165,   675,  -501,  -501,   877,   282,   169,
     214,   719,   720,   605,   164,   215,   202,   530,   216,   839,
     124,   124,   124,   716,    35,   386,   124,   534,    35,   170,
     582,   217,   710,   583,   142,    81,   218,   124,   593,    35,
     221,   219,  -271,   220,   481,   392,  -364,  -364,   424,   537,
     236,   963,   749,   246,   487,   420,   479,    35,   247,   142,
     426,   424,   424,   142,   815,   482,  1009,    35,   149,   149,
    -266,   424,   143,   424,   142,   144,   242,   875,   168,   494,
     520,   753,   760,   761,    81,   529,   242,   171,   732,   533,
     676,   248,   579,   699,   676,   203,   582,   143,   221,   583,
     144,   143,   520,   421,   144,   298,   426,  -589,   242,    81,
     224,   225,   143,    81,   249,   144,   145,   760,   761,   426,
     426,   124,   364,    35,    81,   250,   728,   729,   407,   426,
     251,   426,  -523,  1069,   146,   678,   124,   805,   733,   734,
     422,   582,    81,   254,   583,   584,   763,   681,   255,   716,
     422,  -396,    81,   569,   300,   242,   578,  -398,   142,  -379,
     302,   242,   100,   301,   242,  -383,    48,   387,   224,   225,
     397,   398,   284,   285,   597,   958,   552,   -55,   -55,   -55,
     228,   861,   311,   146,   124,   221,    35,   842,   843,   145,
     222,   146,   719,   720,   242,   282,   143,   915,   916,   144,
     313,   146,   221,  -173,  -173,  -173,   242,   237,    81,   149,
     318,   582,   221,   319,   583,   221,   145,   240,   145,  -179,
     392,   142,   314,   424,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     424,   520,   520,   520,   520,   520,   321,   624,  -163,  -163,
    -163,   647,   520,   675,   223,   224,   225,   165,   149,   162,
     221,   881,   163,   242,   353,   392,   149,   323,   357,   425,
     325,    81,   224,   225,  1076,  1077,   149,   326,   145,   147,
     150,   426,   224,   225,   393,   224,   225,  -161,  -161,  -161,
     329,  -397,   347,   528,   342,   242,   350,  -240,   426,  -381,
     759,   760,   761,   346,   926,   348,   145,   884,   885,   886,
     887,   888,   889,  -163,   520,   473,   712,   369,   610,   945,
     584,   239,   241,   521,   382,   584,   400,   401,   425,   473,
     224,   225,   168,   169,   855,   760,   761,   403,   164,   406,
     408,   409,   411,   676,   412,   521,   417,   419,   431,   830,
     495,   499,  -161,   170,   497,   500,   837,   501,   503,   146,
     538,   145,   145,   520,   543,   744,   909,   549,   556,   971,
     884,   885,   886,   887,   888,   889,   551,   520,   558,   769,
     559,   756,   561,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     520,   520,   520,   520,   520,   520,   520,   520,   520,   520,
     581,   171,   587,  1008,   589,  1017,   610,   590,   592,   520,
     584,  -544,   630,  -387,   679,   145,  -391,  1007,   682,   633,
     644,   646,   146,   874,   149,   598,   620,   376,   635,   609,
     614,  1028,   649,   684,   822,   677,   584,  1017,   686,   687,
     689,   584,   691,   704,   578,   700,   709,   711,   713,   146,
     726,   146,   717,   718,   754,   766,   387,   801,   765,  1042,
     803,   804,   145,  1045,   810,  1058,   811,   813,   825,   820,
     829,   145,   824,   828,   521,   521,   521,   521,   521,  -512,
     846,   850,   845,   847,   849,   521,   940,   520,   853,   520,
     856,   864,   868,  1072,   870,   815,   899,   149,   873,   520,
     879,  1068,   903,   900,   907,   908,   913,   911,   920,   927,
     934,   146,   924,  1089,   925,   951,   955,   956,   928,   952,
     938,   943,   954,   882,   149,   953,   149,   960,   961,   883,
     967,   145,   884,   885,   886,   887,   888,   889,   890,   146,
     973,   976,   981,   984,   975,   990,   993,   521,   584,   995,
     991,   992,   584,   424,   882,   997,   745,  1018,  1005,  1021,
     883,  1022,   983,   884,   885,   886,   887,   888,   889,   890,
    1023,   165,  1024,   145,  1027,   918,   520,  -177,  1032,  1034,
    -228,   891,   919,  1035,  1037,  1038,   149,  1039,  1040,   520,
    1041,  1043,  1053,  1052,   146,   146,   521,  1054,  1059,  1060,
    1061,  1064,  1062,  1067,  1066,  -234,   584,  1070,  1071,  1074,
     521,   426,   942,  1073,   149,  1079,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   947,  1082,   145,   168,  1083,   959,  1087,
    1091,   424,   521,  1094,   520,  1096,   584,  1092,   146,   683,
    1088,   688,   539,   680,   823,   852,  1002,   929,   902,   149,
     149,   136,   821,   880,   541,  1036,   232,   148,   148,   941,
     906,   768,   365,   936,   974,   570,   571,   384,   854,   809,
     767,     0,   807,     0,     0,     0,     0,     0,     0,   520,
     584,   996,   584,     0,     0,   146,     0,     0,     0,   426,
     197,  -194,     0,   520,   146,     0,     0,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,     0,
     521,     0,   521,   149,   584,     0,     0,     0,     0,     0,
       0,   520,   521,     0,     0,   520,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -501,  -501,     0,     0,
       0,     0,   584,     0,     0,     0,     0,     0,     0,  1050,
       0,     0,     0,     0,   146,     0,     0,     0,     0,     0,
     149,     0,     0,   520,   584,     0,     0,     0,     0,   149,
     584,     0,     0,     0,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,     0,     0,     0,     0,
     584,     0,     0,     0,     0,     0,   146,     0,   316,   521,
     106,   128,   129,     0,   131,   132,   133,   135,   137,   138,
     139,   140,   521,  -501,  -501,   151,   152,   153,   154,   155,
     156,   157,   159,     0,   172,   341,     0,     0,     0,   149,
       0,     0,     0,     0,   181,     0,   298,     0,  -194,     0,
       0,   189,   191,   969,     0,     0,   196,   366,   199,     0,
       0,     0,     0,     0,     0,   375,   377,   381,     0,     0,
       0,     0,     0,     0,   985,   391,   989,     0,   146,   257,
     258,   149,     0,   994,   234,     0,     0,   521,     0,     0,
       0,  1003,     0,     0,     0,   259,  1006,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,     0,   281,
       0,     0,  1031,   298,     0,  -363,  -363,     0,  1033,     0,
       0,     0,   521,     0,     0,     0,   308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   521,   310,     0,     0,
       0,     0,  1048,   149,     0,     0,     0,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1063,     0,   521,     0,     0,     0,   521,   234,
       0,     0,   234,     0,     0,     0,     0,     0,   106,     0,
     339,   196,     0,     0,  1075,     0,     0,     0,     0,     0,
    1080,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     522,     0,     0,     0,     0,     0,   521,  1095,     0,     0,
       0,   282,   196,   196,     0,     0,   159,     0,     0,     0,
     390,     0,   522,   553,     0,     0,     0,     0,     0,     0,
       0,     0,   405,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   580,
       0,     0,     0,   429,     0,     0,     0,     0,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,     0,   455,     0,
       0,     0,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,     0,   606,     0,     0,     0,
     477,     0,     0,     0,     0,   196,     0,     0,     0,     0,
       0,     0,     0,   484,     0,   486,   256,   257,   258,     0,
       0,     0,     0,   316,     0,   316,   106,     0,     0,   496,
       0,     0,     0,   259,     0,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,     0,   281,     0,     0,
     540,   522,   522,   522,   522,   522,     0,     0,     0,     0,
       0,     0,   522,  -591,  -591,  -591,  -591,   273,   274,   275,
     276,   277,   278,   279,   280,   375,   281,  -591,  -591,  -591,
    -591,   667,   668,   669,   670,   671,   672,   673,   674,     0,
     106,     0,     0,     0,     0,   196,     0,     0,     0,     0,
       0,     0,   675,   316,     0,     0,     0,     0,   594,   256,
     257,   258,     0,     0,   599,     0,   600,     0,   602,   603,
     604,     0,     0,     0,   522,     0,   259,     0,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   282,
     281,     0,     0,     0,     0,     0,     0,   812,   751,   751,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   522,     0,     0,     0,     0,   282,     0,
       0,     0,     0,     0,   106,     0,     0,   522,     0,     0,
       0,     0,   676,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   522,
     377,     0,   553,     0,     0,     0,     0,     0,     0,   522,
       0,     0,     0,     0,     0,     0,     0,   580,     0,     0,
       0,     0,     0,     0,     0,   698,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,   560,     0,
     706,     0,     0,     0,     0,     0,     0,     0,     0,   316,
       0,     0,     0,     0,     0,     0,     0,     0,   848,     0,
       0,     0,     0,     0,     0,     0,     0,   730,     0,     0,
       0,     0,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   740,     0,     0,   522,     0,   522,
       0,     0,   339,   747,     0,     0,     0,     0,   106,   522,
     650,   651,   652,     0,     0,     0,     0,     0,     0,     0,
       0,  -501,  -501,     0,     0,     0,     0,   653,   553,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,     0,   675,     0,     0,   196,     0,     0,     0,
     751,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   196,     0,     0,   522,     0,     0,  -501,
    -501,     0,     0,     0,     0,     0,     0,     0,     0,   522,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -501,  -501,     0,     0,   838,     0,   637,   638,   639,   640,
     641,   298,     0,  -365,  -365,     0,     0,   648,     0,     0,
       0,     0,     0,     0,     0,     0,   857,     0,     0,     0,
       0,     0,   553,     0,     0,     0,   256,   257,   258,     0,
       0,     0,     0,   676,     0,     0,     0,     0,     0,     0,
       0,   867,     0,   259,   522,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   872,   281,     0,   298,
       0,     0,   349,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,     0,     0,   905,     0,   522,
     298,     0,   550,     0,     0,     0,     0,     0,     0,   106,
       0,     0,     0,   522,     0,     0,     0,     0,     0,     0,
       0,     0,  -501,  -501,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   522,   641,     0,     0,   522,     0,     0,   773,   774,
     775,   777,   778,   779,   780,   781,   782,   783,   784,   785,
     786,   787,   788,   789,   790,   791,   792,   793,   794,   795,
     796,   797,   798,   799,   800,     0,   256,   257,   258,   282,
       0,     0,     0,   522,     0,   572,     0,   339,     0,     0,
       0,     0,     0,   259,     0,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,     0,   281,     0,   256,
     257,   258,   298,     0,     0,     0,     0,     0,   106,     0,
       0,   106,   106,     0,     0,     0,   259,     0,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,     0,
     281,     0,   862,     0,   863,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   865,     0,     0,     5,     6,     7,
       8,     9,     0,     0,     0,     0,    10,    11,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,     0,   281,    12,    13,   282,
       0,     0,   402,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,     0,     0,     0,    31,    32,    33,    34,    35,     0,
      36,     0,     0,     0,    37,    38,    39,    40,     0,    41,
       0,    42,   282,    43,   932,     0,    44,     0,   615,     0,
      45,    46,    47,    48,    49,    50,    51,     0,     0,    52,
      53,     0,    54,    55,    56,    57,     0,     0,     0,     0,
      58,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,    65,    66,     0,    67,    68,    69,    70,    71,    72,
       5,     6,     7,     8,     9,     0,    73,     0,   282,    10,
      11,    74,    75,    76,    77,     0,     0,     0,    78,   970,
      79,    80,     0,    81,     0,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,     0,     0,     0,    31,    32,    33,
      34,    35,     0,    36,     0,     0,     0,    37,    38,    39,
      40,     0,    41,     0,    42,     0,    43,     0,     0,    44,
       0,     0,     0,    45,    46,    47,    48,     0,    50,    51,
       0,     0,    52,     0,     0,    54,    55,    56,    57,     0,
       0,     0,     0,    58,    59,    60,   567,    62,    63,    64,
       0,     0,     0,     0,    65,    66,     0,    67,    68,    69,
      70,    71,    72,     5,     6,     7,     8,     9,     0,    73,
       0,     0,    10,    11,   126,    75,    76,    77,     0,     0,
       0,    78,     0,    79,    80,     0,    81,   623,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,     0,     0,     0,
      31,    32,    33,    34,    35,     0,    36,     0,     0,     0,
      37,    38,    39,    40,     0,    41,     0,    42,     0,    43,
       0,     0,    44,     0,     0,     0,    45,    46,    47,    48,
       0,    50,    51,     0,     0,    52,     0,     0,    54,    55,
       0,     0,     0,     0,     0,     0,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,     0,
      67,    68,    69,    70,    71,    72,     5,     6,     7,     8,
       9,     0,    73,     0,     0,    10,    11,   126,    75,    76,
      77,     0,     0,     0,    78,     0,    79,    80,     0,    81,
     755,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,     0,     0,    31,    32,    33,    34,    35,     0,    36,
       0,     0,     0,    37,    38,    39,    40,     0,    41,     0,
      42,     0,    43,     0,     0,    44,     0,     0,     0,    45,
      46,    47,    48,     0,    50,    51,     0,     0,    52,     0,
       0,    54,    55,     0,     0,     0,     0,     0,     0,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,     0,    67,    68,    69,    70,    71,    72,     5,
       6,     7,     8,     9,     0,    73,     0,     0,    10,    11,
     126,    75,    76,    77,     0,     0,     0,    78,     0,    79,
      80,     0,    81,   999,    82,    83,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     0,     0,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,     0,     0,     0,    31,    32,    33,    34,
      35,     0,    36,     0,     0,     0,    37,    38,    39,    40,
       0,    41,     0,    42,     0,    43,     0,     0,    44,     0,
       0,     0,    45,    46,    47,    48,     0,    50,    51,     0,
       0,    52,     0,     0,    54,    55,     0,     0,     0,     0,
       0,     0,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,     0,    67,    68,    69,    70,
      71,    72,     5,     6,     7,     8,     9,     0,    73,     0,
       0,    10,    11,   126,    75,    76,    77,     0,     0,     0,
      78,     0,    79,    80,     0,    81,  1049,    82,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,     0,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,     0,     0,    31,
      32,    33,    34,    35,     0,    36,     0,     0,     0,    37,
      38,    39,    40,     0,    41,     0,    42,     0,    43,     0,
       0,    44,     0,     0,     0,    45,    46,    47,    48,     0,
      50,    51,     0,     0,    52,     0,     0,    54,    55,     0,
       0,     0,     0,     0,     0,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,     0,    67,
      68,    69,    70,    71,    72,     5,     6,     7,     8,     9,
       0,    73,     0,     0,    10,    11,   126,    75,    76,    77,
       0,     0,     0,    78,     0,    79,    80,     0,    81,     0,
      82,    83,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
       0,     0,    31,    32,    33,    34,    35,     0,    36,     0,
       0,     0,    37,    38,    39,    40,     0,    41,     0,    42,
       0,    43,     0,     0,    44,     0,     0,     0,    45,    46,
      47,    48,     0,    50,    51,     0,     0,    52,     0,     0,
      54,    55,     0,     0,     0,     0,     0,     0,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      66,     0,    67,    68,    69,    70,    71,    72,     5,     6,
       7,     8,     9,     0,    73,     0,     0,    10,    11,   126,
      75,    76,    77,     0,     0,     0,    78,     0,    79,    80,
       0,    81,     0,    82,    83,     0,     0,   573,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
       0,     0,     0,     0,    14,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,     0,     0,     0,    31,    32,   124,    34,    35,
       0,     0,     0,     0,     0,    37,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,    59,    60,     0,  -501,  -501,     0,     0,     0,
       0,     0,    65,    66,     0,    67,    68,    69,    70,    71,
      72,     5,     6,     7,     8,     9,     0,    73,     0,     0,
      10,   123,   126,    75,    76,    77,   574,     0,     0,    78,
     575,     0,     0,   502,    81,     0,    82,    83,     0,     0,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,    31,    32,
     124,    34,    35,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,   298,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    66,     0,    67,    68,
      69,    70,    71,    72,     5,     6,     7,     8,     9,     0,
      73,     0,     0,    10,   123,   126,    75,    76,    77,   574,
       0,     0,    78,     0,     0,     0,     0,    81,     0,    82,
      83,     0,     0,   158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,     0,     0,     0,     0,
      14,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,    31,    32,   124,    34,    35,     0,     0,     0,     0,
       0,    37,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,     0,     0,   675,     0,     0,     0,     0,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
       0,    67,    68,    69,    70,    71,    72,     5,     6,     7,
       8,     9,     0,    73,     0,     0,    10,   123,   126,    75,
      76,    77,     0,     0,     0,    78,     0,     0,     0,     0,
      81,     0,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    13,     0,
       0,     0,     0,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,     0,     0,   676,    31,    32,   124,    34,    35,     0,
       0,     0,     0,     0,    37,     0,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,    48,   281,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,    59,    60,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,     0,    67,    68,    69,    70,    71,    72,
       5,     6,     7,     8,     9,     0,    73,     0,     0,    10,
     123,   126,    75,    76,    77,     0,     0,     0,    78,     0,
     188,     0,     0,    81,     0,    82,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,     0,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     0,     0,     0,   282,    31,    32,   124,
      34,    35,     0,     0,     0,     0,     0,    37,   658,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,   675,     0,
       0,     0,     0,     0,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,    65,    66,     0,    67,    68,    69,
      70,    71,    72,     5,     6,     7,     8,     9,     0,    73,
       0,     0,    10,   123,   126,    75,    76,    77,     0,     0,
       0,    78,     0,   190,     0,     0,    81,     0,    82,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,    14,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     0,     0,   676,     0,
      31,    32,   124,    34,    35,     0,     0,     0,     0,     0,
      37,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,     0,   281,    48,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,     0,     0,     0,     0,     0,     0,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,     0,
      67,    68,    69,    70,    71,    72,     5,     6,     7,     8,
       9,     0,    73,     0,     0,    10,    11,   126,    75,    76,
      77,     0,     0,     0,    78,     0,   194,     0,     0,    81,
       0,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,     0,    14,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     0,
     282,     0,     0,    31,    32,   124,    34,    35,     0,     0,
       0,     0,     0,    37,  -591,  -591,  -591,  -591,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
       0,   281,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   125,     0,     0,     0,     0,     0,     0,     0,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,     0,    67,    68,    69,    70,    71,    72,     5,
       6,     7,     8,     9,     0,    73,     0,     0,    10,   123,
     126,    75,    76,    77,     0,     0,     0,    78,   328,     0,
       0,     0,    81,     0,    82,    83,     0,     0,   456,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     0,     0,    14,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     0,   282,     0,     0,    31,    32,   124,    34,
      35,     0,     0,     0,     0,     0,    37,  -591,  -591,  -591,
    -591,   663,   664,   665,   666,   667,   668,   669,   670,   671,
     672,   673,   674,     0,     0,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,   675,     0,     0,     0,
       0,     0,     0,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,    65,    66,     0,    67,    68,    69,    70,
      71,    72,     5,     6,     7,     8,     9,     0,    73,     0,
       0,    10,   123,   126,    75,    76,    77,     0,     0,     0,
      78,     0,     0,     0,     0,    81,     0,    82,    83,     0,
       0,   483,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,     0,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     0,   676,     0,     0,    31,
      32,   124,    34,    35,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   125,     0,
       0,     0,     0,     0,     0,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,    65,    66,     0,    67,
      68,    69,    70,    71,    72,     5,     6,     7,     8,     9,
       0,    73,     0,     0,    10,   123,   126,    75,    76,    77,
       0,     0,     0,    78,     0,     0,     0,     0,    81,     0,
      82,    83,     0,     0,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
       0,    14,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     0,     0,
       0,     0,    31,    32,   124,    34,    35,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,     0,     0,     0,     0,     0,     0,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      66,     0,    67,    68,    69,    70,    71,    72,     5,     6,
       7,     8,     9,     0,    73,     0,     0,    10,   123,   126,
      75,    76,    77,     0,     0,     0,    78,     0,     0,     0,
       0,    81,     0,    82,    83,     0,     0,   739,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
       0,     0,     0,     0,    14,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     0,     0,     0,     0,    31,    32,   124,    34,    35,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,     0,     0,     0,
       0,     0,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,     0,    67,    68,    69,    70,    71,
      72,     5,     6,     7,     8,     9,     0,    73,     0,     0,
      10,   123,   126,    75,    76,    77,     0,     0,     0,    78,
       0,     0,     0,     0,    81,     0,    82,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,     0,    14,     0,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     0,     0,     0,     0,    31,    32,
     124,    34,    35,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,     0,
       0,     0,     0,     0,     0,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    66,     0,    67,    68,
      69,    70,    71,    72,     5,     6,     7,     8,     9,     0,
      73,     0,     0,    10,    11,   126,    75,    76,    77,     0,
       0,     0,    78,     0,     0,     0,     0,    81,     0,    82,
      83,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,     0,     0,     0,     0,
      14,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     0,     0,     0,
       0,    31,    32,   124,    34,    35,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      48,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,     0,     0,     0,     0,     0,     0,     0,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,    65,    66,
       0,    67,    68,    69,    70,    71,    72,     5,     6,     7,
       8,     9,     0,    73,     0,     0,    10,   123,   126,    75,
      76,    77,     0,     0,     0,    78,     0,     0,     0,     0,
      81,     0,    82,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,    13,     0,
       0,     0,     0,    14,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       0,     0,     0,     0,    31,    32,   124,   389,    35,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,    59,    60,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,     0,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,    73,     0,     0,     0,
       0,   126,    75,    76,    77,   256,   257,   258,    78,     0,
       0,     0,     0,    81,     0,    82,    83,     0,     0,     0,
       0,     0,   259,     0,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,     0,   281,   256,   257,   258,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,     0,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,     0,   281,   256,
     257,   258,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   259,     0,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,     0,
     281,     0,     0,     0,     0,     0,     0,     0,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,     0,     0,   685,   259,   858,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,     0,   281,
     256,   257,   258,     0,     0,     0,     0,     0,     0,     0,
     282,     0,     0,     0,     0,     0,   727,   259,     0,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
       0,   281,   256,   257,   258,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,     0,   912,   259,
       0,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,     0,   281,     0,     0,     0,   256,   257,   258,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   282,     0,     0,   259,   859,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,     0,   281,   256,
     257,   258,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,     0,     0,   259,   283,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,     0,
     281,   256,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   282,     0,     0,   259,   344,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,     0,   281,     0,     0,     0,   650,   651,   652,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     282,     0,     0,   653,   345,   654,   655,   656,   657,   658,
     659,   660,   661,   662,   663,   664,   665,   666,   667,   668,
     669,   670,   671,   672,   673,   674,     0,     0,   256,   257,
     258,     0,     0,     0,     0,     0,     0,     0,     0,   675,
       0,     0,   282,     0,     0,   259,   351,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,     0,   281,
       0,   256,   257,   258,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   282,     0,     0,   478,   259,     0,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,     0,   281,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   676,
       0,     0,   770,   652,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,     0,   653,     0,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   282,   256,   257,   258,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   675,     0,     0,     0,   317,   259,
       0,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,     0,   281,   282,   256,   257,   258,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,   731,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,     0,   281,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   650,   651,   652,   676,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   653,   618,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   650,   651,   652,     0,   282,     0,     0,     0,     0,
       0,     0,     0,     0,   675,     0,     0,     0,   653,   866,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,     0,     0,   675,     0,     0,     0,     0,     0,
     650,   651,   652,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   653,   764,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   667,   668,   669,   670,   671,   672,   673,   674,
     256,   257,   258,     0,   676,     0,     0,     0,     0,     0,
       0,     0,     0,   675,     0,     0,     0,   259,     0,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
       0,   281,     0,     0,   676,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   650,
     651,   652,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   653,   931,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   651,
     652,     0,     0,   676,     0,     0,     0,     0,     0,     0,
       0,     0,   675,     0,     0,   653,     0,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   258,     0,
       0,     0,     0,   282,     0,     0,     0,     0,     0,     0,
       0,   675,     0,   259,     0,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,     0,   281,     0,   776,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   508,   509,     0,     0,     0,
       0,   510,   676,   511,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   512,     0,     0,     0,     0,     0,
       0,     0,    31,    32,   124,     0,     0,     0,     0,     0,
       0,     0,   513,     0,     0,     0,     0,     0,     0,     0,
       0,   676,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
     514,     0,   515,    68,    69,    70,    71,    72,     0,     0,
       0,     0,     0,     0,   516,     0,     0,     0,     0,   517,
      75,    76,   518,     0,     0,   259,   519,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   653,   281,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   675,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,     0,   281,   654,   655,
     656,   657,   658,   659,   660,   661,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   675,     0,     0,     0,     0,     0,     0,     0,
       0,   282,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,     0,   281,   676,   655,   656,   657,   658,   659,
     660,   661,   662,   663,   664,   665,   666,   667,   668,   669,
     670,   671,   672,   673,   674,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   675,   282,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,     0,
     281,     0,   676,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   508,   509,     0,     0,     0,     0,   510,     0,
     511,     0,     0,     0,     0,   675,     0,     0,     0,     0,
       0,   512,     0,     0,     0,   282,     0,     0,     0,    31,
      32,   124,     0,     0,     0,     0,     0,     0,     0,   513,
       0,     0,     0,     0,     0,     0,     0,     0,   676,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   282,     0,     0,     0,     0,   514,     0,   515,
      68,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,   516,     0,     0,     0,   676,   517,    75,    76,   518,
       0,     0,     0,   519
};

static const yytype_int16 yycheck[] =
{
      17,    18,   127,     4,   492,    27,   626,   254,    11,   687,
      27,    78,     4,   483,   281,   485,   629,     8,   396,     8,
       8,   896,    29,    30,   243,    27,     8,     8,    27,     8,
       8,     8,   506,    27,   808,   816,    53,    44,    50,     8,
     718,     8,    62,    62,     8,     8,     8,    50,     8,     8,
       8,    74,     8,   300,     8,     8,     8,    74,    72,    74,
      77,    72,    62,    55,    72,    62,   313,   314,    72,    62,
     369,    32,     0,    91,     0,   146,   323,   154,   325,   150,
     299,    32,    72,    27,    74,    75,    72,   212,    74,    74,
     146,    99,   100,   222,   150,   146,   154,   226,   412,   150,
      46,    47,    48,   573,    50,   154,   173,    27,   237,   176,
     239,   240,   241,    74,    99,    62,   120,   119,   249,   250,
      62,   144,   145,    74,   255,   154,   146,   144,   154,   910,
      79,    72,   150,   125,   154,   154,   150,   157,   157,   150,
     152,   158,   150,   157,   159,    74,   163,    72,   922,    43,
      44,    45,    46,    47,    48,   152,    50,   157,   157,   633,
     941,   635,   156,  1038,   157,   156,   157,   156,   156,   171,
     301,   157,   303,   159,   156,   156,   183,   156,   156,   156,
     399,   182,   185,   200,   201,   202,   564,   156,    72,   156,
     207,   155,   155,   155,   143,   155,   155,   155,   215,   155,
      74,   155,   155,   155,   146,    72,   152,    32,   225,   150,
       8,   228,    62,   216,   217,   157,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   475,    62,
     159,    43,    44,    45,    46,    47,    48,   850,    46,    47,
      48,   155,   156,    17,    18,   492,    72,    72,   120,    74,
      62,    62,   254,    27,    62,    53,    54,    62,   152,   281,
     120,   128,   129,    63,   281,   154,   150,    91,   154,   739,
      72,    72,    72,   587,    74,   125,    72,    91,    74,   281,
     147,   154,   581,   150,   109,   159,   154,    72,   419,    74,
      74,   154,   125,   154,   311,    79,   155,   156,   300,    91,
     157,   921,   127,    72,   321,    72,   309,    74,    72,   109,
     254,   313,   314,   109,   125,    72,    72,    74,    17,    18,
     125,   323,   147,   325,   109,   150,   150,   815,    27,   330,
     347,   630,    94,    95,   159,   352,   150,   281,   605,   356,
     152,   156,   409,   562,   152,   362,   147,   147,    74,   150,
     150,   147,   369,   120,   150,   153,   300,   155,   150,   159,
     144,   145,   147,   159,    62,   150,   383,    94,    95,   313,
     314,    72,   157,    74,   159,    62,   595,   596,   162,   323,
      32,   325,    62,  1061,   158,    91,    72,   686,   607,   608,
     157,   147,   159,   146,   150,   412,   158,    91,    62,   713,
     157,   146,   159,   404,   146,   150,   409,   146,   109,   154,
     125,   150,   404,    62,   150,   154,    99,   143,   144,   145,
     156,   157,    53,    54,   426,   913,   127,    67,    68,    69,
     150,   158,   150,   207,    72,    74,    74,    67,    68,   456,
      79,   215,   128,   129,   150,   152,   147,    67,    68,   150,
     146,   225,    74,    67,    68,    69,   150,    79,   159,   158,
     160,   147,    74,     8,   150,    74,   483,    79,   485,   155,
      79,   109,   146,   475,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
     492,   508,   509,   510,   511,   512,   150,   498,    93,    94,
      95,   518,   519,    62,   143,   144,   145,   281,   207,   147,
      74,   825,   150,   150,   531,    79,   215,   146,   535,   254,
     146,   159,   144,   145,   156,   157,   225,   125,   545,    17,
      18,   475,   144,   145,   143,   144,   145,    93,    94,    95,
      27,   146,    14,   350,   154,   150,   157,    99,   492,   154,
      93,    94,    95,   156,   853,   156,   573,   109,   110,   111,
     112,   113,   114,   158,   581,   300,   583,    14,   815,   883,
     587,    82,    83,   347,   155,   592,   155,   155,   313,   314,
     144,   145,   281,   605,    93,    94,    95,   158,   605,   161,
      72,   154,    72,   152,   123,   369,    72,    62,    27,   724,
     160,   156,   158,   605,    83,     8,   737,    91,    72,   383,
      72,   628,   629,   630,    74,   622,   835,   155,   155,   933,
     109,   110,   111,   112,   113,   114,   156,   644,    72,   646,
      62,   632,   158,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
      14,   605,   123,   977,   160,   979,   913,   160,   154,   686,
     687,   154,    14,   154,    72,   692,   154,   976,    72,   156,
     154,   150,   456,   814,   383,   160,   493,   690,   156,   160,
     160,   990,   146,    72,   711,   158,   713,  1011,    14,   154,
     156,   718,   154,   154,   707,   158,   155,   150,   124,   483,
     160,   485,   157,   154,    72,     8,   143,   103,   160,  1018,
      72,    72,   739,  1022,    14,  1039,   160,   158,     8,   155,
       8,   748,   157,   155,   508,   509,   510,   511,   512,   154,
      84,   126,   156,   156,   154,   519,   877,   764,    14,   766,
     156,   155,   154,  1067,   155,   125,   155,   456,   158,   776,
     156,  1060,   151,   106,    62,    62,   125,   160,   156,    90,
     104,   545,   155,  1087,   155,   157,   907,   908,   156,   154,
     160,    72,    74,   100,   483,   157,   485,    27,    69,   106,
     156,   808,   109,   110,   111,   112,   113,   114,   115,   573,
     157,    14,    74,    72,   160,    14,    27,   581,   825,   156,
     160,   160,   829,   815,   100,   155,   623,    14,   157,    72,
     106,    14,   947,   109,   110,   111,   112,   113,   114,   115,
     158,   605,    74,   850,   158,   842,   853,    69,    74,   158,
      91,   158,   843,   158,   156,    91,   545,   107,   156,   866,
     146,    74,   155,    88,   628,   629,   630,   158,    72,    14,
     154,   156,    74,     8,    72,    72,   883,    86,   157,   156,
     644,   815,   158,   155,   573,   158,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   895,   158,   922,   605,   103,   915,   154,
      74,   913,   686,   157,   931,   158,   933,   155,   692,   535,
    1085,   545,   362,   531,   713,   752,   966,   857,   829,   628,
     629,    11,   707,   824,   367,  1011,    78,    17,    18,   878,
     832,   644,   207,   870,   939,   404,   404,   220,   755,   692,
     643,    -1,   690,    -1,    -1,    -1,    -1,    -1,    -1,   976,
     977,   962,   979,    -1,    -1,   739,    -1,    -1,    -1,   913,
      50,     8,    -1,   990,   748,    -1,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
     764,    -1,   766,   692,  1011,    -1,    -1,    -1,    -1,    -1,
      -1,  1018,   776,    -1,    -1,  1022,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,
      -1,    -1,  1039,    -1,    -1,    -1,    -1,    -1,    -1,  1030,
      -1,    -1,    -1,    -1,   808,    -1,    -1,    -1,    -1,    -1,
     739,    -1,    -1,  1060,  1061,    -1,    -1,    -1,    -1,   748,
    1067,    -1,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
    1087,    -1,    -1,    -1,    -1,    -1,   850,    -1,   158,   853,
       4,     5,     6,    -1,     8,     9,    10,    11,    12,    13,
      14,    15,   866,    53,    54,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    28,   185,    -1,    -1,    -1,   808,
      -1,    -1,    -1,    -1,    38,    -1,   153,    -1,   155,    -1,
      -1,    45,    46,   930,    -1,    -1,    50,   207,    52,    -1,
      -1,    -1,    -1,    -1,    -1,   215,   216,   217,    -1,    -1,
      -1,    -1,    -1,    -1,   951,   225,   953,    -1,   922,    10,
      11,   850,    -1,   960,    78,    -1,    -1,   931,    -1,    -1,
      -1,   968,    -1,    -1,    -1,    26,   973,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      -1,    -1,   999,   153,    -1,   155,   156,    -1,  1005,    -1,
      -1,    -1,   976,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   990,   141,    -1,    -1,
      -1,    -1,  1029,   922,    -1,    -1,    -1,    -1,    -1,   309,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1049,    -1,  1018,    -1,    -1,    -1,  1022,   173,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,   182,    -1,
     184,   185,    -1,    -1,  1071,    -1,    -1,    -1,    -1,    -1,
    1077,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     347,    -1,    -1,    -1,    -1,    -1,  1060,  1094,    -1,    -1,
      -1,   152,   216,   217,    -1,    -1,   220,    -1,    -1,    -1,
     224,    -1,   369,   383,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,
      -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,    -1,   282,    -1,
      -1,    -1,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,    -1,   456,    -1,    -1,    -1,
     304,    -1,    -1,    -1,    -1,   309,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   317,    -1,   319,     9,    10,    11,    -1,
      -1,    -1,    -1,   483,    -1,   485,   330,    -1,    -1,   333,
      -1,    -1,    -1,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,    -1,
     364,   508,   509,   510,   511,   512,    -1,    -1,    -1,    -1,
      -1,    -1,   519,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,   545,    50,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
     404,    -1,    -1,    -1,    -1,   409,    -1,    -1,    -1,    -1,
      -1,    -1,    62,   573,    -1,    -1,    -1,    -1,   422,     9,
      10,    11,    -1,    -1,   428,    -1,   430,    -1,   432,   433,
     434,    -1,    -1,    -1,   581,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,   152,
      50,    -1,    -1,    -1,    -1,    -1,    -1,   160,   628,   629,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   630,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,   644,    -1,    -1,
      -1,    -1,   152,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     690,    -1,   692,    -1,    -1,    -1,    -1,    -1,    -1,   686,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   707,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   559,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,   158,    -1,
     574,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   739,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   748,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   601,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   618,    -1,    -1,   764,    -1,   766,
      -1,    -1,   626,   627,    -1,    -1,    -1,    -1,   632,   776,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    -1,    -1,    -1,    -1,    26,   808,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    62,    -1,    -1,   690,    -1,    -1,    -1,
     850,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   707,    -1,    -1,   853,    -1,    -1,    53,
      54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   866,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    -1,    -1,   738,    -1,   508,   509,   510,   511,
     512,   153,    -1,   155,   156,    -1,    -1,   519,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   760,    -1,    -1,    -1,
      -1,    -1,   922,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   160,    -1,    26,   931,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,   810,    50,    -1,   153,
      -1,    -1,   156,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,   831,    -1,   976,
     153,    -1,   155,    -1,    -1,    -1,    -1,    -1,    -1,   843,
      -1,    -1,    -1,   990,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1018,   644,    -1,    -1,  1022,    -1,    -1,   650,   651,
     652,   653,   654,   655,   656,   657,   658,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,   669,   670,   671,
     672,   673,   674,   675,   676,    -1,     9,    10,    11,   152,
      -1,    -1,    -1,  1060,    -1,   158,    -1,   921,    -1,    -1,
      -1,    -1,    -1,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,     9,
      10,    11,   153,    -1,    -1,    -1,    -1,    -1,   962,    -1,
      -1,   965,   966,    -1,    -1,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    -1,   764,    -1,   766,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   776,    -1,    -1,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1030,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    43,    44,   152,
      -1,    -1,   155,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    -1,    -1,    -1,    70,    71,    72,    73,    74,    -1,
      76,    -1,    -1,    -1,    80,    81,    82,    83,    -1,    85,
      -1,    87,   152,    89,   866,    -1,    92,    -1,   158,    -1,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,   105,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
       3,     4,     5,     6,     7,    -1,   142,    -1,   152,    12,
      13,   147,   148,   149,   150,    -1,    -1,    -1,   154,   931,
     156,   157,    -1,   159,    -1,   161,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    -1,    76,    -1,    -1,    -1,    80,    81,    82,
      83,    -1,    85,    -1,    87,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    96,    97,    98,    99,    -1,   101,   102,
      -1,    -1,   105,    -1,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,   127,   128,    -1,   130,   131,   132,
     133,   134,   135,     3,     4,     5,     6,     7,    -1,   142,
      -1,    -1,    12,    13,   147,   148,   149,   150,    -1,    -1,
      -1,   154,    -1,   156,   157,    -1,   159,    27,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    -1,    76,    -1,    -1,    -1,
      80,    81,    82,    83,    -1,    85,    -1,    87,    -1,    89,
      -1,    -1,    92,    -1,    -1,    -1,    96,    97,    98,    99,
      -1,   101,   102,    -1,    -1,   105,    -1,    -1,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,     3,     4,     5,     6,
       7,    -1,   142,    -1,    -1,    12,    13,   147,   148,   149,
     150,    -1,    -1,    -1,   154,    -1,   156,   157,    -1,   159,
      27,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    -1,    76,
      -1,    -1,    -1,    80,    81,    82,    83,    -1,    85,    -1,
      87,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,
      97,    98,    99,    -1,   101,   102,    -1,    -1,   105,    -1,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,    -1,   130,   131,   132,   133,   134,   135,     3,
       4,     5,     6,     7,    -1,   142,    -1,    -1,    12,    13,
     147,   148,   149,   150,    -1,    -1,    -1,   154,    -1,   156,
     157,    -1,   159,    27,   161,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    -1,    76,    -1,    -1,    -1,    80,    81,    82,    83,
      -1,    85,    -1,    87,    -1,    89,    -1,    -1,    92,    -1,
      -1,    -1,    96,    97,    98,    99,    -1,   101,   102,    -1,
      -1,   105,    -1,    -1,   108,   109,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,     3,     4,     5,     6,     7,    -1,   142,    -1,
      -1,    12,    13,   147,   148,   149,   150,    -1,    -1,    -1,
     154,    -1,   156,   157,    -1,   159,    27,   161,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    85,    -1,    87,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,    96,    97,    98,    99,    -1,
     101,   102,    -1,    -1,   105,    -1,    -1,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,   130,
     131,   132,   133,   134,   135,     3,     4,     5,     6,     7,
      -1,   142,    -1,    -1,    12,    13,   147,   148,   149,   150,
      -1,    -1,    -1,   154,    -1,   156,   157,    -1,   159,    -1,
     161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    -1,    76,    -1,
      -1,    -1,    80,    81,    82,    83,    -1,    85,    -1,    87,
      -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    96,    97,
      98,    99,    -1,   101,   102,    -1,    -1,   105,    -1,    -1,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,     3,     4,
       5,     6,     7,    -1,   142,    -1,    -1,    12,    13,   147,
     148,   149,   150,    -1,    -1,    -1,   154,    -1,   156,   157,
      -1,   159,    -1,   161,   162,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,    -1,    53,    54,    -1,    -1,    -1,
      -1,    -1,   127,   128,    -1,   130,   131,   132,   133,   134,
     135,     3,     4,     5,     6,     7,    -1,   142,    -1,    -1,
      12,    13,   147,   148,   149,   150,   151,    -1,    -1,   154,
     155,    -1,    -1,    91,   159,    -1,   161,   162,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,     3,     4,     5,     6,     7,    -1,
     142,    -1,    -1,    12,    13,   147,   148,   149,   150,   151,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,
     162,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    62,    -1,    -1,    -1,    -1,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,   130,   131,   132,   133,   134,   135,     3,     4,     5,
       6,     7,    -1,   142,    -1,    -1,    12,    13,   147,   148,
     149,   150,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,    -1,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    -1,    -1,   152,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    99,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
       3,     4,     5,     6,     7,    -1,   142,    -1,    -1,    12,
      13,   147,   148,   149,   150,    -1,    -1,    -1,   154,    -1,
     156,    -1,    -1,   159,    -1,   161,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    -1,    -1,    -1,   152,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    -1,    -1,    80,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    62,    -1,
      -1,    -1,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   127,   128,    -1,   130,   131,   132,
     133,   134,   135,     3,     4,     5,     6,     7,    -1,   142,
      -1,    -1,    12,    13,   147,   148,   149,   150,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,   159,    -1,   161,   162,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,
      -1,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    -1,   152,    -1,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,
      80,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    99,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,
     130,   131,   132,   133,   134,   135,     3,     4,     5,     6,
       7,    -1,   142,    -1,    -1,    12,    13,   147,   148,   149,
     150,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,   159,
      -1,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    -1,    49,    -1,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
     152,    -1,    -1,    70,    71,    72,    73,    74,    -1,    -1,
      -1,    -1,    -1,    80,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     127,   128,    -1,   130,   131,   132,   133,   134,   135,     3,
       4,     5,     6,     7,    -1,   142,    -1,    -1,    12,    13,
     147,   148,   149,   150,    -1,    -1,    -1,   154,   155,    -1,
      -1,    -1,   159,    -1,   161,   162,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    -1,   152,    -1,    -1,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    -1,    -1,    80,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    -1,    99,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    62,    -1,    -1,    -1,
      -1,    -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   127,   128,    -1,   130,   131,   132,   133,
     134,   135,     3,     4,     5,     6,     7,    -1,   142,    -1,
      -1,    12,    13,   147,   148,   149,   150,    -1,    -1,    -1,
     154,    -1,    -1,    -1,    -1,   159,    -1,   161,   162,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    -1,   152,    -1,    -1,    70,
      71,    72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   127,   128,    -1,   130,
     131,   132,   133,   134,   135,     3,     4,     5,     6,     7,
      -1,   142,    -1,    -1,    12,    13,   147,   148,   149,   150,
      -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,
     161,   162,    -1,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      -1,    49,    -1,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,
     128,    -1,   130,   131,   132,   133,   134,   135,     3,     4,
       5,     6,     7,    -1,   142,    -1,    -1,    12,    13,   147,
     148,   149,   150,    -1,    -1,    -1,   154,    -1,    -1,    -1,
      -1,   159,    -1,   161,   162,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   127,   128,    -1,   130,   131,   132,   133,   134,
     135,     3,     4,     5,     6,     7,    -1,   142,    -1,    -1,
      12,    13,   147,   148,   149,   150,    -1,    -1,    -1,   154,
      -1,    -1,    -1,    -1,   159,    -1,   161,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   127,   128,    -1,   130,   131,
     132,   133,   134,   135,     3,     4,     5,     6,     7,    -1,
     142,    -1,    -1,    12,    13,   147,   148,   149,   150,    -1,
      -1,    -1,   154,    -1,    -1,    -1,    -1,   159,    -1,   161,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      49,    -1,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   127,   128,
      -1,   130,   131,   132,   133,   134,   135,     3,     4,     5,
       6,     7,    -1,   142,    -1,    -1,    12,    13,   147,   148,
     149,   150,    -1,    -1,    -1,   154,    -1,    -1,    -1,    -1,
     159,    -1,   161,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    49,    -1,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   127,   128,    -1,   130,   131,   132,   133,   134,   135,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,   147,   148,   149,   150,     9,    10,    11,   154,    -1,
      -1,    -1,    -1,   159,    -1,   161,   162,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,   158,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    -1,    -1,    -1,   158,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,   158,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    -1,    -1,    -1,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    26,   156,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    26,   156,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,    -1,    -1,    26,   156,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    -1,    -1,    -1,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,    -1,    26,   156,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    -1,     9,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,
      -1,    -1,   152,    -1,    -1,    26,   156,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      -1,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   152,    -1,    -1,   155,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
      -1,    -1,   155,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,    26,    -1,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   152,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,   126,    26,
      -1,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,   152,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     9,    10,    11,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,   126,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,     9,    10,    11,    -1,   152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,   126,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       9,    10,    11,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    -1,    -1,    -1,    26,    -1,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,   126,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    10,
      11,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    26,    -1,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    11,    -1,
      -1,    -1,    -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    26,    -1,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      -1,    49,   152,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,
     128,    -1,   130,   131,   132,   133,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,   147,
     148,   149,   150,    -1,    -1,    26,   154,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    26,    50,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   152,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,   152,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    62,   152,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    -1,   152,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    43,    44,    -1,    -1,    -1,    -1,    49,    -1,
      51,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    62,    -1,    -1,    -1,   152,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   152,    -1,    -1,    -1,    -1,   128,    -1,   130,
     131,   132,   133,   134,   135,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,    -1,    -1,   152,   147,   148,   149,   150,
      -1,    -1,    -1,   154
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   164,   165,     0,   166,     3,     4,     5,     6,     7,
      12,    13,    43,    44,    49,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    70,    71,    72,    73,    74,    76,    80,    81,    82,
      83,    85,    87,    89,    92,    96,    97,    98,    99,   100,
     101,   102,   105,   106,   108,   109,   110,   111,   116,   117,
     118,   119,   120,   121,   122,   127,   128,   130,   131,   132,
     133,   134,   135,   142,   147,   148,   149,   150,   154,   156,
     157,   159,   161,   162,   167,   168,   177,   181,   182,   216,
     217,   220,   222,   225,   227,   293,   295,   309,   310,   311,
     312,   315,   324,   335,   340,   341,   345,   346,   347,   349,
     350,   360,   361,   362,   363,   365,   366,   367,   368,   374,
     384,   388,   390,    13,    72,   109,   147,   312,   345,   345,
     154,   345,   345,   345,   295,   345,   350,   345,   345,   345,
     345,   306,   109,   147,   150,   167,   324,   349,   350,   362,
     349,   345,   345,   345,   345,   345,   345,   345,    32,   345,
     378,   379,   147,   150,   167,   324,   326,   327,   362,   366,
     367,   374,   345,   154,   332,   346,   154,   346,    27,    62,
     283,   345,   189,   187,   154,   154,   199,   346,   156,   345,
     156,   345,    72,    72,   156,   295,   345,   350,   200,   345,
      99,   100,   150,   167,   171,   172,    74,   159,   257,   258,
      74,   259,   312,   120,   120,   154,   154,   154,   154,   154,
     154,    74,    79,   143,   144,   145,   380,   381,   150,   157,
     167,   167,   293,   309,   345,   178,   157,    79,   333,   380,
      79,   380,   150,   316,     8,   156,    72,    72,   156,    62,
      62,    32,   218,   364,   146,    62,     9,    10,    11,    26,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    50,   152,   156,    53,    54,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,   153,   323,
     146,    62,   125,    62,   157,   159,   367,   218,   345,   126,
     345,   150,   167,   146,   146,   348,   350,   126,   160,     8,
     343,   150,   167,   146,   294,   146,   125,   367,   155,    27,
     183,   345,   369,     8,   156,   181,   346,   284,   285,   345,
     295,   350,   154,   194,   156,   156,   156,    14,   156,   156,
     157,   156,   150,   167,   173,   174,   150,   167,   175,   176,
     167,    91,     8,   156,   157,   347,   350,     8,   156,    14,
       8,   156,   218,   214,   215,   350,   295,   350,   385,   387,
     295,   350,   155,   296,   378,    62,   125,   143,   381,    73,
     345,   350,    79,   143,   381,   167,   170,   156,   157,   318,
     155,   155,   155,   158,   179,   345,   161,   162,    72,   154,
     254,    72,   123,   226,   224,   369,   369,    72,   307,    62,
      72,   120,   157,   360,   367,   373,   374,   369,   300,   345,
     301,    27,   303,   298,   299,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   326,   345,    32,   345,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     254,    72,   360,   373,   369,   351,   369,   345,   155,   295,
     350,   167,    72,    32,   345,    32,   345,   167,   360,   254,
     334,   360,   328,   185,   181,   160,   345,    83,   188,   156,
       8,    91,    91,    72,   237,    27,   157,   238,    43,    44,
      49,    51,    62,    80,   128,   130,   142,   147,   150,   154,
     167,   324,   335,   336,   337,   338,   339,   389,   178,   167,
      91,     8,   156,   167,    91,     8,   156,    91,    72,   172,
     345,   258,   337,    74,   308,     8,   155,     8,   155,   155,
     155,   156,   127,   350,   375,   376,   155,   382,    72,    62,
     158,   158,   317,   165,   169,   254,   302,   119,   180,   181,
     216,   217,   158,    32,   151,   155,   255,   256,   295,   309,
     350,    14,   147,   150,   167,   325,   223,   123,   228,   160,
     160,   221,   154,   369,   345,   320,   319,   367,   160,   345,
     345,   305,   345,   345,   345,    63,   350,   322,   321,   160,
     360,   370,   372,   373,   160,   158,   348,   348,   126,   370,
     178,   184,   190,    27,   181,   243,   191,   286,   197,   195,
      14,     8,   155,   156,   239,   156,   239,   338,   338,   338,
     338,   338,   342,   344,   154,    79,   150,   167,   338,   146,
       9,    10,    11,    26,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    62,   152,   158,    91,    72,
     174,    91,    72,   176,    72,   158,    14,   154,   215,   156,
     386,   154,     8,   155,    72,    74,    75,   383,   345,   254,
     158,   165,   291,   292,   154,   348,   345,     8,   155,   155,
     337,   150,   167,   124,   229,   230,   325,   157,   154,   128,
     129,   250,   251,   252,   253,   325,   160,   158,   254,   254,
     345,    27,   326,   254,   254,   371,   352,    62,   157,    32,
     345,   329,   186,   244,   346,   178,   284,   345,    32,   127,
     232,   350,   232,   337,    72,    27,   181,   236,   239,    93,
      94,    95,   239,   158,   126,   160,     8,   343,   342,   167,
     155,    72,   120,   338,   338,   338,    27,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   103,   202,    72,    72,   337,   250,   387,   377,   376,
      14,   160,   160,   158,    62,   125,   287,   288,   289,   354,
     155,   256,   167,   230,   157,     8,   260,   250,   155,     8,
     218,   304,   297,   356,   357,   358,   359,   369,   345,   348,
     330,   246,    67,    68,   248,   156,    84,   156,   350,   154,
     126,   231,   231,    14,   178,    93,   156,   345,    27,   156,
     242,   158,   338,   338,   155,   338,    27,   160,   154,   201,
     155,   375,   345,   158,   369,   370,   354,    62,   290,   156,
     260,   325,   100,   106,   109,   110,   111,   112,   113,   114,
     115,   158,   261,   264,   277,   278,   279,   280,   282,   155,
     106,   313,   252,   151,   219,   345,   334,    62,    62,   254,
     353,   160,   158,   125,   331,    67,    68,   249,   346,   181,
     156,   192,   233,   232,   155,   155,   337,    90,   156,   242,
     241,   126,   338,   203,   104,   207,   313,   155,   160,   355,
     369,   287,   158,    72,   265,   325,   262,   312,   280,     8,
     156,   157,   154,   157,    74,   369,   369,   354,   370,   346,
      27,    69,   245,   284,   375,   198,   196,   156,   240,   178,
     338,   325,   208,   157,   359,   160,    14,     8,   156,   157,
     266,    74,   281,   218,    72,   178,    32,    74,   314,   178,
      14,   160,   160,    27,   178,   156,   181,   155,   155,    27,
     181,   235,   235,   178,   204,   157,   178,   337,   325,    72,
     267,   268,   269,   270,   272,   273,   274,   325,    14,     8,
     156,    72,    14,   158,    74,     8,   155,   158,   337,   247,
     193,   178,    74,   178,   158,   158,   269,   156,    91,   107,
     156,   146,   337,    74,   263,   337,    32,    74,   178,    27,
     181,   234,    88,   155,   158,   275,   280,   271,   325,    72,
      14,   154,    74,   178,   156,   205,    72,     8,   337,   250,
      86,   157,   325,   155,   156,   178,   156,   157,   276,   158,
     178,   206,   158,   103,   209,   210,   211,   154,   211,   325,
     212,    74,   155,   213,   157,   178,   158
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   163,   164,   166,   165,   165,   167,   167,   168,   168,
     168,   168,   168,   169,   168,   170,   168,   168,   168,   168,
     168,   171,   171,   172,   172,   172,   172,   173,   173,   174,
     174,   174,   174,   175,   175,   176,   176,   176,   176,   177,
     177,   179,   178,   178,   180,   180,   180,   180,   181,   181,
     182,   183,   184,   182,   185,   186,   182,   187,   188,   182,
     189,   190,   182,   191,   192,   193,   182,   194,   182,   182,
     182,   182,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   182,   182,   195,   196,   182,   197,   198,   182,   199,
     182,   182,   200,   201,   182,   182,   182,   202,   203,   204,
     205,   206,   202,   207,   208,   207,   209,   209,   210,   210,
     212,   213,   211,   214,   214,   215,   216,   217,   218,   218,
     219,   219,   221,   220,   223,   222,   224,   222,   225,   225,
     225,   225,   226,   226,   227,   228,   228,   229,   229,   230,
     230,   231,   231,   232,   232,   233,   232,   234,   234,   235,
     235,   236,   236,   237,   237,   238,   238,   238,   238,   239,
     240,   239,   241,   239,   242,   242,   243,   243,   244,   245,
     244,   246,   247,   246,   248,   248,   249,   249,   250,   250,
     251,   251,   252,   252,   253,   253,   253,   253,   254,   254,
     254,   255,   255,   256,   256,   256,   256,   257,   257,   258,
     258,   258,   259,   259,   259,   259,   260,   260,   262,   261,
     261,   261,   263,   261,   264,   265,   265,   266,   266,   267,
     267,   268,   268,   269,   269,   270,   271,   271,   272,   272,
     273,   274,   274,   275,   275,   276,   276,   277,   277,   278,
     278,   279,   279,   280,   280,   280,   280,   280,   280,   281,
     281,   281,   281,   282,   282,   283,   283,   284,   284,   286,
     285,   285,   287,   287,   288,   288,   290,   289,   289,   289,
     291,   292,   291,   294,   293,   296,   295,   295,   295,   297,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   298,   295,
     299,   295,   300,   295,   301,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   302,   295,   303,   304,   295,   305,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     306,   295,   295,   295,   295,   295,   295,   295,   307,   295,
     308,   295,   309,   309,   309,   309,   310,   310,   310,   310,
     311,   311,   312,   313,   313,   314,   314,   314,   314,   316,
     315,   317,   315,   318,   315,   319,   315,   320,   315,   321,
     315,   322,   315,   323,   315,   324,   324,   324,   324,   325,
     325,   325,   326,   326,   328,   329,   327,   327,   330,   330,
     331,   332,   332,   332,   333,   333,   333,   334,   334,   335,
     335,   335,   335,   335,   335,   335,   335,   335,   335,   335,
     335,   336,   337,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   340,   340,   340,   340,
     341,   341,   341,   341,   341,   341,   341,   342,   342,   343,
     343,   344,   344,   344,   344,   345,   345,   346,   346,   347,
     348,   349,   351,   352,   350,   350,   353,   353,   355,   354,
     356,   356,   358,   357,   359,   359,   359,   360,   360,   361,
     361,   362,   363,   364,   363,   365,   365,   365,   366,   366,
     366,   367,   367,   367,   368,   368,   369,   369,   370,   371,
     370,   372,   372,   372,   373,   373,   374,   374,   375,   375,
     376,   377,   376,   376,   378,   378,   379,   379,   379,   379,
     379,   379,   379,   379,   380,   380,   380,   380,   381,   382,
     381,   381,   381,   381,   381,   383,   383,   383,   384,   384,
     384,   384,   384,   384,   384,   384,   385,   386,   385,   387,
     387,   388,   388,   389,   390
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     3,     0,     1,     3,     1,     1,
       1,     4,     3,     0,     6,     0,     5,     3,     4,     4,
       2,     3,     1,     1,     3,     2,     4,     3,     1,     1,
       3,     2,     4,     3,     1,     1,     3,     2,     4,     5,
       4,     0,     3,     0,     1,     1,     1,     4,     1,     2,
       3,     0,     0,     7,     0,     0,    10,     0,     0,     5,
       0,     0,     7,     0,     0,     0,    12,     0,     4,     2,
       3,     2,     3,     2,     3,     3,     2,     3,     3,     3,
       1,     2,     5,     0,     0,    10,     0,     0,    10,     0,
       6,     1,     0,     0,     8,     3,     3,     0,     0,     0,
       0,     0,    13,     0,     0,     5,     1,     0,     1,     2,
       0,     0,    10,     1,     3,     1,     1,     1,     0,     1,
       0,     1,     0,    10,     0,     8,     0,     7,     1,     2,
       1,     2,     0,     2,     1,     0,     2,     0,     2,     1,
       3,     0,     2,     1,     2,     0,     5,     1,     4,     1,
       4,     1,     4,     3,     5,     3,     4,     4,     5,     0,
       0,     6,     0,     5,     1,     1,     1,     4,     0,     0,
       5,     0,     0,     6,     0,     2,     0,     3,     1,     0,
       1,     3,     4,     6,     0,     1,     1,     1,     2,     3,
       3,     1,     3,     1,     1,     2,     2,     3,     1,     1,
       2,     4,     3,     5,     1,     3,     2,     0,     0,     4,
       2,     1,     0,     9,     3,     1,     3,     1,     3,     0,
       1,     1,     2,     2,     2,     3,     1,     3,     1,     1,
       3,     4,     3,     0,     1,     1,     3,     1,     1,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     3,
       5,     1,     3,     5,     4,     3,     1,     0,     1,     0,
       4,     1,     2,     1,     4,     3,     0,     3,     1,     1,
       0,     0,     2,     0,     4,     0,     7,     3,     4,     0,
       7,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     0,     4,
       0,     4,     0,     4,     0,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     0,     5,     0,     0,     7,     0,
       5,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       0,     3,     1,     1,     1,     3,     2,     1,     0,    10,
       0,    11,     2,     2,     4,     4,     4,     4,     4,     4,
       4,     3,     1,     0,     4,     3,     4,     1,     2,     0,
       3,     0,     5,     0,     4,     0,     5,     0,     5,     0,
       5,     0,     5,     0,     3,     1,     1,     3,     2,     1,
       3,     2,     1,     1,     0,     0,     6,     1,     2,     0,
       2,     0,     2,     1,     0,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     3,     1,     1,     1,     1,     3,     2,     4,     3,
       1,     1,     1,     4,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     5,     2,     2,     3,     1,     1,     3,     2,
       1,     1,     1,     1,     3,     3,     1,     0,     2,     0,
       1,     5,     3,     3,     1,     1,     1,     3,     3,     1,
       1,     1,     0,     0,     7,     1,     2,     0,     0,     4,
       4,     4,     0,     2,     1,     1,     0,     1,     2,     3,
       3,     1,     4,     0,     5,     1,     1,     1,     1,     2,
       1,     4,     4,     1,     1,     4,     0,     1,     1,     0,
       2,     4,     4,     1,     1,     3,     1,     2,     3,     1,
       1,     0,     5,     0,     0,     2,     5,     3,     3,     1,
       6,     4,     4,     2,     2,     2,     1,     2,     1,     0,
       5,     3,     3,     6,     3,     1,     1,     1,     4,     4,
       4,     2,     2,     4,     2,     2,     1,     0,     4,     1,
       1,     3,     3,     3,     3
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

  if (yychar <= END)
    {
      yychar = END;
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
  case 2: /* start: top_statement_list  */
#line 223 "Zend/zend_language_parser.y"
                                { zend_do_end_compilation(TSRMLS_C); }
#line 3445 "Zend/zend_language_parser.c"
    break;

  case 3: /* $@1: %empty  */
#line 227 "Zend/zend_language_parser.y"
                                    { zend_do_extended_info(TSRMLS_C); }
#line 3451 "Zend/zend_language_parser.c"
    break;

  case 4: /* top_statement_list: top_statement_list $@1 top_statement  */
#line 227 "Zend/zend_language_parser.y"
                                                                                       { HANDLE_INTERACTIVE(); }
#line 3457 "Zend/zend_language_parser.c"
    break;

  case 6: /* namespace_name: "identifier (T_STRING)"  */
#line 232 "Zend/zend_language_parser.y"
                         { yyval = yyvsp[0]; }
#line 3463 "Zend/zend_language_parser.c"
    break;

  case 7: /* namespace_name: namespace_name "\\ (T_NS_SEPARATOR)" "identifier (T_STRING)"  */
#line 233 "Zend/zend_language_parser.y"
                                                       { zend_do_build_namespace_name(&yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 3469 "Zend/zend_language_parser.c"
    break;

  case 8: /* top_statement: statement  */
#line 237 "Zend/zend_language_parser.y"
                                                                        { zend_verify_namespace(TSRMLS_C); }
#line 3475 "Zend/zend_language_parser.c"
    break;

  case 9: /* top_statement: function_declaration_statement  */
#line 238 "Zend/zend_language_parser.y"
                                                { zend_verify_namespace(TSRMLS_C); zend_do_early_binding(TSRMLS_C); }
#line 3481 "Zend/zend_language_parser.c"
    break;

  case 10: /* top_statement: class_declaration_statement  */
#line 239 "Zend/zend_language_parser.y"
                                                        { zend_verify_namespace(TSRMLS_C); zend_do_early_binding(TSRMLS_C); }
#line 3487 "Zend/zend_language_parser.c"
    break;

  case 11: /* top_statement: "__halt_compiler (T_HALT_COMPILER)" '(' ')' ';'  */
#line 240 "Zend/zend_language_parser.y"
                                                        { zend_do_halt_compiler_register(TSRMLS_C); YYACCEPT; }
#line 3493 "Zend/zend_language_parser.c"
    break;

  case 12: /* top_statement: "namespace (T_NAMESPACE)" namespace_name ';'  */
#line 241 "Zend/zend_language_parser.y"
                                                { zend_do_begin_namespace(&yyvsp[-1], 0 TSRMLS_CC); }
#line 3499 "Zend/zend_language_parser.c"
    break;

  case 13: /* $@2: %empty  */
#line 242 "Zend/zend_language_parser.y"
                                                { zend_do_begin_namespace(&yyvsp[-1], 1 TSRMLS_CC); }
#line 3505 "Zend/zend_language_parser.c"
    break;

  case 14: /* top_statement: "namespace (T_NAMESPACE)" namespace_name '{' $@2 top_statement_list '}'  */
#line 243 "Zend/zend_language_parser.y"
                                                    { zend_do_end_namespace(TSRMLS_C); }
#line 3511 "Zend/zend_language_parser.c"
    break;

  case 15: /* $@3: %empty  */
#line 244 "Zend/zend_language_parser.y"
                                                                { zend_do_begin_namespace(NULL, 1 TSRMLS_CC); }
#line 3517 "Zend/zend_language_parser.c"
    break;

  case 16: /* top_statement: "namespace (T_NAMESPACE)" '{' $@3 top_statement_list '}'  */
#line 245 "Zend/zend_language_parser.y"
                                                        { zend_do_end_namespace(TSRMLS_C); }
#line 3523 "Zend/zend_language_parser.c"
    break;

  case 17: /* top_statement: "use (T_USE)" use_declarations ';'  */
#line 246 "Zend/zend_language_parser.y"
                                                { zend_verify_namespace(TSRMLS_C); }
#line 3529 "Zend/zend_language_parser.c"
    break;

  case 18: /* top_statement: "use (T_USE)" "function (T_FUNCTION)" use_function_declarations ';'  */
#line 247 "Zend/zend_language_parser.y"
                                                               { zend_verify_namespace(TSRMLS_C); }
#line 3535 "Zend/zend_language_parser.c"
    break;

  case 19: /* top_statement: "use (T_USE)" "const (T_CONST)" use_const_declarations ';'  */
#line 248 "Zend/zend_language_parser.y"
                                                               { zend_verify_namespace(TSRMLS_C); }
#line 3541 "Zend/zend_language_parser.c"
    break;

  case 20: /* top_statement: constant_declaration ';'  */
#line 249 "Zend/zend_language_parser.y"
                                                        { zend_verify_namespace(TSRMLS_C); }
#line 3547 "Zend/zend_language_parser.c"
    break;

  case 23: /* use_declaration: namespace_name  */
#line 258 "Zend/zend_language_parser.y"
                                                { zend_do_use(&yyvsp[0], NULL TSRMLS_CC); }
#line 3553 "Zend/zend_language_parser.c"
    break;

  case 24: /* use_declaration: namespace_name "as (T_AS)" "identifier (T_STRING)"  */
#line 259 "Zend/zend_language_parser.y"
                                                { zend_do_use(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 3559 "Zend/zend_language_parser.c"
    break;

  case 25: /* use_declaration: "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 260 "Zend/zend_language_parser.y"
                                              { zend_do_use(&yyvsp[0], NULL TSRMLS_CC); }
#line 3565 "Zend/zend_language_parser.c"
    break;

  case 26: /* use_declaration: "\\ (T_NS_SEPARATOR)" namespace_name "as (T_AS)" "identifier (T_STRING)"  */
#line 261 "Zend/zend_language_parser.y"
                                                            { zend_do_use(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 3571 "Zend/zend_language_parser.c"
    break;

  case 29: /* use_function_declaration: namespace_name  */
#line 270 "Zend/zend_language_parser.y"
                                                { zend_do_use_function(&yyvsp[0], NULL TSRMLS_CC); }
#line 3577 "Zend/zend_language_parser.c"
    break;

  case 30: /* use_function_declaration: namespace_name "as (T_AS)" "identifier (T_STRING)"  */
#line 271 "Zend/zend_language_parser.y"
                                                { zend_do_use_function(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 3583 "Zend/zend_language_parser.c"
    break;

  case 31: /* use_function_declaration: "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 272 "Zend/zend_language_parser.y"
                                              { zend_do_use_function(&yyvsp[0], NULL TSRMLS_CC); }
#line 3589 "Zend/zend_language_parser.c"
    break;

  case 32: /* use_function_declaration: "\\ (T_NS_SEPARATOR)" namespace_name "as (T_AS)" "identifier (T_STRING)"  */
#line 273 "Zend/zend_language_parser.y"
                                                            { zend_do_use_function(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 3595 "Zend/zend_language_parser.c"
    break;

  case 35: /* use_const_declaration: namespace_name  */
#line 282 "Zend/zend_language_parser.y"
                                                { zend_do_use_const(&yyvsp[0], NULL TSRMLS_CC); }
#line 3601 "Zend/zend_language_parser.c"
    break;

  case 36: /* use_const_declaration: namespace_name "as (T_AS)" "identifier (T_STRING)"  */
#line 283 "Zend/zend_language_parser.y"
                                                { zend_do_use_const(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 3607 "Zend/zend_language_parser.c"
    break;

  case 37: /* use_const_declaration: "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 284 "Zend/zend_language_parser.y"
                                              { zend_do_use_const(&yyvsp[0], NULL TSRMLS_CC); }
#line 3613 "Zend/zend_language_parser.c"
    break;

  case 38: /* use_const_declaration: "\\ (T_NS_SEPARATOR)" namespace_name "as (T_AS)" "identifier (T_STRING)"  */
#line 285 "Zend/zend_language_parser.y"
                                                            { zend_do_use_const(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 3619 "Zend/zend_language_parser.c"
    break;

  case 39: /* constant_declaration: constant_declaration ',' "identifier (T_STRING)" '=' static_scalar  */
#line 289 "Zend/zend_language_parser.y"
                                                                        { zend_do_declare_constant(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 3625 "Zend/zend_language_parser.c"
    break;

  case 40: /* constant_declaration: "const (T_CONST)" "identifier (T_STRING)" '=' static_scalar  */
#line 290 "Zend/zend_language_parser.y"
                                                   { zend_do_declare_constant(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 3631 "Zend/zend_language_parser.c"
    break;

  case 41: /* $@4: %empty  */
#line 294 "Zend/zend_language_parser.y"
                                      { zend_do_extended_info(TSRMLS_C); }
#line 3637 "Zend/zend_language_parser.c"
    break;

  case 42: /* inner_statement_list: inner_statement_list $@4 inner_statement  */
#line 294 "Zend/zend_language_parser.y"
                                                                                           { HANDLE_INTERACTIVE(); }
#line 3643 "Zend/zend_language_parser.c"
    break;

  case 47: /* inner_statement: "__halt_compiler (T_HALT_COMPILER)" '(' ')' ';'  */
#line 303 "Zend/zend_language_parser.y"
                                              { zend_error_noreturn(E_COMPILE_ERROR, "__HALT_COMPILER() can only be used from the outermost scope"); }
#line 3649 "Zend/zend_language_parser.c"
    break;

  case 48: /* statement: unticked_statement  */
#line 308 "Zend/zend_language_parser.y"
                                   { DO_TICKS(); }
#line 3655 "Zend/zend_language_parser.c"
    break;

  case 49: /* statement: "identifier (T_STRING)" ':'  */
#line 309 "Zend/zend_language_parser.y"
                             { zend_do_label(&yyvsp[-1] TSRMLS_CC); }
#line 3661 "Zend/zend_language_parser.c"
    break;

  case 51: /* $@5: %empty  */
#line 314 "Zend/zend_language_parser.y"
                                      { zend_do_if_cond(&yyvsp[0], &yyvsp[-1] TSRMLS_CC); }
#line 3667 "Zend/zend_language_parser.c"
    break;

  case 52: /* $@6: %empty  */
#line 314 "Zend/zend_language_parser.y"
                                                                                         { zend_do_if_after_statement(&yyvsp[-3], 1 TSRMLS_CC); }
#line 3673 "Zend/zend_language_parser.c"
    break;

  case 53: /* unticked_statement: "if (T_IF)" parenthesis_expr $@5 statement $@6 elseif_list else_single  */
#line 314 "Zend/zend_language_parser.y"
                                                                                                                                                                   { zend_do_if_end(TSRMLS_C); }
#line 3679 "Zend/zend_language_parser.c"
    break;

  case 54: /* $@7: %empty  */
#line 315 "Zend/zend_language_parser.y"
                                          { zend_do_if_cond(&yyvsp[-1], &yyvsp[-2] TSRMLS_CC); }
#line 3685 "Zend/zend_language_parser.c"
    break;

  case 55: /* $@8: %empty  */
#line 315 "Zend/zend_language_parser.y"
                                                                                                        { zend_do_if_after_statement(&yyvsp[-4], 1 TSRMLS_CC); }
#line 3691 "Zend/zend_language_parser.c"
    break;

  case 56: /* unticked_statement: "if (T_IF)" parenthesis_expr ':' $@7 inner_statement_list $@8 new_elseif_list new_else_single "endif (T_ENDIF)" ';'  */
#line 315 "Zend/zend_language_parser.y"
                                                                                                                                                                                                      { zend_do_if_end(TSRMLS_C); }
#line 3697 "Zend/zend_language_parser.c"
    break;

  case 57: /* $@9: %empty  */
#line 316 "Zend/zend_language_parser.y"
                        { yyvsp[0].u.op.opline_num = get_next_op_number(CG(active_op_array)); }
#line 3703 "Zend/zend_language_parser.c"
    break;

  case 58: /* @10: %empty  */
#line 316 "Zend/zend_language_parser.y"
                                                                                                           { zend_do_while_cond(&yyvsp[0], &yyval TSRMLS_CC); }
#line 3709 "Zend/zend_language_parser.c"
    break;

  case 59: /* unticked_statement: "while (T_WHILE)" $@9 parenthesis_expr @10 while_statement  */
#line 316 "Zend/zend_language_parser.y"
                                                                                                                                                                       { zend_do_while_end(&yyvsp[-4], &yyvsp[-1] TSRMLS_CC); }
#line 3715 "Zend/zend_language_parser.c"
    break;

  case 60: /* $@11: %empty  */
#line 317 "Zend/zend_language_parser.y"
                     { yyvsp[0].u.op.opline_num = get_next_op_number(CG(active_op_array));  zend_do_do_while_begin(TSRMLS_C); }
#line 3721 "Zend/zend_language_parser.c"
    break;

  case 61: /* $@12: %empty  */
#line 317 "Zend/zend_language_parser.y"
                                                                                                                                            { yyvsp[0].u.op.opline_num = get_next_op_number(CG(active_op_array)); }
#line 3727 "Zend/zend_language_parser.c"
    break;

  case 62: /* unticked_statement: "do (T_DO)" $@11 statement "while (T_WHILE)" $@12 parenthesis_expr ';'  */
#line 317 "Zend/zend_language_parser.y"
                                                                                                                                                                                                                                   { zend_do_do_while_end(&yyvsp[-6], &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 3733 "Zend/zend_language_parser.c"
    break;

  case 63: /* $@13: %empty  */
#line 321 "Zend/zend_language_parser.y"
                            { zend_do_free(&yyvsp[-1] TSRMLS_CC); yyvsp[0].u.op.opline_num = get_next_op_number(CG(active_op_array)); }
#line 3739 "Zend/zend_language_parser.c"
    break;

  case 64: /* $@14: %empty  */
#line 323 "Zend/zend_language_parser.y"
                            { zend_do_extended_info(TSRMLS_C); zend_do_for_cond(&yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 3745 "Zend/zend_language_parser.c"
    break;

  case 65: /* $@15: %empty  */
#line 325 "Zend/zend_language_parser.y"
                            { zend_do_free(&yyvsp[-1] TSRMLS_CC); zend_do_for_before_statement(&yyvsp[-6], &yyvsp[-3] TSRMLS_CC); }
#line 3751 "Zend/zend_language_parser.c"
    break;

  case 66: /* unticked_statement: "for (T_FOR)" '(' for_expr ';' $@13 for_expr ';' $@14 for_expr ')' $@15 for_statement  */
#line 326 "Zend/zend_language_parser.y"
                                      { zend_do_for_end(&yyvsp[-5] TSRMLS_CC); }
#line 3757 "Zend/zend_language_parser.c"
    break;

  case 67: /* $@16: %empty  */
#line 327 "Zend/zend_language_parser.y"
                                                { zend_do_switch_cond(&yyvsp[0] TSRMLS_CC); }
#line 3763 "Zend/zend_language_parser.c"
    break;

  case 68: /* unticked_statement: "switch (T_SWITCH)" parenthesis_expr $@16 switch_case_list  */
#line 327 "Zend/zend_language_parser.y"
                                                                                                         { zend_do_switch_end(&yyvsp[0] TSRMLS_CC); }
#line 3769 "Zend/zend_language_parser.c"
    break;

  case 69: /* unticked_statement: "break (T_BREAK)" ';'  */
#line 328 "Zend/zend_language_parser.y"
                                                        { zend_do_brk_cont(ZEND_BRK, NULL TSRMLS_CC); }
#line 3775 "Zend/zend_language_parser.c"
    break;

  case 70: /* unticked_statement: "break (T_BREAK)" expr ';'  */
#line 329 "Zend/zend_language_parser.y"
                                                { zend_do_brk_cont(ZEND_BRK, &yyvsp[-1] TSRMLS_CC); }
#line 3781 "Zend/zend_language_parser.c"
    break;

  case 71: /* unticked_statement: "continue (T_CONTINUE)" ';'  */
#line 330 "Zend/zend_language_parser.y"
                                                { zend_do_brk_cont(ZEND_CONT, NULL TSRMLS_CC); }
#line 3787 "Zend/zend_language_parser.c"
    break;

  case 72: /* unticked_statement: "continue (T_CONTINUE)" expr ';'  */
#line 331 "Zend/zend_language_parser.y"
                                                { zend_do_brk_cont(ZEND_CONT, &yyvsp[-1] TSRMLS_CC); }
#line 3793 "Zend/zend_language_parser.c"
    break;

  case 73: /* unticked_statement: "return (T_RETURN)" ';'  */
#line 332 "Zend/zend_language_parser.y"
                                                                        { zend_do_return(NULL, 0 TSRMLS_CC); }
#line 3799 "Zend/zend_language_parser.c"
    break;

  case 74: /* unticked_statement: "return (T_RETURN)" expr_without_variable ';'  */
#line 333 "Zend/zend_language_parser.y"
                                                        { zend_do_return(&yyvsp[-1], 0 TSRMLS_CC); }
#line 3805 "Zend/zend_language_parser.c"
    break;

  case 75: /* unticked_statement: "return (T_RETURN)" variable ';'  */
#line 334 "Zend/zend_language_parser.y"
                                                                { zend_do_return(&yyvsp[-1], 1 TSRMLS_CC); }
#line 3811 "Zend/zend_language_parser.c"
    break;

  case 76: /* unticked_statement: yield_expr ';'  */
#line 335 "Zend/zend_language_parser.y"
                               { zend_do_free(&yyvsp[-1] TSRMLS_CC); }
#line 3817 "Zend/zend_language_parser.c"
    break;

  case 80: /* unticked_statement: T_INLINE_HTML  */
#line 339 "Zend/zend_language_parser.y"
                                                { zend_do_echo(&yyvsp[0] TSRMLS_CC); }
#line 3823 "Zend/zend_language_parser.c"
    break;

  case 81: /* unticked_statement: expr ';'  */
#line 340 "Zend/zend_language_parser.y"
                                                        { zend_do_free(&yyvsp[-1] TSRMLS_CC); }
#line 3829 "Zend/zend_language_parser.c"
    break;

  case 83: /* $@17: %empty  */
#line 343 "Zend/zend_language_parser.y"
                { zend_do_foreach_begin(&yyvsp[-3], &yyvsp[-2], &yyvsp[-1], &yyvsp[0], 1 TSRMLS_CC); }
#line 3835 "Zend/zend_language_parser.c"
    break;

  case 84: /* $@18: %empty  */
#line 344 "Zend/zend_language_parser.y"
                                                          { zend_do_foreach_cont(&yyvsp[-7], &yyvsp[-6], &yyvsp[-4], &yyvsp[-2], &yyvsp[-1] TSRMLS_CC); }
#line 3841 "Zend/zend_language_parser.c"
    break;

  case 85: /* unticked_statement: "foreach (T_FOREACH)" '(' variable "as (T_AS)" $@17 foreach_variable foreach_optional_arg ')' $@18 foreach_statement  */
#line 345 "Zend/zend_language_parser.y"
                                  { zend_do_foreach_end(&yyvsp[-9], &yyvsp[-6] TSRMLS_CC); }
#line 3847 "Zend/zend_language_parser.c"
    break;

  case 86: /* $@19: %empty  */
#line 347 "Zend/zend_language_parser.y"
                { zend_do_foreach_begin(&yyvsp[-3], &yyvsp[-2], &yyvsp[-1], &yyvsp[0], 0 TSRMLS_CC); }
#line 3853 "Zend/zend_language_parser.c"
    break;

  case 87: /* $@20: %empty  */
#line 348 "Zend/zend_language_parser.y"
                                                          { zend_do_foreach_cont(&yyvsp[-7], &yyvsp[-6], &yyvsp[-4], &yyvsp[-2], &yyvsp[-1] TSRMLS_CC); }
#line 3859 "Zend/zend_language_parser.c"
    break;

  case 88: /* unticked_statement: "foreach (T_FOREACH)" '(' expr_without_variable "as (T_AS)" $@19 foreach_variable foreach_optional_arg ')' $@20 foreach_statement  */
#line 349 "Zend/zend_language_parser.y"
                                  { zend_do_foreach_end(&yyvsp[-9], &yyvsp[-6] TSRMLS_CC); }
#line 3865 "Zend/zend_language_parser.c"
    break;

  case 89: /* $@21: %empty  */
#line 350 "Zend/zend_language_parser.y"
                          { yyvsp[0].u.op.opline_num = get_next_op_number(CG(active_op_array)); zend_do_declare_begin(TSRMLS_C); }
#line 3871 "Zend/zend_language_parser.c"
    break;

  case 90: /* unticked_statement: "declare (T_DECLARE)" $@21 '(' declare_list ')' declare_statement  */
#line 350 "Zend/zend_language_parser.y"
                                                                                                                                                                    { zend_do_declare_end(&yyvsp[-5] TSRMLS_CC); }
#line 3877 "Zend/zend_language_parser.c"
    break;

  case 92: /* $@22: %empty  */
#line 352 "Zend/zend_language_parser.y"
                      { zend_do_try(&yyvsp[0] TSRMLS_CC); }
#line 3883 "Zend/zend_language_parser.c"
    break;

  case 93: /* $@23: %empty  */
#line 353 "Zend/zend_language_parser.y"
                                { zend_do_bind_catch(&yyvsp[-5], &yyvsp[0] TSRMLS_CC); }
#line 3889 "Zend/zend_language_parser.c"
    break;

  case 94: /* unticked_statement: "try (T_TRY)" $@22 '{' inner_statement_list '}' catch_statement $@23 finally_statement  */
#line 354 "Zend/zend_language_parser.y"
                                  { zend_do_end_finally(&yyvsp[-7], &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 3895 "Zend/zend_language_parser.c"
    break;

  case 95: /* unticked_statement: "throw (T_THROW)" expr ';'  */
#line 355 "Zend/zend_language_parser.y"
                                 { zend_do_throw(&yyvsp[-1] TSRMLS_CC); }
#line 3901 "Zend/zend_language_parser.c"
    break;

  case 96: /* unticked_statement: "goto (T_GOTO)" "identifier (T_STRING)" ';'  */
#line 356 "Zend/zend_language_parser.y"
                                    { zend_do_goto(&yyvsp[-1] TSRMLS_CC); }
#line 3907 "Zend/zend_language_parser.c"
    break;

  case 97: /* catch_statement: %empty  */
#line 360 "Zend/zend_language_parser.y"
                                            { yyval.op_type = IS_UNUSED; }
#line 3913 "Zend/zend_language_parser.c"
    break;

  case 98: /* $@24: %empty  */
#line 361 "Zend/zend_language_parser.y"
                            { zend_initialize_try_catch_element(&yyvsp[-1] TSRMLS_CC); }
#line 3919 "Zend/zend_language_parser.c"
    break;

  case 99: /* $@25: %empty  */
#line 362 "Zend/zend_language_parser.y"
                                           { zend_do_first_catch(&yyvsp[-2] TSRMLS_CC); }
#line 3925 "Zend/zend_language_parser.c"
    break;

  case 100: /* $@26: %empty  */
#line 363 "Zend/zend_language_parser.y"
                               { zend_do_begin_catch(&yyvsp[-6], &yyvsp[-3], &yyvsp[-1], &yyvsp[-5] TSRMLS_CC); }
#line 3931 "Zend/zend_language_parser.c"
    break;

  case 101: /* $@27: %empty  */
#line 364 "Zend/zend_language_parser.y"
                                             { zend_do_end_catch(&yyvsp[-10] TSRMLS_CC); }
#line 3937 "Zend/zend_language_parser.c"
    break;

  case 102: /* catch_statement: "catch (T_CATCH)" '(' $@24 fully_qualified_class_name $@25 "variable (T_VARIABLE)" ')' $@26 '{' inner_statement_list '}' $@27 additional_catches  */
#line 365 "Zend/zend_language_parser.y"
                                   { zend_do_mark_last_catch(&yyvsp[-11], &yyvsp[0] TSRMLS_CC); yyval = yyvsp[-12];}
#line 3943 "Zend/zend_language_parser.c"
    break;

  case 103: /* finally_statement: %empty  */
#line 368 "Zend/zend_language_parser.y"
                                                    { yyval.op_type = IS_UNUSED; }
#line 3949 "Zend/zend_language_parser.c"
    break;

  case 104: /* $@28: %empty  */
#line 369 "Zend/zend_language_parser.y"
                          { zend_do_finally(&yyvsp[0] TSRMLS_CC); }
#line 3955 "Zend/zend_language_parser.c"
    break;

  case 105: /* finally_statement: "finally (T_FINALLY)" $@28 '{' inner_statement_list '}'  */
#line 369 "Zend/zend_language_parser.y"
                                                                                           { yyval = yyvsp[-4]; }
#line 3961 "Zend/zend_language_parser.c"
    break;

  case 106: /* additional_catches: non_empty_additional_catches  */
#line 373 "Zend/zend_language_parser.y"
                                             { yyval = yyvsp[0]; }
#line 3967 "Zend/zend_language_parser.c"
    break;

  case 107: /* additional_catches: %empty  */
#line 374 "Zend/zend_language_parser.y"
                            { yyval.u.op.opline_num = -1; }
#line 3973 "Zend/zend_language_parser.c"
    break;

  case 108: /* non_empty_additional_catches: additional_catch  */
#line 378 "Zend/zend_language_parser.y"
                                 { yyval = yyvsp[0]; }
#line 3979 "Zend/zend_language_parser.c"
    break;

  case 109: /* non_empty_additional_catches: non_empty_additional_catches additional_catch  */
#line 379 "Zend/zend_language_parser.y"
                                                              { yyval = yyvsp[0]; }
#line 3985 "Zend/zend_language_parser.c"
    break;

  case 110: /* @29: %empty  */
#line 383 "Zend/zend_language_parser.y"
                                               { yyval.u.op.opline_num = get_next_op_number(CG(active_op_array)); }
#line 3991 "Zend/zend_language_parser.c"
    break;

  case 111: /* $@30: %empty  */
#line 383 "Zend/zend_language_parser.y"
                                                                                                                                { zend_do_begin_catch(&yyvsp[-5], &yyvsp[-3], &yyvsp[-1], NULL TSRMLS_CC); }
#line 3997 "Zend/zend_language_parser.c"
    break;

  case 112: /* additional_catch: "catch (T_CATCH)" '(' fully_qualified_class_name @29 "variable (T_VARIABLE)" ')' $@30 '{' inner_statement_list '}'  */
#line 383 "Zend/zend_language_parser.y"
                                                                                                                                                                                                                     { zend_do_end_catch(&yyvsp[-9] TSRMLS_CC); }
#line 4003 "Zend/zend_language_parser.c"
    break;

  case 115: /* unset_variable: variable  */
#line 392 "Zend/zend_language_parser.y"
                                { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_UNSET, 0 TSRMLS_CC); zend_do_unset(&yyvsp[0] TSRMLS_CC); }
#line 4009 "Zend/zend_language_parser.c"
    break;

  case 116: /* function_declaration_statement: unticked_function_declaration_statement  */
#line 396 "Zend/zend_language_parser.y"
                                                        { DO_TICKS(); }
#line 4015 "Zend/zend_language_parser.c"
    break;

  case 117: /* class_declaration_statement: unticked_class_declaration_statement  */
#line 400 "Zend/zend_language_parser.y"
                                                        { DO_TICKS(); }
#line 4021 "Zend/zend_language_parser.c"
    break;

  case 118: /* is_reference: %empty  */
#line 404 "Zend/zend_language_parser.y"
                                { yyval.op_type = 0; }
#line 4027 "Zend/zend_language_parser.c"
    break;

  case 119: /* is_reference: '&'  */
#line 405 "Zend/zend_language_parser.y"
                                        { yyval.op_type = 1; }
#line 4033 "Zend/zend_language_parser.c"
    break;

  case 120: /* is_variadic: %empty  */
#line 409 "Zend/zend_language_parser.y"
                            { yyval.op_type = 0; }
#line 4039 "Zend/zend_language_parser.c"
    break;

  case 121: /* is_variadic: "... (T_ELLIPSIS)"  */
#line 410 "Zend/zend_language_parser.y"
                            { yyval.op_type = 1; }
#line 4045 "Zend/zend_language_parser.c"
    break;

  case 122: /* $@31: %empty  */
#line 414 "Zend/zend_language_parser.y"
                                               { zend_do_begin_function_declaration(&yyvsp[-2], &yyvsp[0], 0, yyvsp[-1].op_type, NULL TSRMLS_CC); }
#line 4051 "Zend/zend_language_parser.c"
    break;

  case 123: /* unticked_function_declaration_statement: function is_reference "identifier (T_STRING)" $@31 '(' parameter_list ')' '{' inner_statement_list '}'  */
#line 416 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_declaration(&yyvsp[-9] TSRMLS_CC); }
#line 4057 "Zend/zend_language_parser.c"
    break;

  case 124: /* $@32: %empty  */
#line 421 "Zend/zend_language_parser.y"
                        { zend_do_begin_class_declaration(&yyvsp[-2], &yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 4063 "Zend/zend_language_parser.c"
    break;

  case 125: /* unticked_class_declaration_statement: class_entry_type "identifier (T_STRING)" extends_from $@32 implements_list '{' class_statement_list '}'  */
#line 425 "Zend/zend_language_parser.y"
                            { zend_do_end_class_declaration(&yyvsp[-7], &yyvsp[-5] TSRMLS_CC); }
#line 4069 "Zend/zend_language_parser.c"
    break;

  case 126: /* $@33: %empty  */
#line 427 "Zend/zend_language_parser.y"
                        { zend_do_begin_class_declaration(&yyvsp[-1], &yyvsp[0], NULL TSRMLS_CC); }
#line 4075 "Zend/zend_language_parser.c"
    break;

  case 127: /* unticked_class_declaration_statement: interface_entry "identifier (T_STRING)" $@33 interface_extends_list '{' class_statement_list '}'  */
#line 431 "Zend/zend_language_parser.y"
                            { zend_do_end_class_declaration(&yyvsp[-6], NULL TSRMLS_CC); }
#line 4081 "Zend/zend_language_parser.c"
    break;

  case 128: /* class_entry_type: "class (T_CLASS)"  */
#line 436 "Zend/zend_language_parser.y"
                                        { yyval.u.op.opline_num = CG(zend_lineno); yyval.EA = 0; }
#line 4087 "Zend/zend_language_parser.c"
    break;

  case 129: /* class_entry_type: "abstract (T_ABSTRACT)" "class (T_CLASS)"  */
#line 437 "Zend/zend_language_parser.y"
                                   { yyval.u.op.opline_num = CG(zend_lineno); yyval.EA = ZEND_ACC_EXPLICIT_ABSTRACT_CLASS; }
#line 4093 "Zend/zend_language_parser.c"
    break;

  case 130: /* class_entry_type: "trait (T_TRAIT)"  */
#line 438 "Zend/zend_language_parser.y"
                        { yyval.u.op.opline_num = CG(zend_lineno); yyval.EA = ZEND_ACC_TRAIT; }
#line 4099 "Zend/zend_language_parser.c"
    break;

  case 131: /* class_entry_type: "final (T_FINAL)" "class (T_CLASS)"  */
#line 439 "Zend/zend_language_parser.y"
                                { yyval.u.op.opline_num = CG(zend_lineno); yyval.EA = ZEND_ACC_FINAL_CLASS; }
#line 4105 "Zend/zend_language_parser.c"
    break;

  case 132: /* extends_from: %empty  */
#line 443 "Zend/zend_language_parser.y"
                                                                { yyval.op_type = IS_UNUSED; }
#line 4111 "Zend/zend_language_parser.c"
    break;

  case 133: /* extends_from: "extends (T_EXTENDS)" fully_qualified_class_name  */
#line 444 "Zend/zend_language_parser.y"
                                                        { zend_do_fetch_class(&yyval, &yyvsp[0] TSRMLS_CC); }
#line 4117 "Zend/zend_language_parser.c"
    break;

  case 134: /* interface_entry: "interface (T_INTERFACE)"  */
#line 448 "Zend/zend_language_parser.y"
                                { yyval.u.op.opline_num = CG(zend_lineno); yyval.EA = ZEND_ACC_INTERFACE; }
#line 4123 "Zend/zend_language_parser.c"
    break;

  case 139: /* interface_list: fully_qualified_class_name  */
#line 462 "Zend/zend_language_parser.y"
                                                                { zend_do_implements_interface(&yyvsp[0] TSRMLS_CC); }
#line 4129 "Zend/zend_language_parser.c"
    break;

  case 140: /* interface_list: interface_list ',' fully_qualified_class_name  */
#line 463 "Zend/zend_language_parser.y"
                                                              { zend_do_implements_interface(&yyvsp[0] TSRMLS_CC); }
#line 4135 "Zend/zend_language_parser.c"
    break;

  case 141: /* foreach_optional_arg: %empty  */
#line 467 "Zend/zend_language_parser.y"
                                                                        { yyval.op_type = IS_UNUSED; }
#line 4141 "Zend/zend_language_parser.c"
    break;

  case 142: /* foreach_optional_arg: "=> (T_DOUBLE_ARROW)" foreach_variable  */
#line 468 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; }
#line 4147 "Zend/zend_language_parser.c"
    break;

  case 143: /* foreach_variable: variable  */
#line 472 "Zend/zend_language_parser.y"
                                                { zend_check_writable_variable(&yyvsp[0]); yyval = yyvsp[0]; }
#line 4153 "Zend/zend_language_parser.c"
    break;

  case 144: /* foreach_variable: '&' variable  */
#line 473 "Zend/zend_language_parser.y"
                                        { zend_check_writable_variable(&yyvsp[0]); yyval = yyvsp[0];  yyval.EA |= ZEND_PARSED_REFERENCE_VARIABLE; }
#line 4159 "Zend/zend_language_parser.c"
    break;

  case 145: /* $@34: %empty  */
#line 474 "Zend/zend_language_parser.y"
                           { zend_do_list_init(TSRMLS_C); }
#line 4165 "Zend/zend_language_parser.c"
    break;

  case 146: /* foreach_variable: "list (T_LIST)" '(' $@34 assignment_list ')'  */
#line 474 "Zend/zend_language_parser.y"
                                                                                { yyval = yyvsp[-4]; yyval.EA = ZEND_PARSED_LIST_EXPR; }
#line 4171 "Zend/zend_language_parser.c"
    break;

  case 153: /* declare_list: "identifier (T_STRING)" '=' static_scalar  */
#line 496 "Zend/zend_language_parser.y"
                                                                                { zend_do_declare_stmt(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4177 "Zend/zend_language_parser.c"
    break;

  case 154: /* declare_list: declare_list ',' "identifier (T_STRING)" '=' static_scalar  */
#line 497 "Zend/zend_language_parser.y"
                                                                { zend_do_declare_stmt(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4183 "Zend/zend_language_parser.c"
    break;

  case 155: /* switch_case_list: '{' case_list '}'  */
#line 502 "Zend/zend_language_parser.y"
                                                                        { yyval = yyvsp[-1]; }
#line 4189 "Zend/zend_language_parser.c"
    break;

  case 156: /* switch_case_list: '{' ';' case_list '}'  */
#line 503 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[-1]; }
#line 4195 "Zend/zend_language_parser.c"
    break;

  case 157: /* switch_case_list: ':' case_list "endswitch (T_ENDSWITCH)" ';'  */
#line 504 "Zend/zend_language_parser.y"
                                                        { yyval = yyvsp[-2]; }
#line 4201 "Zend/zend_language_parser.c"
    break;

  case 158: /* switch_case_list: ':' ';' case_list "endswitch (T_ENDSWITCH)" ';'  */
#line 505 "Zend/zend_language_parser.y"
                                                        { yyval = yyvsp[-2]; }
#line 4207 "Zend/zend_language_parser.c"
    break;

  case 159: /* case_list: %empty  */
#line 510 "Zend/zend_language_parser.y"
                                { yyval.op_type = IS_UNUSED; }
#line 4213 "Zend/zend_language_parser.c"
    break;

  case 160: /* $@35: %empty  */
#line 511 "Zend/zend_language_parser.y"
                                                     { zend_do_extended_info(TSRMLS_C);  zend_do_case_before_statement(&yyvsp[-3], &yyvsp[-2], &yyvsp[-1] TSRMLS_CC); }
#line 4219 "Zend/zend_language_parser.c"
    break;

  case 161: /* case_list: case_list "case (T_CASE)" expr case_separator $@35 inner_statement_list  */
#line 511 "Zend/zend_language_parser.y"
                                                                                                                                                                        { zend_do_case_after_statement(&yyval, &yyvsp[-4] TSRMLS_CC); yyval.op_type = IS_CONST; }
#line 4225 "Zend/zend_language_parser.c"
    break;

  case 162: /* $@36: %empty  */
#line 512 "Zend/zend_language_parser.y"
                                                   { zend_do_extended_info(TSRMLS_C);  zend_do_default_before_statement(&yyvsp[-2], &yyvsp[-1] TSRMLS_CC); }
#line 4231 "Zend/zend_language_parser.c"
    break;

  case 163: /* case_list: case_list "default (T_DEFAULT)" case_separator $@36 inner_statement_list  */
#line 512 "Zend/zend_language_parser.y"
                                                                                                                                                                    { zend_do_case_after_statement(&yyval, &yyvsp[-3] TSRMLS_CC); yyval.op_type = IS_CONST; }
#line 4237 "Zend/zend_language_parser.c"
    break;

  case 169: /* $@37: %empty  */
#line 531 "Zend/zend_language_parser.y"
                                                      { zend_do_if_cond(&yyvsp[0], &yyvsp[-1] TSRMLS_CC); }
#line 4243 "Zend/zend_language_parser.c"
    break;

  case 170: /* elseif_list: elseif_list "elseif (T_ELSEIF)" parenthesis_expr $@37 statement  */
#line 531 "Zend/zend_language_parser.y"
                                                                                                         { zend_do_if_after_statement(&yyvsp[-3], 0 TSRMLS_CC); }
#line 4249 "Zend/zend_language_parser.c"
    break;

  case 172: /* $@38: %empty  */
#line 537 "Zend/zend_language_parser.y"
                                                              { zend_do_if_cond(&yyvsp[-1], &yyvsp[-2] TSRMLS_CC); }
#line 4255 "Zend/zend_language_parser.c"
    break;

  case 173: /* new_elseif_list: new_elseif_list "elseif (T_ELSEIF)" parenthesis_expr ':' $@38 inner_statement_list  */
#line 537 "Zend/zend_language_parser.y"
                                                                                                                            { zend_do_if_after_statement(&yyvsp[-4], 0 TSRMLS_CC); }
#line 4261 "Zend/zend_language_parser.c"
    break;

  case 182: /* parameter: optional_class_type is_reference is_variadic "variable (T_VARIABLE)"  */
#line 566 "Zend/zend_language_parser.y"
                        { zend_do_receive_param(ZEND_RECV, &yyvsp[0], NULL, &yyvsp[-3], yyvsp[-2].op_type, yyvsp[-1].op_type TSRMLS_CC); }
#line 4267 "Zend/zend_language_parser.c"
    break;

  case 183: /* parameter: optional_class_type is_reference is_variadic "variable (T_VARIABLE)" '=' static_scalar  */
#line 568 "Zend/zend_language_parser.y"
                        { zend_do_receive_param(ZEND_RECV_INIT, &yyvsp[-2], &yyvsp[0], &yyvsp[-5], yyvsp[-4].op_type, yyvsp[-3].op_type TSRMLS_CC); }
#line 4273 "Zend/zend_language_parser.c"
    break;

  case 184: /* optional_class_type: %empty  */
#line 573 "Zend/zend_language_parser.y"
                                                                { yyval.op_type = IS_UNUSED; }
#line 4279 "Zend/zend_language_parser.c"
    break;

  case 185: /* optional_class_type: "array (T_ARRAY)"  */
#line 574 "Zend/zend_language_parser.y"
                                                                { yyval.op_type = IS_CONST; Z_TYPE(yyval.u.constant)=IS_ARRAY; }
#line 4285 "Zend/zend_language_parser.c"
    break;

  case 186: /* optional_class_type: "callable (T_CALLABLE)"  */
#line 575 "Zend/zend_language_parser.y"
                                                                { yyval.op_type = IS_CONST; Z_TYPE(yyval.u.constant)=IS_CALLABLE; }
#line 4291 "Zend/zend_language_parser.c"
    break;

  case 187: /* optional_class_type: fully_qualified_class_name  */
#line 576 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 4297 "Zend/zend_language_parser.c"
    break;

  case 188: /* function_call_parameter_list: '(' ')'  */
#line 581 "Zend/zend_language_parser.y"
                        { Z_LVAL(yyval.u.constant) = 0; }
#line 4303 "Zend/zend_language_parser.c"
    break;

  case 189: /* function_call_parameter_list: '(' non_empty_function_call_parameter_list ')'  */
#line 582 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[-1]; }
#line 4309 "Zend/zend_language_parser.c"
    break;

  case 190: /* function_call_parameter_list: '(' yield_expr ')'  */
#line 583 "Zend/zend_language_parser.y"
                                        { zend_do_pass_param(&yyvsp[-1], ZEND_SEND_VAL TSRMLS_CC); }
#line 4315 "Zend/zend_language_parser.c"
    break;

  case 193: /* function_call_parameter: expr_without_variable  */
#line 593 "Zend/zend_language_parser.y"
                                        { zend_do_pass_param(&yyvsp[0], ZEND_SEND_VAL TSRMLS_CC); }
#line 4321 "Zend/zend_language_parser.c"
    break;

  case 194: /* function_call_parameter: variable  */
#line 594 "Zend/zend_language_parser.y"
                                                        { zend_do_pass_param(&yyvsp[0], ZEND_SEND_VAR TSRMLS_CC); }
#line 4327 "Zend/zend_language_parser.c"
    break;

  case 195: /* function_call_parameter: '&' w_variable  */
#line 595 "Zend/zend_language_parser.y"
                                                { zend_do_pass_param(&yyvsp[0], ZEND_SEND_REF TSRMLS_CC); }
#line 4333 "Zend/zend_language_parser.c"
    break;

  case 196: /* function_call_parameter: "... (T_ELLIPSIS)" expr  */
#line 596 "Zend/zend_language_parser.y"
                                                { zend_do_unpack_params(&yyvsp[0] TSRMLS_CC); }
#line 4339 "Zend/zend_language_parser.c"
    break;

  case 197: /* global_var_list: global_var_list ',' global_var  */
#line 600 "Zend/zend_language_parser.y"
                                                { zend_do_fetch_global_variable(&yyvsp[0], NULL, ZEND_FETCH_GLOBAL_LOCK TSRMLS_CC); }
#line 4345 "Zend/zend_language_parser.c"
    break;

  case 198: /* global_var_list: global_var  */
#line 601 "Zend/zend_language_parser.y"
                                                                        { zend_do_fetch_global_variable(&yyvsp[0], NULL, ZEND_FETCH_GLOBAL_LOCK TSRMLS_CC); }
#line 4351 "Zend/zend_language_parser.c"
    break;

  case 199: /* global_var: "variable (T_VARIABLE)"  */
#line 606 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; }
#line 4357 "Zend/zend_language_parser.c"
    break;

  case 200: /* global_var: '$' r_variable  */
#line 607 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[0]; }
#line 4363 "Zend/zend_language_parser.c"
    break;

  case 201: /* global_var: '$' '{' expr '}'  */
#line 608 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[-1]; }
#line 4369 "Zend/zend_language_parser.c"
    break;

  case 202: /* static_var_list: static_var_list ',' "variable (T_VARIABLE)"  */
#line 613 "Zend/zend_language_parser.y"
                                               { zend_do_fetch_static_variable(&yyvsp[0], NULL, ZEND_FETCH_STATIC TSRMLS_CC); }
#line 4375 "Zend/zend_language_parser.c"
    break;

  case 203: /* static_var_list: static_var_list ',' "variable (T_VARIABLE)" '=' static_scalar  */
#line 614 "Zend/zend_language_parser.y"
                                                                 { zend_do_fetch_static_variable(&yyvsp[-2], &yyvsp[0], ZEND_FETCH_STATIC TSRMLS_CC); }
#line 4381 "Zend/zend_language_parser.c"
    break;

  case 204: /* static_var_list: "variable (T_VARIABLE)"  */
#line 615 "Zend/zend_language_parser.y"
                            { zend_do_fetch_static_variable(&yyvsp[0], NULL, ZEND_FETCH_STATIC TSRMLS_CC); }
#line 4387 "Zend/zend_language_parser.c"
    break;

  case 205: /* static_var_list: "variable (T_VARIABLE)" '=' static_scalar  */
#line 616 "Zend/zend_language_parser.y"
                                             { zend_do_fetch_static_variable(&yyvsp[-2], &yyvsp[0], ZEND_FETCH_STATIC TSRMLS_CC); }
#line 4393 "Zend/zend_language_parser.c"
    break;

  case 208: /* $@39: %empty  */
#line 628 "Zend/zend_language_parser.y"
                                   { CG(access_type) = Z_LVAL(yyvsp[0].u.constant); }
#line 4399 "Zend/zend_language_parser.c"
    break;

  case 212: /* $@40: %empty  */
#line 631 "Zend/zend_language_parser.y"
                                                                { zend_do_begin_function_declaration(&yyvsp[-2], &yyvsp[0], 1, yyvsp[-1].op_type, &yyvsp[-3] TSRMLS_CC); }
#line 4405 "Zend/zend_language_parser.c"
    break;

  case 213: /* class_statement: method_modifiers function is_reference "identifier (T_STRING)" $@40 '(' parameter_list ')' method_body  */
#line 633 "Zend/zend_language_parser.y"
                            { zend_do_abstract_method(&yyvsp[-5], &yyvsp[-8], &yyvsp[0] TSRMLS_CC); zend_do_end_function_declaration(&yyvsp[-7] TSRMLS_CC); }
#line 4411 "Zend/zend_language_parser.c"
    break;

  case 215: /* trait_list: fully_qualified_class_name  */
#line 641 "Zend/zend_language_parser.y"
                                                                                        { zend_do_use_trait(&yyvsp[0] TSRMLS_CC); }
#line 4417 "Zend/zend_language_parser.c"
    break;

  case 216: /* trait_list: trait_list ',' fully_qualified_class_name  */
#line 642 "Zend/zend_language_parser.y"
                                                                        { zend_do_use_trait(&yyvsp[0] TSRMLS_CC); }
#line 4423 "Zend/zend_language_parser.c"
    break;

  case 225: /* trait_precedence: trait_method_reference_fully_qualified "insteadof (T_INSTEADOF)" trait_reference_list  */
#line 666 "Zend/zend_language_parser.y"
                                                                                { zend_add_trait_precedence(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4429 "Zend/zend_language_parser.c"
    break;

  case 226: /* trait_reference_list: fully_qualified_class_name  */
#line 670 "Zend/zend_language_parser.y"
                                                                                                                { zend_resolve_class_name(&yyvsp[0] TSRMLS_CC); zend_init_list(&yyval.u.op.ptr, Z_STRVAL(yyvsp[0].u.constant) TSRMLS_CC); }
#line 4435 "Zend/zend_language_parser.c"
    break;

  case 227: /* trait_reference_list: trait_reference_list ',' fully_qualified_class_name  */
#line 671 "Zend/zend_language_parser.y"
                                                                                        { zend_resolve_class_name(&yyvsp[0] TSRMLS_CC); zend_add_to_list(&yyvsp[-2].u.op.ptr, Z_STRVAL(yyvsp[0].u.constant) TSRMLS_CC); yyval = yyvsp[-2]; }
#line 4441 "Zend/zend_language_parser.c"
    break;

  case 228: /* trait_method_reference: "identifier (T_STRING)"  */
#line 675 "Zend/zend_language_parser.y"
                                                                                                                                { zend_prepare_reference(&yyval, NULL, &yyvsp[0] TSRMLS_CC); }
#line 4447 "Zend/zend_language_parser.c"
    break;

  case 229: /* trait_method_reference: trait_method_reference_fully_qualified  */
#line 676 "Zend/zend_language_parser.y"
                                                                                                { yyval = yyvsp[0]; }
#line 4453 "Zend/zend_language_parser.c"
    break;

  case 230: /* trait_method_reference_fully_qualified: fully_qualified_class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" "identifier (T_STRING)"  */
#line 680 "Zend/zend_language_parser.y"
                                                                                { zend_prepare_reference(&yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4459 "Zend/zend_language_parser.c"
    break;

  case 231: /* trait_alias: trait_method_reference "as (T_AS)" trait_modifiers "identifier (T_STRING)"  */
#line 684 "Zend/zend_language_parser.y"
                                                                                { zend_add_trait_alias(&yyvsp[-3], &yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 4465 "Zend/zend_language_parser.c"
    break;

  case 232: /* trait_alias: trait_method_reference "as (T_AS)" member_modifier  */
#line 685 "Zend/zend_language_parser.y"
                                                                                                { zend_add_trait_alias(&yyvsp[-2], &yyvsp[0], NULL TSRMLS_CC); }
#line 4471 "Zend/zend_language_parser.c"
    break;

  case 233: /* trait_modifiers: %empty  */
#line 689 "Zend/zend_language_parser.y"
                                                                { Z_LVAL(yyval.u.constant) = 0x0; }
#line 4477 "Zend/zend_language_parser.c"
    break;

  case 234: /* trait_modifiers: member_modifier  */
#line 690 "Zend/zend_language_parser.y"
                                { yyval = yyvsp[0]; }
#line 4483 "Zend/zend_language_parser.c"
    break;

  case 235: /* method_body: ';'  */
#line 694 "Zend/zend_language_parser.y"
                                                        { Z_LVAL(yyval.u.constant) = ZEND_ACC_ABSTRACT; }
#line 4489 "Zend/zend_language_parser.c"
    break;

  case 236: /* method_body: '{' inner_statement_list '}'  */
#line 695 "Zend/zend_language_parser.y"
                                                { Z_LVAL(yyval.u.constant) = 0;	}
#line 4495 "Zend/zend_language_parser.c"
    break;

  case 237: /* variable_modifiers: non_empty_member_modifiers  */
#line 699 "Zend/zend_language_parser.y"
                                                        { yyval = yyvsp[0]; }
#line 4501 "Zend/zend_language_parser.c"
    break;

  case 238: /* variable_modifiers: "var (T_VAR)"  */
#line 700 "Zend/zend_language_parser.y"
                                                                        { Z_LVAL(yyval.u.constant) = ZEND_ACC_PUBLIC; }
#line 4507 "Zend/zend_language_parser.c"
    break;

  case 239: /* method_modifiers: %empty  */
#line 704 "Zend/zend_language_parser.y"
                                                                                { Z_LVAL(yyval.u.constant) = ZEND_ACC_PUBLIC; }
#line 4513 "Zend/zend_language_parser.c"
    break;

  case 240: /* method_modifiers: non_empty_member_modifiers  */
#line 705 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0];  if (!(Z_LVAL(yyval.u.constant) & ZEND_ACC_PPP_MASK)) { Z_LVAL(yyval.u.constant) |= ZEND_ACC_PUBLIC; } }
#line 4519 "Zend/zend_language_parser.c"
    break;

  case 241: /* non_empty_member_modifiers: member_modifier  */
#line 709 "Zend/zend_language_parser.y"
                                                                        { yyval = yyvsp[0]; }
#line 4525 "Zend/zend_language_parser.c"
    break;

  case 242: /* non_empty_member_modifiers: non_empty_member_modifiers member_modifier  */
#line 710 "Zend/zend_language_parser.y"
                                                                { Z_LVAL(yyval.u.constant) = zend_do_verify_access_types(&yyvsp[-1], &yyvsp[0]); }
#line 4531 "Zend/zend_language_parser.c"
    break;

  case 243: /* member_modifier: "public (T_PUBLIC)"  */
#line 714 "Zend/zend_language_parser.y"
                                                        { Z_LVAL(yyval.u.constant) = ZEND_ACC_PUBLIC; }
#line 4537 "Zend/zend_language_parser.c"
    break;

  case 244: /* member_modifier: "protected (T_PROTECTED)"  */
#line 715 "Zend/zend_language_parser.y"
                                                        { Z_LVAL(yyval.u.constant) = ZEND_ACC_PROTECTED; }
#line 4543 "Zend/zend_language_parser.c"
    break;

  case 245: /* member_modifier: "private (T_PRIVATE)"  */
#line 716 "Zend/zend_language_parser.y"
                                                        { Z_LVAL(yyval.u.constant) = ZEND_ACC_PRIVATE; }
#line 4549 "Zend/zend_language_parser.c"
    break;

  case 246: /* member_modifier: "static (T_STATIC)"  */
#line 717 "Zend/zend_language_parser.y"
                                                        { Z_LVAL(yyval.u.constant) = ZEND_ACC_STATIC; }
#line 4555 "Zend/zend_language_parser.c"
    break;

  case 247: /* member_modifier: "abstract (T_ABSTRACT)"  */
#line 718 "Zend/zend_language_parser.y"
                                                        { Z_LVAL(yyval.u.constant) = ZEND_ACC_ABSTRACT; }
#line 4561 "Zend/zend_language_parser.c"
    break;

  case 248: /* member_modifier: "final (T_FINAL)"  */
#line 719 "Zend/zend_language_parser.y"
                                                        { Z_LVAL(yyval.u.constant) = ZEND_ACC_FINAL; }
#line 4567 "Zend/zend_language_parser.c"
    break;

  case 249: /* class_variable_declaration: class_variable_declaration ',' "variable (T_VARIABLE)"  */
#line 723 "Zend/zend_language_parser.y"
                                                                                                { zend_do_declare_property(&yyvsp[0], NULL, CG(access_type) TSRMLS_CC); }
#line 4573 "Zend/zend_language_parser.c"
    break;

  case 250: /* class_variable_declaration: class_variable_declaration ',' "variable (T_VARIABLE)" '=' static_scalar  */
#line 724 "Zend/zend_language_parser.y"
                                                                                { zend_do_declare_property(&yyvsp[-2], &yyvsp[0], CG(access_type) TSRMLS_CC); }
#line 4579 "Zend/zend_language_parser.c"
    break;

  case 251: /* class_variable_declaration: "variable (T_VARIABLE)"  */
#line 725 "Zend/zend_language_parser.y"
                                                                        { zend_do_declare_property(&yyvsp[0], NULL, CG(access_type) TSRMLS_CC); }
#line 4585 "Zend/zend_language_parser.c"
    break;

  case 252: /* class_variable_declaration: "variable (T_VARIABLE)" '=' static_scalar  */
#line 726 "Zend/zend_language_parser.y"
                                                { zend_do_declare_property(&yyvsp[-2], &yyvsp[0], CG(access_type) TSRMLS_CC); }
#line 4591 "Zend/zend_language_parser.c"
    break;

  case 253: /* class_constant_declaration: class_constant_declaration ',' "identifier (T_STRING)" '=' static_scalar  */
#line 730 "Zend/zend_language_parser.y"
                                                                                { zend_do_declare_class_constant(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4597 "Zend/zend_language_parser.c"
    break;

  case 254: /* class_constant_declaration: "const (T_CONST)" "identifier (T_STRING)" '=' static_scalar  */
#line 731 "Zend/zend_language_parser.y"
                                                        { zend_do_declare_class_constant(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4603 "Zend/zend_language_parser.c"
    break;

  case 255: /* echo_expr_list: echo_expr_list ',' expr  */
#line 735 "Zend/zend_language_parser.y"
                                        { zend_do_echo(&yyvsp[0] TSRMLS_CC); }
#line 4609 "Zend/zend_language_parser.c"
    break;

  case 256: /* echo_expr_list: expr  */
#line 736 "Zend/zend_language_parser.y"
                                                        { zend_do_echo(&yyvsp[0] TSRMLS_CC); }
#line 4615 "Zend/zend_language_parser.c"
    break;

  case 257: /* for_expr: %empty  */
#line 741 "Zend/zend_language_parser.y"
                                                { yyval.op_type = IS_CONST;  Z_TYPE(yyval.u.constant) = IS_BOOL;  Z_LVAL(yyval.u.constant) = 1; }
#line 4621 "Zend/zend_language_parser.c"
    break;

  case 258: /* for_expr: non_empty_for_expr  */
#line 742 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[0]; }
#line 4627 "Zend/zend_language_parser.c"
    break;

  case 259: /* $@41: %empty  */
#line 746 "Zend/zend_language_parser.y"
                                        { zend_do_free(&yyvsp[-1] TSRMLS_CC); }
#line 4633 "Zend/zend_language_parser.c"
    break;

  case 260: /* non_empty_for_expr: non_empty_for_expr ',' $@41 expr  */
#line 746 "Zend/zend_language_parser.y"
                                                                              { yyval = yyvsp[0]; }
#line 4639 "Zend/zend_language_parser.c"
    break;

  case 261: /* non_empty_for_expr: expr  */
#line 747 "Zend/zend_language_parser.y"
                                                        { yyval = yyvsp[0]; }
#line 4645 "Zend/zend_language_parser.c"
    break;

  case 262: /* chaining_method_or_property: chaining_method_or_property variable_property  */
#line 751 "Zend/zend_language_parser.y"
                                                                { yyval.EA = yyvsp[0].EA; }
#line 4651 "Zend/zend_language_parser.c"
    break;

  case 263: /* chaining_method_or_property: variable_property  */
#line 752 "Zend/zend_language_parser.y"
                                                                                                { yyval.EA = yyvsp[0].EA; }
#line 4657 "Zend/zend_language_parser.c"
    break;

  case 264: /* chaining_dereference: chaining_dereference '[' dim_offset ']'  */
#line 756 "Zend/zend_language_parser.y"
                                                        { fetch_array_dim(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 4663 "Zend/zend_language_parser.c"
    break;

  case 265: /* chaining_dereference: '[' dim_offset ']'  */
#line 757 "Zend/zend_language_parser.y"
                                                { zend_do_pop_object(&yyvsp[-2] TSRMLS_CC); fetch_array_dim(&yyval, &yyvsp[-2], &yyvsp[-1] TSRMLS_CC); }
#line 4669 "Zend/zend_language_parser.c"
    break;

  case 266: /* $@42: %empty  */
#line 761 "Zend/zend_language_parser.y"
                                                { zend_do_push_object(&yyvsp[0] TSRMLS_CC); }
#line 4675 "Zend/zend_language_parser.c"
    break;

  case 267: /* chaining_instance_call: chaining_dereference $@42 chaining_method_or_property  */
#line 761 "Zend/zend_language_parser.y"
                                                                                                                    { yyval = yyvsp[0]; }
#line 4681 "Zend/zend_language_parser.c"
    break;

  case 268: /* chaining_instance_call: chaining_dereference  */
#line 762 "Zend/zend_language_parser.y"
                                                { zend_do_push_object(&yyvsp[0] TSRMLS_CC); yyval = yyvsp[0]; }
#line 4687 "Zend/zend_language_parser.c"
    break;

  case 269: /* chaining_instance_call: chaining_method_or_property  */
#line 763 "Zend/zend_language_parser.y"
                                            { yyval = yyvsp[0]; }
#line 4693 "Zend/zend_language_parser.c"
    break;

  case 270: /* instance_call: %empty  */
#line 767 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[0]; }
#line 4699 "Zend/zend_language_parser.c"
    break;

  case 271: /* $@43: %empty  */
#line 768 "Zend/zend_language_parser.y"
                { zend_do_push_object(&yyvsp[0] TSRMLS_CC); zend_do_begin_variable_parse(TSRMLS_C); }
#line 4705 "Zend/zend_language_parser.c"
    break;

  case 272: /* instance_call: $@43 chaining_instance_call  */
#line 769 "Zend/zend_language_parser.y"
                                        { zend_do_pop_object(&yyval TSRMLS_CC); zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); }
#line 4711 "Zend/zend_language_parser.c"
    break;

  case 273: /* $@44: %empty  */
#line 773 "Zend/zend_language_parser.y"
                                           { zend_do_extended_fcall_begin(TSRMLS_C); zend_do_begin_new_object(&yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 4717 "Zend/zend_language_parser.c"
    break;

  case 274: /* new_expr: "new (T_NEW)" class_name_reference $@44 ctor_arguments  */
#line 773 "Zend/zend_language_parser.y"
                                                                                                                                                    { zend_do_end_new_object(&yyval, &yyvsp[-3] TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);}
#line 4723 "Zend/zend_language_parser.c"
    break;

  case 275: /* $@45: %empty  */
#line 777 "Zend/zend_language_parser.y"
                           { zend_do_list_init(TSRMLS_C); }
#line 4729 "Zend/zend_language_parser.c"
    break;

  case 276: /* expr_without_variable: "list (T_LIST)" '(' $@45 assignment_list ')' '=' expr  */
#line 777 "Zend/zend_language_parser.y"
                                                                                         { zend_do_list_end(&yyval, &yyvsp[0] TSRMLS_CC); }
#line 4735 "Zend/zend_language_parser.c"
    break;

  case 277: /* expr_without_variable: variable '=' expr  */
#line 778 "Zend/zend_language_parser.y"
                                                { zend_check_writable_variable(&yyvsp[-2]); zend_do_assign(&yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4741 "Zend/zend_language_parser.c"
    break;

  case 278: /* expr_without_variable: variable '=' '&' variable  */
#line 779 "Zend/zend_language_parser.y"
                                          { zend_check_writable_variable(&yyvsp[-3]); zend_do_end_variable_parse(&yyvsp[0], BP_VAR_W, 1 TSRMLS_CC); zend_do_end_variable_parse(&yyvsp[-3], BP_VAR_W, 0 TSRMLS_CC); zend_do_assign_ref(&yyval, &yyvsp[-3], &yyvsp[0] TSRMLS_CC); }
#line 4747 "Zend/zend_language_parser.c"
    break;

  case 279: /* $@46: %empty  */
#line 780 "Zend/zend_language_parser.y"
                                                            { zend_error(E_DEPRECATED, "Assigning the return value of new by reference is deprecated");  zend_check_writable_variable(&yyvsp[-4]); zend_do_extended_fcall_begin(TSRMLS_C); zend_do_begin_new_object(&yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 4753 "Zend/zend_language_parser.c"
    break;

  case 280: /* expr_without_variable: variable '=' '&' "new (T_NEW)" class_name_reference $@46 ctor_arguments  */
#line 780 "Zend/zend_language_parser.y"
                                                                                                                                                                                                                                                                                                   { zend_do_end_new_object(&yyvsp[-4], &yyvsp[-3] TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C); zend_do_end_variable_parse(&yyvsp[-6], BP_VAR_W, 0 TSRMLS_CC); yyvsp[-4].EA = ZEND_PARSED_NEW; zend_do_assign_ref(&yyval, &yyvsp[-6], &yyvsp[-4] TSRMLS_CC); }
#line 4759 "Zend/zend_language_parser.c"
    break;

  case 281: /* expr_without_variable: "clone (T_CLONE)" expr  */
#line 781 "Zend/zend_language_parser.y"
                             { zend_do_clone(&yyval, &yyvsp[0] TSRMLS_CC); }
#line 4765 "Zend/zend_language_parser.c"
    break;

  case 282: /* expr_without_variable: variable "+= (T_PLUS_EQUAL)" expr  */
#line 782 "Zend/zend_language_parser.y"
                                                { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_ADD, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4771 "Zend/zend_language_parser.c"
    break;

  case 283: /* expr_without_variable: variable "-= (T_MINUS_EQUAL)" expr  */
#line 783 "Zend/zend_language_parser.y"
                                                { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_SUB, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4777 "Zend/zend_language_parser.c"
    break;

  case 284: /* expr_without_variable: variable "*= (T_MUL_EQUAL)" expr  */
#line 784 "Zend/zend_language_parser.y"
                                                        { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_MUL, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4783 "Zend/zend_language_parser.c"
    break;

  case 285: /* expr_without_variable: variable "**= (T_POW_EQUAL)" expr  */
#line 785 "Zend/zend_language_parser.y"
                                                        { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_POW, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4789 "Zend/zend_language_parser.c"
    break;

  case 286: /* expr_without_variable: variable "/= (T_DIV_EQUAL)" expr  */
#line 786 "Zend/zend_language_parser.y"
                                                        { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_DIV, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4795 "Zend/zend_language_parser.c"
    break;

  case 287: /* expr_without_variable: variable ".= (T_CONCAT_EQUAL)" expr  */
#line 787 "Zend/zend_language_parser.y"
                                                { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_CONCAT, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4801 "Zend/zend_language_parser.c"
    break;

  case 288: /* expr_without_variable: variable "%= (T_MOD_EQUAL)" expr  */
#line 788 "Zend/zend_language_parser.y"
                                                        { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_MOD, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4807 "Zend/zend_language_parser.c"
    break;

  case 289: /* expr_without_variable: variable "&= (T_AND_EQUAL)" expr  */
#line 789 "Zend/zend_language_parser.y"
                                                        { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_BW_AND, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4813 "Zend/zend_language_parser.c"
    break;

  case 290: /* expr_without_variable: variable "|= (T_OR_EQUAL)" expr  */
#line 790 "Zend/zend_language_parser.y"
                                                        { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_BW_OR, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4819 "Zend/zend_language_parser.c"
    break;

  case 291: /* expr_without_variable: variable "^= (T_XOR_EQUAL)" expr  */
#line 791 "Zend/zend_language_parser.y"
                                                        { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_BW_XOR, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4825 "Zend/zend_language_parser.c"
    break;

  case 292: /* expr_without_variable: variable "<<= (T_SL_EQUAL)" expr  */
#line 792 "Zend/zend_language_parser.y"
                                                { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_SL, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4831 "Zend/zend_language_parser.c"
    break;

  case 293: /* expr_without_variable: variable ">>= (T_SR_EQUAL)" expr  */
#line 793 "Zend/zend_language_parser.y"
                                                { zend_check_writable_variable(&yyvsp[-2]); zend_do_end_variable_parse(&yyvsp[-2], BP_VAR_RW, 0 TSRMLS_CC); zend_do_binary_assign_op(ZEND_ASSIGN_SR, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4837 "Zend/zend_language_parser.c"
    break;

  case 294: /* expr_without_variable: rw_variable "++ (T_INC)"  */
#line 794 "Zend/zend_language_parser.y"
                                  { zend_do_post_incdec(&yyval, &yyvsp[-1], ZEND_POST_INC TSRMLS_CC); }
#line 4843 "Zend/zend_language_parser.c"
    break;

  case 295: /* expr_without_variable: "++ (T_INC)" rw_variable  */
#line 795 "Zend/zend_language_parser.y"
                                  { zend_do_pre_incdec(&yyval, &yyvsp[0], ZEND_PRE_INC TSRMLS_CC); }
#line 4849 "Zend/zend_language_parser.c"
    break;

  case 296: /* expr_without_variable: rw_variable "-- (T_DEC)"  */
#line 796 "Zend/zend_language_parser.y"
                                  { zend_do_post_incdec(&yyval, &yyvsp[-1], ZEND_POST_DEC TSRMLS_CC); }
#line 4855 "Zend/zend_language_parser.c"
    break;

  case 297: /* expr_without_variable: "-- (T_DEC)" rw_variable  */
#line 797 "Zend/zend_language_parser.y"
                                  { zend_do_pre_incdec(&yyval, &yyvsp[0], ZEND_PRE_DEC TSRMLS_CC); }
#line 4861 "Zend/zend_language_parser.c"
    break;

  case 298: /* $@47: %empty  */
#line 798 "Zend/zend_language_parser.y"
                                  { zend_do_boolean_or_begin(&yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 4867 "Zend/zend_language_parser.c"
    break;

  case 299: /* expr_without_variable: expr "|| (T_BOOLEAN_OR)" $@47 expr  */
#line 798 "Zend/zend_language_parser.y"
                                                                                         { zend_do_boolean_or_end(&yyval, &yyvsp[-3], &yyvsp[0], &yyvsp[-2] TSRMLS_CC); }
#line 4873 "Zend/zend_language_parser.c"
    break;

  case 300: /* $@48: %empty  */
#line 799 "Zend/zend_language_parser.y"
                                   { zend_do_boolean_and_begin(&yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 4879 "Zend/zend_language_parser.c"
    break;

  case 301: /* expr_without_variable: expr "&& (T_BOOLEAN_AND)" $@48 expr  */
#line 799 "Zend/zend_language_parser.y"
                                                                                           { zend_do_boolean_and_end(&yyval, &yyvsp[-3], &yyvsp[0], &yyvsp[-2] TSRMLS_CC); }
#line 4885 "Zend/zend_language_parser.c"
    break;

  case 302: /* $@49: %empty  */
#line 800 "Zend/zend_language_parser.y"
                                  { zend_do_boolean_or_begin(&yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 4891 "Zend/zend_language_parser.c"
    break;

  case 303: /* expr_without_variable: expr "or (T_LOGICAL_OR)" $@49 expr  */
#line 800 "Zend/zend_language_parser.y"
                                                                                         { zend_do_boolean_or_end(&yyval, &yyvsp[-3], &yyvsp[0], &yyvsp[-2] TSRMLS_CC); }
#line 4897 "Zend/zend_language_parser.c"
    break;

  case 304: /* $@50: %empty  */
#line 801 "Zend/zend_language_parser.y"
                                   { zend_do_boolean_and_begin(&yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 4903 "Zend/zend_language_parser.c"
    break;

  case 305: /* expr_without_variable: expr "and (T_LOGICAL_AND)" $@50 expr  */
#line 801 "Zend/zend_language_parser.y"
                                                                                           { zend_do_boolean_and_end(&yyval, &yyvsp[-3], &yyvsp[0], &yyvsp[-2] TSRMLS_CC); }
#line 4909 "Zend/zend_language_parser.c"
    break;

  case 306: /* expr_without_variable: expr "xor (T_LOGICAL_XOR)" expr  */
#line 802 "Zend/zend_language_parser.y"
                                        { zend_do_binary_op(ZEND_BOOL_XOR, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4915 "Zend/zend_language_parser.c"
    break;

  case 307: /* expr_without_variable: expr '|' expr  */
#line 803 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_BW_OR, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4921 "Zend/zend_language_parser.c"
    break;

  case 308: /* expr_without_variable: expr '&' expr  */
#line 804 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_BW_AND, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4927 "Zend/zend_language_parser.c"
    break;

  case 309: /* expr_without_variable: expr '^' expr  */
#line 805 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_BW_XOR, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4933 "Zend/zend_language_parser.c"
    break;

  case 310: /* expr_without_variable: expr '.' expr  */
#line 806 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_CONCAT, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4939 "Zend/zend_language_parser.c"
    break;

  case 311: /* expr_without_variable: expr '+' expr  */
#line 807 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_ADD, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4945 "Zend/zend_language_parser.c"
    break;

  case 312: /* expr_without_variable: expr '-' expr  */
#line 808 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_SUB, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4951 "Zend/zend_language_parser.c"
    break;

  case 313: /* expr_without_variable: expr '*' expr  */
#line 809 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_MUL, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4957 "Zend/zend_language_parser.c"
    break;

  case 314: /* expr_without_variable: expr "** (T_POW)" expr  */
#line 810 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_POW, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4963 "Zend/zend_language_parser.c"
    break;

  case 315: /* expr_without_variable: expr '/' expr  */
#line 811 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_DIV, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4969 "Zend/zend_language_parser.c"
    break;

  case 316: /* expr_without_variable: expr '%' expr  */
#line 812 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_MOD, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4975 "Zend/zend_language_parser.c"
    break;

  case 317: /* expr_without_variable: expr "<< (T_SL)" expr  */
#line 813 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_SL, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4981 "Zend/zend_language_parser.c"
    break;

  case 318: /* expr_without_variable: expr ">> (T_SR)" expr  */
#line 814 "Zend/zend_language_parser.y"
                                { zend_do_binary_op(ZEND_SR, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 4987 "Zend/zend_language_parser.c"
    break;

  case 319: /* expr_without_variable: '+' expr  */
#line 815 "Zend/zend_language_parser.y"
                                     { ZVAL_LONG(&yyvsp[-1].u.constant, 0); if (yyvsp[0].op_type == IS_CONST) { add_function(&yyvsp[0].u.constant, &yyvsp[-1].u.constant, &yyvsp[0].u.constant TSRMLS_CC); yyval = yyvsp[0]; } else { yyvsp[-1].op_type = IS_CONST; INIT_PZVAL(&yyvsp[-1].u.constant); zend_do_binary_op(ZEND_ADD, &yyval, &yyvsp[-1], &yyvsp[0] TSRMLS_CC); } }
#line 4993 "Zend/zend_language_parser.c"
    break;

  case 320: /* expr_without_variable: '-' expr  */
#line 816 "Zend/zend_language_parser.y"
                                     { ZVAL_LONG(&yyvsp[-1].u.constant, 0); if (yyvsp[0].op_type == IS_CONST) { sub_function(&yyvsp[0].u.constant, &yyvsp[-1].u.constant, &yyvsp[0].u.constant TSRMLS_CC); yyval = yyvsp[0]; } else { yyvsp[-1].op_type = IS_CONST; INIT_PZVAL(&yyvsp[-1].u.constant); zend_do_binary_op(ZEND_SUB, &yyval, &yyvsp[-1], &yyvsp[0] TSRMLS_CC); } }
#line 4999 "Zend/zend_language_parser.c"
    break;

  case 321: /* expr_without_variable: '!' expr  */
#line 817 "Zend/zend_language_parser.y"
                         { zend_do_unary_op(ZEND_BOOL_NOT, &yyval, &yyvsp[0] TSRMLS_CC); }
#line 5005 "Zend/zend_language_parser.c"
    break;

  case 322: /* expr_without_variable: '~' expr  */
#line 818 "Zend/zend_language_parser.y"
                         { zend_do_unary_op(ZEND_BW_NOT, &yyval, &yyvsp[0] TSRMLS_CC); }
#line 5011 "Zend/zend_language_parser.c"
    break;

  case 323: /* expr_without_variable: expr "=== (T_IS_IDENTICAL)" expr  */
#line 819 "Zend/zend_language_parser.y"
                                                        { zend_do_binary_op(ZEND_IS_IDENTICAL, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 5017 "Zend/zend_language_parser.c"
    break;

  case 324: /* expr_without_variable: expr "!== (T_IS_NOT_IDENTICAL)" expr  */
#line 820 "Zend/zend_language_parser.y"
                                                { zend_do_binary_op(ZEND_IS_NOT_IDENTICAL, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 5023 "Zend/zend_language_parser.c"
    break;

  case 325: /* expr_without_variable: expr "== (T_IS_EQUAL)" expr  */
#line 821 "Zend/zend_language_parser.y"
                                                        { zend_do_binary_op(ZEND_IS_EQUAL, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 5029 "Zend/zend_language_parser.c"
    break;

  case 326: /* expr_without_variable: expr "!= (T_IS_NOT_EQUAL)" expr  */
#line 822 "Zend/zend_language_parser.y"
                                                        { zend_do_binary_op(ZEND_IS_NOT_EQUAL, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 5035 "Zend/zend_language_parser.c"
    break;

  case 327: /* expr_without_variable: expr '<' expr  */
#line 823 "Zend/zend_language_parser.y"
                                                                { zend_do_binary_op(ZEND_IS_SMALLER, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 5041 "Zend/zend_language_parser.c"
    break;

  case 328: /* expr_without_variable: expr "<= (T_IS_SMALLER_OR_EQUAL)" expr  */
#line 824 "Zend/zend_language_parser.y"
                                                { zend_do_binary_op(ZEND_IS_SMALLER_OR_EQUAL, &yyval, &yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 5047 "Zend/zend_language_parser.c"
    break;

  case 329: /* expr_without_variable: expr '>' expr  */
#line 825 "Zend/zend_language_parser.y"
                                                                { zend_do_binary_op(ZEND_IS_SMALLER, &yyval, &yyvsp[0], &yyvsp[-2] TSRMLS_CC); }
#line 5053 "Zend/zend_language_parser.c"
    break;

  case 330: /* expr_without_variable: expr ">= (T_IS_GREATER_OR_EQUAL)" expr  */
#line 826 "Zend/zend_language_parser.y"
                                                { zend_do_binary_op(ZEND_IS_SMALLER_OR_EQUAL, &yyval, &yyvsp[0], &yyvsp[-2] TSRMLS_CC); }
#line 5059 "Zend/zend_language_parser.c"
    break;

  case 331: /* expr_without_variable: expr "instanceof (T_INSTANCEOF)" class_name_reference  */
#line 827 "Zend/zend_language_parser.y"
                                                       { zend_do_instanceof(&yyval, &yyvsp[-2], &yyvsp[0], 0 TSRMLS_CC); }
#line 5065 "Zend/zend_language_parser.c"
    break;

  case 332: /* expr_without_variable: parenthesis_expr  */
#line 828 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[0]; }
#line 5071 "Zend/zend_language_parser.c"
    break;

  case 333: /* expr_without_variable: new_expr  */
#line 829 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[0]; }
#line 5077 "Zend/zend_language_parser.c"
    break;

  case 334: /* @51: %empty  */
#line 830 "Zend/zend_language_parser.y"
                                 { yyval = yyvsp[-1]; }
#line 5083 "Zend/zend_language_parser.c"
    break;

  case 335: /* expr_without_variable: '(' new_expr ')' @51 instance_call  */
#line 830 "Zend/zend_language_parser.y"
                                                            { yyval = yyvsp[0]; }
#line 5089 "Zend/zend_language_parser.c"
    break;

  case 336: /* $@52: %empty  */
#line 831 "Zend/zend_language_parser.y"
                         { zend_do_begin_qm_op(&yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 5095 "Zend/zend_language_parser.c"
    break;

  case 337: /* $@53: %empty  */
#line 832 "Zend/zend_language_parser.y"
                         { zend_do_qm_true(&yyvsp[-1], &yyvsp[-3], &yyvsp[0] TSRMLS_CC); }
#line 5101 "Zend/zend_language_parser.c"
    break;

  case 338: /* expr_without_variable: expr '?' $@52 expr ':' $@53 expr  */
#line 833 "Zend/zend_language_parser.y"
                         { zend_do_qm_false(&yyval, &yyvsp[0], &yyvsp[-5], &yyvsp[-2] TSRMLS_CC); }
#line 5107 "Zend/zend_language_parser.c"
    break;

  case 339: /* $@54: %empty  */
#line 834 "Zend/zend_language_parser.y"
                             { zend_do_jmp_set(&yyvsp[-2], &yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 5113 "Zend/zend_language_parser.c"
    break;

  case 340: /* expr_without_variable: expr '?' ':' $@54 expr  */
#line 835 "Zend/zend_language_parser.y"
                         { zend_do_jmp_set_else(&yyval, &yyvsp[0], &yyvsp[-3], &yyvsp[-2] TSRMLS_CC); }
#line 5119 "Zend/zend_language_parser.c"
    break;

  case 341: /* expr_without_variable: internal_functions_in_yacc  */
#line 836 "Zend/zend_language_parser.y"
                                           { yyval = yyvsp[0]; }
#line 5125 "Zend/zend_language_parser.c"
    break;

  case 342: /* expr_without_variable: "(int) (T_INT_CAST)" expr  */
#line 837 "Zend/zend_language_parser.y"
                                        { zend_do_cast(&yyval, &yyvsp[0], IS_LONG TSRMLS_CC); }
#line 5131 "Zend/zend_language_parser.c"
    break;

  case 343: /* expr_without_variable: "(double) (T_DOUBLE_CAST)" expr  */
#line 838 "Zend/zend_language_parser.y"
                                        { zend_do_cast(&yyval, &yyvsp[0], IS_DOUBLE TSRMLS_CC); }
#line 5137 "Zend/zend_language_parser.c"
    break;

  case 344: /* expr_without_variable: "(string) (T_STRING_CAST)" expr  */
#line 839 "Zend/zend_language_parser.y"
                                        { zend_do_cast(&yyval, &yyvsp[0], IS_STRING TSRMLS_CC); }
#line 5143 "Zend/zend_language_parser.c"
    break;

  case 345: /* expr_without_variable: "(array) (T_ARRAY_CAST)" expr  */
#line 840 "Zend/zend_language_parser.y"
                                        { zend_do_cast(&yyval, &yyvsp[0], IS_ARRAY TSRMLS_CC); }
#line 5149 "Zend/zend_language_parser.c"
    break;

  case 346: /* expr_without_variable: "(object) (T_OBJECT_CAST)" expr  */
#line 841 "Zend/zend_language_parser.y"
                                        { zend_do_cast(&yyval, &yyvsp[0], IS_OBJECT TSRMLS_CC); }
#line 5155 "Zend/zend_language_parser.c"
    break;

  case 347: /* expr_without_variable: "(bool) (T_BOOL_CAST)" expr  */
#line 842 "Zend/zend_language_parser.y"
                                        { zend_do_cast(&yyval, &yyvsp[0], IS_BOOL TSRMLS_CC); }
#line 5161 "Zend/zend_language_parser.c"
    break;

  case 348: /* expr_without_variable: "(unset) (T_UNSET_CAST)" expr  */
#line 843 "Zend/zend_language_parser.y"
                                        { zend_do_cast(&yyval, &yyvsp[0], IS_NULL TSRMLS_CC); }
#line 5167 "Zend/zend_language_parser.c"
    break;

  case 349: /* expr_without_variable: "exit (T_EXIT)" exit_expr  */
#line 844 "Zend/zend_language_parser.y"
                                        { zend_do_exit(&yyval, &yyvsp[0] TSRMLS_CC); }
#line 5173 "Zend/zend_language_parser.c"
    break;

  case 350: /* $@55: %empty  */
#line 845 "Zend/zend_language_parser.y"
                    { zend_do_begin_silence(&yyvsp[0] TSRMLS_CC); }
#line 5179 "Zend/zend_language_parser.c"
    break;

  case 351: /* expr_without_variable: '@' $@55 expr  */
#line 845 "Zend/zend_language_parser.y"
                                                                   { zend_do_end_silence(&yyvsp[-2] TSRMLS_CC); yyval = yyvsp[0]; }
#line 5185 "Zend/zend_language_parser.c"
    break;

  case 352: /* expr_without_variable: scalar  */
#line 846 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; }
#line 5191 "Zend/zend_language_parser.c"
    break;

  case 353: /* expr_without_variable: combined_scalar_offset  */
#line 847 "Zend/zend_language_parser.y"
                                       { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); }
#line 5197 "Zend/zend_language_parser.c"
    break;

  case 354: /* expr_without_variable: combined_scalar  */
#line 848 "Zend/zend_language_parser.y"
                                { yyval = yyvsp[0]; }
#line 5203 "Zend/zend_language_parser.c"
    break;

  case 355: /* expr_without_variable: '`' backticks_expr '`'  */
#line 849 "Zend/zend_language_parser.y"
                                       { zend_do_shell_exec(&yyval, &yyvsp[-1] TSRMLS_CC); }
#line 5209 "Zend/zend_language_parser.c"
    break;

  case 356: /* expr_without_variable: "print (T_PRINT)" expr  */
#line 850 "Zend/zend_language_parser.y"
                              { zend_do_print(&yyval, &yyvsp[0] TSRMLS_CC); }
#line 5215 "Zend/zend_language_parser.c"
    break;

  case 357: /* expr_without_variable: "yield (T_YIELD)"  */
#line 851 "Zend/zend_language_parser.y"
                        { zend_do_yield(&yyval, NULL, NULL, 0 TSRMLS_CC); }
#line 5221 "Zend/zend_language_parser.c"
    break;

  case 358: /* @56: %empty  */
#line 852 "Zend/zend_language_parser.y"
                                      { zend_do_begin_lambda_function_declaration(&yyval, &yyvsp[-1], yyvsp[0].op_type, 0 TSRMLS_CC); }
#line 5227 "Zend/zend_language_parser.c"
    break;

  case 359: /* expr_without_variable: function is_reference @56 '(' parameter_list ')' lexical_vars '{' inner_statement_list '}'  */
#line 854 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_declaration(&yyvsp[-9] TSRMLS_CC); yyval = yyvsp[-7]; }
#line 5233 "Zend/zend_language_parser.c"
    break;

  case 360: /* @57: %empty  */
#line 855 "Zend/zend_language_parser.y"
                                               { zend_do_begin_lambda_function_declaration(&yyval, &yyvsp[-1], yyvsp[0].op_type, 1 TSRMLS_CC); }
#line 5239 "Zend/zend_language_parser.c"
    break;

  case 361: /* expr_without_variable: "static (T_STATIC)" function is_reference @57 '(' parameter_list ')' lexical_vars '{' inner_statement_list '}'  */
#line 857 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_declaration(&yyvsp[-9] TSRMLS_CC); yyval = yyvsp[-7]; }
#line 5245 "Zend/zend_language_parser.c"
    break;

  case 362: /* yield_expr: "yield (T_YIELD)" expr_without_variable  */
#line 861 "Zend/zend_language_parser.y"
                                              { zend_do_yield(&yyval, &yyvsp[0], NULL, 0 TSRMLS_CC); }
#line 5251 "Zend/zend_language_parser.c"
    break;

  case 363: /* yield_expr: "yield (T_YIELD)" variable  */
#line 862 "Zend/zend_language_parser.y"
                                 { zend_do_yield(&yyval, &yyvsp[0], NULL, 1 TSRMLS_CC); }
#line 5257 "Zend/zend_language_parser.c"
    break;

  case 364: /* yield_expr: "yield (T_YIELD)" expr "=> (T_DOUBLE_ARROW)" expr_without_variable  */
#line 863 "Zend/zend_language_parser.y"
                                                                  { zend_do_yield(&yyval, &yyvsp[0], &yyvsp[-2], 0 TSRMLS_CC); }
#line 5263 "Zend/zend_language_parser.c"
    break;

  case 365: /* yield_expr: "yield (T_YIELD)" expr "=> (T_DOUBLE_ARROW)" variable  */
#line 864 "Zend/zend_language_parser.y"
                                                     { zend_do_yield(&yyval, &yyvsp[0], &yyvsp[-2], 1 TSRMLS_CC); }
#line 5269 "Zend/zend_language_parser.c"
    break;

  case 366: /* combined_scalar_offset: combined_scalar '[' dim_offset ']'  */
#line 868 "Zend/zend_language_parser.y"
                                                   { zend_do_begin_variable_parse(TSRMLS_C); fetch_array_dim(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 5275 "Zend/zend_language_parser.c"
    break;

  case 367: /* combined_scalar_offset: combined_scalar_offset '[' dim_offset ']'  */
#line 869 "Zend/zend_language_parser.y"
                                                          { fetch_array_dim(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 5281 "Zend/zend_language_parser.c"
    break;

  case 368: /* combined_scalar_offset: "quoted-string (T_CONSTANT_ENCAPSED_STRING)" '[' dim_offset ']'  */
#line 870 "Zend/zend_language_parser.y"
                                                              { yyvsp[-3].EA = 0; zend_do_begin_variable_parse(TSRMLS_C); fetch_array_dim(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 5287 "Zend/zend_language_parser.c"
    break;

  case 369: /* combined_scalar_offset: general_constant '[' dim_offset ']'  */
#line 871 "Zend/zend_language_parser.y"
                                                    { zend_do_begin_variable_parse(TSRMLS_C); fetch_array_dim(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 5293 "Zend/zend_language_parser.c"
    break;

  case 370: /* combined_scalar: "array (T_ARRAY)" '(' array_pair_list ')'  */
#line 875 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[-1]; }
#line 5299 "Zend/zend_language_parser.c"
    break;

  case 371: /* combined_scalar: '[' array_pair_list ']'  */
#line 876 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[-1]; }
#line 5305 "Zend/zend_language_parser.c"
    break;

  case 372: /* function: "function (T_FUNCTION)"  */
#line 880 "Zend/zend_language_parser.y"
                   { yyval.u.op.opline_num = CG(zend_lineno); }
#line 5311 "Zend/zend_language_parser.c"
    break;

  case 375: /* lexical_var_list: lexical_var_list ',' "variable (T_VARIABLE)"  */
#line 889 "Zend/zend_language_parser.y"
                                                                { zend_do_fetch_lexical_variable(&yyvsp[0], 0 TSRMLS_CC); }
#line 5317 "Zend/zend_language_parser.c"
    break;

  case 376: /* lexical_var_list: lexical_var_list ',' '&' "variable (T_VARIABLE)"  */
#line 890 "Zend/zend_language_parser.y"
                                                                { zend_do_fetch_lexical_variable(&yyvsp[0], 1 TSRMLS_CC); }
#line 5323 "Zend/zend_language_parser.c"
    break;

  case 377: /* lexical_var_list: "variable (T_VARIABLE)"  */
#line 891 "Zend/zend_language_parser.y"
                                                                                        { zend_do_fetch_lexical_variable(&yyvsp[0], 0 TSRMLS_CC); }
#line 5329 "Zend/zend_language_parser.c"
    break;

  case 378: /* lexical_var_list: '&' "variable (T_VARIABLE)"  */
#line 892 "Zend/zend_language_parser.y"
                                                                                { zend_do_fetch_lexical_variable(&yyvsp[0], 1 TSRMLS_CC); }
#line 5335 "Zend/zend_language_parser.c"
    break;

  case 379: /* @58: %empty  */
#line 896 "Zend/zend_language_parser.y"
                               { yyval.u.op.opline_num = zend_do_begin_function_call(&yyvsp[0], 1 TSRMLS_CC); }
#line 5341 "Zend/zend_language_parser.c"
    break;

  case 380: /* function_call: namespace_name @58 function_call_parameter_list  */
#line 897 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_call(&yyvsp[-2], &yyval, 0, yyvsp[-1].u.op.opline_num TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C); }
#line 5347 "Zend/zend_language_parser.c"
    break;

  case 381: /* @59: %empty  */
#line 898 "Zend/zend_language_parser.y"
                                                          { yyvsp[-2].op_type = IS_CONST; ZVAL_EMPTY_STRING(&yyvsp[-2].u.constant);  zend_do_build_namespace_name(&yyvsp[-2], &yyvsp[-2], &yyvsp[0] TSRMLS_CC); yyval.u.op.opline_num = zend_do_begin_function_call(&yyvsp[-2], 0 TSRMLS_CC); }
#line 5353 "Zend/zend_language_parser.c"
    break;

  case 382: /* function_call: "namespace (T_NAMESPACE)" "\\ (T_NS_SEPARATOR)" namespace_name @59 function_call_parameter_list  */
#line 899 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_call(&yyvsp[-4], &yyval, 0, yyvsp[-1].u.op.opline_num TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C); }
#line 5359 "Zend/zend_language_parser.c"
    break;

  case 383: /* @60: %empty  */
#line 900 "Zend/zend_language_parser.y"
                                              { yyval.u.op.opline_num = zend_do_begin_function_call(&yyvsp[0], 0 TSRMLS_CC); }
#line 5365 "Zend/zend_language_parser.c"
    break;

  case 384: /* function_call: "\\ (T_NS_SEPARATOR)" namespace_name @60 function_call_parameter_list  */
#line 901 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_call(&yyvsp[-2], &yyval, 0, yyvsp[-1].u.op.opline_num TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C); }
#line 5371 "Zend/zend_language_parser.c"
    break;

  case 385: /* @61: %empty  */
#line 902 "Zend/zend_language_parser.y"
                                                                { yyval.u.op.opline_num = zend_do_begin_class_member_function_call(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 5377 "Zend/zend_language_parser.c"
    break;

  case 386: /* function_call: class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" variable_name @61 function_call_parameter_list  */
#line 903 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_call(yyvsp[-1].u.op.opline_num?NULL:&yyvsp[-2], &yyval, yyvsp[-1].u.op.opline_num, yyvsp[-1].u.op.opline_num TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);}
#line 5383 "Zend/zend_language_parser.c"
    break;

  case 387: /* $@62: %empty  */
#line 904 "Zend/zend_language_parser.y"
                                                                           { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); zend_do_begin_class_member_function_call(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 5389 "Zend/zend_language_parser.c"
    break;

  case 388: /* function_call: class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" variable_without_objects $@62 function_call_parameter_list  */
#line 905 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_call(NULL, &yyval, 1, 1 TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);}
#line 5395 "Zend/zend_language_parser.c"
    break;

  case 389: /* $@63: %empty  */
#line 906 "Zend/zend_language_parser.y"
                                                                         { zend_do_begin_class_member_function_call(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 5401 "Zend/zend_language_parser.c"
    break;

  case 390: /* function_call: variable_class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" variable_name $@63 function_call_parameter_list  */
#line 907 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_call(NULL, &yyval, 1, 1 TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);}
#line 5407 "Zend/zend_language_parser.c"
    break;

  case 391: /* $@64: %empty  */
#line 908 "Zend/zend_language_parser.y"
                                                                                    { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); zend_do_begin_class_member_function_call(&yyvsp[-2], &yyvsp[0] TSRMLS_CC); }
#line 5413 "Zend/zend_language_parser.c"
    break;

  case 392: /* function_call: variable_class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" variable_without_objects $@64 function_call_parameter_list  */
#line 909 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_call(NULL, &yyval, 1, 1 TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);}
#line 5419 "Zend/zend_language_parser.c"
    break;

  case 393: /* $@65: %empty  */
#line 910 "Zend/zend_language_parser.y"
                                         { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); zend_do_begin_dynamic_function_call(&yyvsp[0], 0 TSRMLS_CC); }
#line 5425 "Zend/zend_language_parser.c"
    break;

  case 394: /* function_call: variable_without_objects $@65 function_call_parameter_list  */
#line 911 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_call(&yyvsp[-2], &yyval, 0, 1 TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C);}
#line 5431 "Zend/zend_language_parser.c"
    break;

  case 395: /* class_name: "static (T_STATIC)"  */
#line 915 "Zend/zend_language_parser.y"
                         { yyval.op_type = IS_CONST; ZVAL_STRINGL(&yyval.u.constant, "static", sizeof("static")-1, 1);}
#line 5437 "Zend/zend_language_parser.c"
    break;

  case 396: /* class_name: namespace_name  */
#line 916 "Zend/zend_language_parser.y"
                               { yyval = yyvsp[0]; }
#line 5443 "Zend/zend_language_parser.c"
    break;

  case 397: /* class_name: "namespace (T_NAMESPACE)" "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 917 "Zend/zend_language_parser.y"
                                                          { yyval.op_type = IS_CONST; ZVAL_EMPTY_STRING(&yyval.u.constant);  zend_do_build_namespace_name(&yyval, &yyval, &yyvsp[0] TSRMLS_CC); }
#line 5449 "Zend/zend_language_parser.c"
    break;

  case 398: /* class_name: "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 918 "Zend/zend_language_parser.y"
                                              { char *tmp = estrndup(Z_STRVAL(yyvsp[0].u.constant), Z_STRLEN(yyvsp[0].u.constant)+1); memcpy(&(tmp[1]), Z_STRVAL(yyvsp[0].u.constant), Z_STRLEN(yyvsp[0].u.constant)+1); tmp[0] = '\\'; efree(Z_STRVAL(yyvsp[0].u.constant)); Z_STRVAL(yyvsp[0].u.constant) = tmp; ++Z_STRLEN(yyvsp[0].u.constant); yyval = yyvsp[0]; }
#line 5455 "Zend/zend_language_parser.c"
    break;

  case 399: /* fully_qualified_class_name: namespace_name  */
#line 922 "Zend/zend_language_parser.y"
                               { yyval = yyvsp[0]; }
#line 5461 "Zend/zend_language_parser.c"
    break;

  case 400: /* fully_qualified_class_name: "namespace (T_NAMESPACE)" "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 923 "Zend/zend_language_parser.y"
                                                          { yyval.op_type = IS_CONST; ZVAL_EMPTY_STRING(&yyval.u.constant);  zend_do_build_namespace_name(&yyval, &yyval, &yyvsp[0] TSRMLS_CC); }
#line 5467 "Zend/zend_language_parser.c"
    break;

  case 401: /* fully_qualified_class_name: "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 924 "Zend/zend_language_parser.y"
                                              { char *tmp = estrndup(Z_STRVAL(yyvsp[0].u.constant), Z_STRLEN(yyvsp[0].u.constant)+1); memcpy(&(tmp[1]), Z_STRVAL(yyvsp[0].u.constant), Z_STRLEN(yyvsp[0].u.constant)+1); tmp[0] = '\\'; efree(Z_STRVAL(yyvsp[0].u.constant)); Z_STRVAL(yyvsp[0].u.constant) = tmp; ++Z_STRLEN(yyvsp[0].u.constant); yyval = yyvsp[0]; }
#line 5473 "Zend/zend_language_parser.c"
    break;

  case 402: /* class_name_reference: class_name  */
#line 930 "Zend/zend_language_parser.y"
                                                                        { zend_do_fetch_class(&yyval, &yyvsp[0] TSRMLS_CC); }
#line 5479 "Zend/zend_language_parser.c"
    break;

  case 403: /* class_name_reference: dynamic_class_name_reference  */
#line 931 "Zend/zend_language_parser.y"
                                                { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); zend_do_fetch_class(&yyval, &yyvsp[0] TSRMLS_CC); }
#line 5485 "Zend/zend_language_parser.c"
    break;

  case 404: /* $@66: %empty  */
#line 936 "Zend/zend_language_parser.y"
                                                { zend_do_push_object(&yyvsp[-1] TSRMLS_CC); }
#line 5491 "Zend/zend_language_parser.c"
    break;

  case 405: /* $@67: %empty  */
#line 937 "Zend/zend_language_parser.y"
                                        { zend_do_push_object(&yyvsp[0] TSRMLS_CC); }
#line 5497 "Zend/zend_language_parser.c"
    break;

  case 406: /* dynamic_class_name_reference: base_variable "-> (T_OBJECT_OPERATOR)" $@66 object_property $@67 dynamic_class_name_variable_properties  */
#line 938 "Zend/zend_language_parser.y"
                        { zend_do_pop_object(&yyval TSRMLS_CC); yyval.EA = ZEND_PARSED_MEMBER; }
#line 5503 "Zend/zend_language_parser.c"
    break;

  case 407: /* dynamic_class_name_reference: base_variable  */
#line 939 "Zend/zend_language_parser.y"
                              { yyval = yyvsp[0]; }
#line 5509 "Zend/zend_language_parser.c"
    break;

  case 410: /* dynamic_class_name_variable_property: "-> (T_OBJECT_OPERATOR)" object_property  */
#line 950 "Zend/zend_language_parser.y"
                                                  { zend_do_push_object(&yyvsp[0] TSRMLS_CC); }
#line 5515 "Zend/zend_language_parser.c"
    break;

  case 411: /* exit_expr: %empty  */
#line 954 "Zend/zend_language_parser.y"
                                { memset(&yyval, 0, sizeof(znode)); yyval.op_type = IS_UNUSED; }
#line 5521 "Zend/zend_language_parser.c"
    break;

  case 412: /* exit_expr: '(' ')'  */
#line 955 "Zend/zend_language_parser.y"
                                { memset(&yyval, 0, sizeof(znode)); yyval.op_type = IS_UNUSED; }
#line 5527 "Zend/zend_language_parser.c"
    break;

  case 413: /* exit_expr: parenthesis_expr  */
#line 956 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[0]; }
#line 5533 "Zend/zend_language_parser.c"
    break;

  case 414: /* backticks_expr: %empty  */
#line 960 "Zend/zend_language_parser.y"
                                { ZVAL_EMPTY_STRING(&yyval.u.constant); INIT_PZVAL(&yyval.u.constant); yyval.op_type = IS_CONST; }
#line 5539 "Zend/zend_language_parser.c"
    break;

  case 415: /* backticks_expr: "quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)"  */
#line 961 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; }
#line 5545 "Zend/zend_language_parser.c"
    break;

  case 416: /* backticks_expr: encaps_list  */
#line 962 "Zend/zend_language_parser.y"
                                { yyval = yyvsp[0]; }
#line 5551 "Zend/zend_language_parser.c"
    break;

  case 417: /* ctor_arguments: %empty  */
#line 967 "Zend/zend_language_parser.y"
                                { Z_LVAL(yyval.u.constant) = 0; }
#line 5557 "Zend/zend_language_parser.c"
    break;

  case 418: /* ctor_arguments: function_call_parameter_list  */
#line 968 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; }
#line 5563 "Zend/zend_language_parser.c"
    break;

  case 419: /* common_scalar: "integer number (T_LNUMBER)"  */
#line 973 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 5569 "Zend/zend_language_parser.c"
    break;

  case 420: /* common_scalar: "floating-point number (T_DNUMBER)"  */
#line 974 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 5575 "Zend/zend_language_parser.c"
    break;

  case 421: /* common_scalar: "quoted-string (T_CONSTANT_ENCAPSED_STRING)"  */
#line 975 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; }
#line 5581 "Zend/zend_language_parser.c"
    break;

  case 422: /* common_scalar: "__LINE__ (T_LINE)"  */
#line 976 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 5587 "Zend/zend_language_parser.c"
    break;

  case 423: /* common_scalar: "__FILE__ (T_FILE)"  */
#line 977 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 5593 "Zend/zend_language_parser.c"
    break;

  case 424: /* common_scalar: "__DIR__ (T_DIR)"  */
#line 978 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 5599 "Zend/zend_language_parser.c"
    break;

  case 425: /* common_scalar: "__TRAIT__ (T_TRAIT_C)"  */
#line 979 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 5605 "Zend/zend_language_parser.c"
    break;

  case 426: /* common_scalar: "__METHOD__ (T_METHOD_C)"  */
#line 980 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 5611 "Zend/zend_language_parser.c"
    break;

  case 427: /* common_scalar: "__FUNCTION__ (T_FUNC_C)"  */
#line 981 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 5617 "Zend/zend_language_parser.c"
    break;

  case 428: /* common_scalar: "__NAMESPACE__ (T_NS_C)"  */
#line 982 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 5623 "Zend/zend_language_parser.c"
    break;

  case 429: /* common_scalar: "heredoc start (T_START_HEREDOC)" "quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)" "heredoc end (T_END_HEREDOC)"  */
#line 983 "Zend/zend_language_parser.y"
                                                                        { yyval = yyvsp[-1]; }
#line 5629 "Zend/zend_language_parser.c"
    break;

  case 430: /* common_scalar: "heredoc start (T_START_HEREDOC)" "heredoc end (T_END_HEREDOC)"  */
#line 984 "Zend/zend_language_parser.y"
                                              { ZVAL_EMPTY_STRING(&yyval.u.constant); INIT_PZVAL(&yyval.u.constant); yyval.op_type = IS_CONST; }
#line 5635 "Zend/zend_language_parser.c"
    break;

  case 431: /* static_class_constant: class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" "identifier (T_STRING)"  */
#line 988 "Zend/zend_language_parser.y"
                                                           { zend_do_fetch_constant(&yyval, &yyvsp[-2], &yyvsp[0], ZEND_CT, 0 TSRMLS_CC); }
#line 5641 "Zend/zend_language_parser.c"
    break;

  case 432: /* static_scalar: static_scalar_value  */
#line 992 "Zend/zend_language_parser.y"
                            { zend_do_constant_expression(&yyval, yyvsp[0].u.ast TSRMLS_CC); }
#line 5647 "Zend/zend_language_parser.c"
    break;

  case 433: /* static_scalar_value: common_scalar  */
#line 996 "Zend/zend_language_parser.y"
                                { yyval.u.ast = zend_ast_create_constant(&yyvsp[0].u.constant); }
#line 5653 "Zend/zend_language_parser.c"
    break;

  case 434: /* static_scalar_value: static_class_name_scalar  */
#line 997 "Zend/zend_language_parser.y"
                                                { yyval.u.ast = zend_ast_create_constant(&yyvsp[0].u.constant); }
#line 5659 "Zend/zend_language_parser.c"
    break;

  case 435: /* static_scalar_value: namespace_name  */
#line 998 "Zend/zend_language_parser.y"
                                        { zend_do_fetch_constant(&yyval, NULL, &yyvsp[0], ZEND_CT, 1 TSRMLS_CC); yyval.u.ast = zend_ast_create_constant(&yyval.u.constant); }
#line 5665 "Zend/zend_language_parser.c"
    break;

  case 436: /* static_scalar_value: "namespace (T_NAMESPACE)" "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 999 "Zend/zend_language_parser.y"
                                                          { yyval.op_type = IS_CONST; ZVAL_EMPTY_STRING(&yyval.u.constant);  zend_do_build_namespace_name(&yyval, &yyval, &yyvsp[0] TSRMLS_CC); yyvsp[0] = yyval; zend_do_fetch_constant(&yyval, NULL, &yyvsp[0], ZEND_CT, 0 TSRMLS_CC); yyval.u.ast = zend_ast_create_constant(&yyval.u.constant); }
#line 5671 "Zend/zend_language_parser.c"
    break;

  case 437: /* static_scalar_value: "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 1000 "Zend/zend_language_parser.y"
                                              { char *tmp = estrndup(Z_STRVAL(yyvsp[0].u.constant), Z_STRLEN(yyvsp[0].u.constant)+1); memcpy(&(tmp[1]), Z_STRVAL(yyvsp[0].u.constant), Z_STRLEN(yyvsp[0].u.constant)+1); tmp[0] = '\\'; efree(Z_STRVAL(yyvsp[0].u.constant)); Z_STRVAL(yyvsp[0].u.constant) = tmp; ++Z_STRLEN(yyvsp[0].u.constant); zend_do_fetch_constant(&yyval, NULL, &yyvsp[0], ZEND_CT, 0 TSRMLS_CC); yyval.u.ast = zend_ast_create_constant(&yyval.u.constant); }
#line 5677 "Zend/zend_language_parser.c"
    break;

  case 438: /* static_scalar_value: "array (T_ARRAY)" '(' static_array_pair_list ')'  */
#line 1001 "Zend/zend_language_parser.y"
                                                       { yyval = yyvsp[-1]; }
#line 5683 "Zend/zend_language_parser.c"
    break;

  case 439: /* static_scalar_value: '[' static_array_pair_list ']'  */
#line 1002 "Zend/zend_language_parser.y"
                                               { yyval = yyvsp[-1]; }
#line 5689 "Zend/zend_language_parser.c"
    break;

  case 440: /* static_scalar_value: static_class_constant  */
#line 1003 "Zend/zend_language_parser.y"
                                      { yyval.u.ast = zend_ast_create_constant(&yyvsp[0].u.constant); }
#line 5695 "Zend/zend_language_parser.c"
    break;

  case 441: /* static_scalar_value: "__CLASS__ (T_CLASS_C)"  */
#line 1004 "Zend/zend_language_parser.y"
                                                { yyval.u.ast = zend_ast_create_constant(&yyvsp[0].u.constant); }
#line 5701 "Zend/zend_language_parser.c"
    break;

  case 442: /* static_scalar_value: static_operation  */
#line 1005 "Zend/zend_language_parser.y"
                                 { yyval = yyvsp[0]; }
#line 5707 "Zend/zend_language_parser.c"
    break;

  case 443: /* static_operation: static_scalar_value '[' static_scalar_value ']'  */
#line 1009 "Zend/zend_language_parser.y"
                                                                { yyval.u.ast = zend_ast_create_binary(ZEND_FETCH_DIM_R, yyvsp[-3].u.ast, yyvsp[-1].u.ast); }
#line 5713 "Zend/zend_language_parser.c"
    break;

  case 444: /* static_operation: static_scalar_value '+' static_scalar_value  */
#line 1010 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_ADD, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5719 "Zend/zend_language_parser.c"
    break;

  case 445: /* static_operation: static_scalar_value '-' static_scalar_value  */
#line 1011 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_SUB, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5725 "Zend/zend_language_parser.c"
    break;

  case 446: /* static_operation: static_scalar_value '*' static_scalar_value  */
#line 1012 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_MUL, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5731 "Zend/zend_language_parser.c"
    break;

  case 447: /* static_operation: static_scalar_value "** (T_POW)" static_scalar_value  */
#line 1013 "Zend/zend_language_parser.y"
                                                              { yyval.u.ast = zend_ast_create_binary(ZEND_POW, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5737 "Zend/zend_language_parser.c"
    break;

  case 448: /* static_operation: static_scalar_value '/' static_scalar_value  */
#line 1014 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_DIV, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5743 "Zend/zend_language_parser.c"
    break;

  case 449: /* static_operation: static_scalar_value '%' static_scalar_value  */
#line 1015 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_MOD, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5749 "Zend/zend_language_parser.c"
    break;

  case 450: /* static_operation: '!' static_scalar_value  */
#line 1016 "Zend/zend_language_parser.y"
                                        { yyval.u.ast = zend_ast_create_unary(ZEND_BOOL_NOT, yyvsp[0].u.ast); }
#line 5755 "Zend/zend_language_parser.c"
    break;

  case 451: /* static_operation: '~' static_scalar_value  */
#line 1017 "Zend/zend_language_parser.y"
                                        { yyval.u.ast = zend_ast_create_unary(ZEND_BW_NOT, yyvsp[0].u.ast); }
#line 5761 "Zend/zend_language_parser.c"
    break;

  case 452: /* static_operation: static_scalar_value '|' static_scalar_value  */
#line 1018 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_BW_OR, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5767 "Zend/zend_language_parser.c"
    break;

  case 453: /* static_operation: static_scalar_value '&' static_scalar_value  */
#line 1019 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_BW_AND, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5773 "Zend/zend_language_parser.c"
    break;

  case 454: /* static_operation: static_scalar_value '^' static_scalar_value  */
#line 1020 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_BW_XOR, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5779 "Zend/zend_language_parser.c"
    break;

  case 455: /* static_operation: static_scalar_value "<< (T_SL)" static_scalar_value  */
#line 1021 "Zend/zend_language_parser.y"
                                                             { yyval.u.ast = zend_ast_create_binary(ZEND_SL, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5785 "Zend/zend_language_parser.c"
    break;

  case 456: /* static_operation: static_scalar_value ">> (T_SR)" static_scalar_value  */
#line 1022 "Zend/zend_language_parser.y"
                                                             { yyval.u.ast = zend_ast_create_binary(ZEND_SR, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5791 "Zend/zend_language_parser.c"
    break;

  case 457: /* static_operation: static_scalar_value '.' static_scalar_value  */
#line 1023 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_CONCAT, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5797 "Zend/zend_language_parser.c"
    break;

  case 458: /* static_operation: static_scalar_value "xor (T_LOGICAL_XOR)" static_scalar_value  */
#line 1024 "Zend/zend_language_parser.y"
                                                                      { yyval.u.ast = zend_ast_create_binary(ZEND_BOOL_XOR, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5803 "Zend/zend_language_parser.c"
    break;

  case 459: /* static_operation: static_scalar_value "and (T_LOGICAL_AND)" static_scalar_value  */
#line 1025 "Zend/zend_language_parser.y"
                                                                      { yyval.u.ast = zend_ast_create_binary(ZEND_BOOL_AND, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5809 "Zend/zend_language_parser.c"
    break;

  case 460: /* static_operation: static_scalar_value "or (T_LOGICAL_OR)" static_scalar_value  */
#line 1026 "Zend/zend_language_parser.y"
                                                                     { yyval.u.ast = zend_ast_create_binary(ZEND_BOOL_OR, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5815 "Zend/zend_language_parser.c"
    break;

  case 461: /* static_operation: static_scalar_value "&& (T_BOOLEAN_AND)" static_scalar_value  */
#line 1027 "Zend/zend_language_parser.y"
                                                                      { yyval.u.ast = zend_ast_create_binary(ZEND_BOOL_AND, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5821 "Zend/zend_language_parser.c"
    break;

  case 462: /* static_operation: static_scalar_value "|| (T_BOOLEAN_OR)" static_scalar_value  */
#line 1028 "Zend/zend_language_parser.y"
                                                                     { yyval.u.ast = zend_ast_create_binary(ZEND_BOOL_OR, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5827 "Zend/zend_language_parser.c"
    break;

  case 463: /* static_operation: static_scalar_value "=== (T_IS_IDENTICAL)" static_scalar_value  */
#line 1029 "Zend/zend_language_parser.y"
                                                                       { yyval.u.ast = zend_ast_create_binary(ZEND_IS_IDENTICAL, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5833 "Zend/zend_language_parser.c"
    break;

  case 464: /* static_operation: static_scalar_value "!== (T_IS_NOT_IDENTICAL)" static_scalar_value  */
#line 1030 "Zend/zend_language_parser.y"
                                                                           { yyval.u.ast = zend_ast_create_binary(ZEND_IS_NOT_IDENTICAL, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5839 "Zend/zend_language_parser.c"
    break;

  case 465: /* static_operation: static_scalar_value "== (T_IS_EQUAL)" static_scalar_value  */
#line 1031 "Zend/zend_language_parser.y"
                                                                   { yyval.u.ast = zend_ast_create_binary(ZEND_IS_EQUAL, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5845 "Zend/zend_language_parser.c"
    break;

  case 466: /* static_operation: static_scalar_value "!= (T_IS_NOT_EQUAL)" static_scalar_value  */
#line 1032 "Zend/zend_language_parser.y"
                                                                       { yyval.u.ast = zend_ast_create_binary(ZEND_IS_NOT_EQUAL, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5851 "Zend/zend_language_parser.c"
    break;

  case 467: /* static_operation: static_scalar_value '<' static_scalar_value  */
#line 1033 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_IS_SMALLER, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5857 "Zend/zend_language_parser.c"
    break;

  case 468: /* static_operation: static_scalar_value '>' static_scalar_value  */
#line 1034 "Zend/zend_language_parser.y"
                                                            { yyval.u.ast = zend_ast_create_binary(ZEND_IS_SMALLER, yyvsp[0].u.ast, yyvsp[-2].u.ast); }
#line 5863 "Zend/zend_language_parser.c"
    break;

  case 469: /* static_operation: static_scalar_value "<= (T_IS_SMALLER_OR_EQUAL)" static_scalar_value  */
#line 1035 "Zend/zend_language_parser.y"
                                                                              { yyval.u.ast = zend_ast_create_binary(ZEND_IS_SMALLER_OR_EQUAL, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5869 "Zend/zend_language_parser.c"
    break;

  case 470: /* static_operation: static_scalar_value ">= (T_IS_GREATER_OR_EQUAL)" static_scalar_value  */
#line 1036 "Zend/zend_language_parser.y"
                                                                              { yyval.u.ast = zend_ast_create_binary(ZEND_IS_SMALLER_OR_EQUAL, yyvsp[0].u.ast, yyvsp[-2].u.ast); }
#line 5875 "Zend/zend_language_parser.c"
    break;

  case 471: /* static_operation: static_scalar_value '?' ':' static_scalar_value  */
#line 1037 "Zend/zend_language_parser.y"
                                                                { yyval.u.ast = zend_ast_create_ternary(ZEND_SELECT, yyvsp[-3].u.ast, NULL, yyvsp[0].u.ast); }
#line 5881 "Zend/zend_language_parser.c"
    break;

  case 472: /* static_operation: static_scalar_value '?' static_scalar_value ':' static_scalar_value  */
#line 1038 "Zend/zend_language_parser.y"
                                                                                    { yyval.u.ast = zend_ast_create_ternary(ZEND_SELECT, yyvsp[-4].u.ast, yyvsp[-2].u.ast, yyvsp[0].u.ast); }
#line 5887 "Zend/zend_language_parser.c"
    break;

  case 473: /* static_operation: '+' static_scalar_value  */
#line 1039 "Zend/zend_language_parser.y"
                                        { yyval.u.ast = zend_ast_create_unary(ZEND_UNARY_PLUS, yyvsp[0].u.ast); }
#line 5893 "Zend/zend_language_parser.c"
    break;

  case 474: /* static_operation: '-' static_scalar_value  */
#line 1040 "Zend/zend_language_parser.y"
                                        { yyval.u.ast = zend_ast_create_unary(ZEND_UNARY_MINUS, yyvsp[0].u.ast); }
#line 5899 "Zend/zend_language_parser.c"
    break;

  case 475: /* static_operation: '(' static_scalar_value ')'  */
#line 1041 "Zend/zend_language_parser.y"
                                            { yyval = yyvsp[-1]; }
#line 5905 "Zend/zend_language_parser.c"
    break;

  case 476: /* general_constant: class_constant  */
#line 1045 "Zend/zend_language_parser.y"
                               { yyval = yyvsp[0]; }
#line 5911 "Zend/zend_language_parser.c"
    break;

  case 477: /* general_constant: namespace_name  */
#line 1046 "Zend/zend_language_parser.y"
                                { zend_do_fetch_constant(&yyval, NULL, &yyvsp[0], ZEND_RT, 1 TSRMLS_CC); }
#line 5917 "Zend/zend_language_parser.c"
    break;

  case 478: /* general_constant: "namespace (T_NAMESPACE)" "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 1047 "Zend/zend_language_parser.y"
                                                          { yyval.op_type = IS_CONST; ZVAL_EMPTY_STRING(&yyval.u.constant);  zend_do_build_namespace_name(&yyval, &yyval, &yyvsp[0] TSRMLS_CC); yyvsp[0] = yyval; zend_do_fetch_constant(&yyval, NULL, &yyvsp[0], ZEND_RT, 0 TSRMLS_CC); }
#line 5923 "Zend/zend_language_parser.c"
    break;

  case 479: /* general_constant: "\\ (T_NS_SEPARATOR)" namespace_name  */
#line 1048 "Zend/zend_language_parser.y"
                                              { char *tmp = estrndup(Z_STRVAL(yyvsp[0].u.constant), Z_STRLEN(yyvsp[0].u.constant)+1); memcpy(&(tmp[1]), Z_STRVAL(yyvsp[0].u.constant), Z_STRLEN(yyvsp[0].u.constant)+1); tmp[0] = '\\'; efree(Z_STRVAL(yyvsp[0].u.constant)); Z_STRVAL(yyvsp[0].u.constant) = tmp; ++Z_STRLEN(yyvsp[0].u.constant); zend_do_fetch_constant(&yyval, NULL, &yyvsp[0], ZEND_RT, 0 TSRMLS_CC); }
#line 5929 "Zend/zend_language_parser.c"
    break;

  case 480: /* scalar: "variable name (T_STRING_VARNAME)"  */
#line 1052 "Zend/zend_language_parser.y"
                                 { yyval = yyvsp[0]; }
#line 5935 "Zend/zend_language_parser.c"
    break;

  case 481: /* scalar: general_constant  */
#line 1053 "Zend/zend_language_parser.y"
                                 { yyval = yyvsp[0]; }
#line 5941 "Zend/zend_language_parser.c"
    break;

  case 482: /* scalar: class_name_scalar  */
#line 1054 "Zend/zend_language_parser.y"
                                  { yyval = yyvsp[0]; }
#line 5947 "Zend/zend_language_parser.c"
    break;

  case 483: /* scalar: common_scalar  */
#line 1055 "Zend/zend_language_parser.y"
                              { yyval = yyvsp[0]; }
#line 5953 "Zend/zend_language_parser.c"
    break;

  case 484: /* scalar: '"' encaps_list '"'  */
#line 1056 "Zend/zend_language_parser.y"
                                    { yyval = yyvsp[-1]; }
#line 5959 "Zend/zend_language_parser.c"
    break;

  case 485: /* scalar: "heredoc start (T_START_HEREDOC)" encaps_list "heredoc end (T_END_HEREDOC)"  */
#line 1057 "Zend/zend_language_parser.y"
                                                          { yyval = yyvsp[-1]; }
#line 5965 "Zend/zend_language_parser.c"
    break;

  case 486: /* scalar: "__CLASS__ (T_CLASS_C)"  */
#line 1058 "Zend/zend_language_parser.y"
                          { if (Z_TYPE(yyvsp[0].u.constant) == IS_CONSTANT) {zend_do_fetch_constant(&yyval, NULL, &yyvsp[0], ZEND_RT, 1 TSRMLS_CC);} else {yyval = yyvsp[0];} }
#line 5971 "Zend/zend_language_parser.c"
    break;

  case 487: /* static_array_pair_list: %empty  */
#line 1062 "Zend/zend_language_parser.y"
                            { yyval.op_type = IS_CONST; INIT_PZVAL(&yyval.u.constant); array_init(&yyval.u.constant); yyval.u.ast = zend_ast_create_constant(&yyval.u.constant); }
#line 5977 "Zend/zend_language_parser.c"
    break;

  case 488: /* static_array_pair_list: non_empty_static_array_pair_list possible_comma  */
#line 1063 "Zend/zend_language_parser.y"
                                                                { zend_ast_dynamic_shrink(&yyvsp[-1].u.ast); yyval = yyvsp[-1]; }
#line 5983 "Zend/zend_language_parser.c"
    break;

  case 491: /* non_empty_static_array_pair_list: non_empty_static_array_pair_list ',' static_scalar_value "=> (T_DOUBLE_ARROW)" static_scalar_value  */
#line 1072 "Zend/zend_language_parser.y"
                                                                                                            { zend_ast_dynamic_add(&yyval.u.ast, yyvsp[-2].u.ast); zend_ast_dynamic_add(&yyval.u.ast, yyvsp[0].u.ast); }
#line 5989 "Zend/zend_language_parser.c"
    break;

  case 492: /* non_empty_static_array_pair_list: non_empty_static_array_pair_list ',' static_scalar_value  */
#line 1073 "Zend/zend_language_parser.y"
                                                                         { zend_ast_dynamic_add(&yyval.u.ast, NULL); zend_ast_dynamic_add(&yyval.u.ast, yyvsp[0].u.ast); }
#line 5995 "Zend/zend_language_parser.c"
    break;

  case 493: /* non_empty_static_array_pair_list: static_scalar_value "=> (T_DOUBLE_ARROW)" static_scalar_value  */
#line 1074 "Zend/zend_language_parser.y"
                                                                       { yyval.u.ast = zend_ast_create_dynamic(ZEND_INIT_ARRAY); zend_ast_dynamic_add(&yyval.u.ast, yyvsp[-2].u.ast); zend_ast_dynamic_add(&yyval.u.ast, yyvsp[0].u.ast); }
#line 6001 "Zend/zend_language_parser.c"
    break;

  case 494: /* non_empty_static_array_pair_list: static_scalar_value  */
#line 1075 "Zend/zend_language_parser.y"
                                    { yyval.u.ast = zend_ast_create_dynamic(ZEND_INIT_ARRAY); zend_ast_dynamic_add(&yyval.u.ast, NULL); zend_ast_dynamic_add(&yyval.u.ast, yyvsp[0].u.ast); }
#line 6007 "Zend/zend_language_parser.c"
    break;

  case 495: /* expr: r_variable  */
#line 1079 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; }
#line 6013 "Zend/zend_language_parser.c"
    break;

  case 496: /* expr: expr_without_variable  */
#line 1080 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; }
#line 6019 "Zend/zend_language_parser.c"
    break;

  case 497: /* parenthesis_expr: '(' expr ')'  */
#line 1084 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[-1]; }
#line 6025 "Zend/zend_language_parser.c"
    break;

  case 498: /* parenthesis_expr: '(' yield_expr ')'  */
#line 1085 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[-1]; }
#line 6031 "Zend/zend_language_parser.c"
    break;

  case 499: /* r_variable: variable  */
#line 1090 "Zend/zend_language_parser.y"
                 { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); yyval = yyvsp[0]; }
#line 6037 "Zend/zend_language_parser.c"
    break;

  case 500: /* w_variable: variable  */
#line 1095 "Zend/zend_language_parser.y"
                        { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_W, 0 TSRMLS_CC); yyval = yyvsp[0];
				  zend_check_writable_variable(&yyvsp[0]); }
#line 6044 "Zend/zend_language_parser.c"
    break;

  case 501: /* rw_variable: variable  */
#line 1100 "Zend/zend_language_parser.y"
                        { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_RW, 0 TSRMLS_CC); yyval = yyvsp[0];
				  zend_check_writable_variable(&yyvsp[0]); }
#line 6051 "Zend/zend_language_parser.c"
    break;

  case 502: /* $@68: %empty  */
#line 1105 "Zend/zend_language_parser.y"
                                                                    { zend_do_push_object(&yyvsp[-1] TSRMLS_CC); }
#line 6057 "Zend/zend_language_parser.c"
    break;

  case 503: /* $@69: %empty  */
#line 1106 "Zend/zend_language_parser.y"
                                        { zend_do_push_object(&yyvsp[0] TSRMLS_CC); }
#line 6063 "Zend/zend_language_parser.c"
    break;

  case 504: /* variable: base_variable_with_function_calls "-> (T_OBJECT_OPERATOR)" $@68 object_property $@69 method_or_not variable_properties  */
#line 1107 "Zend/zend_language_parser.y"
                        { zend_do_pop_object(&yyval TSRMLS_CC); yyval.EA = yyvsp[-6].EA | (yyvsp[0].EA ? yyvsp[0].EA : yyvsp[-1].EA); }
#line 6069 "Zend/zend_language_parser.c"
    break;

  case 505: /* variable: base_variable_with_function_calls  */
#line 1108 "Zend/zend_language_parser.y"
                                                  { yyval = yyvsp[0]; }
#line 6075 "Zend/zend_language_parser.c"
    break;

  case 506: /* variable_properties: variable_properties variable_property  */
#line 1112 "Zend/zend_language_parser.y"
                                                      { yyval.EA = yyvsp[0].EA; }
#line 6081 "Zend/zend_language_parser.c"
    break;

  case 507: /* variable_properties: %empty  */
#line 1113 "Zend/zend_language_parser.y"
                            { yyval.EA = 0; }
#line 6087 "Zend/zend_language_parser.c"
    break;

  case 508: /* $@70: %empty  */
#line 1118 "Zend/zend_language_parser.y"
                                                  { zend_do_push_object(&yyvsp[0] TSRMLS_CC); }
#line 6093 "Zend/zend_language_parser.c"
    break;

  case 509: /* variable_property: "-> (T_OBJECT_OPERATOR)" object_property $@70 method_or_not  */
#line 1118 "Zend/zend_language_parser.y"
                                                                                                        { yyval.EA = yyvsp[0].EA; }
#line 6099 "Zend/zend_language_parser.c"
    break;

  case 510: /* array_method_dereference: array_method_dereference '[' dim_offset ']'  */
#line 1122 "Zend/zend_language_parser.y"
                                                            { fetch_array_dim(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 6105 "Zend/zend_language_parser.c"
    break;

  case 511: /* array_method_dereference: method '[' dim_offset ']'  */
#line 1123 "Zend/zend_language_parser.y"
                                          { yyvsp[-3].EA = ZEND_PARSED_METHOD_CALL; fetch_array_dim(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 6111 "Zend/zend_language_parser.c"
    break;

  case 512: /* @71: %empty  */
#line 1127 "Zend/zend_language_parser.y"
                { zend_do_pop_object(&yyval TSRMLS_CC); zend_do_begin_method_call(&yyval TSRMLS_CC); }
#line 6117 "Zend/zend_language_parser.c"
    break;

  case 513: /* method: @71 function_call_parameter_list  */
#line 1128 "Zend/zend_language_parser.y"
                                             { zend_do_end_function_call(&yyvsp[-1], &yyval, 1, 1 TSRMLS_CC); zend_do_extended_fcall_end(TSRMLS_C); }
#line 6123 "Zend/zend_language_parser.c"
    break;

  case 514: /* method_or_not: method  */
#line 1132 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[0]; yyval.EA = ZEND_PARSED_METHOD_CALL; zend_do_push_object(&yyval TSRMLS_CC); }
#line 6129 "Zend/zend_language_parser.c"
    break;

  case 515: /* method_or_not: array_method_dereference  */
#line 1133 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; zend_do_push_object(&yyval TSRMLS_CC); }
#line 6135 "Zend/zend_language_parser.c"
    break;

  case 516: /* method_or_not: %empty  */
#line 1134 "Zend/zend_language_parser.y"
                            { yyval.EA = ZEND_PARSED_MEMBER; }
#line 6141 "Zend/zend_language_parser.c"
    break;

  case 517: /* variable_without_objects: reference_variable  */
#line 1138 "Zend/zend_language_parser.y"
                                   { yyval = yyvsp[0]; }
#line 6147 "Zend/zend_language_parser.c"
    break;

  case 518: /* variable_without_objects: simple_indirect_reference reference_variable  */
#line 1139 "Zend/zend_language_parser.y"
                                                             { zend_do_indirect_references(&yyval, &yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 6153 "Zend/zend_language_parser.c"
    break;

  case 519: /* static_member: class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" variable_without_objects  */
#line 1143 "Zend/zend_language_parser.y"
                                                                           { yyval = yyvsp[0]; zend_do_fetch_static_member(&yyval, &yyvsp[-2] TSRMLS_CC); }
#line 6159 "Zend/zend_language_parser.c"
    break;

  case 520: /* static_member: variable_class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" variable_without_objects  */
#line 1144 "Zend/zend_language_parser.y"
                                                                                    { yyval = yyvsp[0]; zend_do_fetch_static_member(&yyval, &yyvsp[-2] TSRMLS_CC); }
#line 6165 "Zend/zend_language_parser.c"
    break;

  case 521: /* variable_class_name: reference_variable  */
#line 1149 "Zend/zend_language_parser.y"
                                   { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); yyval=yyvsp[0];; }
#line 6171 "Zend/zend_language_parser.c"
    break;

  case 522: /* array_function_dereference: array_function_dereference '[' dim_offset ']'  */
#line 1153 "Zend/zend_language_parser.y"
                                                              { fetch_array_dim(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 6177 "Zend/zend_language_parser.c"
    break;

  case 523: /* $@72: %empty  */
#line 1154 "Zend/zend_language_parser.y"
                              { zend_do_begin_variable_parse(TSRMLS_C); yyvsp[0].EA = ZEND_PARSED_FUNCTION_CALL; }
#line 6183 "Zend/zend_language_parser.c"
    break;

  case 524: /* array_function_dereference: function_call $@72 '[' dim_offset ']'  */
#line 1155 "Zend/zend_language_parser.y"
                                   { fetch_array_dim(&yyval, &yyvsp[-4], &yyvsp[-1] TSRMLS_CC); }
#line 6189 "Zend/zend_language_parser.c"
    break;

  case 525: /* base_variable_with_function_calls: base_variable  */
#line 1159 "Zend/zend_language_parser.y"
                                                        { yyval = yyvsp[0]; }
#line 6195 "Zend/zend_language_parser.c"
    break;

  case 526: /* base_variable_with_function_calls: array_function_dereference  */
#line 1160 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; }
#line 6201 "Zend/zend_language_parser.c"
    break;

  case 527: /* base_variable_with_function_calls: function_call  */
#line 1161 "Zend/zend_language_parser.y"
                              { zend_do_begin_variable_parse(TSRMLS_C); yyval = yyvsp[0]; yyval.EA = ZEND_PARSED_FUNCTION_CALL; }
#line 6207 "Zend/zend_language_parser.c"
    break;

  case 528: /* base_variable: reference_variable  */
#line 1166 "Zend/zend_language_parser.y"
                                   { yyval = yyvsp[0]; yyval.EA = ZEND_PARSED_VARIABLE; }
#line 6213 "Zend/zend_language_parser.c"
    break;

  case 529: /* base_variable: simple_indirect_reference reference_variable  */
#line 1167 "Zend/zend_language_parser.y"
                                                             { zend_do_indirect_references(&yyval, &yyvsp[-1], &yyvsp[0] TSRMLS_CC); yyval.EA = ZEND_PARSED_VARIABLE; }
#line 6219 "Zend/zend_language_parser.c"
    break;

  case 530: /* base_variable: static_member  */
#line 1168 "Zend/zend_language_parser.y"
                              { yyval = yyvsp[0]; yyval.EA = ZEND_PARSED_STATIC_MEMBER; }
#line 6225 "Zend/zend_language_parser.c"
    break;

  case 531: /* reference_variable: reference_variable '[' dim_offset ']'  */
#line 1172 "Zend/zend_language_parser.y"
                                                        { fetch_array_dim(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 6231 "Zend/zend_language_parser.c"
    break;

  case 532: /* reference_variable: reference_variable '{' expr '}'  */
#line 1173 "Zend/zend_language_parser.y"
                                                        { fetch_string_offset(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 6237 "Zend/zend_language_parser.c"
    break;

  case 533: /* reference_variable: compound_variable  */
#line 1174 "Zend/zend_language_parser.y"
                                                        { zend_do_begin_variable_parse(TSRMLS_C); fetch_simple_variable(&yyval, &yyvsp[0], 1 TSRMLS_CC); }
#line 6243 "Zend/zend_language_parser.c"
    break;

  case 534: /* compound_variable: "variable (T_VARIABLE)"  */
#line 1179 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; }
#line 6249 "Zend/zend_language_parser.c"
    break;

  case 535: /* compound_variable: '$' '{' expr '}'  */
#line 1180 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[-1]; }
#line 6255 "Zend/zend_language_parser.c"
    break;

  case 536: /* dim_offset: %empty  */
#line 1184 "Zend/zend_language_parser.y"
                                        { yyval.op_type = IS_UNUSED; }
#line 6261 "Zend/zend_language_parser.c"
    break;

  case 537: /* dim_offset: expr  */
#line 1185 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[0]; }
#line 6267 "Zend/zend_language_parser.c"
    break;

  case 538: /* object_property: object_dim_list  */
#line 1190 "Zend/zend_language_parser.y"
                                { yyval = yyvsp[0]; }
#line 6273 "Zend/zend_language_parser.c"
    break;

  case 539: /* $@73: %empty  */
#line 1191 "Zend/zend_language_parser.y"
                                         { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); }
#line 6279 "Zend/zend_language_parser.c"
    break;

  case 540: /* object_property: variable_without_objects $@73  */
#line 1191 "Zend/zend_language_parser.y"
                                                                                                     { znode tmp_znode;  zend_do_pop_object(&tmp_znode TSRMLS_CC);  zend_do_fetch_property(&yyval, &tmp_znode, &yyvsp[-1] TSRMLS_CC);}
#line 6285 "Zend/zend_language_parser.c"
    break;

  case 541: /* object_dim_list: object_dim_list '[' dim_offset ']'  */
#line 1195 "Zend/zend_language_parser.y"
                                                        { fetch_array_dim(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 6291 "Zend/zend_language_parser.c"
    break;

  case 542: /* object_dim_list: object_dim_list '{' expr '}'  */
#line 1196 "Zend/zend_language_parser.y"
                                                        { fetch_string_offset(&yyval, &yyvsp[-3], &yyvsp[-1] TSRMLS_CC); }
#line 6297 "Zend/zend_language_parser.c"
    break;

  case 543: /* object_dim_list: variable_name  */
#line 1197 "Zend/zend_language_parser.y"
                              { znode tmp_znode;  zend_do_pop_object(&tmp_znode TSRMLS_CC);  zend_do_fetch_property(&yyval, &tmp_znode, &yyvsp[0] TSRMLS_CC);}
#line 6303 "Zend/zend_language_parser.c"
    break;

  case 544: /* variable_name: "identifier (T_STRING)"  */
#line 1201 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[0]; }
#line 6309 "Zend/zend_language_parser.c"
    break;

  case 545: /* variable_name: '{' expr '}'  */
#line 1202 "Zend/zend_language_parser.y"
                                { yyval = yyvsp[-1]; }
#line 6315 "Zend/zend_language_parser.c"
    break;

  case 546: /* simple_indirect_reference: '$'  */
#line 1206 "Zend/zend_language_parser.y"
                    { Z_LVAL(yyval.u.constant) = 1; }
#line 6321 "Zend/zend_language_parser.c"
    break;

  case 547: /* simple_indirect_reference: simple_indirect_reference '$'  */
#line 1207 "Zend/zend_language_parser.y"
                                              { Z_LVAL(yyval.u.constant)++; }
#line 6327 "Zend/zend_language_parser.c"
    break;

  case 550: /* assignment_list_element: variable  */
#line 1217 "Zend/zend_language_parser.y"
                                                                                        { zend_do_add_list_element(&yyvsp[0] TSRMLS_CC); }
#line 6333 "Zend/zend_language_parser.c"
    break;

  case 551: /* $@74: %empty  */
#line 1218 "Zend/zend_language_parser.y"
                           { zend_do_new_list_begin(TSRMLS_C); }
#line 6339 "Zend/zend_language_parser.c"
    break;

  case 552: /* assignment_list_element: "list (T_LIST)" '(' $@74 assignment_list ')'  */
#line 1218 "Zend/zend_language_parser.y"
                                                                                        { zend_do_new_list_end(TSRMLS_C); }
#line 6345 "Zend/zend_language_parser.c"
    break;

  case 553: /* assignment_list_element: %empty  */
#line 1219 "Zend/zend_language_parser.y"
                                                                                { zend_do_add_list_element(NULL TSRMLS_CC); }
#line 6351 "Zend/zend_language_parser.c"
    break;

  case 554: /* array_pair_list: %empty  */
#line 1224 "Zend/zend_language_parser.y"
                            { zend_do_init_array(&yyval, NULL, NULL, 0 TSRMLS_CC); }
#line 6357 "Zend/zend_language_parser.c"
    break;

  case 555: /* array_pair_list: non_empty_array_pair_list possible_comma  */
#line 1225 "Zend/zend_language_parser.y"
                                                                { yyval = yyvsp[-1]; }
#line 6363 "Zend/zend_language_parser.c"
    break;

  case 556: /* non_empty_array_pair_list: non_empty_array_pair_list ',' expr "=> (T_DOUBLE_ARROW)" expr  */
#line 1229 "Zend/zend_language_parser.y"
                                                                        { zend_do_add_array_element(&yyval, &yyvsp[0], &yyvsp[-2], 0 TSRMLS_CC); }
#line 6369 "Zend/zend_language_parser.c"
    break;

  case 557: /* non_empty_array_pair_list: non_empty_array_pair_list ',' expr  */
#line 1230 "Zend/zend_language_parser.y"
                                                                        { zend_do_add_array_element(&yyval, &yyvsp[0], NULL, 0 TSRMLS_CC); }
#line 6375 "Zend/zend_language_parser.c"
    break;

  case 558: /* non_empty_array_pair_list: expr "=> (T_DOUBLE_ARROW)" expr  */
#line 1231 "Zend/zend_language_parser.y"
                                                { zend_do_init_array(&yyval, &yyvsp[0], &yyvsp[-2], 0 TSRMLS_CC); }
#line 6381 "Zend/zend_language_parser.c"
    break;

  case 559: /* non_empty_array_pair_list: expr  */
#line 1232 "Zend/zend_language_parser.y"
                                                { zend_do_init_array(&yyval, &yyvsp[0], NULL, 0 TSRMLS_CC); }
#line 6387 "Zend/zend_language_parser.c"
    break;

  case 560: /* non_empty_array_pair_list: non_empty_array_pair_list ',' expr "=> (T_DOUBLE_ARROW)" '&' w_variable  */
#line 1233 "Zend/zend_language_parser.y"
                                                                                 { zend_do_add_array_element(&yyval, &yyvsp[0], &yyvsp[-3], 1 TSRMLS_CC); }
#line 6393 "Zend/zend_language_parser.c"
    break;

  case 561: /* non_empty_array_pair_list: non_empty_array_pair_list ',' '&' w_variable  */
#line 1234 "Zend/zend_language_parser.y"
                                                             { zend_do_add_array_element(&yyval, &yyvsp[0], NULL, 1 TSRMLS_CC); }
#line 6399 "Zend/zend_language_parser.c"
    break;

  case 562: /* non_empty_array_pair_list: expr "=> (T_DOUBLE_ARROW)" '&' w_variable  */
#line 1235 "Zend/zend_language_parser.y"
                                                        { zend_do_init_array(&yyval, &yyvsp[0], &yyvsp[-3], 1 TSRMLS_CC); }
#line 6405 "Zend/zend_language_parser.c"
    break;

  case 563: /* non_empty_array_pair_list: '&' w_variable  */
#line 1236 "Zend/zend_language_parser.y"
                                                { zend_do_init_array(&yyval, &yyvsp[0], NULL, 1 TSRMLS_CC); }
#line 6411 "Zend/zend_language_parser.c"
    break;

  case 564: /* encaps_list: encaps_list encaps_var  */
#line 1240 "Zend/zend_language_parser.y"
                                       { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC);  zend_do_add_variable(&yyval, &yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 6417 "Zend/zend_language_parser.c"
    break;

  case 565: /* encaps_list: encaps_list "quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)"  */
#line 1241 "Zend/zend_language_parser.y"
                                                        { zend_do_add_string(&yyval, &yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 6423 "Zend/zend_language_parser.c"
    break;

  case 566: /* encaps_list: encaps_var  */
#line 1242 "Zend/zend_language_parser.y"
                           { zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); zend_do_add_variable(&yyval, NULL, &yyvsp[0] TSRMLS_CC); }
#line 6429 "Zend/zend_language_parser.c"
    break;

  case 567: /* encaps_list: "quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)" encaps_var  */
#line 1243 "Zend/zend_language_parser.y"
                                                        { zend_do_add_string(&yyval, NULL, &yyvsp[-1] TSRMLS_CC); zend_do_end_variable_parse(&yyvsp[0], BP_VAR_R, 0 TSRMLS_CC); zend_do_add_variable(&yyval, &yyval, &yyvsp[0] TSRMLS_CC); }
#line 6435 "Zend/zend_language_parser.c"
    break;

  case 568: /* encaps_var: "variable (T_VARIABLE)"  */
#line 1249 "Zend/zend_language_parser.y"
                           { zend_do_begin_variable_parse(TSRMLS_C); fetch_simple_variable(&yyval, &yyvsp[0], 1 TSRMLS_CC); }
#line 6441 "Zend/zend_language_parser.c"
    break;

  case 569: /* $@75: %empty  */
#line 1250 "Zend/zend_language_parser.y"
                               { zend_do_begin_variable_parse(TSRMLS_C); }
#line 6447 "Zend/zend_language_parser.c"
    break;

  case 570: /* encaps_var: "variable (T_VARIABLE)" '[' $@75 encaps_var_offset ']'  */
#line 1250 "Zend/zend_language_parser.y"
                                                                                                        { fetch_array_begin(&yyval, &yyvsp[-4], &yyvsp[-1] TSRMLS_CC); }
#line 6453 "Zend/zend_language_parser.c"
    break;

  case 571: /* encaps_var: "variable (T_VARIABLE)" "-> (T_OBJECT_OPERATOR)" "identifier (T_STRING)"  */
#line 1251 "Zend/zend_language_parser.y"
                                                      { zend_do_begin_variable_parse(TSRMLS_C); fetch_simple_variable(&yyvsp[-1], &yyvsp[-2], 1 TSRMLS_CC); zend_do_fetch_property(&yyval, &yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 6459 "Zend/zend_language_parser.c"
    break;

  case 572: /* encaps_var: "${ (T_DOLLAR_OPEN_CURLY_BRACES)" expr '}'  */
#line 1252 "Zend/zend_language_parser.y"
                                                    { zend_do_begin_variable_parse(TSRMLS_C);  fetch_simple_variable(&yyval, &yyvsp[-1], 1 TSRMLS_CC); }
#line 6465 "Zend/zend_language_parser.c"
    break;

  case 573: /* encaps_var: "${ (T_DOLLAR_OPEN_CURLY_BRACES)" "variable name (T_STRING_VARNAME)" '[' expr ']' '}'  */
#line 1253 "Zend/zend_language_parser.y"
                                                                             { zend_do_begin_variable_parse(TSRMLS_C);  fetch_array_begin(&yyval, &yyvsp[-4], &yyvsp[-2] TSRMLS_CC); }
#line 6471 "Zend/zend_language_parser.c"
    break;

  case 574: /* encaps_var: "{$ (T_CURLY_OPEN)" variable '}'  */
#line 1254 "Zend/zend_language_parser.y"
                                          { yyval = yyvsp[-1]; }
#line 6477 "Zend/zend_language_parser.c"
    break;

  case 575: /* encaps_var_offset: "identifier (T_STRING)"  */
#line 1259 "Zend/zend_language_parser.y"
                                        { yyval = yyvsp[0]; }
#line 6483 "Zend/zend_language_parser.c"
    break;

  case 576: /* encaps_var_offset: "number (T_NUM_STRING)"  */
#line 1260 "Zend/zend_language_parser.y"
                                { yyval = yyvsp[0]; }
#line 6489 "Zend/zend_language_parser.c"
    break;

  case 577: /* encaps_var_offset: "variable (T_VARIABLE)"  */
#line 1261 "Zend/zend_language_parser.y"
                                        { fetch_simple_variable(&yyval, &yyvsp[0], 1 TSRMLS_CC); }
#line 6495 "Zend/zend_language_parser.c"
    break;

  case 578: /* internal_functions_in_yacc: "isset (T_ISSET)" '(' isset_variables ')'  */
#line 1266 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[-1]; }
#line 6501 "Zend/zend_language_parser.c"
    break;

  case 579: /* internal_functions_in_yacc: "empty (T_EMPTY)" '(' variable ')'  */
#line 1267 "Zend/zend_language_parser.y"
                                                { zend_do_isset_or_isempty(ZEND_ISEMPTY, &yyval, &yyvsp[-1] TSRMLS_CC); }
#line 6507 "Zend/zend_language_parser.c"
    break;

  case 580: /* internal_functions_in_yacc: "empty (T_EMPTY)" '(' expr_without_variable ')'  */
#line 1268 "Zend/zend_language_parser.y"
                                                      { zend_do_unary_op(ZEND_BOOL_NOT, &yyval, &yyvsp[-1] TSRMLS_CC); }
#line 6513 "Zend/zend_language_parser.c"
    break;

  case 581: /* internal_functions_in_yacc: "include (T_INCLUDE)" expr  */
#line 1269 "Zend/zend_language_parser.y"
                                                { zend_do_include_or_eval(ZEND_INCLUDE, &yyval, &yyvsp[0] TSRMLS_CC); }
#line 6519 "Zend/zend_language_parser.c"
    break;

  case 582: /* internal_functions_in_yacc: "include_once (T_INCLUDE_ONCE)" expr  */
#line 1270 "Zend/zend_language_parser.y"
                                        { zend_do_include_or_eval(ZEND_INCLUDE_ONCE, &yyval, &yyvsp[0] TSRMLS_CC); }
#line 6525 "Zend/zend_language_parser.c"
    break;

  case 583: /* internal_functions_in_yacc: "eval (T_EVAL)" '(' expr ')'  */
#line 1271 "Zend/zend_language_parser.y"
                                        { zend_do_include_or_eval(ZEND_EVAL, &yyval, &yyvsp[-1] TSRMLS_CC); }
#line 6531 "Zend/zend_language_parser.c"
    break;

  case 584: /* internal_functions_in_yacc: "require (T_REQUIRE)" expr  */
#line 1272 "Zend/zend_language_parser.y"
                                                { zend_do_include_or_eval(ZEND_REQUIRE, &yyval, &yyvsp[0] TSRMLS_CC); }
#line 6537 "Zend/zend_language_parser.c"
    break;

  case 585: /* internal_functions_in_yacc: "require_once (T_REQUIRE_ONCE)" expr  */
#line 1273 "Zend/zend_language_parser.y"
                                                { zend_do_include_or_eval(ZEND_REQUIRE_ONCE, &yyval, &yyvsp[0] TSRMLS_CC); }
#line 6543 "Zend/zend_language_parser.c"
    break;

  case 586: /* isset_variables: isset_variable  */
#line 1277 "Zend/zend_language_parser.y"
                                                { yyval = yyvsp[0]; }
#line 6549 "Zend/zend_language_parser.c"
    break;

  case 587: /* $@76: %empty  */
#line 1278 "Zend/zend_language_parser.y"
                                    { zend_do_boolean_and_begin(&yyvsp[-1], &yyvsp[0] TSRMLS_CC); }
#line 6555 "Zend/zend_language_parser.c"
    break;

  case 588: /* isset_variables: isset_variables ',' $@76 isset_variable  */
#line 1278 "Zend/zend_language_parser.y"
                                                                                                      { zend_do_boolean_and_end(&yyval, &yyvsp[-3], &yyvsp[0], &yyvsp[-2] TSRMLS_CC); }
#line 6561 "Zend/zend_language_parser.c"
    break;

  case 589: /* isset_variable: variable  */
#line 1282 "Zend/zend_language_parser.y"
                                                        { zend_do_isset_or_isempty(ZEND_ISSET, &yyval, &yyvsp[0] TSRMLS_CC); }
#line 6567 "Zend/zend_language_parser.c"
    break;

  case 590: /* isset_variable: expr_without_variable  */
#line 1283 "Zend/zend_language_parser.y"
                                        { zend_error_noreturn(E_COMPILE_ERROR, "Cannot use isset() on the result of an expression (you can use \"null !== expression\" instead)"); }
#line 6573 "Zend/zend_language_parser.c"
    break;

  case 591: /* class_constant: class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" "identifier (T_STRING)"  */
#line 1287 "Zend/zend_language_parser.y"
                                                           { zend_do_fetch_constant(&yyval, &yyvsp[-2], &yyvsp[0], ZEND_RT, 0 TSRMLS_CC); }
#line 6579 "Zend/zend_language_parser.c"
    break;

  case 592: /* class_constant: variable_class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" "identifier (T_STRING)"  */
#line 1288 "Zend/zend_language_parser.y"
                                                                    { zend_do_fetch_constant(&yyval, &yyvsp[-2], &yyvsp[0], ZEND_RT, 0 TSRMLS_CC); }
#line 6585 "Zend/zend_language_parser.c"
    break;

  case 593: /* static_class_name_scalar: class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" "class (T_CLASS)"  */
#line 1292 "Zend/zend_language_parser.y"
                                                  { zend_do_resolve_class_name(&yyval, &yyvsp[-2], 1 TSRMLS_CC); }
#line 6591 "Zend/zend_language_parser.c"
    break;

  case 594: /* class_name_scalar: class_name ":: (T_PAAMAYIM_NEKUDOTAYIM)" "class (T_CLASS)"  */
#line 1296 "Zend/zend_language_parser.y"
                                                  { zend_do_resolve_class_name(&yyval, &yyvsp[-2], 0 TSRMLS_CC); }
#line 6597 "Zend/zend_language_parser.c"
    break;


#line 6601 "Zend/zend_language_parser.c"

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

      if (yychar <= END)
        {
          /* Return failure if at end of input.  */
          if (yychar == END)
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

#line 1299 "Zend/zend_language_parser.y"


/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T zend_yytnamerr(char *yyres, const char *yystr)
{
	if (!yyres) {
		return yystrlen(yystr);
	}
	{
		TSRMLS_FETCH();
		if (CG(parse_error) == 0) {
			char buffer[120];
			const unsigned char *end, *str, *tok1 = NULL, *tok2 = NULL;
			unsigned int len = 0, toklen = 0, yystr_len;
			
			CG(parse_error) = 1;

			if (LANG_SCNG(yy_text)[0] == 0 &&
				LANG_SCNG(yy_leng) == 1 &&
				memcmp(yystr, "\"end of file\"", sizeof("\"end of file\"") - 1) == 0) {
				yystpcpy(yyres, "end of file");
				return sizeof("end of file")-1;
			}
			
			str = LANG_SCNG(yy_text);
			end = memchr(str, '\n', LANG_SCNG(yy_leng));
			yystr_len = yystrlen(yystr);
			
			if ((tok1 = memchr(yystr, '(', yystr_len)) != NULL
				&& (tok2 = zend_memrchr(yystr, ')', yystr_len)) != NULL) {
				toklen = (tok2 - tok1) + 1;
			} else {
				tok1 = tok2 = NULL;
				toklen = 0;
			}
			
			if (end == NULL) {
				len = LANG_SCNG(yy_leng) > 30 ? 30 : LANG_SCNG(yy_leng);
			} else {
				len = (end - str) > 30 ? 30 : (end - str);
			}
			if (toklen) {
				snprintf(buffer, sizeof(buffer), "'%.*s' %.*s", len, str, toklen, tok1);
			} else {
				snprintf(buffer, sizeof(buffer), "'%.*s'", len, str);
			}
			yystpcpy(yyres, buffer);
			return len + (toklen ? toklen + 1 : 0) + 2;
		}		
	}	
	if (*yystr == '"') {
		YYSIZE_T yyn = 0;
		const char *yyp = yystr;

		for (; *++yyp != '"'; ++yyn) {
			yyres[yyn] = *yyp;
		}
		yyres[yyn] = '\0';
		return yyn;
	}
	yystpcpy(yyres, yystr);
	return strlen(yystr);
}

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
