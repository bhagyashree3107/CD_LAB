%{
#include <stdio.h>

int consonants = 0;
%}

%%

[b-df-hj-np-tv-zB-DF-HJ-NP-TV-Z]
                { consonants++; }

.               ;
\n              ;

%%

int main()
{
    printf("Enter a sentence: ");
    yylex();

    printf("Number of consonants = %d\n", consonants);

    return 0;
}
