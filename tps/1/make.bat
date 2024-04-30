:: Compile and build 'analisis_covid' on windows using cmd or PowerShell

SET CC=gcc
SET CFLAGS=-std=c99 -Wall -pedantic

%CC% %CFLAGS% -c print_file.c
%CC% %CFLAGS% -c read_file.c
%CC% %CFLAGS% -c load_country_codes.c
%CC% %CFLAGS% -c perrors.c
%CC% %CFLAGS% -c arguments.c
%CC% %CFLAGS% -c main.c
%CC% %CFLAGS% main.o arguments.o perrors.o load_country_codes.o read_file.o print_file.o -o analisis_covid

:: Deletes unnecessary .o files after the compile ends;
del .\*.o
