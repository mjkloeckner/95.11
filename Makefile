$(CC)=gcc

all: main clean


main: main.o arguments.o data.o load_country_codes.o
	$(CC) main.o arguments.o data.o load_country_codes.o -g -o main 

main.o: main.c main.h arguments.h macros.h
	$(CC) -g -c main.c

arguments.o: arguments.c arguments.h macros.h
	$(CC) -c arguments.c

data.o: main.c main.h
	$(CC) -c data.c

load_country_codes.o: load_country_codes.h main.h
	$(CC) -c load_country_codes.c 

clean:
	rm -f *.o main 

run: 
	./main -in input.csv
