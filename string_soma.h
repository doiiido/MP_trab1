#include "string_soma.c"
/*! \file */
/**\Class Soma_string()
*\brief A função soma_string() recebe uma string como entrada na forma "//[;]\n2;3\n" e retorna a soma dos valores processados
*	respeitando o padrao seguinte:
*		A string poderá conter qualquer quantidade de números. Em cada linha se pode ter 0, 1, 2
*		ou 3 números. Os números são separados por exatamente um delimitador que no caso é a
*		vírgula. Qualquer separador diferente é considerado erro a menos que tenha sido
*		adicionado como delimitador. 
*				
*/
int soma_string(char * string_entrada );