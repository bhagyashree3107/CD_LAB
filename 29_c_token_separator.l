%{
#include <stdio.h>
%}

%%

"int"|"float"|"char"|"double"|"void"|"if"|"else"|"for"|"while"|"return"
                { printf("%s -> KEYWORD\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*
                { printf("%s -> IDENTIFIER\n", yytext); }

[0-9]+(\.[0-9]+)?
                { printf("%s -> CONSTANT\n", yytext); }

\"([^\"\\]|\\.)*\"
                { printf("%s -> STRING\n", yytext); }

"=="|"!="|"<="|">="|"++"|"--"|"&&"|"||"|"+"|"-"|"*"|"/"|"="|"<"|">"
                { printf("%s -> OPERATOR\n", yytext); }

[;,(){}[\]]
                { printf("%s -> SPECIAL SYMBOL\n", yytext); }

[ \t\n]+        ;

.               { printf("%s -> UNKNOWN\n", yytext); }

%%

int main()
{
    yylex();
    return 0;
}
