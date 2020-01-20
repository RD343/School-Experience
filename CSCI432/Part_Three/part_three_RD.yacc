	//Rankin Dam 432 Project Part Three Yacc

%{

#include <stdio.h>
#include <string.h>

extern int yylex();
extern char *yystype;
void yyerror(char *);
int while_count = 0;
int else_count = 0;
int end_count = 0;
char var1[50];
%}

%token WHILE DO IF THEN ELSE ENDIF ENDWHILE
	PLUS MINUS
	LT GT LTE GTE EQUAL NOTEQUAL ASSIGN
	SEMI
	JUNK

%union
{
	int number;
	char *string;
}

%token <number> NUM
%token <string> VAR

%start prog
%%

prog:		stmts
		|/*Nothing*/;

stmts:		stmt
		| stmts stmt;

stmt:		left ASSIGN asgn SEMI		{ printf("\tMOV %s, R1\n", var1); }
		|
		whle wcpr DO stmts ENDWHILE SEMI
		{
			printf("\tJMP wtop%d\nend%d:\n", while_count, end_count);
			while_count--;
			end_count--; }
		|
		if icpr THEN stmt else prog ENDIF SEMI
		{
			printf("end%d\n", end_count);
			else_count--;
			end_count--; };

left:		VAR	{ strcpy(var1, yylval.string); };

asgn:		VAR	{ printf("\tMOV R1, %s\n", yylval.string); }
		| NUM	{ printf("\tMOV R1, %d\n", yylval.number); }
		| mths;

mths:		mthl math;

mthl:		VAR	{ printf("\tMOV R1, %s\n", yylval.string); }
		| NUM	{ printf("\tMOV R1, %d\n", yylval.number); };

//Recursion must be left side to process first
math:		math PLUS VAR		{ printf("\tADD R1, %s\n", yylval.string); }
		| math MINUS VAR	{ printf("\tSUB R1, %s\n", yylval.string); }
		| math PLUS NUM		{ printf("\tADD R1, %d\n", yylval.number); }
		| math MINUS NUM	{ printf("\tSUB R1, %d\n", yylval.number); }
		|/*nothing*/;


whle:		WHILE
		{
			while_count++;
			end_count++;
			printf("wtop%d:\tMOV R8, ", while_count);/*Attaches to printf in cmpl*/ };

if:		IF
		{
			else_count++;
			end_count++;
			printf("\tMOV R8, "); };

else:		ELSE
		{ 
			printf("\tJMP end%d\n", end_count);
			printf("else%d:", else_count);/*connects to printf of next stmt*/ }; 

wcpr:		cmpl smbl VAR
		{
			printf("\tMOV R7, %s\n", yylval.string);
			printf("\tCMP R7\n");
			printf("\t%s end%d\n", var1, end_count); }
		| cmpl smbl NUM
		{
			printf("\tMOV R7, %d\n", yylval.number);
			printf("\tCMP R7\n");
			printf("\t%s end%d\n", var1, end_count); };

icpr:		cmpl smbl VAR
		{
			printf("\tMOV R7, %s\n", yylval.string);
			printf("\tCMP R7\n");
			printf("\t%s else%d\n", var1, else_count); }
		| cmpl smbl NUM
		{
			printf("\tMOV R7, %d\n", yylval.number);
			printf("\tCMP R7\n");
			printf("\t%s else%d\n", var1, else_count); };

cmpl:		VAR	{ printf("%s\n", yylval.string); } //continued from while or if printf
		| NUM	{ printf("%d\n", yylval.number); };

smbl:		LT		{ strcpy(var1, "BGE"); }
		| GT		{ strcpy(var1, "BLE"); }
		| LTE		{ strcpy(var1, "BGT"); }
		| GTE		{ strcpy(var1, "BLT"); }
		| EQUAL		{ strcpy(var1, "BEQ"); }
		| NOTEQUAL	{ strcpy(var1, "BNE"); };

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
