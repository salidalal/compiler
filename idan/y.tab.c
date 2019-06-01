/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 8 "file.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "definitions.h"
#include "lex.yy.c"

#include "Tree.c"
#include "SymTable.c"
#include "Semantics.c"
#include "3AC.c"


#line 82 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 23 "file.y" /* yacc.c:355  */

    char *value;
    Node *nPtr;

#line 233 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 250 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   415

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    68,    69,    70,    74,    75,    79,    81,
      86,    88,    93,    97,   101,   102,   106,   110,   111,   115,
     116,   117,   118,   119,   120,   121,   122,   134,   135,   139,
     143,   145,   150,   151,   152,   153,   154,   155,   156,   157,
     161,   162,   166,   167,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   183,   185,   189,   190,   194,   198,   199,
     203,   205,   210,   214,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   239,   240
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "DOUBLE", "SEMICOLON", "PROC",
  "FUNC", "RETURN", "NUL", "IF", "ELSE", "WHILE", "FOR", "VAR", "INT",
  "CHAR", "REAL", "INTP", "CHARP", "REALP", "BOOL", "STRING", "LB", "RB",
  "LCB", "RCB", "LSB", "RSB", "COLON", "COMMA", "GREATER", "GREATEREQUAL",
  "LESS", "LESSEQUAL", "EQUAL", "AND", "DIVIDE", "ASSIGNMENT", "LENGTH",
  "PLUS", "MINUS", "MULT", "OR", "REF", "DEREF", "NOT", "DIFF", "TRUE",
  "FALSE", "IDENTIFIER", "CHARACTER", "STR", "MAIN", "$accept", "program",
  "process", "code", "proc", "func", "retType", "parameters", "arguments",
  "argumentList", "args", "type", "body", "main", "funcbody", "retval",
  "bool", "statements", "statement", "funcCall", "funcArgs",
  "retStatement", "if", "loop", "declare", "assign", "exp", "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -119

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-119)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,     9,   -40,    11,  -119,    14,  -119,  -119,  -119,     6,
      29,    34,    40,  -119,  -119,   155,    48,   -22,   -20,  -119,
    -119,  -119,   155,   -40,   155,   155,   155,  -119,  -119,     4,
    -119,  -119,  -119,  -119,  -119,   351,  -119,    44,    44,    52,
    -119,    60,    45,  -119,    69,    65,   294,    49,  -119,  -119,
    -119,   122,  -119,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   155,    41,  -119,  -119,    44,   -40,
      64,   -40,    64,    84,  -119,  -119,  -119,   -11,   368,   194,
     194,   194,   194,   194,  -119,   -28,    61,    61,   -28,    57,
     194,   -40,   155,    71,    73,    82,   -40,  -119,  -119,  -119,
    -119,   183,  -119,   101,  -119,  -119,  -119,  -119,   103,    75,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,  -119,    87,
    -119,  -119,    86,  -119,    64,  -119,   155,   210,   155,   155,
     -40,   110,  -119,  -119,  -119,  -119,   155,   113,   173,  -119,
      86,   368,  -119,   314,   334,   115,  -119,   368,    90,   155,
     204,  -119,   214,   214,   155,  -119,   235,   155,   111,  -119,
     253,    95,   274,   214,   -40,  -119,    97,  -119,   100,  -119,
     214,  -119
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     2,     4,     6,     7,     5,    82,
       0,     0,     0,     1,     3,     0,     0,     0,     0,    32,
      33,    38,     0,     0,     0,     0,     0,    40,    41,    82,
      34,    35,    81,    37,    80,     0,    36,     0,     0,     0,
      13,    14,     0,    18,     0,     0,     0,     0,    77,    78,
      76,     0,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     9,     0,     0,
       0,     0,     0,     0,    79,    39,    54,     0,    56,    70,
      71,    72,    73,    69,    68,    67,    64,    65,    66,    75,
      74,     0,     0,     0,     0,     0,     0,    28,    49,    48,
      47,     0,    43,     0,    51,    44,    46,    50,     0,     0,
       8,    15,    19,    20,    21,    22,    23,    24,    25,     0,
      16,    17,     0,    12,     0,    53,     0,     0,     0,     0,
       0,     0,    27,    42,    52,    45,     0,     0,     0,    11,
       0,    55,    57,     0,     0,     0,    62,    63,     0,     0,
       0,    10,     0,     0,     0,    26,     0,     0,    58,    60,
       0,    57,     0,     0,     0,    31,    57,    59,     0,    30,
       0,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -119,  -119,   123,  -119,    18,    24,     3,   114,    67,    37,
    -119,    70,   -12,  -119,    -6,  -119,  -119,     1,   -92,   -51,
    -119,  -119,  -119,  -119,  -119,  -118,   -19,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    98,    99,   122,    39,    40,    41,
      42,   123,   100,     8,   139,    32,    33,   101,   102,    34,
      77,   104,   105,   106,   107,   108,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    12,    38,    46,    44,    48,    49,    50,    58,   133,
       9,    13,   145,   125,   103,    63,    43,    43,     6,   126,
       1,     2,    47,     6,     7,    66,    67,    51,     9,     7,
       9,    15,    78,    15,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   168,    91,     2,    92,
     103,    93,    16,    94,    95,    96,   110,    17,   133,     9,
     158,   159,    10,    18,   109,    69,    65,    97,    43,    65,
     121,   167,    37,   127,    70,    71,    68,    72,   171,   112,
     113,   114,   115,   116,   117,   118,   119,   103,    75,    73,
      11,    29,   124,    58,   128,    43,   129,    58,    59,   103,
     109,   103,   103,    62,    63,   130,   134,   141,   135,   143,
     144,   138,   103,   136,   137,   146,   148,   147,   155,   103,
     154,   165,   163,   169,   170,    19,    20,   140,    14,   109,
     156,    21,    45,   131,   151,   160,   111,   109,   162,   150,
     120,     0,     0,     0,     0,    22,    76,     0,     0,   109,
       0,   109,   109,     0,     0,     0,     0,     0,    19,    20,
       0,    23,   109,   109,    21,     0,    24,    25,    26,   109,
      27,    28,    29,    30,    31,     0,     0,     0,    22,    91,
       2,   149,     0,    93,     0,    94,    95,    96,     0,    91,
       2,    92,     0,    93,    23,    94,    95,    96,    65,    24,
      25,    26,     0,    27,    28,    29,    30,    31,    65,   132,
      91,     2,   157,     0,    93,   142,    94,    95,    96,     0,
      91,     2,    92,    29,    93,     0,    94,    95,    96,    65,
      58,    59,     0,    29,    60,    61,    62,    63,     0,    65,
     161,    53,    54,    55,    56,    57,    58,    59,     0,     0,
      60,    61,    62,    63,    29,     0,     0,    64,   164,     0,
       0,     0,     0,     0,    29,     0,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    60,    61,    62,    63,   166,
       0,     0,    64,     0,    53,    54,    55,    56,    57,    58,
      59,     0,     0,    60,    61,    62,    63,     0,     0,     0,
      64,     0,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,    61,    62,    63,    74,     0,
       0,    64,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,    61,    62,    63,   152,     0,
       0,    64,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,    61,    62,    63,   153,     0,
       0,    64,     0,     0,     0,    53,    54,    55,    56,    57,
      58,    59,     0,     0,    60,    61,    62,    63,     0,    52,
       0,    64,    53,    54,    55,    56,    57,    58,    59,     0,
       0,    60,    61,    62,    63,     0,     0,     0,    64,    53,
      54,    55,    56,    57,    58,    59,     0,     0,    60,    61,
      62,    63,     0,     0,     0,    64
};

static const yytype_int16 yycheck[] =
{
       1,     2,    24,    22,    24,    24,    25,    26,    36,   101,
      50,     0,   130,    24,    65,    43,    17,    18,     0,    30,
       6,     7,    23,     5,     0,    37,    38,    23,    50,     5,
      50,    27,    51,    27,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   164,     6,     7,     8,
     101,    10,    23,    12,    13,    14,    68,    23,   150,    50,
     152,   153,    53,    23,    65,     5,    25,    26,    69,    25,
      71,   163,    24,    92,    29,    30,    24,     8,   170,    15,
      16,    17,    18,    19,    20,    21,    22,   138,    39,    24,
      91,    50,     8,    36,    23,    96,    23,    36,    37,   150,
     101,   152,   153,    42,    43,    23,     5,   126,     5,   128,
     129,    25,   163,    38,    27,     5,     3,   136,    28,   170,
       5,    26,    11,    26,    24,     3,     4,   124,     5,   130,
     149,     9,    18,    96,   140,   154,    69,   138,   157,   138,
      70,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,   150,
      -1,   152,   153,    -1,    -1,    -1,    -1,    -1,     3,     4,
      -1,    39,   163,   164,     9,    -1,    44,    45,    46,   170,
      48,    49,    50,    51,    52,    -1,    -1,    -1,    23,     6,
       7,     8,    -1,    10,    -1,    12,    13,    14,    -1,     6,
       7,     8,    -1,    10,    39,    12,    13,    14,    25,    44,
      45,    46,    -1,    48,    49,    50,    51,    52,    25,    26,
       6,     7,     8,    -1,    10,     5,    12,    13,    14,    -1,
       6,     7,     8,    50,    10,    -1,    12,    13,    14,    25,
      36,    37,    -1,    50,    40,    41,    42,    43,    -1,    25,
       5,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      40,    41,    42,    43,    50,    -1,    -1,    47,     5,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    41,    42,    43,     5,
      -1,    -1,    47,    -1,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    40,    41,    42,    43,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    24,    -1,
      -1,    47,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    24,    -1,
      -1,    47,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    24,    -1,
      -1,    47,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    40,    41,    42,    43,    -1,    28,
      -1,    47,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    42,    43,    -1,    -1,    -1,    47,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    40,    41,
      42,    43,    -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    55,    56,    57,    58,    59,    67,    50,
      53,    81,    81,     0,    56,    27,    23,    23,    23,     3,
       4,     9,    23,    39,    44,    45,    46,    48,    49,    50,
      51,    52,    69,    70,    73,    80,    81,    24,    24,    61,
      62,    63,    64,    81,    24,    61,    80,    81,    80,    80,
      80,    23,    28,    31,    32,    33,    34,    35,    36,    37,
      40,    41,    42,    43,    47,    25,    66,    66,    24,     5,
      29,    30,     8,    24,    24,    39,    24,    74,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,     6,     8,    10,    12,    13,    14,    26,    58,    59,
      66,    71,    72,    73,    75,    76,    77,    78,    79,    81,
      66,    62,    15,    16,    17,    18,    19,    20,    21,    22,
      65,    81,    60,    65,     8,    24,    30,    80,    23,    23,
      23,    63,    26,    72,     5,     5,    38,    27,    25,    68,
      60,    80,     5,    80,    80,    79,     5,    80,     3,     8,
      71,    68,    24,    24,     5,    28,    80,     8,    72,    72,
      80,     5,    80,    11,     5,    26,     5,    72,    79,    26,
      24,    72
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    57,    57,    58,    58,
      59,    59,    60,    61,    62,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    70,    71,    71,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    73,    74,    74,    75,    76,    76,
      77,    77,    78,    79,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       8,     7,     1,     1,     1,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     2,     5,
       6,     5,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     2,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     4,     3,     3,     1,     3,     5,     7,
       5,     9,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     3,
       1,     1,     1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 51 "file.y" /* yacc.c:1646  */
    {
        reverseChilds(pTree);
        makeParents(pTree, 1);
        initScopes(pTree);
        // printScopes();
        checkSemantics(pTree, 1);
        errorSummary();
        // if(numOfErrors == 0)
            print(pTree);
        //start3AC(pTree);
         //printCode(pTree);
         //printAllCodes(pTree);
        
    }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 68 "file.y" /* yacc.c:1646  */
    { addChild(pTree, (yyvsp[-1].nPtr)); }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 69 "file.y" /* yacc.c:1646  */
    { addChild(pTree, (yyvsp[0].nPtr)); }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "file.y" /* yacc.c:1646  */
    { addChild(pTree, (yyvsp[0].nPtr)); }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 74 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 75 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1538 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 80 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("PROC", (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL);}
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 82 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("PROC", (yyvsp[-3].nPtr), createNode("ARGS NONE", NULL), (yyvsp[0].nPtr), NULL);}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 87 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("FUNC", (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-1].nPtr), (yyvsp[0].nPtr), NULL);}
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("FUNC", (yyvsp[-5].nPtr), createNode("ARGS NONE", NULL), (yyvsp[-1].nPtr), (yyvsp[0].nPtr), NULL);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 93 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("RET", createNode((yyvsp[0].value), NULL), NULL); }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 97 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("ARGS", (yyvsp[0].nPtr), NULL); }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 101 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("", (yyvsp[0].nPtr), NULL); }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 102 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 106 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode((yyvsp[0].value), (yyvsp[-2].nPtr), NULL);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 110 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 115 "file.y" /* yacc.c:1646  */
    { (yyval.value) = yylval.value; }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 116 "file.y" /* yacc.c:1646  */
    { (yyval.value) = yylval.value; }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 117 "file.y" /* yacc.c:1646  */
    { (yyval.value) = yylval.value; }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 118 "file.y" /* yacc.c:1646  */
    { (yyval.value) = yylval.value; }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 119 "file.y" /* yacc.c:1646  */
    { (yyval.value) = yylval.value; }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 120 "file.y" /* yacc.c:1646  */
    { (yyval.value) = yylval.value; }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "file.y" /* yacc.c:1646  */
    { (yyval.value) = yylval.value; }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 123 "file.y" /* yacc.c:1646  */
    {
        char *s = (char *)malloc(sizeof(char));
        strcat(s, (yyvsp[-3].value));
        strcat(s, "[");
        strcat(s, (yyvsp[-1].value));
        strcat(s, "]");
        (yyval.value) = s;
    }
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 134 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("BLOCK", (yyvsp[-1].nPtr), NULL); }
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 135 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("BLOCK", NULL); }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 139 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("MAIN", (yyvsp[0].nPtr), NULL); }
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 144 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("BODY", (yyvsp[-4].nPtr), createNode("RETURN", (yyvsp[-2].nPtr), NULL), NULL);}
#line 1683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 146 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("BODY", createNode("RETURN", (yyvsp[-2].nPtr), NULL), NULL);}
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 150 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode(yylval.value, NULL); }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 151 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode(yylval.value, NULL); }
#line 1701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 152 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode(yylval.value, NULL); }
#line 1707 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 153 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode(yylval.value, NULL); }
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 154 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 155 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode((yyvsp[0].value), NULL); }
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 156 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode(yylval.value, NULL); }
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 157 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("LEN", (yyvsp[-1].nPtr), NULL);}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 161 "file.y" /* yacc.c:1646  */
    { (yyval.value) = yylval.value; }
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 162 "file.y" /* yacc.c:1646  */
    { (yyval.value) = yylval.value; }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 166 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("", (yyvsp[-1].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 167 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 171 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 172 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 173 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 174 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 175 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 176 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 177 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 178 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 179 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 184 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("CALL", createNode((yyvsp[-3].value), createNode("", (yyvsp[-1].nPtr), NULL), NULL), NULL);}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 185 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("CALL", createNode((yyvsp[-2].value), NULL), NULL);}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 189 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 190 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 194 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("RETURN", (yyvsp[-1].nPtr), NULL);}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 198 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("IF", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL);}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 199 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("IF-ELSE", (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL);}
#line 1857 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 204 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("WHILE", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL);}
#line 1863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 206 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("FOR", (yyvsp[-6].nPtr), (yyvsp[-4].nPtr), (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL);}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 210 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("VAR", (yyvsp[-1].nPtr), NULL); }
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 214 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("=", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL);}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 218 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("+", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 219 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("-", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 220 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("*", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 221 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("/", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 222 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("&&", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 223 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("==", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 224 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode(">", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 225 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode(">=", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 226 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("<", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 227 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("<=", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 228 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("!=", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 229 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("||", (yyvsp[-2].nPtr), (yyvsp[0].nPtr), NULL); }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 230 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("!", (yyvsp[0].nPtr), NULL); }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 231 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("&", (yyvsp[0].nPtr), NULL); }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 232 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode("^", (yyvsp[0].nPtr), NULL); }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 233 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 234 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 235 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 239 "file.y" /* yacc.c:1646  */
    { (yyval.nPtr) = createNode(yylval.value, NULL); }
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 240 "file.y" /* yacc.c:1646  */
    {(yyval.nPtr) = createNode("[]", createNode((yyvsp[-3].value), NULL), (yyvsp[-1].nPtr), NULL);}
#line 2001 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2005 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 243 "file.y" /* yacc.c:1906  */


int main(){
    pTree = createNode("CODE", NULL);
    yyparse();
    return 0;
}

//YACC functions
void yyerror(char *s){
    fprintf(stderr, "%s ", s);
    printf("while reading token '%s'\n", yytext);
}

int yywrap(){
    return 1;
}
