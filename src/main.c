#include <stdio.h>
#include <string.h>
#include "..\include\commands.h"
#include "..\include\prompt.h"

int main(void) 
{
    printf("\n--- Welcome To outshell ---\n");

#ifdef _WIN32
    char userInput[4096];

    while(userInput != '\0') {
        prompt();
        scanf("%4095s", &userInput);  

        if (strcmp(userInput, "pwd") == 0){
            pwd();
        } else if(strcmp(userInput, "quit") == 0) {
            quit();
            return 1;
        } else if(strcmp(userInput, "help") == 0) {
            help();
        } else if(strcmp(userInput, "cd") == 0) {
            cd();
        } else {
            printf("\nInvalid Input!\n");
        }    
    }

#endif
    return 0;
}
