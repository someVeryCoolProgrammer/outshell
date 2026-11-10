#include <stdio.h>
#include "../include/getCurrentDir.h"
#include "../include/prompt.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int prompt (void)
{
    /* 
     * Displays prompt 
     *  
     * Returns:
     *      int
     * */

    char path[4096];

    if (getCurrentDir(path, sizeof(path))) {
        fprintf(stderr ,"\nFailed to get current working directory :(\n");
        return 1;
    } else {
        printf("\n%s\n> ", path);
        return 0;
    }
}
