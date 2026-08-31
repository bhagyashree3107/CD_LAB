#include <stdio.h>

int main()
{
    char ch;

    printf("Enter an operator: ");
    scanf("%c", &ch);

    switch(ch)
    {
        case '+':
            printf("+ is an Addition Operator\n");
            break;

        case '-':
            printf("- is a Subtraction Operator\n");
            break;

        case '*':
            printf("* is a Multiplication Operator\n");
            break;

        case '/':
            printf("/ is a Division Operator\n");
            break;

        default:
            printf("Not an Arithmetic Operator\n");
    }

    return 0;
}