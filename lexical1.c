#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char str[100], word[50];
    int i = 0, j;

    printf("Enter the string: ");
    scanf("%[^\n]", str);

    while (str[i] != '\0')
    {
        if (isspace(str[i]))
        {
            i++;
            continue;
        }
        if (str[i] == '/' && str[i + 1] == '/')
        {
            break;
        }
        if (str[i] == '/' && str[i + 1] == '*')
        {
            i += 2;
            while (!(str[i] == '*' && str[i + 1] == '/') && str[i] != '\0')
            {
                i++;
            }
            i += 2;
            continue;
        }
        if (isalpha(str[i]) || str[i] == '_')
        {
            j = 0;
            while (isalnum(str[i]) || str[i] == '_')
            {
                word[j++] = str[i++];
            }
            word[j] = '\0';

            printf("Identifier : %s\n", word);
        }
        else if (isdigit(str[i]))
        {
            j = 0;
            while (isdigit(str[i]))
            {
                word[j++] = str[i++];
            }
            word[j] = '\0';

            printf("Constant   : %s\n", word);
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' ||
                 str[i] == '/' || str[i] == '=' || str[i] == '<' ||
                 str[i] == '>' || str[i] == '%')
        {
            printf("Operator   : %c\n", str[i]);
            i++;
        }

        else
        {
            i++;
        }
    }

    return 0;
}