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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 1

/* Pull parsers.  */
#define YYPULL 0




/* First part of user prologue.  */
#line 1 "parser.y"

using namespace std;

#include <iostream>
#include <set>
#include <string>
#include <vector>
#include "parser.hpp"

void yyerror(YYLTYPE* loc, const char* err);

Node* root = nullptr;

int nodesSize = 0;

set<string> symbols;

#line 89 "parser.cpp"

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

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_FIELDINVOCATION = 4,            /* FIELDINVOCATION  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_CLASS = 6,                      /* CLASS  */
  YYSYMBOL_INTEGER = 7,                    /* INTEGER  */
  YYSYMBOL_STRING = 8,                     /* STRING  */
  YYSYMBOL_BOOLEAN = 9,                    /* BOOLEAN  */
  YYSYMBOL_INDENT = 10,                    /* INDENT  */
  YYSYMBOL_DEINDENT = 11,                  /* DEINDENT  */
  YYSYMBOL_NEWLINE = 12,                   /* NEWLINE  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_BREAK = 14,                     /* BREAK  */
  YYSYMBOL_DEF = 15,                       /* DEF  */
  YYSYMBOL_ELIF = 16,                      /* ELIF  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_FOR = 18,                       /* FOR  */
  YYSYMBOL_IN = 19,                        /* IN  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_RETURN = 23,                    /* RETURN  */
  YYSYMBOL_WHILE = 24,                     /* WHILE  */
  YYSYMBOL_ASSIGN = 25,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_MINUS = 27,                     /* MINUS  */
  YYSYMBOL_MULTIPLICATION = 28,            /* MULTIPLICATION  */
  YYSYMBOL_DIVISION = 29,                  /* DIVISION  */
  YYSYMBOL_EQUALS = 30,                    /* EQUALS  */
  YYSYMBOL_NOTEQUALS = 31,                 /* NOTEQUALS  */
  YYSYMBOL_GREATERTHAN = 32,               /* GREATERTHAN  */
  YYSYMBOL_GREATERTHANEQUALS = 33,         /* GREATERTHANEQUALS  */
  YYSYMBOL_LESSTHAN = 34,                  /* LESSTHAN  */
  YYSYMBOL_LESSTHANEQUALS = 35,            /* LESSTHANEQUALS  */
  YYSYMBOL_MODULUS = 36,                   /* MODULUS  */
  YYSYMBOL_LEFTPAREN = 37,                 /* LEFTPAREN  */
  YYSYMBOL_RIGHTPAREN = 38,                /* RIGHTPAREN  */
  YYSYMBOL_LEFTBRACKET = 39,               /* LEFTBRACKET  */
  YYSYMBOL_RIGHTBRACKET = 40,              /* RIGHTBRACKET  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_COLON = 42,                     /* COLON  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_statements = 45,                /* statements  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_primary_expression = 47,        /* primary_expression  */
  YYSYMBOL_negated_expression = 48,        /* negated_expression  */
  YYSYMBOL_parameters = 49,                /* parameters  */
  YYSYMBOL_expression = 50,                /* expression  */
  YYSYMBOL_function_call = 51,             /* function_call  */
  YYSYMBOL_function_definition = 52,       /* function_definition  */
  YYSYMBOL_class_definition = 53,          /* class_definition  */
  YYSYMBOL_return_statement = 54,          /* return_statement  */
  YYSYMBOL_assign_statement = 55,          /* assign_statement  */
  YYSYMBOL_block = 56,                     /* block  */
  YYSYMBOL_condition = 57,                 /* condition  */
  YYSYMBOL_if_statement = 58,              /* if_statement  */
  YYSYMBOL_elif_blocks = 59,               /* elif_blocks  */
  YYSYMBOL_else_block = 60,                /* else_block  */
  YYSYMBOL_for_statement = 61,             /* for_statement  */
  YYSYMBOL_while_statement = 62,           /* while_statement  */
  YYSYMBOL_break_statement = 63            /* break_statement  */
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
typedef yytype_uint8 yy_state_t;

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

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  45
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    75,    82,    97,   100,   103,   106,   109,
     112,   115,   118,   121,   127,   134,   141,   148,   155,   162,
     175,   187,   199,   202,   205,   222,   225,   228,   238,   248,
     258,   268,   278,   288,   298,   308,   318,   328,   338,   357,
     381,   402,   426,   453,   465,   483,   500,   520,   538,   541,
     551,   564,   592,   595,   619,   622,   636,   658,   698,   711
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "FIELDINVOCATION", "FLOAT", "CLASS", "INTEGER", "STRING", "BOOLEAN",
  "INDENT", "DEINDENT", "NEWLINE", "AND", "BREAK", "DEF", "ELIF", "ELSE",
  "FOR", "IN", "IF", "NOT", "OR", "RETURN", "WHILE", "ASSIGN", "PLUS",
  "MINUS", "MULTIPLICATION", "DIVISION", "EQUALS", "NOTEQUALS",
  "GREATERTHAN", "GREATERTHANEQUALS", "LESSTHAN", "LESSTHANEQUALS",
  "MODULUS", "LEFTPAREN", "RIGHTPAREN", "LEFTBRACKET", "RIGHTBRACKET",
  "COMMA", "COLON", "$accept", "program", "statements", "statement",
  "primary_expression", "negated_expression", "parameters", "expression",
  "function_call", "function_definition", "class_definition",
  "return_statement", "assign_statement", "block", "condition",
  "if_statement", "elif_blocks", "else_block", "for_statement",
  "while_statement", "break_statement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     151,   -12,    -3,    38,    23,    48,    49,     3,    73,     3,
      37,   151,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,     3,     3,     3,     3,    39,   -33,    42,    63,
      46,   -33,   -33,   -33,   -33,   -33,    41,     3,     3,   -33,
     -33,    92,    -4,    76,     1,   -33,   -33,    78,    -9,    92,
     104,    -2,    77,     3,    82,     3,   -33,   -33,   150,   -21,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,    79,   -33,    80,   -33,    81,    41,   -33,
      83,    84,    32,   -16,    34,   -33,   -33,   161,   161,   168,
     168,    60,    60,    60,    60,    60,    60,    92,   -33,    85,
      84,    84,   -33,   -33,   -33,   151,   -33,    87,     3,    90,
     -33,   -33,   -33,   138,   131,    36,    84,    11,   -33,    84,
     103,   -33,     3,   105,   -33,   -33,   134,    58,   136,    84,
     139,    84,   -33,    84,   -33,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,    10,    11,    12,    13,     5,     6,     7,
       8,     9,     0,    22,     0,    22,     0,    59,     0,     0,
      14,    15,    16,    17,    19,    18,     0,     0,    22,    25,
      26,    48,     0,     0,     0,     1,     4,     0,     0,    23,
       0,     0,     0,    22,     0,    22,    14,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,     0,    45,     0,     0,    46,
       0,     0,     0,     0,     0,    20,    38,    27,    28,    29,
      31,    32,    33,    34,    35,    36,    37,    30,    49,    50,
       0,     0,    40,    24,    41,     0,    43,     0,    22,     0,
      39,    52,    58,     0,     0,     0,     0,    54,    47,     0,
       0,    56,     0,     0,    51,    42,     0,     0,     0,     0,
       0,     0,    57,     0,    55,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,    45,   -10,   -31,   -33,   -22,    -7,   -33,   -33,
     -33,   -33,   -33,   -32,    -5,   -33,   -33,   -33,   -33,   -33,
     -33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    12,    39,    40,    48,    49,    13,    14,
      15,    16,    17,   106,    42,    18,   117,   124,    19,    20,
      21
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,    46,    41,    51,    44,    57,    30,    31,    32,    71,
      33,    34,    35,    22,    71,    47,    59,    50,    72,    86,
      78,   108,    24,    72,    36,    23,   109,   122,   123,    77,
      58,    82,    78,    84,    25,    27,    80,    45,    73,    78,
      37,    26,    38,    75,    56,    31,    32,   103,    33,    34,
      35,    28,    29,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    41,    41,    98,    99,   111,   112,
     107,    71,   110,    78,   120,    78,    43,    78,    37,    53,
      72,    52,    54,    55,   121,    83,   115,   125,    74,    81,
      76,   100,   101,   102,   105,   104,    70,   132,    71,   134,
     130,   135,   116,    46,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    41,    79,   127,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,   114,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     1,     2,   119,     3,   126,   129,   128,   131,   118,
     113,   133,     4,     5,     1,     2,     6,     3,     7,     0,
       0,     8,     9,     0,     0,     4,     5,     0,     0,     6,
       0,     7,     0,     0,     8,     9,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,    85,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    64,    65,
      66,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
       7,    11,     9,    25,     9,    36,     3,     4,     5,    13,
       7,     8,     9,    25,    13,    22,    38,    24,    22,    40,
      41,    37,    25,    22,    21,    37,    42,    16,    17,    38,
      37,    53,    41,    55,    37,    12,    38,     0,    42,    41,
      37,     3,    39,    42,     3,     4,     5,    78,     7,     8,
       9,     3,     3,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    71,    72,   100,   101,
      38,    13,    38,    41,    38,    41,     3,    41,    37,    37,
      22,    42,    19,    37,   116,     3,   108,   119,    12,    12,
      12,    12,    12,    12,    10,    12,    36,   129,    13,   131,
      42,   133,    12,   113,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,   122,    12,   122,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    42,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,     3,     4,    12,     6,    42,    12,    42,    12,    11,
     105,    12,    14,    15,     3,     4,    18,     6,    20,    -1,
      -1,    23,    24,    -1,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,    -1,    -1,    23,    24,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    30,    31,
      32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,    14,    15,    18,    20,    23,    24,
      44,    45,    46,    51,    52,    53,    54,    55,    58,    61,
      62,    63,    25,    37,    25,    37,     3,    12,     3,     3,
       3,     4,     5,     7,     8,     9,    21,    37,    39,    47,
      48,    50,    57,     3,    57,     0,    46,    50,    49,    50,
      50,    49,    42,    37,    19,    37,     3,    47,    50,    49,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    13,    22,    42,    12,    42,    12,    38,    41,    12,
      38,    12,    49,     3,    49,    38,    40,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    57,    57,
      12,    12,    12,    47,    12,    10,    56,    38,    37,    42,
      38,    56,    56,    45,    42,    49,    12,    59,    11,    12,
      38,    56,    16,    17,    60,    56,    42,    57,    42,    12,
      42,    12,    56,    12,    56,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    48,    49,    49,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    52,    53,    54,    55,    55,    56,    57,    57,
      57,    58,    59,    59,    60,    60,    61,    61,    62,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     0,     1,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       5,     5,     8,     5,     3,     4,     4,     3,     1,     3,
       3,     7,     0,     6,     0,     4,     7,    10,     5,     2
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
        yyerror (&yylloc, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
/* Parser data structure.  */
struct yypstate
  {
    /* Number of syntax errors so far.  */
    int yynerrs;

    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;
    /* Whether this instance has not started parsing yet.
     * If 2, it corresponds to a finished parsing.  */
    int yynew;
  };


/* Context of a parse error.  */
typedef struct
{
  yypstate* yyps;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypstate_expected_tokens (yypstate *yyps,
                          yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyps->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}


/* Similar to the previous function.  */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  return yypstate_expected_tokens (yyctx->yyps, yyarg, yyargn);
}


#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}





#define yynerrs yyps->yynerrs
#define yystate yyps->yystate
#define yyerrstatus yyps->yyerrstatus
#define yyssa yyps->yyssa
#define yyss yyps->yyss
#define yyssp yyps->yyssp
#define yyvsa yyps->yyvsa
#define yyvs yyps->yyvs
#define yyvsp yyps->yyvsp
#define yylsa yyps->yylsa
#define yyls yyps->yyls
#define yylsp yyps->yylsp
#define yystacksize yyps->yystacksize

/* Initialize the parser data structure.  */
static void
yypstate_clear (yypstate *yyps)
{
  yynerrs = 0;
  yystate = 0;
  yyerrstatus = 0;

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

  /* Initialize the state stack, in case yypcontext_expected_tokens is
     called before the first call to yyparse. */
  *yyssp = 0;
  yyps->yynew = 1;
}

/* Initialize the parser data structure.  */
yypstate *
yypstate_new (void)
{
  yypstate *yyps;
  yyps = YY_CAST (yypstate *, YYMALLOC (sizeof *yyps));
  if (!yyps)
    return YY_NULLPTR;
  yystacksize = YYINITDEPTH;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yypstate_clear (yyps);
  return yyps;
}

void
yypstate_delete (yypstate *yyps)
{
  if (yyps)
    {
#ifndef yyoverflow
      /* If the stack was reallocated but the parse did not complete, then the
         stack still needs to be freed.  */
      if (yyss != yyssa)
        YYSTACK_FREE (yyss);
#endif
      YYFREE (yyps);
    }
}



/*---------------.
| yypush_parse.  |
`---------------*/

int
yypush_parse (yypstate *yyps,
              int yypushed_char, YYSTYPE const *yypushed_val, YYLTYPE *yypushed_loc)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  switch (yyps->yynew)
    {
    case 0:
      yyn = yypact[yystate];
      goto yyread_pushed_token;

    case 2:
      yypstate_clear (yyps);
      break;

    default:
      break;
    }

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = *yypushed_loc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      if (!yyps->yynew)
        {
          YYDPRINTF ((stderr, "Return for a new token:\n"));
          yyresult = YYPUSH_MORE;
          goto yypushreturn;
        }
      yyps->yynew = 0;
yyread_pushed_token:
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yypushed_char;
      if (yypushed_val)
        yylval = *yypushed_val;
      if (yypushed_loc)
        yylloc = *yypushed_loc;
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statements  */
#line 57 "parser.y"
               { 
        string name = "root" + to_string(nodesSize);

        nodesSize++;

        BlockNode* result = new BlockNode(name);
        BlockNode* block = dynamic_cast<BlockNode*>((yyvsp[0].node));

        vector<Node*>::iterator it;
        for (it = block->childs.begin(); it != block->childs.end(); it++) {
            result->childs.push_back((*it));
        }

        root = result;
    }
#line 1727 "parser.cpp"
    break;

  case 3: /* statements: statement  */
#line 75 "parser.y"
                { 
        BlockNode* result = new BlockNode(string("temp"));

        result->childs.push_back((yyvsp[0].node));

        (yyval.node) = result;
    }
#line 1739 "parser.cpp"
    break;

  case 4: /* statements: statements statement  */
#line 82 "parser.y"
                           { 
        BlockNode* result = new BlockNode(string("temp"));
        BlockNode* originalBlockNode = dynamic_cast<BlockNode*>((yyvsp[-1].node));

        vector<Node*>::iterator it;
        for (it = originalBlockNode->childs.begin(); it != originalBlockNode->childs.end(); ++it) {
            result->childs.push_back((*it));
        }

        result->childs.push_back((yyvsp[0].node));
        (yyval.node) = result;
    }
#line 1756 "parser.cpp"
    break;

  case 5: /* statement: assign_statement  */
#line 97 "parser.y"
                     { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1764 "parser.cpp"
    break;

  case 6: /* statement: if_statement  */
#line 100 "parser.y"
                 { 
        (yyval.node) = (yyvsp[0].node);
    }
#line 1772 "parser.cpp"
    break;

  case 7: /* statement: for_statement  */
#line 103 "parser.y"
                  {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1780 "parser.cpp"
    break;

  case 8: /* statement: while_statement  */
#line 106 "parser.y"
                    {  
        (yyval.node) = (yyvsp[0].node);
    }
#line 1788 "parser.cpp"
    break;

  case 9: /* statement: break_statement  */
#line 109 "parser.y"
                    { 
        (yyval.node) = (yyvsp[0].node);
  }
#line 1796 "parser.cpp"
    break;

  case 10: /* statement: function_call  */
#line 112 "parser.y"
                  {
      (yyval.node) = (yyvsp[0].node);
    }
#line 1804 "parser.cpp"
    break;

  case 11: /* statement: function_definition  */
#line 115 "parser.y"
                        {
      (yyval.node) = (yyvsp[0].node);
    }
#line 1812 "parser.cpp"
    break;

  case 12: /* statement: class_definition  */
#line 118 "parser.y"
                     {
      (yyval.node) = (yyvsp[0].node);
    }
#line 1820 "parser.cpp"
    break;

  case 13: /* statement: return_statement  */
#line 121 "parser.y"
                     {
      (yyval.node) = (yyvsp[0].node);
    }
#line 1828 "parser.cpp"
    break;

  case 14: /* primary_expression: IDENTIFIER  */
#line 127 "parser.y"
               { 
        string name = "iden" + to_string(nodesSize);

        nodesSize++;

        (yyval.node) = new LiteralNode(name, "Identifier", *(yyvsp[0].str));
    }
#line 1840 "parser.cpp"
    break;

  case 15: /* primary_expression: FIELDINVOCATION  */
#line 134 "parser.y"
                    {
        string name = "fieldInvocation" + to_string(nodesSize);

        nodesSize++;

        (yyval.node) = new LiteralNode(name, "Identifier", *(yyvsp[0].str));
    }
#line 1852 "parser.cpp"
    break;

  case 16: /* primary_expression: FLOAT  */
#line 141 "parser.y"
          { 
        string name = "float" + to_string(nodesSize);

        nodesSize++;

        (yyval.node) = new LiteralNode(name, "Float", *(yyvsp[0].str));
    }
#line 1864 "parser.cpp"
    break;

  case 17: /* primary_expression: INTEGER  */
#line 148 "parser.y"
            { 
        string name = "integer" + to_string(nodesSize);

        nodesSize++;

        (yyval.node) = new LiteralNode(name, "Integer", *(yyvsp[0].str));
    }
#line 1876 "parser.cpp"
    break;

  case 18: /* primary_expression: BOOLEAN  */
#line 155 "parser.y"
            { 
        string name = "bool" + to_string(nodesSize);
        
        nodesSize++;
        
        (yyval.node) = new LiteralNode(name, "Boolean", *(yyvsp[0].str));
    }
#line 1888 "parser.cpp"
    break;

  case 19: /* primary_expression: STRING  */
#line 162 "parser.y"
           {
        string name = "string" + to_string(nodesSize);
        
        nodesSize++;
        
        string value = *(yyvsp[0].str);

        value.erase(0, 1);

        value = value.substr(0, value.size()-1);

        (yyval.node) = new LiteralNode(name, "String", value);
    }
#line 1906 "parser.cpp"
    break;

  case 20: /* primary_expression: LEFTPAREN expression RIGHTPAREN  */
#line 175 "parser.y"
                                    { 
        string name = "paren" + to_string(nodesSize);
        
        nodesSize++;

        UnaryNode* result = new UnaryNode(name, "Parenthesis");
        result->child = (yyvsp[-1].node);
        (yyval.node) = result;
    }
#line 1920 "parser.cpp"
    break;

  case 21: /* negated_expression: NOT primary_expression  */
#line 187 "parser.y"
                           { 
        string name = "not" + to_string(nodesSize);
        
        nodesSize++;

        UnaryNode* result = new UnaryNode(name, "NOT");
        result->child = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 1934 "parser.cpp"
    break;

  case 22: /* parameters: %empty  */
#line 199 "parser.y"
           { 
      (yyval.node) = nullptr;
    }
#line 1942 "parser.cpp"
    break;

  case 23: /* parameters: expression  */
#line 202 "parser.y"
               {
      (yyval.node) = (yyvsp[0].node);
    }
#line 1950 "parser.cpp"
    break;

  case 24: /* parameters: parameters COMMA primary_expression  */
#line 205 "parser.y"
                                        {
        LiteralNode* result = dynamic_cast<LiteralNode*>((yyvsp[0].node));
        
        LiteralNode* tmp1 = dynamic_cast<LiteralNode*>((yyvsp[-2].node));
        
        result->siblings.push_back(tmp1);

        vector<LiteralNode*>::iterator it;
        for (it = tmp1->siblings.begin(); it != tmp1->siblings.end(); ++it) {
          result->siblings.push_back((*it));
        }

        (yyval.node) = result;
   }
#line 1969 "parser.cpp"
    break;

  case 25: /* expression: primary_expression  */
#line 222 "parser.y"
                       { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1977 "parser.cpp"
    break;

  case 26: /* expression: negated_expression  */
#line 225 "parser.y"
                       { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 1985 "parser.cpp"
    break;

  case 27: /* expression: expression PLUS expression  */
#line 228 "parser.y"
                               { 
        string name = "plus" + to_string(nodesSize);

        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "Plus");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2000 "parser.cpp"
    break;

  case 28: /* expression: expression MINUS expression  */
#line 238 "parser.y"
                                { 
        string name = "minus" + to_string(nodesSize);
        
        nodesSize++;
        
        BinaryNode* result = new BinaryNode(name, "Minus");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2015 "parser.cpp"
    break;

  case 29: /* expression: expression MULTIPLICATION expression  */
#line 248 "parser.y"
                                         { 
        string name = "multiplication" + to_string(nodesSize);

        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "Multiplication");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2030 "parser.cpp"
    break;

  case 30: /* expression: expression MODULUS expression  */
#line 258 "parser.y"
                                  {
      string name = "modulus" + to_string(nodesSize);

      nodesSize++;

      BinaryNode* result = new BinaryNode(name, "Modulus");
      result->left = (yyvsp[-2].node);
      result->right = (yyvsp[0].node);
      (yyval.node) = result;
    }
#line 2045 "parser.cpp"
    break;

  case 31: /* expression: expression DIVISION expression  */
#line 268 "parser.y"
                                   { 
        string name = "division" + to_string(nodesSize);

        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "Division");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2060 "parser.cpp"
    break;

  case 32: /* expression: expression EQUALS expression  */
#line 278 "parser.y"
                                 { 
        string name = "equals" + to_string(nodesSize);

        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "Equals");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2075 "parser.cpp"
    break;

  case 33: /* expression: expression NOTEQUALS expression  */
#line 288 "parser.y"
                                    { 
        string name = "notequals" + to_string(nodesSize);

        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "NotEquals");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2090 "parser.cpp"
    break;

  case 34: /* expression: expression GREATERTHAN expression  */
#line 298 "parser.y"
                                      { 
        string name = "greaterthan" + to_string(nodesSize);
        
        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "GreaterThan");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2105 "parser.cpp"
    break;

  case 35: /* expression: expression GREATERTHANEQUALS expression  */
#line 308 "parser.y"
                                            { 
        string name = "greaterthanequals" + to_string(nodesSize);
        
        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "GreaterThanEquals");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2120 "parser.cpp"
    break;

  case 36: /* expression: expression LESSTHAN expression  */
#line 318 "parser.y"
                                   { 
        string name = "lessthan" + to_string(nodesSize);
        
        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "LessThan");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2135 "parser.cpp"
    break;

  case 37: /* expression: expression LESSTHANEQUALS expression  */
#line 328 "parser.y"
                                         { 
        string name = "lessthanequals" + to_string(nodesSize);
        
        nodesSize++;

        BinaryNode* result = new BinaryNode(name, "LessThanEquals");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2150 "parser.cpp"
    break;

  case 38: /* expression: LEFTBRACKET parameters RIGHTBRACKET  */
#line 338 "parser.y"
                                        {
        string name = "arrayinitialization" + to_string(nodesSize);

        nodesSize++;

        LiteralNodes* result = new LiteralNodes(name, "Literals");

        if ((yyvsp[-1].node) != nullptr) {
            LiteralNode* literal = dynamic_cast<LiteralNode*>((yyvsp[-1].node));
            result->literals.push_back(literal);

            vector<LiteralNode*>::iterator it;
            for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
                result->literals.push_back((*it));
            }
        }

        (yyval.node) = result;
    }
#line 2174 "parser.cpp"
    break;

  case 39: /* expression: IDENTIFIER LEFTPAREN parameters RIGHTPAREN  */
#line 357 "parser.y"
                                               {
      string name = "functioncall" + to_string(nodesSize);

      nodesSize++;

      LiteralNodes* parameters = new LiteralNodes("parameters" + nodesSize, "Parameters");

      if ((yyvsp[-1].node) != nullptr) {
        LiteralNode* literal = dynamic_cast<LiteralNode*>((yyvsp[-1].node));
        parameters->literals.push_back(literal);

        vector<LiteralNode*>::iterator it;
        for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
          parameters->literals.push_back((*it));
        }
      }

      FunctionNode* result = new FunctionNode(name, "FunctionCall", *(yyvsp[-3].str), parameters);

      (yyval.node) = result;
    }
#line 2200 "parser.cpp"
    break;

  case 40: /* function_call: IDENTIFIER LEFTPAREN parameters RIGHTPAREN NEWLINE  */
#line 381 "parser.y"
                                                       {
    string name = "functioncall" + to_string(nodesSize);

    nodesSize++;

    LiteralNodes* parameters = new LiteralNodes("parameters" + nodesSize, "Parameters");

    if ((yyvsp[-2].node) != nullptr) {
      LiteralNode* literal = dynamic_cast<LiteralNode*>((yyvsp[-2].node));
      parameters->literals.push_back(literal);

      vector<LiteralNode*>::iterator it;
      for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
        parameters->literals.push_back((*it));
      }
    }

    FunctionNode* result = new FunctionNode(name, "FunctionCall", *(yyvsp[-4].str), parameters);

    (yyval.node) = result;
  }
#line 2226 "parser.cpp"
    break;

  case 41: /* function_call: FIELDINVOCATION LEFTPAREN parameters RIGHTPAREN NEWLINE  */
#line 402 "parser.y"
                                                            {
    string name = "functioncall" + to_string(nodesSize);

    nodesSize++;

    LiteralNodes* parameters = new LiteralNodes("parameters" + nodesSize, "Parameters");

    if ((yyvsp[-2].node) != nullptr) {
      LiteralNode* literal = dynamic_cast<LiteralNode*>((yyvsp[-2].node));
      parameters->literals.push_back(literal);

      vector<LiteralNode*>::iterator it;
      for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
        parameters->literals.push_back((*it));
      }
    }

    FunctionNode* result = new FunctionNode(name, "FunctionCall", *(yyvsp[-4].str), parameters);

    (yyval.node) = result;
  }
#line 2252 "parser.cpp"
    break;

  case 42: /* function_definition: DEF IDENTIFIER LEFTPAREN parameters RIGHTPAREN COLON NEWLINE block  */
#line 426 "parser.y"
                                                                       {
    string name = "functiondefinition" + to_string(nodesSize);

    nodesSize++;

    LiteralNodes* parameters = new LiteralNodes("parameters" + to_string(nodesSize), "Arguments");

    nodesSize++;
    if ((yyvsp[-4].node) != nullptr) {
      LiteralNode* literal = dynamic_cast<LiteralNode*>((yyvsp[-4].node));
      parameters->literals.push_back(literal);

      vector<LiteralNode*>::iterator it;
      for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
        parameters->literals.push_back((*it));
      }
    }

    FunctionNode* result = new FunctionNode(name, "FunctionDefinition", *(yyvsp[-6].str), parameters);

    result->functionBlock = dynamic_cast<BlockNode*>((yyvsp[0].node));

    (yyval.node) = result;
  }
#line 2281 "parser.cpp"
    break;

  case 43: /* class_definition: CLASS IDENTIFIER COLON NEWLINE block  */
#line 453 "parser.y"
                                         {
    string name = "class" + to_string(nodesSize);

    nodesSize++;

    ClassNode* result = new ClassNode(name, *(yyvsp[-3].str), dynamic_cast<BlockNode*>((yyvsp[0].node)));

    (yyval.node) = result;
  }
#line 2295 "parser.cpp"
    break;

  case 44: /* return_statement: RETURN IDENTIFIER NEWLINE  */
#line 465 "parser.y"
                              {
        string name = "return" + to_string(nodesSize);

        nodesSize++;

        UnaryNode* result = new UnaryNode(name, "Return");

        string nameLiteral = "returnvalue" + to_string(nodesSize);

        nodesSize++;

        result->child = new LiteralNode(nameLiteral, "Return identifier", *(yyvsp[-1].str));

        (yyval.node) = result;
  }
#line 2315 "parser.cpp"
    break;

  case 45: /* assign_statement: IDENTIFIER ASSIGN expression NEWLINE  */
#line 483 "parser.y"
                                         { 
        string name = "assign" + to_string(nodesSize);
        
        nodesSize++;
        
        BinaryNode* result = new BinaryNode(name, "ASSIGNMENT");
        
        string name1 = "iden" + to_string(nodesSize);
        
        nodesSize++;
        
        LiteralNode* iden = new LiteralNode(name1, "Identifier", *(yyvsp[-3].str));
        result->left = iden;

        result->right = (yyvsp[-1].node);
        (yyval.node) = result;
    }
#line 2337 "parser.cpp"
    break;

  case 46: /* assign_statement: FIELDINVOCATION ASSIGN expression NEWLINE  */
#line 500 "parser.y"
                                              { 
        string name = "assign" + to_string(nodesSize);
        
        nodesSize++;
        
        BinaryNode* result = new BinaryNode(name, "ASSIGNMENT");
        
        string name1 = "iden" + to_string(nodesSize);
        
        nodesSize++;
        
        LiteralNode* iden = new LiteralNode(name1, "Identifier", *(yyvsp[-3].str));
        result->left = iden;

        result->right = (yyvsp[-1].node);
        (yyval.node) = result;
    }
#line 2359 "parser.cpp"
    break;

  case 47: /* block: INDENT statements DEINDENT  */
#line 520 "parser.y"
                               { 
        string name = "block" + to_string(nodesSize);
        
        nodesSize++;
        
        BlockNode* result = new BlockNode(name);
        BlockNode* statements = dynamic_cast<BlockNode*>((yyvsp[-1].node));

        vector<Node*>::iterator it;
        for (it = statements->childs.begin(); it != statements->childs.end(); ++it) {
            result->childs.push_back((*it));
        }

        (yyval.node) = result;
    }
#line 2379 "parser.cpp"
    break;

  case 48: /* condition: expression  */
#line 538 "parser.y"
               { 
        (yyval.node) = (yyvsp[0].node); 
    }
#line 2387 "parser.cpp"
    break;

  case 49: /* condition: condition AND condition  */
#line 541 "parser.y"
                            { 
        string name = "and" + to_string(nodesSize);
        
        nodesSize++;
        
        BinaryNode* result = new BinaryNode(name, "AND");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2402 "parser.cpp"
    break;

  case 50: /* condition: condition OR condition  */
#line 551 "parser.y"
                           { 
        string name = "or" + to_string(nodesSize);
        
        nodesSize++;
        
        BinaryNode* result = new BinaryNode(name, "OR");
        result->left = (yyvsp[-2].node);
        result->right = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2417 "parser.cpp"
    break;

  case 51: /* if_statement: IF condition COLON NEWLINE block elif_blocks else_block  */
#line 564 "parser.y"
                                                            { 
        string name = "if" + to_string(nodesSize);
        
        nodesSize++;
        
        IfNode* result = new IfNode(name);
        result->condition = (yyvsp[-5].node);
        result->ifBlock = dynamic_cast<BlockNode*>((yyvsp[-2].node));

        if ((yyvsp[-1].node) != nullptr) {
            ElifNode* elifnode = dynamic_cast<ElifNode*>((yyvsp[-1].node));
            result->elifs.push_back(elifnode);

            vector<ElifNode*>::iterator it;
            for (it = elifnode->siblings.begin(); it != elifnode->siblings.end(); ++it) {
                result->elifs.push_back((*it));
            }
        }

        if ((yyvsp[0].node) != nullptr) {
          result->elseBlock = dynamic_cast<BlockNode*>((yyvsp[0].node));
        }

        (yyval.node) = result;
    }
#line 2447 "parser.cpp"
    break;

  case 52: /* elif_blocks: %empty  */
#line 592 "parser.y"
           { 
        (yyval.node) = nullptr;
    }
#line 2455 "parser.cpp"
    break;

  case 53: /* elif_blocks: elif_blocks ELIF condition COLON NEWLINE block  */
#line 595 "parser.y"
                                                   { 
        string name = "elif" + to_string(nodesSize);
        
        nodesSize++;

        ElifNode* result = new ElifNode(name);
        result->condition = (yyvsp[-3].node);
        result->block = dynamic_cast<BlockNode*>((yyvsp[0].node));

        if ((yyvsp[-5].node) != nullptr) {
            ElifNode* tmp1 = dynamic_cast<ElifNode*>((yyvsp[-5].node));
            result->siblings.push_back(tmp1);

            vector<ElifNode*>::iterator it;
            for (it = tmp1->siblings.begin(); it != tmp1->siblings.end(); ++it) {
                result->siblings.push_back((*it));
            }
        }

        (yyval.node) = result;
    }
#line 2481 "parser.cpp"
    break;

  case 54: /* else_block: %empty  */
#line 619 "parser.y"
           { 
        (yyval.node) = nullptr;
    }
#line 2489 "parser.cpp"
    break;

  case 55: /* else_block: ELSE COLON NEWLINE block  */
#line 622 "parser.y"
                             { 
        string name = "block" + to_string(nodesSize);
        
        nodesSize++;
        
        BlockNode* result = new BlockNode(name);
        /* ? */
        (yyval.node) = result;
        /* ? */
        (yyval.node) = (yyvsp[0].node);
    }
#line 2505 "parser.cpp"
    break;

  case 56: /* for_statement: FOR IDENTIFIER IN IDENTIFIER COLON NEWLINE block  */
#line 636 "parser.y"
                                                     {
      string name = "for" + to_string(nodesSize);

      nodesSize++;

      string literalName = "iterationLiteral" + to_string(nodesSize);

      nodesSize++;

      LiteralNode* iterationLiteral = new LiteralNode(literalName, "IterationVar", *(yyvsp[-5].str));

      string arrayName = "arrayLiteral" + to_string(nodesSize);

      nodesSize++;

      LiteralNode* arrayLiteral = new LiteralNode(arrayName, "ArrayVar", *(yyvsp[-3].str));

      ForNode* result = new ForNode(name, iterationLiteral, arrayLiteral);
      result->block = (yyvsp[0].node);

      (yyval.node) = result;
    }
#line 2532 "parser.cpp"
    break;

  case 57: /* for_statement: FOR IDENTIFIER IN IDENTIFIER LEFTPAREN parameters RIGHTPAREN COLON NEWLINE block  */
#line 658 "parser.y"
                                                                                     {
      string name = "for" + to_string(nodesSize);

      nodesSize++;

      string literalName = "iterationLiteral" + to_string(nodesSize);

      nodesSize++;

      LiteralNode* iterationLiteral = new LiteralNode(literalName, "IterationVar", *(yyvsp[-8].str));

      ForNode* result = new ForNode(name, iterationLiteral, nullptr);
  
      string functionCallName = "functioncall" + to_string(nodesSize);

      nodesSize++;

      LiteralNodes* parameters = new LiteralNodes("parameters" + nodesSize, "Parameters");

      if ((yyvsp[-4].node) != nullptr) {
        LiteralNode* literal = dynamic_cast<LiteralNode*>((yyvsp[-4].node));
        parameters->literals.push_back(literal);

        vector<LiteralNode*>::iterator it;
        for (it = literal->siblings.begin(); it != literal->siblings.end(); ++it) {
          parameters->literals.push_back((*it));
        }
      }

      FunctionNode* functioncall = new FunctionNode(functionCallName, "FunctionCall", *(yyvsp[-6].str), parameters);

      result->functionCallNodeArray = functioncall;
      
      result->block = (yyvsp[0].node);

      (yyval.node) = result;
    }
#line 2574 "parser.cpp"
    break;

  case 58: /* while_statement: WHILE condition COLON NEWLINE block  */
#line 698 "parser.y"
                                        { 
        string name = "while" + to_string(nodesSize);
        
        nodesSize++;
        
        WhileNode* result = new WhileNode(name);
        result->condition = (yyvsp[-3].node);
        result->block = (yyvsp[0].node);
        (yyval.node) = result;
    }
#line 2589 "parser.cpp"
    break;

  case 59: /* break_statement: BREAK NEWLINE  */
#line 711 "parser.y"
                  { 
        string name = "break" + to_string(nodesSize);

        nodesSize;

        UnaryNode* result = new UnaryNode(name, "Break");

        (yyval.node) = result;
    }
#line 2603 "parser.cpp"
    break;


#line 2607 "parser.cpp"

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
  *++yylsp = yyloc;

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
      {
        yypcontext_t yyctx
          = {yyps, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
  yyps->yynew = 2;
  goto yypushreturn;


/*-------------------------.
| yypushreturn -- return.  |
`-------------------------*/
yypushreturn:
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}
#undef yynerrs
#undef yystate
#undef yyerrstatus
#undef yyssa
#undef yyss
#undef yyssp
#undef yyvsa
#undef yyvs
#undef yyvsp
#undef yylsa
#undef yyls
#undef yylsp
#undef yystacksize
#line 722 "parser.y"


void yyerror(YYLTYPE* loc, const char* err) {
  cout << "Error (line " << loc->first_line << "): " << err << endl;
}
