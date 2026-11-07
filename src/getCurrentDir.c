#include <stdio.h>
#include <string.h>
#include "../include/getCurrentDir.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

int getCurrentDir (char *path, const size_t size)
{
    /* Gets the current directory user is in
     * 
     * Args:
     *      char *path: Path to where user is
     *      const size_t size: Size of buffer to where path will be stored
     *  
     *  Returns:
     *      int
     * */
#ifdef _WIN32
    const DWORD len = GetCurrentDirectoryA((DWORD) size, path);
     
    if (len  == 0 || len > size) {
        return 1;
    }
#else
    if (!getcwd(path, size)) {
        return 1;
    }
#endif
    return 0;
}
