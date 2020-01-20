%{
#include <stdio.h>
#include <string.h>
#include "y.tab.h"

%}

%%

"-"	return MINUS;
"+"	return PLUS;
[0-9]+	return NUM;
\n	return RETURN;
.	;

%%

int lex()
{
	while(yylex());
}
