%{
#include <stdio.h>
%}

%%

[0-9]+(\.[0-9]+)?    { printf("Constant: %s\n", yytext); }
[ \t\n]+             ;
.                    ;

%%

int main()
{
    printf("Enter C source code:\n");
    yylex();
    return 0;
}
