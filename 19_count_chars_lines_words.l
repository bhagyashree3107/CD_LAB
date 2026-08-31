%{
#include <stdio.h>

int characters = 0;
int words = 0;
int lines = 0;
%}

%%

\n              { lines++; characters++; }
[ \t]+           { characters += yyleng; }
[^ \t\n]+        { words++; characters += yyleng; }

%%

int main()
{
    yylex();

    printf("Number of characters = %d\n", characters);
    printf("Number of words      = %d\n", words);
    printf("Number of lines      = %d\n", lines);

    return 0;
}
