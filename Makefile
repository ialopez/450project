all:
	gcc -ggdb -c RIG.c
	gcc -ggdb -o regalloc RIG.o main.c

