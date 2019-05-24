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
#line 1 "project.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdarg.h>
#include <malloc.h>
#include "node.c"
#include "symTbl.c"



Node * tree;



void closeTree();

int yylex(void);
void yyerror(char*);
extern char* yytext;

#define YYSTYPE struct Node *

#line 90 "y.tab.c" /* yacc.c:339  */

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
    TYPE_BOOL = 258,
    TYPE_CHAR = 259,
    TYPE_INT = 260,
    TYPE_REAL = 261,
    TYPE_STRING = 262,
    INT_PTR = 263,
    CHAR_PTR = 264,
    REAL_PTR = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    FOR = 269,
    PROC = 270,
    FUNC = 271,
    VAR = 272,
    MAIN = 273,
    RETURN = 274,
    TYPE_NULL = 275,
    BOOL_TRUE = 276,
    BOOL_FALSE = 277,
    REAL = 278,
    ID = 279,
    INT = 280,
    CHAR = 281,
    STRING = 282,
    AND = 283,
    DIVIDE = 284,
    EQ = 285,
    EQEQ = 286,
    GT = 287,
    GTE = 288,
    LT = 289,
    LTE = 290,
    MINUS = 291,
    NOT = 292,
    NOTEQ = 293,
    OR = 294,
    PLUS = 295,
    MUL = 296,
    AMP = 297,
    DEREF = 298
  };
#endif
/* Tokens.  */
#define TYPE_BOOL 258
#define TYPE_CHAR 259
#define TYPE_INT 260
#define TYPE_REAL 261
#define TYPE_STRING 262
#define INT_PTR 263
#define CHAR_PTR 264
#define REAL_PTR 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define FOR 269
#define PROC 270
#define FUNC 271
#define VAR 272
#define MAIN 273
#define RETURN 274
#define TYPE_NULL 275
#define BOOL_TRUE 276
#define BOOL_FALSE 277
#define REAL 278
#define ID 279
#define INT 280
#define CHAR 281
#define STRING 282
#define AND 283
#define DIVIDE 284
#define EQ 285
#define EQEQ 286
#define GT 287
#define GTE 288
#define LT 289
#define LTE 290
#define MINUS 291
#define NOT 292
#define NOTEQ 293
#define OR 294
#define PLUS 295
#define MUL 296
#define AMP 297
#define DEREF 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 227 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
      49,    50,     2,     2,    23,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,    21,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,    53,    48,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    58,    59,    60,    61,    64,    69,    71,
      77,    80,    81,    85,    86,    90,    91,    93,    98,    99,
     102,   103,   106,   113,   116,   120,   123,   127,   128,   129,
     130,   131,   132,   133,   136,   137,   145,   146,   147,   148,
     149,   150,   154,   155,   156,   157,   158,   161,   165,   166,
     175,   178,   179,   182,   187,   191,   192,   195,   198,   201,
     204,   208,   209,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   232,   233,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     240,   241,   242,   243,   244,   245,   246,   247,   250,   251,
     254,   258,   261,   262,   265,   266,   269,   270,   271,   272,
     273
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE_BOOL", "TYPE_CHAR", "TYPE_INT",
  "TYPE_REAL", "TYPE_STRING", "INT_PTR", "CHAR_PTR", "REAL_PTR", "IF",
  "ELSE", "WHILE", "FOR", "PROC", "FUNC", "VAR", "MAIN", "RETURN",
  "TYPE_NULL", "';'", "':'", "','", "BOOL_TRUE", "BOOL_FALSE", "REAL",
  "ID", "INT", "CHAR", "STRING", "AND", "DIVIDE", "EQ", "EQEQ", "GT",
  "GTE", "LT", "LTE", "MINUS", "NOT", "NOTEQ", "OR", "PLUS", "MUL", "AMP",
  "DEREF", "'{'", "'}'", "'('", "')'", "'['", "']'", "'|'", "$accept",
  "program", "code", "func", "proc", "main", "get_arg", "args_list",
  "yes_args", "args", "no_args", "call_args", "args_2", "arg_type",
  "continue_func", "proc_id", "continue_proc", "body", "return_va",
  "the_ret", "statment", "semico", "statmentss", "var_decls", "ids",
  "initign_statment", "if_statment", "else_statment", "while_statment",
  "for_statment", "for_cond", "init", "block", "expression", "lhs",
  "value", "type", "id", "ref", "call", "len", "boolean", "string", "char",
  "real", "int", "null", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    59,    58,    44,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   123,   125,    40,
      41,    91,    93,   124
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -116,     7,     3,  -116,   -10,   -21,  -116,  -116,  -116,   -38,
    -116,    -3,   -22,  -116,   -14,   -18,  -116,   -21,   -21,     6,
       4,  -116,    36,    -2,  -116,  -116,    15,   178,  -116,     6,
     -21,    84,   -21,    47,    21,    26,    27,   -21,   -21,   202,
      29,   178,  -116,  -116,    19,  -116,  -116,   178,  -116,  -116,
    -116,  -116,  -116,    49,    34,    48,  -116,    16,  -116,  -116,
    -116,  -116,    55,  -116,  -116,  -116,  -116,  -116,  -116,    93,
     202,   202,   -17,    18,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,   202,    58,   202,   -15,   222,  -116,    34,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   202,    31,
    -116,  -116,   202,   202,  -116,  -116,    84,    79,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,    61,   274,   291,    62,
      48,    80,  -116,    84,   -21,    20,  -116,   308,    63,    64,
    -116,   202,   202,   202,   202,   202,   202,   202,   202,   202,
     202,   202,   202,   255,  -116,   241,  -116,    65,    91,   325,
    -116,    66,   178,   178,   193,   193,   202,   202,    98,  -116,
    -116,  -116,  -116,    17,  -116,    20,    20,    20,    20,    20,
    -116,   339,    17,  -116,  -116,  -116,  -116,  -116,   202,  -116,
     102,   110,   154,  -116,  -116,  -116,   241,   325,  -116,   325,
      75,   178,  -116,  -116,   -17,  -116,  -116,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     1,     0,     0,     4,     3,     5,     0,
      98,     0,     0,    24,     0,     0,    99,    17,    17,     0,
       0,    10,    12,     0,    11,    15,     0,    35,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      98,    35,    44,    45,     0,    46,    49,    26,    41,    40,
      37,    39,    38,     0,    78,     0,     8,     0,    91,    92,
      90,    93,     0,    95,    96,    97,    13,    22,    16,     0,
       0,     0,     0,     0,    52,   110,   104,   105,   108,   109,
     107,   106,     0,     0,     0,     0,     0,    77,    80,    88,
      87,    86,    81,    82,    83,    84,    85,    89,     0,     0,
      25,    48,     0,    17,    47,    36,     0,     0,    29,    28,
      27,    30,    31,    32,    33,     7,     0,     0,     0,     0,
       0,     0,    78,     0,     0,    72,   100,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,     0,    19,     0,    18,    20,
      14,     0,    35,    35,    35,    35,     0,     0,     0,    51,
      76,   102,   103,    75,    66,    67,    68,    69,    70,    71,
      64,    73,    74,    63,    65,    79,    53,   101,     0,    94,
      35,    56,     0,    62,    57,    58,     0,    60,    50,    21,
       0,    35,    54,    61,     0,    23,    55,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -116,  -116,  -116,   122,   123,  -116,   108,  -116,  -116,   116,
      50,  -116,  -116,    46,  -116,   127,   125,     8,  -116,   -24,
     -44,  -115,   -37,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,   -39,     9,     2,   -63,  -116,    38,    -4,  -116,   -25,
    -116,  -116,    77,  -116,  -116,    56,  -116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    42,    43,     8,    20,    21,    22,    23,
      24,   147,   148,    66,   115,    12,    28,    44,   116,    45,
      46,   105,    47,    48,    73,    49,    50,   192,    51,    52,
     119,   120,   184,    86,    53,    87,    67,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    13,    55,   101,    99,   156,    10,     3,     9,   121,
      40,    15,    10,    25,    25,    81,    55,    10,     4,     5,
      31,    32,    55,    54,    16,    11,    25,    17,    68,    11,
     176,    11,    19,    13,    74,    18,    11,    54,   106,    32,
     123,   124,    34,    54,    35,    36,    37,     5,    38,   132,
      39,   131,   132,    27,    29,   101,   138,    30,    40,   138,
     141,   142,   140,   141,   142,    33,    69,   100,   122,   104,
      70,   194,   117,   118,    55,    71,    72,    11,    41,   144,
      98,   128,   102,   103,   125,   126,   127,    58,    59,    60,
      61,    62,    63,    64,    65,    54,   108,   109,   110,   111,
     143,   112,   113,   114,   145,   149,   107,    79,   152,   181,
     183,   183,   155,   157,   178,   177,   161,   162,   179,   188,
     159,    39,   191,   195,     6,     7,    26,    55,    55,    55,
      55,   121,    14,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    99,    57,   196,    54,    54,
      54,    54,   150,   146,    56,   197,   190,    55,   186,   187,
     180,   158,   129,   151,   185,    34,    55,    35,    36,    37,
       5,    38,     0,    39,     0,     0,     0,     0,    54,     0,
     189,    40,     0,     0,     0,     0,     0,    54,     0,    34,
     122,    35,    36,    37,     5,    38,     0,    39,     0,     0,
      11,    41,   193,     0,    34,    40,    35,    36,    37,     5,
      38,     0,    39,     0,     0,     0,     0,     0,     0,     0,
      40,     0,    75,     0,    11,    41,    76,    77,    78,    10,
      79,    80,    81,     0,     0,     0,     0,     0,     0,    11,
     182,     0,    82,   130,     0,     0,     0,    83,    11,     0,
       0,    84,     0,   131,   132,    85,   133,   134,   135,   136,
     137,   138,   104,   139,   140,   141,   142,     0,     0,     0,
       0,     0,   131,   132,     0,   133,   134,   135,   136,   137,
     138,     0,   139,   140,   141,   142,   131,   132,     0,   133,
     134,   135,   136,   137,   138,     0,   139,   140,   141,   142,
       0,     0,     0,     0,     0,   131,   132,   175,   133,   134,
     135,   136,   137,   138,     0,   139,   140,   141,   142,     0,
       0,     0,   131,   132,   153,   133,   134,   135,   136,   137,
     138,     0,   139,   140,   141,   142,     0,     0,     0,   131,
     132,   154,   133,   134,   135,   136,   137,   138,     0,   139,
     140,   141,   142,     0,     0,     0,   131,   132,   160,   133,
     134,   135,   136,   137,   138,     0,   139,   140,   141,   142,
     131,   132,     0,   133,   134,   135,   136,   137,   138,     0,
       0,   140,   141,   142
};

static const yytype_int16 yycheck[] =
{
       4,     5,    27,    47,    41,   120,    27,     0,    18,    72,
      27,    49,    27,    17,    18,    30,    41,    27,    15,    16,
      22,    23,    47,    27,    27,    46,    30,    49,    32,    46,
     145,    46,    50,    37,    38,    49,    46,    41,    22,    23,
      22,    23,    11,    47,    13,    14,    15,    16,    17,    32,
      19,    31,    32,    47,    50,    99,    39,    21,    27,    39,
      43,    44,    42,    43,    44,    50,    19,    48,    72,    21,
      49,   186,    70,    71,    99,    49,    49,    46,    47,    48,
      51,    85,    33,    49,    82,    27,    84,     3,     4,     5,
       6,     7,     8,     9,    10,    99,     3,     4,     5,     6,
      98,     8,     9,    10,   102,   103,    51,    28,    47,   153,
     154,   155,    50,    33,    23,    50,    53,    53,    52,    21,
     124,    19,    12,    48,     2,     2,    18,   152,   153,   154,
     155,   194,     5,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   182,    30,   191,   152,   153,
     154,   155,   106,   103,    29,   194,   180,   182,   156,   157,
     152,   123,    85,   107,   155,    11,   191,    13,    14,    15,
      16,    17,    -1,    19,    -1,    -1,    -1,    -1,   182,    -1,
     178,    27,    -1,    -1,    -1,    -1,    -1,   191,    -1,    11,
     194,    13,    14,    15,    16,    17,    -1,    19,    -1,    -1,
      46,    47,    48,    -1,    11,    27,    13,    14,    15,    16,
      17,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    -1,    20,    -1,    46,    47,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    40,    21,    -1,    -1,    -1,    45,    46,    -1,
      -1,    49,    -1,    31,    32,    53,    34,    35,    36,    37,
      38,    39,    21,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    31,    32,    52,    34,    35,
      36,    37,    38,    39,    -1,    41,    42,    43,    44,    -1,
      -1,    -1,    31,    32,    50,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    -1,    -1,    -1,    31,
      32,    50,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    -1,    -1,    -1,    31,    32,    50,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    56,     0,    15,    16,    57,    58,    59,    18,
      27,    46,    69,    91,    69,    49,    27,    49,    49,    50,
      60,    61,    62,    63,    64,    91,    60,    47,    70,    50,
      21,    22,    23,    50,    11,    13,    14,    15,    17,    19,
      27,    47,    57,    58,    71,    73,    74,    76,    77,    79,
      80,    82,    83,    88,    91,    93,    70,    63,     3,     4,
       5,     6,     7,     8,     9,    10,    67,    90,    91,    19,
      49,    49,    49,    78,    91,    20,    24,    25,    26,    28,
      29,    30,    40,    45,    49,    53,    87,    89,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,    51,    76,
      48,    74,    33,    49,    21,    75,    22,    51,     3,     4,
       5,     6,     8,     9,    10,    68,    72,    87,    87,    84,
      85,    88,    91,    22,    23,    87,    27,    87,    91,    96,
      21,    31,    32,    34,    35,    36,    37,    38,    39,    41,
      42,    43,    44,    87,    48,    87,    64,    65,    66,    87,
      67,    99,    47,    50,    50,    50,    75,    33,    90,    91,
      50,    53,    53,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    52,    75,    50,    23,    52,
      71,    74,    47,    74,    86,    86,    87,    87,    21,    87,
      73,    12,    81,    48,    75,    48,    74,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    56,    57,    58,    59,
      60,    61,    61,    62,    62,    63,    63,    64,    65,    65,
      66,    66,    67,    68,    69,    70,    71,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    76,    76,
      77,    78,    78,    79,    80,    81,    81,    82,    83,    84,
      85,    86,    86,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    93,    94,    94,    95,    95,    96,    97,    98,    99,
     100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     7,     6,     5,
       1,     1,     1,     3,     5,     1,     3,     0,     1,     1,
       1,     3,     1,     5,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     2,     1,     1,     1,
       1,     1,     3,     0,     1,     1,     1,     1,     2,     1,
       5,     3,     1,     4,     6,     2,     0,     5,     5,     5,
       3,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     1,     1,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     2,
       2,     4,     3,     3,     1,     1,     1,     1,     1,     1,
       1
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
#line 55 "project.y" /* yacc.c:1646  */
    { 	 closeTree();}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 58 "project.y" /* yacc.c:1646  */
    {addToTree((yyvsp[0]),tree);}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 59 "project.y" /* yacc.c:1646  */
    {addToTree((yyvsp[0]),tree);}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 60 "project.y" /* yacc.c:1646  */
    {addToTree((yyvsp[0]),tree);}
#line 1506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 64 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("FUNC",(yyvsp[-5]),(yyvsp[-3]),(yyvsp[0])->sons[0],(yyvsp[0])->sons[1],(yyvsp[0])->sons[2],NULL);}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 69 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("PROC",(yyvsp[-4]),(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 71 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("MAIN",(yyvsp[0]),NULL); }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 77 "project.y" /* yacc.c:1646  */
    {  (yyvsp[0])->value="ARGS"; (yyval)=(yyvsp[0]); }
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 80 "project.y" /* yacc.c:1646  */
    {  (yyval) = (yyvsp[0]); }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 81 "project.y" /* yacc.c:1646  */
    { if((yyvsp[0])->size>1){Node*temp = makeNode("",NULL); fixRec((yyvsp[0]),temp);  (yyvsp[0])=temp;} (yyval) = (yyvsp[0]); }
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 85 "project.y" /* yacc.c:1646  */
    {Node*temp = makeNode("",NULL);fixRec((yyvsp[-2]),temp);  temp->value = (yyvsp[0])->value; (yyval) = temp ; }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 86 "project.y" /* yacc.c:1646  */
    {    Node*temp = makeNode("",NULL);fixRec((yyvsp[-2]),temp);  temp->value =(yyvsp[0])->value; (yyvsp[-2]) = makeNode((yyvsp[0])->value,temp,NULL); 
													(yyval) = makeNode("REC ARGS",temp,(yyvsp[-4])); }
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 90 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 91 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("REC ARGS",(yyvsp[0]),(yyvsp[-2]),NULL);}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 93 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("NONE",NULL);}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 98 "project.y" /* yacc.c:1646  */
    { Node*temp = makeNode("",NULL);fixRec((yyvsp[0]),temp); (yyval)=temp; }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 99 "project.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 102 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 103 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("REC ARGS",(yyvsp[0]),(yyvsp[-2]),NULL);}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 106 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 113 "project.y" /* yacc.c:1646  */
    {  (yyval) = makeNode("BODY", (yyvsp[-4]),(yyvsp[-2]),(yyvsp[-1]),NULL);}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 116 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 120 "project.y" /* yacc.c:1646  */
    { (yyvsp[-1])->value="BODY"; (yyval)=(yyvsp[-1]);}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 123 "project.y" /* yacc.c:1646  */
    {Node*temp = makeNode("BODY",NULL);fixRec((yyvsp[0]),temp); (yyval)=temp;}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 127 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("RET INT", NULL);}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 128 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("RET CHAR", NULL);}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 129 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("RET BOOL", NULL);}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 130 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("RET REAL", NULL);}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 131 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("RET INT*", NULL);}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 132 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("RET CHAR*", NULL);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 133 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("RET REAL*", NULL);}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 136 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("RETEXP",(yyvsp[-1]),NULL); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 137 "project.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 145 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 146 "project.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 147 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 148 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 149 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 150 "project.y" /* yacc.c:1646  */
    {  (yyvsp[0])->value="VAR";   (yyvsp[0])->sons[0]->sons= (yyvsp[0])->sons[1]->sons;
														(yyvsp[0])->sons[0]->size= (yyvsp[0])->sons[1]->size;  
														(yyvsp[0])->sons[1]=NULL; (yyvsp[0])->size=1; (yyval)=(yyvsp[0]); }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 154 "project.y" /* yacc.c:1646  */
    { Node*temp = makeNode("BLOCK",NULL);fixRec((yyvsp[-1]),temp);   (yyval)=temp;}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 155 "project.y" /* yacc.c:1646  */
    { (yyval) = makeNode("EMPTY",NULL);}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 156 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 157 "project.y" /* yacc.c:1646  */
    {(yyval) =(yyvsp[0]);}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 158 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 165 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("REC ARGS",(yyvsp[0]),(yyvsp[-1]), NULL);}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 166 "project.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]);}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 175 "project.y" /* yacc.c:1646  */
    {Node*temp = makeNode("",NULL);fixRec((yyvsp[-3]),temp); (yyval)=makeNode("",(yyvsp[-1]),temp,NULL);}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 178 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("REC ARGS",(yyvsp[0]),(yyvsp[-2]),NULL);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 179 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 182 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("=",(yyvsp[-3]),(yyvsp[-1]),NULL); }
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 187 "project.y" /* yacc.c:1646  */
    { if((yyvsp[0])){(yyval) = makeNode("IF-ELSE",makeNode("IF",(yyvsp[-3]),(yyvsp[-1]),NULL),(yyvsp[0]),NULL);}
																		else {(yyval) = makeNode("IF",(yyvsp[-3]),(yyvsp[-1]),NULL); }   }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 191 "project.y" /* yacc.c:1646  */
    { (yyval)= makeNode("ELSE",(yyvsp[0]),NULL); }
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 192 "project.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 195 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("WHILE",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 198 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("FOR",(yyvsp[-2])->sons[0],(yyvsp[-2])->sons[1],(yyvsp[-2])->sons[2],(yyvsp[0]),NULL);}
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 201 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("",(yyvsp[-4]),(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 204 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("=",(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 208 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("EMPTY",NULL);}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 209 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 214 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("+",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 215 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("-",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 216 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("*",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 217 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("/",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 218 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("==",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 219 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(">",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 220 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(">=",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 221 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("<",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 222 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("<=",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 223 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("!",(yyvsp[0]),NULL);}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 224 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("!=",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 225 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("||",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 226 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("&&",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 227 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 228 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 232 "project.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]); }
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 233 "project.y" /* yacc.c:1646  */
    {(yyval) = makeNode("ARR",makeNode((char*)(yyvsp[-3]),NULL),(yyvsp[-1]),NULL);}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 240 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("INT",NULL);}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 241 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("BOOL",NULL);}
#line 1954 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 242 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("CHAR",NULL);}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 243 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("REAL",NULL);}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 244 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode( concat("STRING",concat("[",concat((yyvsp[-1])->value,"]"))) ,NULL);}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 245 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("INT*",NULL);}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 246 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("CHAR*",NULL);}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 247 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("REAL*",NULL);}
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 250 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode((char*)(yyvsp[0]),NULL) ; }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 251 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("DEREF",makeNode((char*)(yyvsp[0]),NULL),NULL); }
#line 2002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 254 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("AMP",makeNode((char*)(yyvsp[0]),NULL),NULL); }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 258 "project.y" /* yacc.c:1646  */
    { (yyval) = makeNode("CALL",(yyvsp[-3]),makeNode("ARGS",(yyvsp[-1]),NULL),NULL); }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 261 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("LEN",(yyvsp[-1]),NULL); }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 262 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("STRING LEN",(yyvsp[-1]),NULL); }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 265 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("TRUE",NULL);}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 266 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("FALSE",NULL);}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 269 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(yytext,NULL);}
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 270 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(yytext,NULL);}
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 271 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(yytext,NULL);}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 272 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(yytext,NULL); }
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 273 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(yytext,NULL); }
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2072 "y.tab.c" /* yacc.c:1646  */
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
#line 274 "project.y" /* yacc.c:1906  */
	

#include "lex.yy.c"
int main(){
	tree= makeNode("CODE", NULL);
	return yyparse();
}









void yyerror(char* s){
	printf("%s: at line %d found token [%s] \n",s,counter,yytext);
}






void closeTree(){
	changeP(tree);

	printTree(tree);
	initScopes(tree);
	printScopes();
	checks(tree, 1 );
	errorSummary();


}
