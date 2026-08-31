#include <stdio.h>

int main()
{
    char op1, op2, operator;

    printf("Enter three address statement:\n");
    printf("Example: t1 = a + b\n");

    scanf("t1 = %c %c %c",
          &op1, &operator, &op2);

    printf("\nGenerated Assembly Code:\n");

    printf("MOV R0, %c\n", op1);

    switch (operator)
    {
    case '+':
        printf("ADD R0, %c\n", op2);
        break;

    case '-':
        printf("SUB R0, %c\n", op2);
        break;

    case '*':
        printf("MUL R0, %c\n", op2);
        break;

    case '/':
        printf("DIV R0, %c\n", op2);
        break;

    default:
        printf("Invalid operator\n");
        return 1;
    }

    printf("MOV t1, R0\n");

    return 0;
}
