	//Rankin Dam 432 Lex Project Part One

%{
#include <stdio.h>
%}

%%

"while"		printf ("WHILE\n");
"do"		printf ("DO\n");
"if"		printf ("IF\n");
"then"		printf ("THEN\n");
"else"		printf ("ELSE\n");
"end"		printf ("END\n");

"+"		printf ("PLUS\n");
"-"		printf ("MINUS\n");
"<"		printf ("LT\n");
">"		printf ("GT\n");
"<="		printf ("LTE\n");
">="		printf ("GTE\n");
"=="		printf ("EQUAL\n");
"="		printf ("ASSIGN\n");

[a-z]+		printf ("VAR\n");

[0-9]+		printf ("NUM\n");

";"		printf ("SEMI\n");

" "		;

.		printf ("UNKOWN\n");

%%
