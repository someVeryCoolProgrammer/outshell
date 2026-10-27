#include <stdio.h>
#include <string.h>
#include "..\include\commands.h"
#include "..\include\getCurrentDir.h"

// Only windows is supported currently. Unix based operating systems will NOT supported in the future. 
#ifdef _WIN32
#include <windows.h>
#endif

int main(void) 
{
    printf("\n--- Welcome To outshell ---\n");

#ifdef _WIN32
    
    char path[4096];
    char userInput[4096];

    if (getCurrentDir(path, sizeof(path))) {
        printf("\nFailed to get current working directory :(\n");
        return 1;
    } else { 
        while(userInput != '\0') {
            
            printf("\noutshell %s > ", path);
            scanf("%4095s", &userInput);
            
            if (strcmp(userInput, "pwd") == 0){
                pwd();
            } else if(strcmp(userInput, "quit") == 0) {
                quit();
                return 1;
            } else if(strcmp(userInput, "help") == 0) {
                help();
            } else {
                printf("\nInvalid Input!\n");
            }    
        }
    }

#endif
    return 0;
}
