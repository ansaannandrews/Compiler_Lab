%{
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
int yyerror(const char *);
%}

%token ID NL INVALID

%%
stmt:
	exp NL {
		printf("Valid Identifier\n");
		return 0;
	}
	;
exp: ID
     ;
	
%%

int yyerror(const char *) {
	printf("Invalid Identifier: \n");
	return 0;
}

int main() {
	printf("Enter Identifier: ");
	yyparse();
	return 0;
}
