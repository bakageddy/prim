all: main
main: main.c
	gcc main.c -o main -lncurses -lm -Wall -Wextra -pedantic
