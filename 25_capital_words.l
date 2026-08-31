%{
#include <stdio.h>
%}

%%

[A-Z]+          { printf("Capital Word: %s\n", yytext); }
[ \t\n]+        ;
.               ;

%%

int main()
{
    printf("Enter text:\n");
    yylex();

    return 0;
}
