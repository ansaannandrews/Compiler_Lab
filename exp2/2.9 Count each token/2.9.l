%{
#include <stdio.h>

int keyword = 0, identifier = 0, constant = 0;
int operator = 0, delimiter = 0;
%}

%%
"int"|"float"|"char"|"if"|"else"|"while"|"return" {
    keyword++;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    identifier++;
}

[0-9]+ {
    constant++;
}

"+"|"-"|"*"|"/"|"="|"=="|"<"|">" {
    operator++;
}

[(){};,] {
    delimiter++;
}

[ \t\n]+ ;

. ;

%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the input:\n");
    yylex();

    printf("\nNumber of Keywords = %d\n", keyword);
    printf("Number of Identifiers = %d\n", identifier);
    printf("Number of Constants = %d\n", constant);
    printf("Number of Operators = %d\n", operator);
    printf("Number of Delimiters = %d\n", delimiter);

    return 0;
}
