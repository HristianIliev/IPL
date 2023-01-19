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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 20 "parser.y"

    #include "ast.hpp"

#line 53 "parser.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    FIELDINVOCATION = 259,         /* FIELDINVOCATION  */
    FLOAT = 260,                   /* FLOAT  */
    CLASS = 261,                   /* CLASS  */
    INTEGER = 262,                 /* INTEGER  */
    STRING = 263,                  /* STRING  */
    BOOLEAN = 264,                 /* BOOLEAN  */
    INDENT = 265,                  /* INDENT  */
    DEINDENT = 266,                /* DEINDENT  */
    NEWLINE = 267,                 /* NEWLINE  */
    AND = 268,                     /* AND  */
    BREAK = 269,                   /* BREAK  */
    DEF = 270,                     /* DEF  */
    ELIF = 271,                    /* ELIF  */
    ELSE = 272,                    /* ELSE  */
    FOR = 273,                     /* FOR  */
    IN = 274,                      /* IN  */
    IF = 275,                      /* IF  */
    NOT = 276,                     /* NOT  */
    OR = 277,                      /* OR  */
    RETURN = 278,                  /* RETURN  */
    WHILE = 279,                   /* WHILE  */
    ASSIGN = 280,                  /* ASSIGN  */
    PLUS = 281,                    /* PLUS  */
    MINUS = 282,                   /* MINUS  */
    MULTIPLICATION = 283,          /* MULTIPLICATION  */
    DIVISION = 284,                /* DIVISION  */
    EQUALS = 285,                  /* EQUALS  */
    NOTEQUALS = 286,               /* NOTEQUALS  */
    GREATERTHAN = 287,             /* GREATERTHAN  */
    GREATERTHANEQUALS = 288,       /* GREATERTHANEQUALS  */
    LESSTHAN = 289,                /* LESSTHAN  */
    LESSTHANEQUALS = 290,          /* LESSTHANEQUALS  */
    MODULUS = 291,                 /* MODULUS  */
    LEFTPAREN = 292,               /* LEFTPAREN  */
    RIGHTPAREN = 293,              /* RIGHTPAREN  */
    LEFTBRACKET = 294,             /* LEFTBRACKET  */
    RIGHTBRACKET = 295,            /* RIGHTBRACKET  */
    COMMA = 296,                   /* COMMA  */
    COLON = 297                    /* COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "parser.y"

    string* str;
    Node* node;

#line 117 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif




#ifndef YYPUSH_MORE_DEFINED
# define YYPUSH_MORE_DEFINED
enum { YYPUSH_MORE = 4 };
#endif

typedef struct yypstate yypstate;


int yypush_parse (yypstate *ps,
                  int pushed_char, YYSTYPE const *pushed_val, YYLTYPE *pushed_loc);

yypstate *yypstate_new (void);
void yypstate_delete (yypstate *ps);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
