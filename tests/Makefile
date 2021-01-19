$(CC)=gcc

all: make_main


make_main: main.o 
	$(CC) readlines.o -o main

main.o: readlines.c ISO3166-1.h
	$(CC) -c readlines.c

clean: 
	rm -f *.c *.out
