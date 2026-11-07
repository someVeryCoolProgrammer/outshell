#include <stdio.h>
#include <string.h>
#include "../include/getCurrentDir.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int getCurrentDir (char *path, size_t size)
{
#ifdef _WIN32
    const DWORD len = GetCurrentDirectoryA(4096, path);
        
    if (len  == 0 || len > 4096) {
        return 1;
    }
#else
    char *getcwd(4096, path)
#endif
    return 0;
}
