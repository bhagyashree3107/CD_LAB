#include <stdio.h>
#include <string.h>

int main()
{
    char expr[100];
    int temp = 1;
    int i;

    printf("Enter expression: ");
    scanf("%s", expr);

    printf("\nThree Address Code:\n");

    /* Multiplication first */
    for (i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '*')
        {
            printf("t%d = %c * %c\n",
                   temp,
                   expr[i - 1],
                   expr[i + 1]);

            expr[i - 1] = '0' + temp;
            expr[i] = ' ';
            expr[i + 1] = ' ';

            temp++;
        }
    }

    /* Addition */
    for (i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '+')
        {
            char left = expr[i - 1];
            char right = expr[i + 1];

            printf("t%d = %c + %c\n",
                   temp, left, right);

            printf("Result = t%d\n", temp);

            temp++;
        }
    }

    return 0;
}
