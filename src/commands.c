#include <stdio.h>
#include <stdlib.h>

#include "../include/commands.h"
#include "../include/getCurrentDir.h"
#include "../include/prompt.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int pwd (void)
{
    char path[4096];

    if(getCurrentDir(path, sizeof(path))) {
        perror("\nFailed to get current working directory :(\n");
        return 1;
    }
    else {
        printf("\n%s\n", path);
        return 0;
    }
}

void quit (void) 
{
    printf("\nGoodbye\n");
}

void help (void)
{
    printf("\npwd: Get the current direcory you're in\n");
    printf("quit: Quit outshell\n");
    printf("help: outshell's help guide\n");
    printf("cd: Change directory\n");
    printf("echo: Print to console\n");
    printf("clear: Clear the terminal\n");
}

int cd (void)
{
#ifdef _WIN32
    char filePath[4096];

    scanf(" %4094s", filePath);
    
    if (SetCurrentDirectoryA(filePath)) {
        SetCurrentDirectoryA(filePath);
        return 0;
    }
    
    else {
        perror("No such directory or file");
        return 1;
    }
#endif
    return 0;
}

void echo (void)
{
    char buf[4096];
   
    scanf("%4095s", buf);

    printf("%s", buf);
}

void clear (void)
{
    printf("\033[2J\033[H");
}

