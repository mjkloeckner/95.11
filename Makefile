CC=gcc
CFLAGS=-std=c99 -pedantic -Wall
SRCFOLDER=source
HFOLDER=include
PROGNAME=main

all: main clean

main: main.o cla.o errors.o io.o
	$(CC) $(CFLAGS) main.o cla.o errors.o io.o -o $(PROGNAME)

main.o: $(HFOLDER)/cla.h $(HFOLDER)/errors.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/main.c

cla.o: $(HFOLDER)/cla.h $(HFOLDER)/types.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/cla.c

errors.o: $(HFOLDER)/types.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/errors.c

io.o: $(HFOLDER)/types.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/io.c

clean:
	rm *.o
