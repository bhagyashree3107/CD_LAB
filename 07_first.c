#include <stdio.h>
#include <string.h>

void findFirst(char symbol)
{
    if (symbol == 'S')
    {
        printf("FIRST(S) = { a, b }\n");
    }
    else if (symbol == 'A')
    {
        printf("FIRST(A) = { epsilon }\n");
    }
    else if (symbol == 'B')
    {
        printf("FIRST(B) = { epsilon }\n");
    }
}

int main()
{
    printf("Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> epsilon\n");
    printf("B -> epsilon\n\n");

    findFirst('S');
    findFirst('A');
    findFirst('B');

    return 0;
}
