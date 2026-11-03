#ifdef _WIN32
    #include <stdio.h>
    #include <windows.h>
    #include "..\include\commands.h"
    #include "..\include\getCurrentDir.h"
    #include "..\include\prompt.h"
#else
    printf("Unix based operating systems not supported");
#endif

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
    printf("cd: Change current directory\n");
    printf("echo: Print something to console\n"); 
}

int cd(void)
{
#ifdef _WIN32
    char filePath[4096];
    char path[4096];

    if(SetCurrentDirectoryA){
        printf("\nEnter a file path: ");
        scanf(" %4094s", &filePath);
         
        SetCurrentDirectoryA(filePath);
        printf(L"\n>> Switched to '%s'\n", filePath);
        return 0;
    }

    else {
        printf("Failed to switch to: %s", filePath);
        return 1;
    }
#endif
    return 0;
}

void echo (void)
{
    char buff[4096];
    
    printf("\nEnter something you would like to print (to the console): ");
    scanf("%4095s", &buff);

    printf("\n%s\n", buff);
}
