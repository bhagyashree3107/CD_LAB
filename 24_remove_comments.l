%{
#include <stdio.h>

int comments = 0;
FILE *output;
%}

%%

"//".*                         { comments++; }

"/*"([^*]|\*+[^*/])*\*+"/"    { comments++; }

\n                             { fprintf(output, "\n"); }
.                              { fprintf(output, "%s", yytext); }

%%

int main()
{
    output = fopen("output.c", "w");

    if (output == NULL)
    {
        printf("Unable to create output file.\n");
        return 1;
    }

    yylex();

    fclose(output);

    printf("Number of comments removed = %d\n", comments);
    printf("Comments removed successfully.\n");
    printf("Output written to output.c\n");

    return 0;
}
