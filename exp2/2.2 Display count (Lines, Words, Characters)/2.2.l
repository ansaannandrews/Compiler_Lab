%{
#include<stdio.h>
int lines = 0,words = 0,chars = 0;
%}


%%
\n {lines++; chars++;}
[ \t]+ {chars += yyleng;}
[^ \t\n]+ {words++; chars += yyleng;}
%%
int yywrap() {
        return 1;
}

int main() {
        printf("Enter the text: \n");
        yylex();
        
        printf("\nNumberof Lines: %d\n",lines);
        printf("Numberof Words: %d\n",words);
        printf("Numberof Characters: %d\n",chars);
        return 0;
}
