/*! \file */
#include <stdio.h>
#include <math.h>
#include <string.h>

int soma_string(const char * string_entrada ){
	char ref = '0';
	const char * ptr = string_entrada;
	char buff;
	char int_last[4]={'i','i','i','i'};/**< guarda os inteiros lidos anteriormente para reprocessamento da base 10 (i representa invalido). ex.: 12 = 1*10^1 + 2*10^0.*/
	int sum=0, int_last_cont=0, i=0, j=0, int_readed = 0;
	int ibuff;
	int potencia10 = 0;/**< guarda a ultima potencia de 10*/
	int last = 0; /**< marca se o ultimo foi \n(0), delimitador(1) ou numero(2)*/
	while(1){
		sscanf(ptr,"%c", &buff);
		ptr ++;
		switch(last){
			case 2:
				if(buff >= '0'&& buff <='9'){
					i = int_last_cont - 1;
					j=0;
					while (i>=0){
						sum -= (int_last[i] - '0')*pow(10,j);
						i--;
						j++;
					}
					j = int_last_cont;
					i=0;
					ibuff = sum;
					while (i<int_last_cont){
						sum += (int_last[i] - '0')*pow(10,j);
						i++;
						j--;
					}
					if(sum-ibuff >1000){
						return -1;
					}
					last = 2;
					sum += buff - '0';
					int_last[int_last_cont] = buff;
					int_last_cont ++;
					int_readed = 1;
				}else if(buff == ','){
					int_last_cont=0;
					last = 1;
					int_readed = 0;
				}else if(buff =='\n'){ 
					int_last_cont=0;
					last = 0;
				}else return -1;
				break;
			case 1:
				if(buff >= '0'&& buff <='9'){
					sum += buff - '0';
					int_last[int_last_cont] = buff;
					int_last_cont ++;
					last = 2;
					int_readed = 1;
				}else if (ptr == string_entrada+strlen(string_entrada)+1){/**< Final do vetor*/
					return sum;
				}else if(buff =='\n'){ 
					last = 0;
					break;
				}else return -1;
				break;
			case 0:
				if(buff >= '0'&& buff <='9'){
					sum += buff - '0';
					int_last[int_last_cont] = buff;
					int_last_cont ++;
					last = 2;
					int_readed = 1;
				}else if(buff == ','){
					int_last_cont=0;
					last = 1;
					if (!int_readed)
						return -1;
				}else if (ptr == string_entrada+strlen(string_entrada)+1){/**< Final do vetor*/
					if (!int_readed)
						return -1;
					return sum;
				}else if(buff =='\n'){ 
					break;
				}else{
					return -1;
				}
				break;
		}
	}
	return -2;
}