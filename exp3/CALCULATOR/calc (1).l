%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+      { yylval = atoi(yytext); return NUMBER; }

[ \t]       ;

\n          { return NL; }

"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"("         { return '('; }
")"         { return ')'; }

.           { printf("Invalid Character: %s\n", yytext); }

%%

int yywrap()
{
    return 1;
}
