%{
#include<stdio.h>
%}

%%
"if"|"else"|"break"|"case" {
        printf("Keyword: %s\n",yytext);
}

[a-z_][a-zA-Z0-9_]* {
        printf("Identifier: %s",yytext);
}

"+"|"-"|"*"|"/"|"<"|">"|"<="|">=" {
        printf("Operator: %s\n",yytext);
}

"("|")"|"{"|"}" {
        printf("Special Symbols: %s\n",yytext);
}

[0-9]+ {
        printf("Constant: %s\n",yytext);
}

[\t\n]+ ;

. {
        printf("Unknown: %s\n",yytext);
}
%%

int yywrap() {
	return 1;
}

int main() {
	printf("Enter the string: \n");
	yylex();
	return 0;
}
