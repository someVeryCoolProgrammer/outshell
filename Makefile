CPPFLAGS = -Iinclude 
CFLAGS :=  -Wall -Wextra -Wpedantic -Wconversion -Wshadow
SRC := src/commands.c src/main.c src/parser.c src/token.c utils/getCurrentDir.c utils/prompt.c src/launchProgram/launch.c

.PHONY: w u rw ru cleanW cleanU 

w:
	gcc $(CPPFLAGS) $(CFLAGS) $(SRC) -o bin/outshell.exe

u:
	gcc $(CPPFLAGS) $(CFLAGS) $(SRC) -o bin/outshell 

rw:
	./bin/outshell.exe

ru:
	./bin/outshell

cleanW:
	rm bin/outshell.exe

cleanU:
	rm -rf bin/outshell
