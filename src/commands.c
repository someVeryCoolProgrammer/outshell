#include <stdio.h>
#include <stdlib.h>

#include "../include/commands.h"
#include "../include/token.h"
#include "../include/utils/getCurrentDir.h"
#include "../include/utils/prompt.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define BUFFER 4096

int
pwd(int argc, char **argv)
{
	// Print the current working directory the user is in.
	char path[BUFFER];

	if (argc == 1) {
		getCurrentDir(path, BUFFER);
		printf("\n%s\n", path);
		return 0;
	} else if (argc > 1 && strcmp(argv[1], "--help") == 0) {
		printf("Print the current working directory you're in.\n"
		       "\tFlags:\n\t\t --help: Help for command: 'pwd'");
		return 0;
	} else {
		printf("\033[31mFlag: '%s' was not found. 'pwd --help' for "
		       "guide on how to use pwd\n\033[0m",
		       argv[1]);
		return 0;
	}
	return 0;
}

int
help(int argc, char **argv)
{
	// Help guide for outshell's commands.

	printf("\npwd: Get the current direcory you're in\n"
	       "\tFlags:\n\t\t--help: help for command: 'pwd'\n"
	       "exit:  Exit outshell\n"
	       "help:  outshell's help guide\n"
	       "cd:    Change directory\n"
	       "echo:  Print to console\n"
	       "clear: Clear the terminal\n");

	return 0;
}

int
cd(int argc, char **argv)
{
	// Change current working directory.

#ifdef _WIN32
	if (argc == 1) {
		fprintf(stderr, "\033[31mPlease enter a file or directory.\033[0m\n");
		return 1;
	} else if (SetCurrentDirectoryA(argv[1])) {
		return 0;
	} else {
		fprintf(stderr, "\033[31mNo such directory or file. Try "
				"absoloute path.\033[0m\n");
		return 1;
	}
#else

	if (argc == 1) {
		fprintf(stderr, "\033[31mPlease enter a file or directory.\033[0m\n");
		return 1;
	} else if (chdir(argv[1])) {
		return 0;
	} else {
		fprintf(stderr, "\033[31mNo such directory or file. Try "
				"absoloute path.\033[0m");
		return -1;
	}

#endif
}

int
echo(int argc, char **argv)
{
	// Print something to console.

	// i starts at 1 to avoid printing "echo"
	for (int i = 1; i < argc; i++) {
		printf("%s\n", argv[i]);
	}
	return 0;
}

int
clear(int argc, char **argv)
{
	// Clearn screen.

#ifdef _WIN32
	system("cls");

	return 0;
#else
	system("clear");

	return 0;
#endif
}
