#include <stdio.h>
#include "../include/utils/getCurrentDir.h"
#include "../include/utils/prompt.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define PATH_MAX_LENGTH 4096

int prompt (void)
{
    /* 
     * Displays prompt 
     *  
     * Returns:
     *      int
     * */

    char path[PATH_MAX_LENGTH];

    if (getCurrentDir(path, sizeof(path))) {
        fprintf(stderr ,"\nFailed to get current working directory :(\n");
        return 1;
    } else {
        printf("\n%s\n> ", path);
        fflush(stdout);
        return 0;
    }
}
