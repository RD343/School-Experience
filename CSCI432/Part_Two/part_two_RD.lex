	//Rankin Dam 432 Project Part Two Lex

%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
int line = 1;
%}

%%

"while"		return WHILE;
"do"		return DO;
"if"		return IF;
"then"		return THEN;
"else"		return ELSE;
"endif"		return ENDIF;
"endwhile"	return ENDWHILE;

"+"		return PLUS;
"-"		return MINUS;
"<"		return LT;
">"		return GT;
"<="		return LTE;
">="		return GTE;
"=="		return EQUAL;
"!="		return NOTEQUAL;
"="		return ASSIGN;

[a-z]+		return VAR;

[0-9]+		return NUM;

";"		return SEMI;

" "		;
"\n"		line++;
"\t"		;

.		return JUNK;

%%
