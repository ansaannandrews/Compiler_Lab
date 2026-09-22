%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token NUMBER NL

%left '+' '-'
%left '*' '/'

%%

input:
        expr NL      { printf("Result = %d\n", $1); }
        ;

expr:
        expr '+' expr    { $$ = $1 + $3; }
      | expr '-' expr    { $$ = $1 - $3; }
      | expr '*' expr    { $$ = $1 * $3; }
      | expr '/' expr
            {
                if($3 == 0)
                {
                    printf("Division by zero not allowed\n");
                    $$ = 0;
                }
                else
                    $$ = $1 / $3;
            }
      | '(' expr ')'     { $$ = $2; }
      | NUMBER           { $$ = $1; }
      ;

%%

void yyerror(const char *s)
{
    printf("Invalid Expression\n");
}

int main()
{
    printf("Enter Arithmetic Expression: ");
    yyparse();
    return 0;
}
