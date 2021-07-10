CC=gcc
CFLAGS=-std=c99 -pedantic -Wall
SRCFOLDER=source

all: main

main: main.o cla.o
	$(CC) $(CFLAGS) main.o cla.o

main.o:
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/main.c 

cla.o:
	$(CC) $(CFLAGS) -c $(SRCFOLDER)/cla.c
