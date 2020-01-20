%{
#include <stdio.h>
#include <string.h>

extern int yylex();
void yyerror(char *);

%}

%token NUM
%token PLUS
%token MINUS
%token RETURN

%start prog

%%

prog:	stmts ;

stmts:	stmt
	| stmt stmts ;

stmt:	NUM		{ printf("NUM"); }
	| PLUS NUM	{ printf(" PLUS NUM"); }
	| MINUS NUM	{ printf("MINUS NUM"); }
	| RETURN	{ printf("RETURN\n"); };

%%

int main()
{
	yyparse();
}

void yyerror(char *msg)
{
	printf("\n%s\n", msg);
}
