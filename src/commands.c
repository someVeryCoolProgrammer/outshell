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
    /* 
     * Command to list the current working directory the user currently is in 
     * 
     * Returns:
     *      int
     * */
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
    // Csmmand to quit outshell
    printf("\nGoodbye\n");
}

void help (void)
{
    // Command help guide
    printf("\npwd: Get the current direcory you're in\n");
    printf("quit: Quit outshell\n");
    printf("help: outshell's help guide\n");
    printf("cd: Change directory\n");
    printf("echo: Print to console\n");
    printf("clear: Clear the terminal\n");
}

int cd (void)
{
    /* Command to change current working directory 
     * 
     * Returns:
     *      int
     * */
#ifdef _WIN32
    char filePathWin[4096];

    scanf(" %4094s", filePathWin);
    
    if (SetCurrentDirectoryA(filePathWin)) {
        SetCurrentDirectoryA(filePathWin);
        return 0;
    }
    
    else {
        perror("No such directory or file");
        return 1;
    }
#else
    char filePathUnix[4096]

    scanf(" %4095s", filePathUnix);

    if (chdir("%s", filePathUnix)) {
        chdir("%s", filePathUnix);
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
    // Command that prints to console like printf(); in C
    char buf[4096];
   
    scanf("%4095s", buf);

    printf("%s", buf);
}

void clear (void)
{
    // Clear the screan 
    printf("\033[2J\033[H");
}

