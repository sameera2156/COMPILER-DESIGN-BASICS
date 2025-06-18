#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[10][10] = {"int", "return", "if", "else", "while", "for", "char", "float", "double", "void"};
char operators[] = "+-*/=%<>&|!";

int isKeyword(char *word) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[100];
    int i = 0;

    fp = fopen("input.c", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        // If the character is a letter or digit, store it
        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        } else {
            // End of a word/token
            if (i > 0) {
                buffer[i] = '\0';
                if (isKeyword(buffer))
                    printf("Keyword: %s\n", buffer);
                else
                    printf("Identifier: %s\n", buffer);
                i = 0;
            }

            // Check for operators
            if (isOperator(ch)) {
                printf("Operator: %c\n", ch);
            }
        }
    }

    fclose(fp);
    return 0;
}
