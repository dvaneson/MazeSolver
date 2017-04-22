CFLAGS = -g -Wall -ansi -pedantic -O0

rhr: main.c maze.h maze.c
	gcc $(CFLAGS) -o rhr main.c maze.h maze.c

clean:
	rm -f *.o rhr
