all: funWithMake

lab10 : frontend.o parser.o
	gcc -Wall -g parser.o frontend.o -o funWithMake

parser.o: parser.c parser.h
	gcc -Wall -g parser.c -c

frontend.o: frontend.c parser.h parser.c
	gcc -Wall -g frontend.c -c
