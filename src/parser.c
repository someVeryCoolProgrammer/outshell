#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "../include/commands.h"
#include "../include/parser.h"
#include "../include/prompt.h"

void parser (void) 
{

    printf("\n\t--- Welcome To outshell ---\n");
    
    char userInput[4096];

    while (true) {
        prompt();
        scanf("%4095s", userInput);

        if (strcmp(userInput,"pwd") == 0){
            pwd();
        } else if (strcmp(userInput, "quit") == 0) {
            quit();
            break;
        } else if (strcmp(userInput, "help") == 0) {
            help();
        } else if (strcmp(userInput,"cd") == 0) {
            cd();
        }else if (strcmp(userInput, "echo") == 0) {
            echo();
        } else if (strcmp(userInput, "clear") == 0) {
            clear();
        } else {
            fprintf(stderr, "\nCommand: '%s' was not found\n", userInput);
        }    
    }
}

