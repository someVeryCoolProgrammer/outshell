#include <stdio.h>
#include <string.h>

// Only windows is supported currently. Unix based operating systems will be supported in the future. 
#ifdef _WIN32
#include <windows.h>
#else
printf("Unix based operating systems not supported.");
#endif

int main(void) 
{

    printf("--- Welcome To outshell ---\n");

#ifdef _WIN32
    char path[4096];
    char userInput[4096];
    
    const DWORD len = GetCurrentDirectoryA(4096, path);
        
    if (len == 0 || len > 4096) {
        printf("\nFailed to get current working directory :(\n");
        return 1;
    } else {
        
        while(userInput != '\0') {
            printf("\n%s > ", path);
            scanf("%4095s", &userInput);

            if (strcmp(userInput, "pwd") == 0){
                printf("\n>> Path --> %s\n", path);
            } else if(strcmp(userInput, "quit") == 0) {
                printf("\nGoodBye :)\n");
                break;
            } else if(strcmp(userInput, "help") == 0) {
                printf("\n--- outshell's commands ---\n");
                printf("\npwd: list current dir you're in\n");
                printf("\nquit: quit outshell\n");
                printf("\nhelp: help command\n")
            } else {
                printf("\nInvalid Input!\n");
            }    
        }
    }

#endif
    return 0;
}
