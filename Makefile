CC=gcc
CFLAGS=-pedantic -Wall
SRCFOLDER=source
HFOLDER=include
PROGNAME=main

all: main clean

main: cla.o status.o sort.o io.o main.o user.o 
	$(CC) $(CFLAGS) main.o cla.o status.o io.o sort.o user.o -o $(PROGNAME)

main.o: $(HFOLDER)/cla.h $(HFOLDER)/status.h $(HFOLDER)/user.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/main.c

cla.o: $(HFOLDER)/cla.h $(HFOLDER)/status.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/cla.c

status.o: $(HFOLDER)/status.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/status.c

io.o: $(HFOLDER)/status.h $(HFOLDER)/user.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/io.c

sort.o: $(HFOLDER)/status.h $(HFOLDER)/user.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/sort.c

user.o: $(HFOLDER)/status.h $(HFOLDER)/user.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/user.c

clean:
	rm *.o

run20:
	./main -fmt csv -out output.csv -in examples/test_file_20.csv -ti 1320498000 -tf 1320498046

run2k:
	./main -fmt csv -out output.csv -in examples/test_file_2k.csv -ti 1320498000 -tf 1325499000

run50:
	./main -fmt csv -out output.csv -in examples/test_file_50.csv -ti 1320498000 -tf 1320498049

run500:
	./main -fmt csv -out output.csv -in examples/test_file_500.csv -ti 1320498000 -tf 1320529000

run5k:
	./main -fmt csv -out output.csv -in examples/test_file_5k.csv -ti 1320498000 -tf 1320529000

run50k:
	./main -fmt csv -out output.csv -in examples/test_file_50k.csv -ti 1320498000 -tf 1420529000

run500k:
	./main -fmt csv -out output.csv -in examples/test_file_500k.csv -ti 1320498000 -tf 1420529000

run50xml:
	./main -fmt xml -out output.xml -in examples/test_file_50.csv -ti 1320498000 -tf 1320498049

run5kxml:
	./main -fmt xml -out output.xml -in examples/test_file_5k.csv -ti 1320498000 -tf 1360498049
