%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
[0-9]+ {
	int n = atoi(yytext);
	if(n % 2 == 0)
		printf("Even Number\n");
	else
		printf("Odd Number\n");
}
\n { }
. { }
%%

int yywrap() {
	return 1;
}

int main() {
	printf("Enter the Number: ");
	yylex();
	return 0;
}
	
