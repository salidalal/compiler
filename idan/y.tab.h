/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    DOUBLE = 259,
    SEMICOLON = 260,
    PROC = 261,
    FUNC = 262,
    RETURN = 263,
    NUL = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    FOR = 268,
    VAR = 269,
    INT = 270,
    CHAR = 271,
    REAL = 272,
    INTP = 273,
    CHARP = 274,
    REALP = 275,
    BOOL = 276,
    STRING = 277,
    LB = 278,
    RB = 279,
    LCB = 280,
    RCB = 281,
    LSB = 282,
    RSB = 283,
    COLON = 284,
    COMMA = 285,
    GREATER = 286,
    GREATEREQUAL = 287,
    LESS = 288,
    LESSEQUAL = 289,
    EQUAL = 290,
    AND = 291,
    DIVIDE = 292,
    ASSIGNMENT = 293,
    LENGTH = 294,
    PLUS = 295,
    MINUS = 296,
    MULT = 297,
    OR = 298,
    REF = 299,
    DEREF = 300,
    NOT = 301,
    DIFF = 302,
    TRUE = 303,
    FALSE = 304,
    IDENTIFIER = 305,
    CHARACTER = 306,
    STR = 307,
    MAIN = 308
  };
#endif
/* Tokens.  */
#define NUM 258
#define DOUBLE 259
#define SEMICOLON 260
#define PROC 261
#define FUNC 262
#define RETURN 263
#define NUL 264
#define IF 265
#define ELSE 266
#define WHILE 267
#define FOR 268
#define VAR 269
#define INT 270
#define CHAR 271
#define REAL 272
#define INTP 273
#define CHARP 274
#define REALP 275
#define BOOL 276
#define STRING 277
#define LB 278
#define RB 279
#define LCB 280
#define RCB 281
#define LSB 282
#define RSB 283
#define COLON 284
#define COMMA 285
#define GREATER 286
#define GREATEREQUAL 287
#define LESS 288
#define LESSEQUAL 289
#define EQUAL 290
#define AND 291
#define DIVIDE 292
#define ASSIGNMENT 293
#define LENGTH 294
#define PLUS 295
#define MINUS 296
#define MULT 297
#define OR 298
#define REF 299
#define DEREF 300
#define NOT 301
#define DIFF 302
#define TRUE 303
#define FALSE 304
#define IDENTIFIER 305
#define CHARACTER 306
#define STR 307
#define MAIN 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "file.y" /* yacc.c:1909  */

  char* value;
  Node* nPtr;

#line 165 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
