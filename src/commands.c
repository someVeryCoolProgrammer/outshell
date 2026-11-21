#include <stdio.h>
#include <stdlib.h>

#include "../include/commands.h"
#include "../include/utils/getCurrentDir.h"
#include "../include/utils/prompt.h"
#include "../include/token.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define PATH_MAX_LENGTH 4096
#define USER_INPUT_MAX_LENGTH 4096

int pwd (void) 
{
    // Command to list the current working directory the user currently is in 
    char path[PATH_MAX_LENGTH];

    if(getCurrentDir(path, sizeof(path))) {
        fprintf(stderr, "\n\033[31mFailed to get current working directory\033[0m\n");
        return 1;
    }
    else {
        printf("\nPath: %s\n", path);
        return 0;
    }
}

int help (void) 
{
    // Command help guide 

    printf("\npwd: Get the current direcory you're in\n"
            "exit: Exit outshell\n"
            "help: outshell's help guide\n"
            "cd: Change directory\n"
            "echo: Print to console\n"
            "clear: Clear the terminal\n"
    );

    return 0;
}

int cd (void)
{
     // Command to change current working directory 

#ifdef _WIN32
   
    char userInput[USER_INPUT_MAX_LENGTH];

    scanf("%4095s", userInput);

    if (SetCurrentDirectoryA(userInput)) {
        return 0;
    }
    
    else {
        fprintf(stderr, "\033[31mNo such directory or file.\033[0m\n");
        return 1;
    }
#else

    scanf("%4095s", userInput);

    if (chdir(userInput)) {
        return 0;
    }

    else {
        fprintf(stderr, "\033[31mNo such directory or file.\033[0m");
        return 1;
    }

#endif
    return 0;
}

int echo (void)
{
    // Command that prints to console.

    char userInput[USER_INPUT_MAX_LENGTH];

    fgets(userInput, sizeof(userInput), stdin);

    printf("%s\n", userInput);

    return 0;
}

int clear (void)
{
    // Clears the screan. 
    
    // This does not really clear the screen, it's like pressing ctrl + l.
    printf("\033[2J\033[H");
    return 0;
}

