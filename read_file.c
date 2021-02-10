
#include "read_file.h"


status_t read_file(FILE *src, uint *country, uint *date, uint *infected)
{

//	Esta variable es para saber de que tipo de dato estamos hablando, si es un
//	codigo de pais, una fecha o el numero de infectados;
	data_t data;

	size_t i, j;
//	status_t st;

	char buff1[SIZE_OF_BUFF1];
	char buff2[SIZE_OF_BUFF2];

	clean_buffer(buff1, SIZE_OF_BUFF1);
	clean_buffer(buff2, SIZE_OF_BUFF2);

//	char time_s[TIME_MAX_DIGITS];

//	Lee de el archivo de entrada linea por linea y va guardando las 
//	lineas en buff1 hasta que se terminen;
	if(fgets(buff1, sizeof(buff1), src) == NULL)
		return END_OF_INPUT_FILE;
	
//	Este 'if' es para evitar la primer linea que no contiene ningun
//	tipo de dato;
	for(i = 0, j = 0, data = PAIS; buff1[i] != '\0'; i++)
	{
		if((buff1[i] == ','))
		{
			i++;
			if(data == PAIS) 
				*(country) = atoi(buff2);
			
			else if (data == DATE) 
				*(date) = atol(buff2);
			
			data++;
			j = 0;
			clean_buffer(buff2, SIZE_OF_BUFF2);

		} else if (buff1[i] == '\n') {
			if(data != INFECTED) 
				return ERROR_DATA_ON_FILE_MISSING;

			data = PAIS;
			*(infected) = atol(buff2);
			clean_buffer(buff2, SIZE_OF_BUFF2);
		}
			switch(data) 
			{
				case PAIS: buff2[i] = buff1[i];	break;
				case DATE: buff2[j] = buff1[i]; j++; break;
				case INFECTED: buff2[j] = buff1[i]; j++; break;
			}
	}
	return OK;
}

status_t clean_buffer(char *buffer, size_t size)
{
	if(buffer == NULL)
		return ERROR_NULL_POINTER;

	size_t i;
	for(i = 0; i < size; i++)
		buffer[i] = '\0';
	
	return OK;
}
