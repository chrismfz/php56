/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_ZEND_ZEND_ZEND_LANGUAGE_PARSER_H_INCLUDED
# define YY_ZEND_ZEND_ZEND_LANGUAGE_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int zenddebug;
#endif
/* "%code requires" blocks.  */
#line 50 "Zend/zend_language_parser.y"

#ifdef ZTS
# define YYPARSE_PARAM tsrm_ls
# define YYLEX_PARAM tsrm_ls
#endif

#line 56 "Zend/zend_language_parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    END = 0,                       /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_INCLUDE = 258,               /* "include (T_INCLUDE)"  */
    T_INCLUDE_ONCE = 259,          /* "include_once (T_INCLUDE_ONCE)"  */
    T_EVAL = 260,                  /* "eval (T_EVAL)"  */
    T_REQUIRE = 261,               /* "require (T_REQUIRE)"  */
    T_REQUIRE_ONCE = 262,          /* "require_once (T_REQUIRE_ONCE)"  */
    T_LOGICAL_OR = 263,            /* "or (T_LOGICAL_OR)"  */
    T_LOGICAL_XOR = 264,           /* "xor (T_LOGICAL_XOR)"  */
    T_LOGICAL_AND = 265,           /* "and (T_LOGICAL_AND)"  */
    T_PRINT = 266,                 /* "print (T_PRINT)"  */
    T_YIELD = 267,                 /* "yield (T_YIELD)"  */
    T_PLUS_EQUAL = 268,            /* "+= (T_PLUS_EQUAL)"  */
    T_MINUS_EQUAL = 269,           /* "-= (T_MINUS_EQUAL)"  */
    T_MUL_EQUAL = 270,             /* "*= (T_MUL_EQUAL)"  */
    T_DIV_EQUAL = 271,             /* "/= (T_DIV_EQUAL)"  */
    T_CONCAT_EQUAL = 272,          /* ".= (T_CONCAT_EQUAL)"  */
    T_MOD_EQUAL = 273,             /* "%= (T_MOD_EQUAL)"  */
    T_AND_EQUAL = 274,             /* "&= (T_AND_EQUAL)"  */
    T_OR_EQUAL = 275,              /* "|= (T_OR_EQUAL)"  */
    T_XOR_EQUAL = 276,             /* "^= (T_XOR_EQUAL)"  */
    T_SL_EQUAL = 277,              /* "<<= (T_SL_EQUAL)"  */
    T_SR_EQUAL = 278,              /* ">>= (T_SR_EQUAL)"  */
    T_BOOLEAN_OR = 279,            /* "|| (T_BOOLEAN_OR)"  */
    T_BOOLEAN_AND = 280,           /* "&& (T_BOOLEAN_AND)"  */
    T_IS_EQUAL = 281,              /* "== (T_IS_EQUAL)"  */
    T_IS_NOT_EQUAL = 282,          /* "!= (T_IS_NOT_EQUAL)"  */
    T_IS_IDENTICAL = 283,          /* "=== (T_IS_IDENTICAL)"  */
    T_IS_NOT_IDENTICAL = 284,      /* "!== (T_IS_NOT_IDENTICAL)"  */
    T_IS_SMALLER_OR_EQUAL = 285,   /* "<= (T_IS_SMALLER_OR_EQUAL)"  */
    T_IS_GREATER_OR_EQUAL = 286,   /* ">= (T_IS_GREATER_OR_EQUAL)"  */
    T_SL = 287,                    /* "<< (T_SL)"  */
    T_SR = 288,                    /* ">> (T_SR)"  */
    T_INSTANCEOF = 289,            /* "instanceof (T_INSTANCEOF)"  */
    T_INC = 290,                   /* "++ (T_INC)"  */
    T_DEC = 291,                   /* "-- (T_DEC)"  */
    T_INT_CAST = 292,              /* "(int) (T_INT_CAST)"  */
    T_DOUBLE_CAST = 293,           /* "(double) (T_DOUBLE_CAST)"  */
    T_STRING_CAST = 294,           /* "(string) (T_STRING_CAST)"  */
    T_ARRAY_CAST = 295,            /* "(array) (T_ARRAY_CAST)"  */
    T_OBJECT_CAST = 296,           /* "(object) (T_OBJECT_CAST)"  */
    T_BOOL_CAST = 297,             /* "(bool) (T_BOOL_CAST)"  */
    T_UNSET_CAST = 298,            /* "(unset) (T_UNSET_CAST)"  */
    T_NEW = 299,                   /* "new (T_NEW)"  */
    T_CLONE = 300,                 /* "clone (T_CLONE)"  */
    T_EXIT = 301,                  /* "exit (T_EXIT)"  */
    T_IF = 302,                    /* "if (T_IF)"  */
    T_ELSEIF = 303,                /* "elseif (T_ELSEIF)"  */
    T_ELSE = 304,                  /* "else (T_ELSE)"  */
    T_ENDIF = 305,                 /* "endif (T_ENDIF)"  */
    T_LNUMBER = 306,               /* "integer number (T_LNUMBER)"  */
    T_DNUMBER = 307,               /* "floating-point number (T_DNUMBER)"  */
    T_STRING = 308,                /* "identifier (T_STRING)"  */
    T_STRING_VARNAME = 309,        /* "variable name (T_STRING_VARNAME)"  */
    T_VARIABLE = 310,              /* "variable (T_VARIABLE)"  */
    T_NUM_STRING = 311,            /* "number (T_NUM_STRING)"  */
    T_INLINE_HTML = 312,           /* T_INLINE_HTML  */
    T_CHARACTER = 313,             /* T_CHARACTER  */
    T_BAD_CHARACTER = 314,         /* T_BAD_CHARACTER  */
    T_ENCAPSED_AND_WHITESPACE = 315, /* "quoted-string and whitespace (T_ENCAPSED_AND_WHITESPACE)"  */
    T_CONSTANT_ENCAPSED_STRING = 316, /* "quoted-string (T_CONSTANT_ENCAPSED_STRING)"  */
    T_ECHO = 317,                  /* "echo (T_ECHO)"  */
    T_DO = 318,                    /* "do (T_DO)"  */
    T_WHILE = 319,                 /* "while (T_WHILE)"  */
    T_ENDWHILE = 320,              /* "endwhile (T_ENDWHILE)"  */
    T_FOR = 321,                   /* "for (T_FOR)"  */
    T_ENDFOR = 322,                /* "endfor (T_ENDFOR)"  */
    T_FOREACH = 323,               /* "foreach (T_FOREACH)"  */
    T_ENDFOREACH = 324,            /* "endforeach (T_ENDFOREACH)"  */
    T_DECLARE = 325,               /* "declare (T_DECLARE)"  */
    T_ENDDECLARE = 326,            /* "enddeclare (T_ENDDECLARE)"  */
    T_AS = 327,                    /* "as (T_AS)"  */
    T_SWITCH = 328,                /* "switch (T_SWITCH)"  */
    T_ENDSWITCH = 329,             /* "endswitch (T_ENDSWITCH)"  */
    T_CASE = 330,                  /* "case (T_CASE)"  */
    T_DEFAULT = 331,               /* "default (T_DEFAULT)"  */
    T_BREAK = 332,                 /* "break (T_BREAK)"  */
    T_CONTINUE = 333,              /* "continue (T_CONTINUE)"  */
    T_GOTO = 334,                  /* "goto (T_GOTO)"  */
    T_FUNCTION = 335,              /* "function (T_FUNCTION)"  */
    T_CONST = 336,                 /* "const (T_CONST)"  */
    T_RETURN = 337,                /* "return (T_RETURN)"  */
    T_TRY = 338,                   /* "try (T_TRY)"  */
    T_CATCH = 339,                 /* "catch (T_CATCH)"  */
    T_FINALLY = 340,               /* "finally (T_FINALLY)"  */
    T_THROW = 341,                 /* "throw (T_THROW)"  */
    T_USE = 342,                   /* "use (T_USE)"  */
    T_INSTEADOF = 343,             /* "insteadof (T_INSTEADOF)"  */
    T_GLOBAL = 344,                /* "global (T_GLOBAL)"  */
    T_STATIC = 345,                /* "static (T_STATIC)"  */
    T_ABSTRACT = 346,              /* "abstract (T_ABSTRACT)"  */
    T_FINAL = 347,                 /* "final (T_FINAL)"  */
    T_PRIVATE = 348,               /* "private (T_PRIVATE)"  */
    T_PROTECTED = 349,             /* "protected (T_PROTECTED)"  */
    T_PUBLIC = 350,                /* "public (T_PUBLIC)"  */
    T_VAR = 351,                   /* "var (T_VAR)"  */
    T_UNSET = 352,                 /* "unset (T_UNSET)"  */
    T_ISSET = 353,                 /* "isset (T_ISSET)"  */
    T_EMPTY = 354,                 /* "empty (T_EMPTY)"  */
    T_HALT_COMPILER = 355,         /* "__halt_compiler (T_HALT_COMPILER)"  */
    T_CLASS = 356,                 /* "class (T_CLASS)"  */
    T_TRAIT = 357,                 /* "trait (T_TRAIT)"  */
    T_INTERFACE = 358,             /* "interface (T_INTERFACE)"  */
    T_EXTENDS = 359,               /* "extends (T_EXTENDS)"  */
    T_IMPLEMENTS = 360,            /* "implements (T_IMPLEMENTS)"  */
    T_OBJECT_OPERATOR = 361,       /* "-> (T_OBJECT_OPERATOR)"  */
    T_DOUBLE_ARROW = 362,          /* "=> (T_DOUBLE_ARROW)"  */
    T_LIST = 363,                  /* "list (T_LIST)"  */
    T_ARRAY = 364,                 /* "array (T_ARRAY)"  */
    T_CALLABLE = 365,              /* "callable (T_CALLABLE)"  */
    T_CLASS_C = 366,               /* "__CLASS__ (T_CLASS_C)"  */
    T_TRAIT_C = 367,               /* "__TRAIT__ (T_TRAIT_C)"  */
    T_METHOD_C = 368,              /* "__METHOD__ (T_METHOD_C)"  */
    T_FUNC_C = 369,                /* "__FUNCTION__ (T_FUNC_C)"  */
    T_LINE = 370,                  /* "__LINE__ (T_LINE)"  */
    T_FILE = 371,                  /* "__FILE__ (T_FILE)"  */
    T_COMMENT = 372,               /* "comment (T_COMMENT)"  */
    T_DOC_COMMENT = 373,           /* "doc comment (T_DOC_COMMENT)"  */
    T_OPEN_TAG = 374,              /* "open tag (T_OPEN_TAG)"  */
    T_OPEN_TAG_WITH_ECHO = 375,    /* "open tag with echo (T_OPEN_TAG_WITH_ECHO)"  */
    T_CLOSE_TAG = 376,             /* "close tag (T_CLOSE_TAG)"  */
    T_WHITESPACE = 377,            /* "whitespace (T_WHITESPACE)"  */
    T_START_HEREDOC = 378,         /* "heredoc start (T_START_HEREDOC)"  */
    T_END_HEREDOC = 379,           /* "heredoc end (T_END_HEREDOC)"  */
    T_DOLLAR_OPEN_CURLY_BRACES = 380, /* "${ (T_DOLLAR_OPEN_CURLY_BRACES)"  */
    T_CURLY_OPEN = 381,            /* "{$ (T_CURLY_OPEN)"  */
    T_PAAMAYIM_NEKUDOTAYIM = 382,  /* ":: (T_PAAMAYIM_NEKUDOTAYIM)"  */
    T_NAMESPACE = 383,             /* "namespace (T_NAMESPACE)"  */
    T_NS_C = 384,                  /* "__NAMESPACE__ (T_NS_C)"  */
    T_DIR = 385,                   /* "__DIR__ (T_DIR)"  */
    T_NS_SEPARATOR = 386,          /* "\\ (T_NS_SEPARATOR)"  */
    T_ELLIPSIS = 387,              /* "... (T_ELLIPSIS)"  */
    T_POW = 388,                   /* "** (T_POW)"  */
    T_POW_EQUAL = 389              /* "**= (T_POW_EQUAL)"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define END 0
#define YYerror 256
#define YYUNDEF 257
#define T_INCLUDE 258
#define T_INCLUDE_ONCE 259
#define T_EVAL 260
#define T_REQUIRE 261
#define T_REQUIRE_ONCE 262
#define T_LOGICAL_OR 263
#define T_LOGICAL_XOR 264
#define T_LOGICAL_AND 265
#define T_PRINT 266
#define T_YIELD 267
#define T_PLUS_EQUAL 268
#define T_MINUS_EQUAL 269
#define T_MUL_EQUAL 270
#define T_DIV_EQUAL 271
#define T_CONCAT_EQUAL 272
#define T_MOD_EQUAL 273
#define T_AND_EQUAL 274
#define T_OR_EQUAL 275
#define T_XOR_EQUAL 276
#define T_SL_EQUAL 277
#define T_SR_EQUAL 278
#define T_BOOLEAN_OR 279
#define T_BOOLEAN_AND 280
#define T_IS_EQUAL 281
#define T_IS_NOT_EQUAL 282
#define T_IS_IDENTICAL 283
#define T_IS_NOT_IDENTICAL 284
#define T_IS_SMALLER_OR_EQUAL 285
#define T_IS_GREATER_OR_EQUAL 286
#define T_SL 287
#define T_SR 288
#define T_INSTANCEOF 289
#define T_INC 290
#define T_DEC 291
#define T_INT_CAST 292
#define T_DOUBLE_CAST 293
#define T_STRING_CAST 294
#define T_ARRAY_CAST 295
#define T_OBJECT_CAST 296
#define T_BOOL_CAST 297
#define T_UNSET_CAST 298
#define T_NEW 299
#define T_CLONE 300
#define T_EXIT 301
#define T_IF 302
#define T_ELSEIF 303
#define T_ELSE 304
#define T_ENDIF 305
#define T_LNUMBER 306
#define T_DNUMBER 307
#define T_STRING 308
#define T_STRING_VARNAME 309
#define T_VARIABLE 310
#define T_NUM_STRING 311
#define T_INLINE_HTML 312
#define T_CHARACTER 313
#define T_BAD_CHARACTER 314
#define T_ENCAPSED_AND_WHITESPACE 315
#define T_CONSTANT_ENCAPSED_STRING 316
#define T_ECHO 317
#define T_DO 318
#define T_WHILE 319
#define T_ENDWHILE 320
#define T_FOR 321
#define T_ENDFOR 322
#define T_FOREACH 323
#define T_ENDFOREACH 324
#define T_DECLARE 325
#define T_ENDDECLARE 326
#define T_AS 327
#define T_SWITCH 328
#define T_ENDSWITCH 329
#define T_CASE 330
#define T_DEFAULT 331
#define T_BREAK 332
#define T_CONTINUE 333
#define T_GOTO 334
#define T_FUNCTION 335
#define T_CONST 336
#define T_RETURN 337
#define T_TRY 338
#define T_CATCH 339
#define T_FINALLY 340
#define T_THROW 341
#define T_USE 342
#define T_INSTEADOF 343
#define T_GLOBAL 344
#define T_STATIC 345
#define T_ABSTRACT 346
#define T_FINAL 347
#define T_PRIVATE 348
#define T_PROTECTED 349
#define T_PUBLIC 350
#define T_VAR 351
#define T_UNSET 352
#define T_ISSET 353
#define T_EMPTY 354
#define T_HALT_COMPILER 355
#define T_CLASS 356
#define T_TRAIT 357
#define T_INTERFACE 358
#define T_EXTENDS 359
#define T_IMPLEMENTS 360
#define T_OBJECT_OPERATOR 361
#define T_DOUBLE_ARROW 362
#define T_LIST 363
#define T_ARRAY 364
#define T_CALLABLE 365
#define T_CLASS_C 366
#define T_TRAIT_C 367
#define T_METHOD_C 368
#define T_FUNC_C 369
#define T_LINE 370
#define T_FILE 371
#define T_COMMENT 372
#define T_DOC_COMMENT 373
#define T_OPEN_TAG 374
#define T_OPEN_TAG_WITH_ECHO 375
#define T_CLOSE_TAG 376
#define T_WHITESPACE 377
#define T_START_HEREDOC 378
#define T_END_HEREDOC 379
#define T_DOLLAR_OPEN_CURLY_BRACES 380
#define T_CURLY_OPEN 381
#define T_PAAMAYIM_NEKUDOTAYIM 382
#define T_NAMESPACE 383
#define T_NS_C 384
#define T_DIR 385
#define T_NS_SEPARATOR 386
#define T_ELLIPSIS 387
#define T_POW 388
#define T_POW_EQUAL 389

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int zendparse (void);


#endif /* !YY_ZEND_ZEND_ZEND_LANGUAGE_PARSER_H_INCLUDED  */
