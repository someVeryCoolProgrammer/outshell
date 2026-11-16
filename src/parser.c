#include <stdio.h> 
#include <string.h> 
#include <stdbool.h> 

#include "../include/commands.h"
#include "../include/parser.h"
#include "../include/utils/prompt.h"
#include "../include/token.h"

typedef struct {
    char *name;
    int (*command)(void);
}FindCommand;

#define USER_INPUT_MAX_LENGTH 4096
#define TOKENIZED_USER_INPUT_MAX_LENGTH 64

void parser (void) 
{
    // Displays welcome message, reads and takes user input for commands, and calls commands based on user input

    printf("\n\t--- Welcome To outshell ---\n");
    fflush(stdout);

    char userInput[USER_INPUT_MAX_LENGTH];
    
    FindCommand cmds[] = {
        {"pwd", pwd},
        {"help", help},
        {"cd", cd},
        {"echo", echo},
        {"clear", clear}
    };

    int sizeofCmds = sizeof(cmds) / sizeof(cmds[0]);
    
    bool isRunning = true;    

    char *tokens[TOKENIZED_USER_INPUT_MAX_LENGTH];
    
    while (isRunning) {
        prompt();
        
        fgets(userInput, sizeof(userInput), stdin); 
        userInput[strlen(userInput) - 1] = '\0';
        token(userInput, tokens);

        if (strcmp("exit", userInput) == 0) {
            isRunning = false;
        }

        for (int i = 0; i < sizeofCmds; i++) {
            if (strcmp(cmds[i].name, tokens[0]) == 0) {
                cmds[i].command();
            }
        }
    }
}

