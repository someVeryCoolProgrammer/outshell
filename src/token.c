#include <stdio.h>
#include <string.h>

#include "../include/token.h"

void token(char *userInput, char *tokens[]) {
    /*
     * Tokenize input
     *
     * Args:
     *      char *userInput: Command the user typed.
     *      char *tokens: Array of tokenized user input.
     *      int capacity: Amount of elements inside char *tokens
     * */
    
    char *token = strtok(userInput, " ");

    int counter = 0;

    while (token != NULL) {
        tokens[counter++] = token;
        token = strtok(NULL, " ");
    }
}
