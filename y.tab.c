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
int size =0;
void closeTree();
int yylex(void);
void yyerror(char*);
extern char* yytext;
#define YYSTYPE struct Node *

#line 84 "y.tab.c" /* yacc.c:339  */

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

#line 221 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   346

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

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
       0,    51,    51,    54,    57,    58,    59,    60,    63,    69,
      71,    77,    80,    81,    90,    91,    95,    96,    98,   102,
     103,   107,   108,   111,   118,   121,   125,   128,   129,   133,
     134,   135,   136,   137,   138,   139,   140,   143,   151,   152,
     153,   154,   155,   156,   160,   162,   163,   164,   167,   171,
     172,   181,   184,   185,   188,   189,   195,   199,   200,   203,
     206,   209,   212,   213,   217,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   242,   243,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   250,   251,   252,   253,   254,   255,   256,
     257,   260,   269,   272,   273,   276,   277,   280,   281,   282,
     283,   284
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
  "program", "code", "code_pros", "func", "proc", "main", "get_arg",
  "args_list", "yes_args", "args", "no_args", "call_args", "args_2",
  "arg_type", "continue_func", "proc_id", "continue_proc", "body",
  "return_va", "the_ret", "statment", "semico", "statmentss", "var_decls",
  "ids", "initign_statment", "if_statment", "else_statment",
  "while_statment", "for_statment", "for_cond", "init", "block",
  "expression", "lhs", "value", "type", "id", "call", "len", "boolean",
  "string", "char", "real", "int", "null", YY_NULLPTR
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

#define YYPACT_NINF -121

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-121)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -121,     8,  -121,    23,  -121,   -14,    -6,  -121,  -121,  -121,
     -39,  -121,   -22,  -121,   -19,    -4,    -6,    -6,    12,    10,
    -121,    41,    18,  -121,  -121,    14,   154,  -121,    12,    -6,
     328,    -6,    44,    16,    19,    27,    -6,    -6,   168,    -6,
     154,  -121,  -121,    24,  -121,  -121,   154,  -121,  -121,  -121,
    -121,  -121,    34,   -16,    56,  -121,    20,  -121,  -121,  -121,
    -121,    28,  -121,  -121,  -121,  -121,  -121,  -121,   336,   168,
     168,   -21,    31,  -121,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,   168,   168,   168,   168,   -10,    52,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,  -121,  -121,  -121,    45,    30,   139,
    -121,  -121,   168,   168,   168,  -121,  -121,   328,    57,  -121,
    -121,  -121,  -121,    47,  -121,  -121,  -121,  -121,    53,   221,
     238,    -6,    42,    56,    66,   328,    -6,    13,   -25,   -25,
     255,    61,    62,  -121,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,  -121,   188,  -121,
      69,    99,   272,   202,  -121,    71,    96,   154,   154,   154,
      92,   154,   168,   168,   105,  -121,  -121,  -121,  -121,   -25,
    -121,    13,    13,    13,    13,    13,  -121,   286,   -25,  -121,
    -121,   188,  -121,  -121,   168,  -121,  -121,    75,    80,   119,
    -121,  -121,   168,  -121,   188,   272,  -121,  -121,   272,  -121,
    -121,   154,  -121,   272,   -21,  -121,  -121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     2,     3,     1,     0,     0,     5,     4,     6,
       0,   101,     0,    25,     0,     0,    18,    18,     0,     0,
      11,    13,     0,    12,    16,     0,    28,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    46,    47,     0,    45,    50,    27,    43,    42,    39,
      41,    40,     0,    82,     0,     9,     0,    94,    95,    93,
      96,     0,    98,    99,   100,    14,    23,    17,     0,     0,
       0,     0,     0,    53,   111,   105,   106,   109,   110,   108,
     107,     0,     0,     0,     0,     0,     0,    84,    79,    91,
      90,    85,    86,    87,    88,    89,    92,     0,    82,     0,
      26,    49,     0,    18,     0,    48,    38,     0,     0,    31,
      30,    29,    32,     0,    33,    34,    35,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    81,    80,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,    20,
       0,    19,    21,     0,    15,     0,     0,    28,     0,     0,
       0,     0,     0,     0,     0,    52,    78,   103,   104,    77,
      68,    69,    70,    71,    72,    73,    66,    75,    76,    65,
      67,     0,    54,   102,     0,    83,    97,     0,     0,    58,
      64,    59,     0,    60,     0,    62,    51,    55,    22,    36,
      24,     0,    56,    63,     0,    57,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -121,  -121,  -121,  -121,   129,   133,  -121,   121,  -121,  -121,
     110,    40,  -121,  -121,    38,  -121,   140,   120,    -8,  -121,
    -121,   -41,  -120,   107,  -121,  -121,  -121,  -121,  -121,  -121,
    -121,  -121,   -47,     0,   -33,   -24,  -121,    37,    -5,   -17,
    -121,  -121,    78,  -121,  -121,  -121,  -121
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     3,    41,    42,     9,    19,    20,    21,
      22,    23,   150,   151,    65,   117,    12,    27,    43,   118,
      44,    45,   106,    46,    47,    72,    48,    49,   202,    50,
      51,   122,   123,   191,    86,    87,    88,    66,    53,    89,
      90,    91,    92,    93,    94,    95,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    13,    52,   162,    10,   101,    11,   135,     4,    54,
      15,    24,    24,    11,   141,    97,    52,    11,   144,   145,
      80,    11,    52,    54,    24,   121,    67,    16,   182,    54,
      17,    13,    73,   103,    98,   104,   119,   120,     5,     6,
      30,    31,   107,    31,   134,   135,    18,   124,   127,   128,
     129,   130,   141,   125,   126,   143,   144,   145,   101,    26,
      28,   197,    29,    68,    32,    69,    98,   102,    70,   148,
     152,   153,   100,   133,   204,    52,    71,   105,   146,   108,
     131,   104,    54,   134,   135,   155,   136,   137,   138,   139,
     140,   141,   161,   142,   143,   144,   145,   160,   156,   163,
     157,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   167,   168,    98,   189,   190,   183,
     190,   165,   184,   186,   187,   192,   196,   199,   200,   194,
     195,   201,     7,    52,    52,    52,     8,    52,    25,    56,
      54,    54,    54,   149,    54,   154,    14,    99,    55,   188,
      33,   198,    34,    35,    36,     6,    37,   206,    38,   203,
     205,   193,   164,   132,     0,    33,    11,    34,    35,    36,
       6,    37,     0,    38,     0,     0,     0,    52,     0,     0,
     124,    11,     0,     0,    54,    39,    40,   147,    74,     0,
       0,     0,    75,    76,    77,    11,    78,    79,    80,    98,
      39,    40,     0,     0,     0,     0,     0,     0,    81,   105,
       0,     0,     0,    82,    83,     0,     0,    84,     0,   134,
     135,    85,   136,   137,   138,   139,   140,   141,     0,   142,
     143,   144,   145,   134,   135,     0,   136,   137,   138,   139,
     140,   141,     0,   142,   143,   144,   145,     0,     0,     0,
       0,     0,   134,   135,   185,   136,   137,   138,   139,   140,
     141,     0,   142,   143,   144,   145,     0,     0,     0,   134,
     135,   158,   136,   137,   138,   139,   140,   141,     0,   142,
     143,   144,   145,     0,     0,     0,   134,   135,   159,   136,
     137,   138,   139,   140,   141,     0,   142,   143,   144,   145,
       0,     0,     0,   134,   135,   166,   136,   137,   138,   139,
     140,   141,     0,   142,   143,   144,   145,   134,   135,     0,
     136,   137,   138,   139,   140,   141,     0,     0,   143,   144,
     145,    57,    58,    59,    60,    61,    62,    63,    64,   109,
     110,   111,   112,   113,   114,   115,   116
};

static const yytype_int16 yycheck[] =
{
       5,     6,    26,   123,    18,    46,    27,    32,     0,    26,
      49,    16,    17,    27,    39,    39,    40,    27,    43,    44,
      30,    27,    46,    40,    29,    46,    31,    49,   148,    46,
      49,    36,    37,    49,    39,    51,    69,    70,    15,    16,
      22,    23,    22,    23,    31,    32,    50,    71,    81,    82,
      83,    84,    39,    22,    23,    42,    43,    44,    99,    47,
      50,   181,    21,    19,    50,    49,    71,    33,    49,   102,
     103,   104,    48,    21,   194,    99,    49,    21,    33,    51,
      85,    51,    99,    31,    32,    28,    34,    35,    36,    37,
      38,    39,    50,    41,    42,    43,    44,   121,    51,    33,
      47,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,    53,    53,   121,   158,   159,    50,
     161,   126,    23,    52,    28,    33,    21,    52,    48,   162,
     163,    12,     3,   157,   158,   159,     3,   161,    17,    29,
     157,   158,   159,   103,   161,   107,     6,    40,    28,   157,
      11,   184,    13,    14,    15,    16,    17,   204,    19,   192,
     201,   161,   125,    85,    -1,    11,    27,    13,    14,    15,
      16,    17,    -1,    19,    -1,    -1,    -1,   201,    -1,    -1,
     204,    27,    -1,    -1,   201,    46,    47,    48,    20,    -1,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,   204,
      46,    47,    -1,    -1,    -1,    -1,    -1,    -1,    40,    21,
      -1,    -1,    -1,    45,    46,    -1,    -1,    49,    -1,    31,
      32,    53,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    31,    32,    -1,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    31,    32,    52,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    -1,    -1,    -1,    31,
      32,    50,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    44,    -1,    -1,    -1,    31,    32,    50,    34,
      35,    36,    37,    38,    39,    -1,    41,    42,    43,    44,
      -1,    -1,    -1,    31,    32,    50,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    44,    31,    32,    -1,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    43,
      44,     3,     4,     5,     6,     7,     8,     9,    10,     3,
       4,     5,     6,     7,     8,     9,    10
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    56,    57,     0,    15,    16,    58,    59,    60,
      18,    27,    70,    92,    70,    49,    49,    49,    50,    61,
      62,    63,    64,    65,    92,    61,    47,    71,    50,    21,
      22,    23,    50,    11,    13,    14,    15,    17,    19,    46,
      47,    58,    59,    72,    74,    75,    77,    78,    80,    81,
      83,    84,    89,    92,    93,    71,    64,     3,     4,     5,
       6,     7,     8,     9,    10,    68,    91,    92,    19,    49,
      49,    49,    79,    92,    20,    24,    25,    26,    28,    29,
      30,    40,    45,    46,    49,    53,    88,    89,    90,    93,
      94,    95,    96,    97,    98,    99,   100,    89,    92,    77,
      48,    75,    33,    49,    51,    21,    76,    22,    51,     3,
       4,     5,     6,     7,     8,     9,    10,    69,    73,    88,
      88,    46,    85,    86,    89,    22,    23,    88,    88,    88,
      88,    92,    96,    21,    31,    32,    34,    35,    36,    37,
      38,    39,    41,    42,    43,    44,    33,    48,    88,    65,
      66,    67,    88,    88,    68,    28,    51,    47,    50,    50,
      89,    50,    76,    33,    91,    92,    50,    53,    53,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    76,    50,    23,    52,    52,    28,    72,    75,
      75,    87,    33,    87,    88,    88,    21,    76,    88,    52,
      48,    12,    82,    88,    76,    75,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    57,    57,    57,    57,    58,    59,
      60,    61,    62,    62,    63,    63,    64,    64,    65,    66,
      66,    67,    67,    68,    69,    70,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    76,    77,
      77,    78,    79,    79,    80,    80,    81,    82,    82,    83,
      84,    85,    86,    86,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    89,    89,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    93,    94,    94,    95,    95,    96,    97,    98,
      99,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     0,     7,     6,
       5,     1,     1,     1,     3,     5,     1,     3,     0,     1,
       1,     1,     3,     1,     4,     1,     3,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     4,     3,     2,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       1,     5,     3,     1,     4,     5,     6,     2,     0,     5,
       5,     5,     3,     4,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     1,
       2,     2,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     1,     4,     3,     3,     1,     1,     1,     1,     1,
       1,     1
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
#line 51 "project.y" /* yacc.c:1646  */
    { 	 closeTree();}
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 54 "project.y" /* yacc.c:1646  */
    {}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 57 "project.y" /* yacc.c:1646  */
    {addToTree((yyvsp[0]),tree);}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 58 "project.y" /* yacc.c:1646  */
    {addToTree((yyvsp[0]),tree);}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 59 "project.y" /* yacc.c:1646  */
    {addToTree((yyvsp[0]),tree);}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 63 "project.y" /* yacc.c:1646  */
    {
													(yyval)=makeNode("FUNC",(yyvsp[-5]),(yyvsp[-3]),(yyvsp[0])->sons[0],(yyvsp[0])->sons[1],NULL); }
#line 1508 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 69 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("PROC",(yyvsp[-4]),(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 71 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("Main",(yyvsp[0]),NULL); }
#line 1520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 77 "project.y" /* yacc.c:1646  */
    {   (yyval)=(yyvsp[0]); }
#line 1526 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 80 "project.y" /* yacc.c:1646  */
    { (yyvsp[0])->value = "ARGS NONE"; (yyval) = (yyvsp[0]); }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 81 "project.y" /* yacc.c:1646  */
    {       if(!strcmp("REC ARGS",(yyvsp[0])->value))
										{Node*temp = makeNode("",NULL); fixRec((yyvsp[0]),temp);  (yyvsp[0])=temp;}
									else
										{(yyvsp[0])=makeNode("",(yyvsp[0]),NULL);}	
									(yyvsp[0])->value="ARGS"; (yyval) = (yyvsp[0]);	  									
							}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 90 "project.y" /* yacc.c:1646  */
    {Node*temp = makeNode("",NULL);fixRec((yyvsp[-2]),temp);  temp->value = (yyvsp[0])->value; (yyval) = temp ; }
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 91 "project.y" /* yacc.c:1646  */
    {    Node*temp = makeNode("",NULL);fixRec((yyvsp[-2]),temp);  temp->value =(yyvsp[0])->value; (yyvsp[-2]) = makeNode((yyvsp[0])->value,temp,NULL); 
													(yyval) = makeNode("REC ARGS",temp,(yyvsp[-4]),NULL); }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 95 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 96 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("REC ARGS",(yyvsp[0]),(yyvsp[-2]),NULL);}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 98 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("NONE",NULL);}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 102 "project.y" /* yacc.c:1646  */
    { Node*temp = makeNode("",NULL);fixRec((yyvsp[0]),temp); (yyval)=makeNode("",temp,NULL); }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 103 "project.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[0]); }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 107 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 108 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("REC ARGS",(yyvsp[0]),(yyvsp[-2]),NULL);}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 111 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 118 "project.y" /* yacc.c:1646  */
    {  (yyval) = makeNode("BLOCK", makeNode("RET",(yyvsp[-3]),NULL),(yyvsp[-1]),NULL);}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 121 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 125 "project.y" /* yacc.c:1646  */
    { if(!(yyvsp[-1])){(yyvsp[-1])=makeNode("",NULL);} (yyvsp[-1])->value="BLOCK"; (yyval)=(yyvsp[-1]);}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 128 "project.y" /* yacc.c:1646  */
    {Node*temp = makeNode("BODY",NULL);fixRec((yyvsp[0]),temp); (yyval)=temp;}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 129 "project.y" /* yacc.c:1646  */
    { (yyval) = NULL;}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("INT", NULL);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 134 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("CHAR", NULL);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 135 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("BOOL", NULL);}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 136 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("REAL", NULL);}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 137 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("INT*", NULL);}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 138 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("CHAR*", NULL);}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 139 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("REAL*", NULL);}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 140 "project.y" /* yacc.c:1646  */
    { (yyval)= makeNode(concat("STRING[",concat((char*)(yyvsp[-1]),"]")) ,NULL);}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 143 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("RETURN",(yyvsp[-1]),NULL); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 151 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 152 "project.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 153 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 154 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 155 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 156 "project.y" /* yacc.c:1646  */
    {  (yyvsp[0])->value="VAR";   (yyvsp[0])->sons[0]->sons= (yyvsp[0])->sons[1]->sons;
														(yyvsp[0])->sons[0]->size= (yyvsp[0])->sons[1]->size;  
														(yyvsp[0])->sons[1]=NULL; (yyvsp[0])->size=1; (yyval)=(yyvsp[0]); }
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 160 "project.y" /* yacc.c:1646  */
    { Node*temp = makeNode("BLOCK",NULL);fixRec((yyvsp[-1]),temp);   (yyval)=temp;}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 162 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 163 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 164 "project.y" /* yacc.c:1646  */
    {(yyval) =(yyvsp[0]);}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 171 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("REC ARGS",(yyvsp[0]),(yyvsp[-1]), NULL);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 172 "project.y" /* yacc.c:1646  */
    { (yyval)=(yyvsp[0]);}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 181 "project.y" /* yacc.c:1646  */
    {Node*temp = makeNode("LALA1",NULL);fixRec((yyvsp[-3]),temp); (yyval)=makeNode("LALA2",(yyvsp[-1]),temp,NULL);}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 184 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("REC ARGS",(yyvsp[0]),(yyvsp[-2]),NULL);}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 185 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 188 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("=",(yyvsp[-3]),(yyvsp[-1]),NULL); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 189 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("=",makeNode("^",(yyvsp[-3]),NULL),(yyvsp[-1]),NULL); }
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 195 "project.y" /* yacc.c:1646  */
    { if((yyvsp[0])){(yyval) = makeNode("IFELSE",(yyvsp[-3]),(yyvsp[-1]),(yyvsp[0]),NULL);}
																		else {(yyval) = makeNode("IF",(yyvsp[-3]),(yyvsp[-1]),NULL); }   }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 199 "project.y" /* yacc.c:1646  */
    { (yyval)= (yyvsp[0]); }
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 200 "project.y" /* yacc.c:1646  */
    {(yyval)=NULL;}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 203 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("WHILE",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 206 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("FOR",(yyvsp[-2])->sons[0],(yyvsp[-2])->sons[1],(yyvsp[-2])->sons[2],(yyvsp[0]),NULL);}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 209 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("",(yyvsp[-4]),(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 212 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("=",(yyvsp[-2]),(yyvsp[0]),NULL); }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 213 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("=",makeNode("^",(yyvsp[-2]),NULL),(yyvsp[0]),NULL); }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 217 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 222 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("+",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 223 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("-",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 224 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("*",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 225 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("/",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 226 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("==",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 227 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(">",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 228 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(">=",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 229 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("<",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 230 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("<=",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 231 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("!",(yyvsp[0]),NULL);}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 232 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("!=",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 233 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("||",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 234 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("&&",(yyvsp[-2]),(yyvsp[0]),NULL);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 235 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[-1]);}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 236 "project.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 237 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode((char*)(yyvsp[-1]),(yyvsp[0]),NULL); }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 238 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode((char*)(yyvsp[-1]),(yyvsp[0]),NULL);}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 242 "project.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]); }
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 243 "project.y" /* yacc.c:1646  */
    {(yyval) = makeNode("ARR",makeNode((char*)(yyvsp[-3])->value,NULL),(yyvsp[-1]),NULL);}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 250 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("INT",NULL);}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 251 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("BOOL",NULL);}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 252 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("CHAR",NULL);}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 253 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("REAL",NULL);}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 254 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode( concat("STRING",concat("[",concat((char*)(yyvsp[-1]),"]"))) ,NULL);}
#line 1991 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 255 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("INT*",NULL);}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 256 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("CHAR*",NULL);}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 257 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("REAL*",NULL);}
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 260 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode((char*)(yyvsp[0]),NULL) ; }
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 269 "project.y" /* yacc.c:1646  */
    { (yyvsp[-3])->sons = (yyvsp[-1])->sons; (yyvsp[-3])->size = (yyvsp[-1])->size; (yyval) = makeNode("CALL",(yyvsp[-3]),NULL); }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 272 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("LEN",(yyvsp[-1]),NULL); }
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 273 "project.y" /* yacc.c:1646  */
    { (yyval)=makeNode("STRING LEN",(yyvsp[-1]),NULL); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 276 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("TRUE",NULL);}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 277 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("FALSE",NULL);}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 280 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(yytext,NULL);}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 281 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(yytext,NULL);}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 282 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(yytext,NULL);}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 283 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode(yytext,NULL); }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 284 "project.y" /* yacc.c:1646  */
    {(yyval)=makeNode("NULL",NULL); }
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2079 "y.tab.c" /* yacc.c:1646  */
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
#line 285 "project.y" /* yacc.c:1906  */
	

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

	printf("\nCode tree:\n");
	printTree(tree);
	initScopes(tree);

	printf("\nScopes:\n");
	printScopes();
	checks(tree, 1);
    errorSummary();

}
