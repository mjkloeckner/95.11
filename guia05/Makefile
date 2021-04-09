CC = gcc
FLAGS = -Wall

ex09: ex09.o main.o
	$(CC) -lm ex09.o main.o

ex09.o: ex09.h
	$(CC) -c ex09.c

ex10: ex09.o ex10.o main.o
	$(CC) -lm ex09.o ex10.o main.o

ex10.o: ex10.h
	$(CC) -lm -c ex10.c

main.o: 
	$(CC) -c main.c

clean:
	rm -f *.o *.out
