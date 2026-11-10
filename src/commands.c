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
        fprintf(stderr, "\nFailed to get current working directory :(\n");
        return 1;
    }
    else {
        printf("\n%s\n", path);
        return 0;
    }
}

int exit (void) 
{
    /* 
     * Command to exit outshell  
     *  
     * Returns:
     *      int
     * */
    printf("\nGoodbye\n");
    
    // Exit function when used
    return 1;
}

int help (void)
{
    /* 
     * Command help guide 
     * 
     * Returns:
     *      int
     * */
    printf("\npwd: Get the current direcory you're in\n");
    printf("exit: Exit outshell\n");
    printf("help: outshell's help guide\n");
    printf("cd: Change directory\n");
    printf("echo: Print to console\n");
    printf("clear: Clear the terminal\n");

    return 0;
}

int cd (void)
{
    /* 
     * Command to change current working directory 
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
        fprintf(stderr, "No such directory or file: '%s'", filePathWin);
        return 1;
    }
#else
    char filePathUnix[4096]

    scanf(" %4095s", filePathUnix);

    if (chdir("%s", filePathUnix)) {
        chdir("%s", filePathUnix);
    }

    else {
        fprintf(stderr, "No such directory or file: '%s'", filePathUnix);
        return 1;
    }

#endif
    return 0;
}

int echo (void)
{
    /* 
     * Command that prints to console like printf(); in C 
     *
     * Returns:
     *      int
     * */
    char buf[4096];
   
    scanf("%4095s", buf);

    printf("\n%s\n", buf);
    return 0;
}

int clear (void)
{
    /* 
     * Clears the screan 
     * 
     * Returns:
     *      int 
     * */
    printf("\033[2J\033[H");
    return 0;
}

