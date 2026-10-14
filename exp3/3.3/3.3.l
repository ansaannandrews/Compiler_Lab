%{
#include "y.tab.h"
%}

%%
[a-z_][a-z0-9_]*    { return ID; }
\n                  { return NL; }
.                   { return INVALID; }
%%

int yywrap()
{
    return 1;
}
