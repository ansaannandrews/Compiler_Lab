%{
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+		{ return DIGIT; }
[a-z_][A-Z0-9_]*	{ return ID; }
\n		{ return NL; }
[ \t]		;
.		{ return yytext[0]; }
%%

int yywrap() {
	return 1;
}


