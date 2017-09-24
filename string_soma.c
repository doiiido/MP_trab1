/*! \file */
#include <stdio.h>
#include <math.h>
#include <string.h>


/** A funçao matches_next recebe uma string, o tamanho dela, um array de strings a serem comparadas e a quantidade que há nesse array
*	Retornado se foi encontrado ou nao e passando via referencia o tamanho da string encontrada
*/
int matches_next (const int size,char *string, char * regex, int qte,int *size_of_del){
	int i;
	char * ptr, *ptr2 = regex;
	for(i=0;i<qte;i++){
		 ptr = strstr(string,ptr2);
		 if(ptr != NULL && ptr == string){
			 *size_of_del = strlen(ptr2); 
			 return 1;
		 }
		 ptr2 += size;
	}
	return 0;
}	

int soma_string(char * string_entrada ){
	const int size = strlen(string_entrada)+1;
	const char * ptr = string_entrada;
	char buff[size], sbuff[size], cbuff[2];
	char int_last[4]={'i','i','i','i'};/* guarda os inteiros lidos anteriormente para reprocessamento da base 10 (i representa invalido). ex.: 12 = 1*10^1 + 2*10^0.*/
	char delimitador[size][size];
	int sum=0, int_last_cont=0, i=0, j=0, int_readed = 0, qte_int_readed=0;
	int ibuff;
	int potencia10 = 0;/* guarda a ultima potencia de 10*/
	int last = -1; /* marca se o ultimo foi \n(0), delimitador(1), numero(2), definir delimitador '/' (3) ou ainda incluindo delimitadores*/
	int qte_delimitador=1;
	int size_of_del=0;
	strcpy(delimitador[0],",");
	
	while(1){
		strcpy(buff,ptr);
		switch(last){
			case 5:/* definir delimitador*/
				strcpy(sbuff,"");
				strcpy(cbuff,"");
				while(strstr(cbuff,"]")==NULL){
					strcat(sbuff,cbuff);
					sscanf(ptr,"%1s", cbuff);
					if(ptr == string_entrada + size)/* Prevenindo buffer overrun*/
						return -1;
					ptr++;
				}
				ptr--;
				if(strlen(sbuff)>0){
					strcpy(delimitador[qte_delimitador],sbuff);
					qte_delimitador++;
				}
				last = 4;
				break;
			case 4:/* definir delimitador*/
				if(buff[0] == '\n'){ 
					last=0;
				}else if(buff[0] == '['){
					last = 5;
					break;
				}else{
					return -1;
				}
				break;
			case 3:/* definir delimitador*/
				if(buff[0] == '/'){ 
					last=4;
					break;
				}else{
					return -1;
				}
				break;
			case 2:
				if(buff[0] >= '0'&& buff[0] <='9'){
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
					sum += buff[0] - '0';
					int_last[int_last_cont] = buff[0];
					int_last_cont ++;
					int_readed = 1;
					qte_int_readed ++;
					if (qte_int_readed > 3)
						return -1;
				}else if(matches_next(size,buff,(char*)&delimitador[0],qte_delimitador,&size_of_del)){
					int_last_cont=0;
					last = 1;
					int_readed = 0;
					ptr += size_of_del-1;
					size_of_del=0;
				}else if(buff[0] =='\n'){ 
					int_last_cont=0;
					last = 0;
					qte_int_readed =0;
				}else return -1;
				break;
			case 1:
				if(buff[0] >= '0'&& buff[0] <='9'){
					sum += buff[0] - '0';
					int_last[int_last_cont] = buff[0];
					int_last_cont ++;
					last = 2;
					int_readed = 1;
					qte_int_readed ++;
					if (qte_int_readed > 3)
						return -1;
				}else if(buff[0] =='\n'){ 
					last = 0;
					qte_int_readed =0;
					break;
				}else return -1;
				break;
			case 0:
				if(buff[0] >= '0'&& buff[0] <='9'){
					sum += buff[0] - '0';
					int_last[int_last_cont] = buff[0];
					int_last_cont ++;
					last = 2;
					int_readed = 1;
					qte_int_readed ++;
					if (qte_int_readed > 3)
						return -1;
				}else if(matches_next(size,buff,(char*)&delimitador[0],qte_delimitador,&size_of_del)){
					int_last_cont=0;
					last = 1;
					ptr += size_of_del-1;
					size_of_del=0;
					if (!int_readed)
						return -1;
				}else if (buff[0]==0){/* Final do vetor*/
					if (!int_readed)
						return -1;
					return sum;
				}else if(buff[0] =='\n'){ 
					qte_int_readed =0;
					break;
				}else{
					return -1;
				}
				break;
			case -1:/* Estado Inicial*/
				if(buff[0] >= '0'&& buff[0] <='9'){
					sum += buff[0] - '0';
					int_last[int_last_cont] = buff[0];
					int_last_cont ++;
					last = 2;
					int_readed = 1;
					qte_int_readed ++;
					if (qte_int_readed > 3)
						return -1;
				}else if(buff[0]=='\n'){ 
					break;
				}else if(buff[0] == '/'){ 
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