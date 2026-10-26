#include <stdio.h>

// Only windows is supported currently. Unix based operating systems will be supported in the future. 
#ifdef _WIN32
#include <windows.h>
#else
printf("Unix based operating systems not supported.");
#endif

int main(void) 
{

    printf("--- Welcome To outshell ---\n");

#ifdef _WIN32

    char path[4096];

    const DWORD len = GetCurrentDirectoryA(4096, path);
        
    if (len == 0 || len > 4096) {
        printf("\nFailed to get current working directory :(\n");
        return 1;
    } else {
        printf("\n%s > ", path);
    }
#endif
    return 0;
}
