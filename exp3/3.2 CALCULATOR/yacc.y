%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(const char *);
%}

%token DIGIT NL

%left '+' '-'
%left '*' '/'
%%

stmt:
	expr NL
	{
		printf("Result: %d\n",$1);
		return 0;
	}
	;
	
expr:
	expr '+' expr	{ $$ = $1 + $3; }
	|expr '-' expr	{ $$ = $1 - $3; }
	|expr '*' expr	{ $$ = $1 * $3; }
	|expr '/' expr
	{
		if ($3 == 0)
			$$ = 0;
		else
			$$ = $1 / $3;
	}
	|'(' expr ')'	{$$ = $2; }
	|DIGIT	{$$ = $1; }
	;
%%

int yyerror(const char *) {
	printf("Invalid Expression: \n");
	return 0;
}

int main() {
	printf("Enter Aritheematic Expression: ");
	yyparse();
	return 0;
}




















