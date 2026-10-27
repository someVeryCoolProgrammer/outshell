#include <stdio.h>
#include <string.h>

// Only windows is supported currently. Unix based operating systems will be supported in the future. 
#ifdef _WIN32
#include <windows.h>
#else
printf("Unix based operating systems not supported.");
#endif

int getCurrentDir(char *path, size_t size);
int pwd(void);
void help(void);
int quit(void);

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
            printf("%s\n", userInput);
            if (strcmp(userInput, "pwd") == 0){
                pwd();
            } else if(strcmp(userInput, "quit") == 0) {
                quit();
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

int getCurrentDir(char *path, const size_t size){
#ifdef _WIN32
    const DWORD len = GetCurrentDirectoryA(4096, path);
        
    if (len == 0 || len > 4096) {
        return 1;
    }
#endif
    return 0;
}

int pwd(void) {

#ifdef _WIN32
    char path[4096];
    
    if (getCurrentDir(path, sizeof(path))) {
        printf("\nFailed to get current working directory :(\n");
    }
    else {
        printf("\n>> %s\n", path);
    }
#endif
    return 0;
}

int quit(void) {
    printf("GoodBye");
    return 1;
}

void help(void) {
    printf("\nLpwd: Gets currend directory you're in\n");
    printf("quit: Quit outshell\n");
    printf("help: help quide\n");
}
