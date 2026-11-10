CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wconversion -Wshadow
SRC = src/main.c utils/getCurrentDir.c src/commands.c utils/prompt.c src/parser.c

# Compile outshell on windows
w:
	$(CC) $(CFLAGS) $(SRC) -o bin/outshell.exe

# Compile outshell on unix based operating systems
u:
	$(CC) $(CFLAGS) $(SRC) -o bin/outshell 

# Run outshell on windows
rw:
	./bin/outshell.exe

# Run outshell on unix based operating systems
ru:
	./bin/outshell
