CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: main clean


main: main.o arguments.o perrors.o load_country_codes.o read_file.o print_file.o
	$(CC) $(CFLAGS) main.o arguments.o perrors.o load_country_codes.o read_file.o print_file.o -o main 

main.o: main.c main.h arguments.h macros.h
	$(CC) -c main.c

arguments.o: arguments.c arguments.h macros.h
	$(CC) -c arguments.c

perrors.o: main.c main.h
	$(CC) -c perrors.c

load_country_codes.o: load_country_codes.h main.h
	$(CC) -c load_country_codes.c 

read_file.o: read_file.h main.h
	$(CC) -c read_file.c

print_file.o: print_file.h main.h
	$(CC) -c print_file.c


clean:
	rm -f *.o 

run: 
	./main -in input.csv -out output.txt
