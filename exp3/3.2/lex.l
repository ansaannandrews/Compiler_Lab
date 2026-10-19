%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+		{yylval = atoi(yytext); return DIGIT; }
\n		{return NL; }
[ \t]		;
"+"		{return '+'; }
"-"		{return '-'; }
"*"		{return '*'; }
"/"		{return '/'; }
"("		{return '('; }
")"		{return ')'; }
.		{ printf("Invalid Expression %s\n",yytext); }
%%

int yywrap() {
	return 1;
}
