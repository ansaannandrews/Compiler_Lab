%{
#include <stdio.h>
int zero = 0, one = 0;
%}

%%
0       { zero++; }
1       { one++; }
\n      { return 0; }
.       { }
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the BINARY NUMBER: ");
    yylex();

    printf("Number of zeros = %d\n", zero);
    printf("Number of ones = %d\n", one);

    return 0;
}
