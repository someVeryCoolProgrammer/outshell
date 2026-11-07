CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wconversion -Wshadow

w:
	$(CC) $(CFLAGS) src/main.c src/getCurrentDir.c src/commands.c src/prompt.c src/parser.c -o bin/outshell.exe

u:
	$(CC) $(CFLAGS) src/main.c src/getCurrentDir.c src/commands.c src/prompt.c src/parser.c -o bin/outshell

