#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../include/commands.h"
#include "../include/parser.h"
#include "../include/prompt.h"

typedef struct {
    char *name;
    int (*command)(int argc, char **argv);
}FindCommand;

void parser (void) 
{
    // Displays welcome message, reads and takes user input for commands, and calls commands based on user input

    printf("\n\t--- Welcome To outshell ---\n");
    
    char userInput[4096];
    
    FindCommand cmds[] = {
        {"pwd", pwd},
        {"help", help},
        {"cd", cd},
        {"echo", echo},
        {"clear", clear}
    };

    int sizeofCmds = sizeof(cmds) / sizeof(cmds[0]);
    
    bool isRunning = true;

    while (isRunning) {
        prompt();
        scanf("%4095s", userInput);
       
        if (strcmp("quit", userInput) == 0) {
            isRunning = false;
        }
        
        int argc = argc;
        char **argv = argv;

        for (int i = 0; i < sizeofCmds; i++) {
            if (strcmp(cmds[i].name, userInput) == 0) {
                cmds[i].command(argc, argv);
            }
        } 
    }
}

