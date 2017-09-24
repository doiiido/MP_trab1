#include "string_soma.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*! \file */

/**\Class STDin
*\brief Função que lê da entrada padrão para soma_string() e escreve sua saida na saida padrão 
*/
/** Função com alocação dinamica de memória para a entrada
*/

int main(){
	char cbuff[2] ={0,0}; /* cbuff é um buffer de uma string de 1 char */
	char last=0;
	char *mem=NULL;
	int size = 0;
	int i=0;
	mem = (char*)malloc(sizeof(char));/* MEM é a variavel utilizada para transmitir a string lida para soma_string() */
	do{
		sprintf(cbuff,"%c",getchar()); /* Lendo pra cbuff */
		if(last=='\\'&& cbuff[0] == 'n'){ /* Aqui é verificado se o caractere especial \\n foi lido como a string {'\','n'}, fazendo a correçao*/
			for(i=0;i<strlen(mem)-1;i++);
			mem[i] = '\n';
			sprintf(cbuff,"%c",getchar());
		}
		if(cbuff[0] < 0) /* Quando não é possiver ler da entrada padrao o sprintf fica sem argumento e escreve -1 em cbuff[0], quando deveria ser o '\0'*/
			cbuff[0]=0;
		last = cbuff[0];
		size+=sizeof(char); /* MEM tem aqui o tamanho adicionado em 1 char */
		mem=(char*)realloc(mem,size);
		strcat(mem,cbuff);	/* Aqui é escrito efetivamente o caractere lido para mem */
	}while(!feof(stdin) && strstr(cbuff,"\n")==NULL); /* EOF ocorre no arquivo e '\\n' ocorre no console */
	printf("%d",soma_string(mem)); /* Chamando soma_string() com argumento mem e escrevendo o retorno na saida padrao */
	free(mem);	/* "Voce é responsavel por aquilo que cativa" RAMOS, G.N., logo, liberando a memoria alocada */
	return 0;
}