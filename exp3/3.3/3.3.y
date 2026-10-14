%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *s);
%}

%token ID NL INVALID

%%
stmt : exp NL
     {
         printf("Valid Identifier\n");
         exit(0);
     }
     ;

exp  : ID
     ;
%%

int yyerror(char *s)
{
    printf("Invalid Identifier\n");
    return 0;
}

int main()
{
    printf("Enter the token: ");
    yyparse();
    return 0;
}
