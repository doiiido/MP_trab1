/*! \file */
#include <stdio.h>
#include <math.h>

int soma_string(const char * string_entrada ){
	char ref = '0';
	const char * ptr = string_entrada;
	char buff, int_last[4]={'i','i','i','i'};/**< guarda os inteiros lidos anteriormente para reprocessamento da base 10 (i representa invalido). ex.: 12 = 1*10^1 + 2*10^0.*/
	int sum=0, int_last_cont=0, i=0, j=0;
	int potencia10 = 0;/**< guarda a ultima potencia de 10*/
	int last = 0; /**< marca se o ultimo foi \n(0), delimitador(1) ou numero(2)*/
	do{
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
					while (i<int_last_cont){
						sum += (int_last[i] - '0')*pow(10,j);
						i++;
						j--;
					}
					last = 2;
					sum += buff - '0';
					int_last[int_last_cont] = buff;
					int_last_cont ++;
				}else if(buff == ','){
					int_last_cont=0;
					last = 1;
				}
				break;
			case 1:
				if(buff >= '0'&& buff <='9'){
					sum += buff - '0';
					int_last[int_last_cont] = buff;
					int_last_cont ++;
					last = 2;
				}else return -1;
				break;
			case 0:
				if(buff >= '0'&& buff <='9'){
					sum += buff - '0';
					int_last[int_last_cont] = buff;
					int_last_cont ++;
					last = 2;
				}else{
					return -1;
				}
				break;
		}
	}while(buff != '\n');
	
	return sum;
}