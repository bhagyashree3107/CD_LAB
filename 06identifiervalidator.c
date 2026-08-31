#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char identifier[100];
    int i;
    int valid = 1;

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    /* First character must be alphabet or underscore */
    if (!(isalpha(identifier[0]) || identifier[0] == '_'))
    {
        valid = 0;
    }

    /* Remaining characters */
    for (i = 1; identifier[i] != '\0'; i++)
    {
        if (!(isalnum(identifier[i]) || identifier[i] == '_'))
        {
            valid = 0;
            break;
        }
    }

    if (valid)
        printf("%s is a valid identifier.\n", identifier);
    else
        printf("%s is an invalid identifier.\n", identifier);

    return 0;
}
