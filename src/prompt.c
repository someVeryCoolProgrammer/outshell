#include <stdio.h>
#include "..\include\getCurrentDir.h"
#include "..\include\prompt.h"

#ifdef _WIN32
#include <windows.h>
#endif

int prompt(void)
{
#ifdef _WIN32
    char path[4096];

    if(getCurrentDir(path, sizeof(path))) {
        printf("\nFailed to get current working directory :(\n");
        return 1;
    } else {
        printf("\noutshell %s > ", path);
    }
    
#endif
    return 0;
}
