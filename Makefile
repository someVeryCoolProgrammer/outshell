CC = gcc
CFLAGS: -Wall -Wextra 

all:
	$(CC) $(CFLAGS) src\main.c src\getCurrentDir.c src\commands.c -o bin\outshell.exe
