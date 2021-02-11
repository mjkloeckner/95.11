CC = gcc
CFLAGS = -std=c99 -Wall -pedantic

all: main clean

main: main.o arguments.o perrors.o load_country_codes.o read_file.o print_file.o
	$(CC) $(CFLAGS) main.o arguments.o perrors.o load_country_codes.o read_file.o print_file.o -o analisis_covid 

main.o: main.c main.h arguments.h macros.h
	$(CC) $(CFLAGS) -c main.c

arguments.o: arguments.c arguments.h macros.h
	$(CC) $(CFLAGS) -c arguments.c

perrors.o: main.c main.h
	$(CC) $(CFLAGS) -c perrors.c

load_country_codes.o: load_country_codes.h main.h
	$(CC) $(CFLAGS) -c load_country_codes.c 

read_file.o: read_file.h main.h
	$(CC) $(CFLAGS) -c read_file.c

print_file.o: print_file.h main.h
	$(CC) $(CFLAGS) -c print_file.c


clean:
	rm -f *.o

clear:
	rm -f analisis_covid


# Para probar la invocacion de el programa;
run: 
	./analisis_covid -in input.csv -out output.txt

run2: 
	./analisis_covid -out output.txt -in input.csv 

run3: 
	./analisis_covid -in -out

run4: 
	./analisis_covid -out output.txt -in 

run5: 
	./analisis_covid -in input.csv -out

run6: 
	./analisis_covid -out -in input.csv 

run7: 
	./analisis_covid -in -out output.txt

run8: 
	./analisis_covid -in input.csv 

run9:
	./analisis_covid output.txt -out input.csv -in
