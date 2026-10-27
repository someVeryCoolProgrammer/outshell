#include <stdio.h>
#include "..\include\commands.h"
#include "..\include\getCurrentDir.h"

int pwd(void)
{
#ifdef _WIN32
    char path[4096];

    if(getCurrentDir(path, sizeof(path))) {
        printf("\nFailed to get current working directory :(\n");
        return 1;
    }
    else {
        printf("\n>> %s\n", path);
    }
#endif 
    return 0;
}

void quit(void) 
{
    printf("Goodbye\n");
}

void help(void)
{
    printf("\npwd: Gets the current direcory you're in\n");
    printf("quit: Quit outshell\n");
    printf("help: outshell's help guide\n");
}
