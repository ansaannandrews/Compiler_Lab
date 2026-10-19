%{
#include <stdio.h>
#include <stdlib.h>
int yylex(void);
int yyerror(const char *);
%}

%token DIGIT ID NL

%left '+' '-'
%left '*' '/'

%%
stmt:
     exp NL {
     printf("Valid Expression\n");
     return 0;
     }
     ;
exp:exp'+'exp
    |exp'-'exp
    |exp'*'exp
    |exp'/'exp
    |'('exp')'
    |DIGIT
    |ID
    ;
%%

int yyerror(const char *) {
	printf("InValid Expression\n");
	return 0;
}

int main() {
	printf("Enter Arithematic Expression: ");
	yyparse();
	return 0;
}

