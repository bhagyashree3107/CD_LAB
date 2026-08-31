#include <stdio.h>
#include <ctype.h>
#include <string.h>

char code[] =
"// Sample Program\n"
"int main() {\n"
"   int a = 10;\n"
"   /* This is a comment */\n"
"   int b = 20;\n"
"   int c = a + b;\n"
"   return 0;\n"
"}";

char *keywords[] = {
    "int","float","char","if","else",
    "while","for","return","void","main"
};

int isKeyword(char str[]) {
    int i;
    for(i = 0; i < 10; i++) {
        if(strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    int i = 0, j;
    char token[50];

    while(code[i] != '\0') {

        // Ignore spaces, tabs and new lines
        if(isspace(code[i])) {
            i++;
            continue;
        }

        // Ignore single-line comments
        if(code[i] == '/' && code[i+1] == '/') {
            while(code[i] != '\n' && code[i] != '\0')
                i++;
            continue;
        }

        // Ignore multi-line comments
        if(code[i] == '/' && code[i+1] == '*') {
            i += 2;
            while(!(code[i] == '*' && code[i+1] == '/'))
                i++;
            i += 2;
            continue;
        }

        // Identifier or Keyword
        if(isalpha(code[i]) || code[i] == '_') {
            j = 0;
            while(isalnum(code[i]) || code[i] == '_')
                token[j++] = code[i++];
            token[j] = '\0';

            if(isKeyword(token))
                printf("Keyword : %s\n", token);
            else
                printf("Identifier : %s\n", token);
        }

        // Constant
        else if(isdigit(code[i])) {
            j = 0;
            while(isdigit(code[i]))
                token[j++] = code[i++];
            token[j] = '\0';

            printf("Constant : %s\n", token);
        }

        // Operators
        else if(strchr("+-*/=<>!%", code[i])) {
            printf("Operator : %c\n", code[i]);
            i++;
        }

        // Special Symbols
        else if(strchr("(){};,", code[i])) {
            printf("Special Symbol : %c\n", code[i]);
            i++;
        }

        else {
            i++;
        }
    }

    return 0;
}