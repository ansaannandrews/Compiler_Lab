%{
#include <stdio.h>
%}

%%
0[01]*1    { printf("Valid\n"); }
.         { printf("Invalid\n"); }
%%

int yywrap() {
return 1;
}

int main() {
printf("Enter the binary string: ");
yylex();
return 0;
}
