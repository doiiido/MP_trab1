#include "string_soma.h"

/*! \file */
int main(){
	char local[20], temp[20];
	FILE *data, *text;	/*Ponteiro dos arquivos*/
	
	printf("Digite o nome da pasta onde estão os arquivos text.bin e data.bin:\r\n");
	printf("Se estiverem na mesma pasta que o programa basta digitar 0.\r\n");
	
	scanf("%s", local);
	sprintf(temp,"%s", local);
	
	printf("\r\n");
	if(local[0]=='0'){
		text = fopen("text.bin","rb");	/*read-only modo binário*/
		data = fopen("data.bin","rb");	/*read-only modo binário*/
	}else{
		sprintf(local,"%s/text.bin", local);
		sprintf(temp,"%s/data.bin", temp);
		text = fopen(local,"rb");	/*read-only modo binário*/
		data = fopen(temp,"rb");	/*read-only modo binário*/
	}
	
	if (!text){
		printf("Falha ao abrir o arquivo text.bin para leitura\r\n");
		return -1;
	}
	
	if (!data){
		printf("Falha ao abrir o arquivo data.bin para leitura\r\n");
		return -1;
	}
	if(read_files(data, text) != 0){
		printf("Falha ao ler os arquivos\r\n");
		return -1;
	}
	printf("Arquivos lidos com sucesso.\r\n");
	fclose(data);
	fclose(text);
	
	return 0;
}