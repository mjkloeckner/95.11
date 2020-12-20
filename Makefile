$(CC)=gcc

all: make_main clean


make_main: main.o arguments.o data.o
	$(CC) main.o arguments.o data.o -o main 

main.o: src/main.c include/main.h include/arguments.h include/macros.h
	$(CC) -c src/main.c

arguments.o: src/arguments.c include/arguments.h include/macros.h
	$(CC) -c src/arguments.c

data.o: src/main.c include/main.h
	$(CC) -c src/data.c

clean:
	rm -f *.o


