#ifdef _WIN32
    #include <stdio.h>
    #include <wchar.h>
    #include <windows.h>
    #include "..\include\commands.h"
    #include "..\include\getCurrentDir.h"
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
    printf("echo: Print something to the console (It's like 'prinf' in C)");
}

int cd(void)
{
#ifdef _WIN32
    wchar_t filePath[4096];
    char path[4096];

    if(getCurrentDir(path, sizeof(path))) {
        printf("\nFiled to get current wokring directory :(\n");
        return 1;
    }

    else {
        printf("\nEnter a file path: ");
        scanf(" %4094ls", &filePath);
        
        SetCurrentDirectoryW(filePath);
        wprintf(L"\n%ls\n", filePath);
        wprintf(L"\n>> Switched to '%ls'\n", filePath);

    }
#endif
    return 0;
}

void echo (void)
{
    char buff[4096];
    
    printf("\nEnter something you would like to print (to the console): ");
    scanf("%4095s", &buff);

    printf("\nYou said: '%s'!\n", buff);
}
