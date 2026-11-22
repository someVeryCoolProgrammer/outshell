CFLAGS = -Wall -Wextra -Wpedantic -Wconversion -Wshadow
SRC = src/commands.c src/main.c src/parser.c src/token.c utils/getCurrentDir.c utils/prompt.c

.PHONY: w u rw ru 

w:
	gcc $(CFLAGS) $(SRC) -o bin/outshell.exe

u:
	gcc $(CFLAGS) $(SRC) -o bin/outshell 

rw:
	./bin/outshell.exe

ru:
	./bin/outshell
