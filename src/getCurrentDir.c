#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include "..\include\getCurrentDir.h"
#else
printf("Unix based operating systems not supported.");
#endif

int getCurrentDir(char *path, size_t size)
{
#ifdef _WIN32
    const DWORD len = GetCurrentDirectoryA(4096, path);
        
    if (len  == 0 || len > 4096) {
        return 1;
    }

#endif
    return 0;
}
