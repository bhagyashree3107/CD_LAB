#include <stdio.h>

int main()
{
    char ch;
    int whitespace = 0, newline = 0;

    printf("Enter text (Press Ctrl+D on Linux/Mac or Ctrl+Z then Enter on Windows to stop):\n");

    while ((ch = getchar()) != EOF)
    {
        if (ch == ' ' || ch == '\t')
            whitespace++;

        if (ch == '\n')
            newline++;
    }

    printf("\nNumber of Whitespaces : %d\n", whitespace);
    printf("Number of Newline Characters : %d\n", newline);

    return 0;
}