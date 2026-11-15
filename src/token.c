#include <stdio.h>
#include <string.h>

#include "../include/token.h"

void token(char *userInput, char *tokens[], int capacity) {
    /*
     * Tokenize input
     *
     * Args:
     *      char *userInput: Command the user typed.
     *      char *tokens: Array of tokenized user input.
     *      int capacity: Amount of elements inside char *tokens
     * */
    
    char *token = strtok(userInput, " ");

    char *tokens[capacity];

    int counter = 0;

    while (token != NULL) {
        tokens[counter++] = token;
        token = strtok(NULL, " ");
    }

    int sizeOfTokens = sizeof(tokens) / sizeof(tokens[0]);

    for (int i = 0; i < sizeOfTokens; i++) {
        printf("%s", tokens[i]);
    }
}
