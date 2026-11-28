#include <stdio.h>
#include <windows.h>

#include "launchProgram/launch.h"

bool launch(int argc, char **argv) 
{
#ifdef _WIN32
	/* Launch a program.
	 * Returns:
	 *	true: Is successful.  
	 *	false: If process could not be created. */

	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if(argc == 0) {
		return 1;
	}

	if(CreateProcess(NULL, argv[0], NULL, NULL, false, 0, NULL, NULL, &si, &pi)) {
		return true;
		return 0;
	} else {
		fprintf(stderr, "\033[31mCould not create process: %s.\n\033[0m", argv[1]);
		return false;
		return 1;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
#else
	fprintf(stderr, "\033[31mUnix is currently not supported\033[0m\n");
	return 1;
#endif
	return 0;
}
