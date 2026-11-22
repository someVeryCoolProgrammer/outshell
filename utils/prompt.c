#include "../include/utils/prompt.h"
#include "../include/utils/getCurrentDir.h"
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define PATH_MAX_LENGTH 4096

int
prompt(void)
{
	// Displays prompt.

	char path[PATH_MAX_LENGTH];

	if (getCurrentDir(path, sizeof(path))) {
		fprintf(stderr, "\n\033[31Failed to get current working "
				"directory\033[0m\n");
		return 1;
	} else {
		printf("\n%s\n> ", path);
		fflush(stdout);
		return 0;
	}
}
