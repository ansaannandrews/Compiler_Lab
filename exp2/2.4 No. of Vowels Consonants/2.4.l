%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}

%%
[aeiouAEIOU]	{ vowels++; }
[a-zA-Z]	{ consonants++; }
\n	{ return 0; }
.	;
%%

int yywrap() {
	return 1;
}

int main() {
	printf("Enter the string: ");
	yylex();
	printf("Vowels = %d\n",vowels);
	printf("Consonants = %d\n",consonants);
	return 0;
}
