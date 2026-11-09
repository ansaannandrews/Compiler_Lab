%{
#include <stdio.h>
%}

%%
[a-z]	{
	printf("%c",yytext[0]-32);
}
[A-Z]	{
	printf("%s",yytext);
}
.	{
	printf("%s",yytext);
}
%%

int yywrap() {
	return 1;
}

int main() {
	printf("Enter the string: ");
	yylex();
	return 0;
}
