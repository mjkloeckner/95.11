
#include "read_file.h"


status_t read_file(FILE *src, u_long *country, u_long *date, u_long *infected)
{

//	Esta variable es para saber de que tipo de dato estamos hablando, si es un
//	codigo de pais, una fecha o el numero de infectados;
	data_t data;

	size_t line, i, j;
	status_t st;

	char buff1[SIZE_OF_BUFF1];
	char buff2[SIZE_OF_BUFF2];

	clean_buffer(buff1, SIZE_OF_BUFF1);
	clean_buffer(buff2, SIZE_OF_BUFF2);

	char time_s[TIME_MAX_DIGITS];

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
			switch(data) 
			{
				case PAIS: *(country) = atoi(buff2); break;
				case DATE: *(date) = atol(buff2); j++; break;
			}

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



/*
//	Lee de el archivo de entrada linea por linea y va guardando las 
//	lineas en buff1 hasta que se terminen;
	for(line = 0; fgets(buff1, sizeof(buff1), src) != NULL; line++)
	{
//	Este 'if' es para evitar la primer linea que no contiene ningun tipo de dato;
		if(line != 0) {
//			Recorre el buff1 separando los datos de acuerdo a si es el codigo de
//			un pais, una fecha o el numero de infectados;
			for(i = 0, j = 0, data = PAIS; buff1[i] != '\0'; i++)
			{
//				Si encuentra una coma cambia el tipo de dato;
				if((buff1[i] == ','))
				{
//					Saltea la coma;					
					i++;

//					De acuerdo al tipo de dato que se guardo hasta llegar a la
//					coma va a guardarlo de distinta manera, ej: si el dato que
//					se guardo en buff2 era el codigo de un PAIS, entonces lo 
//					guarda en la variable country, si el tipo de dato que se 
//					guardo en buff2 era una fecha entonces lo guarda en date, etc.
//					Solo puede ser PAIS o DATE, ya que INFECTADOS seria cuando
//					ecuentra un caracter de nueva linea;
					switch(data) 
					{
						case PAIS: *(country) = atoi(buff2); break;
						case DATE: *(date) = atol(buff2); j++; break;
					}


//					Como encontro una coma entonces el tipo de dato cambia;
					data++;

//					j vale cero porque es el indice de el buffer en el que se van
//					guardando los datos;
					j = 0;

//					Se limpia el buffer ya que se va a volver a utilizar;
					clean_buffer(buff2, SIZE_OF_BUFF2);


//				Si en lugar de una coma se encuentra un caracter de nueva line 
//				entonces significa que esta parado en el ultimo dato
				} else if (buff1[i] == '\n') {

//					Si estamos parados en el ultimo dato y no es INFECTED,
//					entonces la variable datos no se incremento tres veces, por
//					lo cual se supone que falta un dato, devolviendo un codigo de
//					error;
					if(data != INFECTED) 
						return ERROR_DATA_ON_FILE_MISSING;

//					Si esta todo bien entonces el dato vuelve a ser PAIS que es 
//					el primer dato de el archivo de entrada
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

		}
	}

	return OK;

*/
