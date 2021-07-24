CC=gcc
CFLAGS=-pedantic -Wall
SRCFOLDER=source
HFOLDER=include
PROGNAME=main

all: main clean

main: main.o cla.o status.o io.o sort.o user.o
	$(CC) $(CFLAGS) main.o cla.o status.o io.o sort.o user.o -o $(PROGNAME)

main.o: $(HFOLDER)/cla.h $(HFOLDER)/status.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/main.c

cla.o: $(HFOLDER)/cla.h $(HFOLDER)/status.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/cla.c

status.o: $(HFOLDER)/status.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/status.c

io.o: $(HFOLDER)/status.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/io.c

sort.o: $(HFOLDER)/status.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/sort.c

user.o: $(HFOLDER)/status.h
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/user.c

clean:
	rm *.o
