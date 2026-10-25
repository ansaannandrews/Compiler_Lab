%{
#include <stdio.h>
int zero = 0, one = 0;
%}

%%
0 { zero++;}
1 { one++;}
\n { 
	printf("Number of zeros = %d\n",zero);
	printf("Number of ones = %d\n",one);
}
. { }
%%

int yywrap() {
	return 1;
}

int main() {
	printf("Enter the BINARY NUMBER: ");
	yylex();
	return 0;
}
