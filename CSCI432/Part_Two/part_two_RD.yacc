	//Rankin Dam 432 Project Part Two Yacc

%{

#include <stdio.h>
#include <string.h>

extern int yylex();
void yyerror(char *);
%}

%token WHILE DO IF THEN ELSE ENDIF ENDWHILE
	PLUS MINUS
	LT GT LTE GTE EQUAL NOTEQUAL ASSIGN
	VAR NUM
	SEMI
	JUNK
%start prog
%%

prog:		stmts
		| /*Nothing*/					;

stmts:		stmt
		| stmts stmt					;

stmt:		VAR ASSIGN asgn
		| cndtn						;


asgn:		VAR math		
		| NUM math					;

math:		PLUS NUM math
		| PLUS VAR math
		| MINUS NUM math
		| MINUS VAR math
		| SEMI						{ printf("Valid Assignment\n"); };

smbl:		LT
		| GT
		| LTE
		| GTE
		| EQUAL
		| NOTEQUAL					;

cndtn:		WHILE cmpr DO stmts ENDWHILE SEMI		{ printf("Valid While\n"); }
		| IF cmpr THEN stmts ELSE prog ENDIF SEMI	{ printf("Valid If Then Else\n"); }
		| IF cmpr THEN stmts ENDIF SEMI			{ printf("Valid If Then\n"); };

cmpr:		VAR smbl VAR	
		| VAR smbl NUM					;

%%

int main()
{
	yyparse();
}

void yyerror(char *msg)
{
	extern int line;
	fprintf(stderr, "Syntax error at line %d %s", line, "\n");
}
