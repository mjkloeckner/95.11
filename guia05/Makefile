CC = gcc
FLAGS = -Wall

ex09: ex09.o main.o
	echo "this executes first"
	$(CC) ex09.o main.o

ex09.o: ex09.h
	$(CC) -c ex09.c

main.o: ex09.h
	$(CC) -c main.c

clean:
	rm -f *.o *.out
