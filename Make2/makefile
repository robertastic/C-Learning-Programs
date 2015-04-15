all: lab11

lab11: main.o function.o
	gcc -Wall -g main.o function.o -o lab11

main.o: main.c header.h
	gcc -Wall -g main.c -c

function.o: function.c header.h
	gcc -Wall -g function.c -c
