/*! \file */
#include <stdio.h>
#include <math.h>
#include <string.h>

int contains(int delimitador[100], int c){
	int i;
	for(i=0;i<100;i++){
		if(c == delimitador[i]){
			return 1;
		}
	}
	return 0;
}

int soma_string(const char * string_entrada ){
	char ref = '0';
	const char * ptr = string_entrada;
	char buff, sbuff[20], cbuff;
	char int_last[4]={'i','i','i','i'};/**< guarda os inteiros lidos anteriormente para reprocessamento da base 10 (i representa invalido). ex.: 12 = 1*10^1 + 2*10^0.*/
	int delimitador[100];
	int sum=0, int_last_cont=0, i=0, j=0, int_readed = 0, qte_int_readed=0;
	int ibuff;
	int potencia10 = 0;/**< guarda a ultima potencia de 10*/
	int last = -1; /**< marca se o ultimo foi \n(0), delimitador(1), numero(2), definir delimitador '/' (3) ou ainda incluindo delimitadores*/
	int qte_delimitador=1;
	int biggest_delimiter=1, possible_delimiter=0;
	const char * del;
	delimitador[0]='\n';
	while(1){
		sscanf(ptr,"%c", &buff);
		del = ptr;
		possible_delimiter=0;
		for(i=0;i<biggest_delimiter;i++){
			sscanf(del,"%c", &cbuff);
			possible_delimiter+= (unsigned)cbuff*pow(100,i);
			del++;
		}
		switch(last){
			case 5:/**< definir delimitador*/
				sscanf(ptr," %[^]]", sbuff);
				ibuff = strlen(sbuff);
				delimitador[qte_delimitador]=buff;
				for(i=1;i<ibuff;i++){
					delimitador[qte_delimitador]+=(unsigned)sbuff[i]*pow(100,i);
					ptr++;
					if(i>biggest_delimiter)
						biggest_delimiter = i;
				}
				printf("Delimiter: %d\n",delimitador[qte_delimitador]); 
				qte_delimitador++;
				last = 4;
				ptr++;
				break;
			case 4:/**< definir delimitador*/
				if(buff == '\n'){ 
					last=0;
				}else if(buff == '['){
					last = 5;
					break;
				}else{
					return -1;
				}
				break;
			case 3:/**< definir delimitador*/
				if(buff == '/'){ 
					last=4;
					break;
				}else{
					return -1;
				}
				break;
			case 2:
				if(buff >= '0'&& buff <='9'){
					i = int_last_cont - 1;
					j=0;
					while (i>=0){
						sum -= (int_last[i] - '0')*pow(10,j);
						i--;
						j++;
						qte_int_readed --;
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
					qte_int_readed ++;
					if (qte_int_readed > 3)
						return -1;
				}else if(buff == ','){
					int_last_cont=0;
					last = 1;
					int_readed = 0;
				}else if(contains(delimitador,possible_delimiter)){ 
					int_last_cont=0;
					last = 0;
					if(buff == '\n'){
						qte_int_readed =0;
					}
				}else return -1;
				break;
			case 1:
				if(buff >= '0'&& buff <='9'){
					sum += buff - '0';
					int_last[int_last_cont] = buff;
					int_last_cont ++;
					last = 2;
					int_readed = 1;
					qte_int_readed ++;
					if (qte_int_readed > 3)
						return -1;
				}else if (ptr == string_entrada+strlen(string_entrada)+1){/**< Final do vetor*/
					return sum;
				}else if(contains(delimitador,possible_delimiter)){ 
					last = 0;
					if(buff == '\n'){
						qte_int_readed =0;
					}
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
					qte_int_readed ++;
					if (qte_int_readed > 3)
						return -1;
				}else if(buff == ','){
					int_last_cont=0;
					last = 1;
					if (!int_readed)
						return -1;
				}else if (ptr == string_entrada+strlen(string_entrada)+1){/**< Final do vetor*/
					if (!int_readed || qte_int_readed != 0)
						return -1;
					return sum;
				}else if(contains(delimitador,possible_delimiter)){
					if(buff == '\n'){
						qte_int_readed =0;
					}
					break;
				}else{
					return -1;
				}
				break;
			case -1:/**< Estado Inicial*/
				if(buff >= '0'&& buff <='9'){
					sum += buff - '0';
					int_last[int_last_cont] = buff;
					int_last_cont ++;
					last = 2;
					int_readed = 1;
					qte_int_readed ++;
					if (qte_int_readed > 3)
						return -1;
				}else if(contains(delimitador,possible_delimiter)){ 
					last = 0; 
					break;
				}else if(buff == '/'){ 
					last=3;
					break;
				}else{
					return -1;
				}
				break;
		}
		ptr ++;
	}
	return -2;
}