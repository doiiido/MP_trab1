/*! \file */
#include <stdio.h>

int soma_string(const char * string_entrada ){
	char ref = '0';
	const char * ptr = string_entrada;
	char buff = '0';
	int sum=0;
	do{
		if (buff != ',')
			sum += buff - '0';
		sscanf(ptr,"%c", &buff);
		ptr ++;
	}while(buff != '\n');
	
	return sum;
}