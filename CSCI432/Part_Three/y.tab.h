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
    WHILE = 258,
    DO = 259,
    IF = 260,
    THEN = 261,
    ELSE = 262,
    ENDIF = 263,
    ENDWHILE = 264,
    PLUS = 265,
    MINUS = 266,
    LT = 267,
    GT = 268,
    LTE = 269,
    GTE = 270,
    EQUAL = 271,
    NOTEQUAL = 272,
    ASSIGN = 273,
    SEMI = 274,
    JUNK = 275,
    NUM = 276,
    VAR = 277
  };
#endif
/* Tokens.  */
#define WHILE 258
#define DO 259
#define IF 260
#define THEN 261
#define ELSE 262
#define ENDIF 263
#define ENDWHILE 264
#define PLUS 265
#define MINUS 266
#define LT 267
#define GT 268
#define LTE 269
#define GTE 270
#define EQUAL 271
#define NOTEQUAL 272
#define ASSIGN 273
#define SEMI 274
#define JUNK 275
#define NUM 276
#define VAR 277

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 24 "part_three_RD.yacc" /* yacc.c:1909  */

	int number;
	char *string;

#line 103 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
