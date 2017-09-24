#include "string_soma.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*! \file */
int main(){
	char cbuff[2] ={0,0};
	char last=0;
	char *mem=NULL;
	int size = 0;
	int i=0;
	mem = (char*)malloc(sizeof(char));
	do{
		sprintf(cbuff,"%c",getchar());
		if(last=='\\'&& cbuff[0] == 'n'){
			for(i=0;i<strlen(mem)-1;i++);
			mem[i] = '\n';
			sprintf(cbuff,"%c",getchar());
		}
		if(cbuff[0] < 0)
			cbuff[0]=0;
		last = cbuff[0];
		size+=sizeof(char);
		mem=(char*)realloc(mem,size);
		strcat(mem,cbuff);
	}while(!feof(stdin) && strstr(cbuff,"\n")==NULL);
	printf("%d",soma_string(mem));
	free(mem);
	return 0;
}