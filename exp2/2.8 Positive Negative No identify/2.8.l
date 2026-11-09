%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
[-+]?[0-9]+ {
    int n = atoi(yytext);

    if(n > 0)
        printf("Positive Number\n");
    else if(n < 0)
        printf("Negative Number\n");
    else
        printf("Zero\n");
}

\n { return 0; }
.  { printf("Invalid Input\n"); }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the Number: ");
    yylex();
    return 0;
}
