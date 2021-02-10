# PROJECT 01 - ALGORITHMS & PROGRAMMING I (95.11)

This folder contains the first project of "Algoritmos y 
Programacion I" a subject from Facultad de Ingenieria de la
Universidad de Buenos Aires. The project is a program that 
runs on CLI which its function is to process data entered via 
a .csv file.

What it does is receive a number for a country, date, and number of
cases (of COVID19), and prints it on a file with a human readable
format.

Bibliography:

"The C programming language" - Brian W. Kernighan & Dennis Ritchie.

Installation:

NOTE: You need to have installed gcc in order to compile the application.  
Install it and make shure you have gcc added to path to execute it from
terminal/cmd.

Arch based distros:
	
	Install base-devel, git(not neccesary unless you want to clone the repo).
		 
	Clone repo from terminal or download the .zip file and unzip it.
		 
	Navigate to the folder and open a terminal there, run 'make install'.

Windows installation:

	Downlaod .zip file and unzip it or clone repo.
	
	Navigate to the downloaded folder.
	
	Execute 'make.bat'.

	
NAME
	analisis_covid - analyze RAW data and export it with a human 
	readable format.

SYNOPSIS

	analisis_covid -in SOURCE -out DEST
	analisis_covid -out DEST -in SOURCE

DESCRIPTION
	Process RAW data from a .csv(comma separated values) file,
	and export it to another .csv file, if the output file doesn't
	exist then it creates one with the specified name.
	When you invoke analisis_covid, expects.. to be continued


AUTHOR
	Written by Martin J. Klöckner - Argentina - December 2020.





