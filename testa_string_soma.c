/*! \file */

#include "gtest/gtest.h"
#include "string_soma.h"
/**\Class testes
*\brief Função que descreve os testes 
*/
/** Testes baseados no documento de especificação
*/

TEST (Calculadora_Trab1, 1_virg_2_ql){ 
	ASSERT_EQ (3, soma_string((char*)"1,2\n"));/**<Teste que verifica se está processando entradas de 2 numeros*/
}
TEST (Calculadora_Trab1, 3_virg_2_virg_1_ql){ 
	ASSERT_EQ (6, soma_string((char*)"3,2,1\n"));/**<Teste que verifica se está processando entradas de 3 numeros*/ 
}
TEST (Calculadora_Trab1, 1_virg_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"1,\n"));/**<Teste que verifica se está invalidando delimitadores que nao possui numero consecutivo*/
}
TEST (Calculadora_Trab1, virg_2_ql){ 
	ASSERT_EQ (-1, soma_string((char*)",2\n"));/**<Teste que verifica se está invalidando delimitadores que nao possui numero anterior a ele*/
}
TEST (Calculadora_Trab1, 1_2virg_2_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"1,,2\n"));/**<Teste que verifica se está invalidando a fata de um numero entre dois delimitadores*/
}
TEST (Calculadora_Trab1, virg_ql){ 
	ASSERT_EQ (-1, soma_string((char*)",\n"));/**<Teste que verifica se está invalidando delimitadores sem numero posterior ou anterior*/
}
TEST (Calculadora_Trab1, 1_dotvirg_2_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"1;2\n"));/**<Teste que verifica se está invalidando caracteres estranhos*/
}
TEST (Calculadora_Trab1, 1_virg_2){ 
	ASSERT_EQ (-1, soma_string((char*)"1,2"));/**<Teste que verifica se está invalidando a falta de quebra de linha ao final*/
}
TEST (Calculadora_Trab1, 1_virg_2_ql_sp){ 
	ASSERT_EQ (-1, soma_string((char*)"1,2\n "));/**<Teste que verifica se está processando todos os caracteres fornecidos*/
}
TEST (Calculadora_Trab1, 1_ql_virg_2_ql){ 
	ASSERT_EQ (3, soma_string((char*)"1\n,2\n"));/**<Teste que verifica se está ignorando as quebras de linhas no processamento da soma (1)*/
}
TEST (Calculadora_Trab1, 1_ql_ql_ql_virg_4_ql){ 
	ASSERT_EQ (5, soma_string((char*)"1\n\n\n,4\n"));/**<Teste que verifica se está ignorando as quebras de linhas no processamento da soma(2)*/
}
TEST (Calculadora_Trab1, 1_ql_ql_ql_virg_ql_ql_ql_3_ql){ 
	ASSERT_EQ (4, soma_string((char*)"1\n\n\n,\n\n\n3\n"));/**<Teste que verifica se está ignorando as quebras de linhas no processamento da soma(3)*/ 
}
TEST (Calculadora_Trab1, 1_virg_2_virg_3_virg_4_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"1,2,3,4\n"));/**<Teste que verifica se está invalidando mais do que 3 numeros por linha*/
}
TEST (Calculadora_Trab1, 1_virg_2_virg_3_ql_virg_4_ql){ 
	ASSERT_EQ (10, soma_string((char*)"1,2,3\n,4\n"));/**<Teste que verifica se está processando as quebras de linhas na contagem de inteiros por linha*/
}
TEST (Calculadora_Trab1, 1_virg_neg_virg_3_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"1,-2,3\n"));/**<Teste que verifica se está invalidando numeros negativos*/
}
TEST (Calculadora_Trab1, 3_virg_2000_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"3,2000\n"));/**<Teste que verifica se está invalidando numeros maiores que 1000*/
}
TEST (Calculadora_Trab1, 1_virg_1000_virg_3_ql){ 
	ASSERT_EQ (1004, soma_string((char*)"1,1000,3\n"));/**<Teste que verifica se está processando numeros até 1000*/
}

TEST (Calculadora_Trab1, del_ql_2_del_3_ql){ 
	ASSERT_EQ (5, soma_string((char*)"//[;]\n2;3\n"));/**<Teste que verifica se está processando a inclusao de um único delimitador de tamanho 1*/
}
TEST (Calculadora_Trab1, del_2_del_3_del_4_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"//[***]2***3***4\n"));/**<Teste que verifica se está processando a inclusao de um único delimitador de qualquer tamanho*/
}
TEST (Calculadora_Trab1, del1_del2_ql_2_del1_1_del2_3_ql){ 
	ASSERT_EQ (6, soma_string((char*)"//[**][%%%]\n2**1%%%3\n"));/**<Teste que verifica se está processando a inclusao de mais de um delimitador de tamanho qualquer*/
}

/**\Class testes_unit
		Testes de desenvolvimento
*/

TEST (Calculadora_Trab1, 21_virg_12_ql){ 
	ASSERT_EQ (33, soma_string((char*)"21,12\n"));/**<Teste que verifica se está processando a soma de inteiros com 2 casas*/
}
TEST (Calculadora_Trab1, sp_21_virg_12_ql){ 
	ASSERT_EQ (-1, soma_string((char*)" 21,12\n"));/**<Teste que verifica se está processando caracteres invalidos antes da sentença*/
}
TEST (Calculadora_Trab1, 21_sp_virg_12_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"21 ,12\n"));/**<Teste que verifica se está processando caracteres invalidos antes de um delimitador*/
}
TEST (Calculadora_Trab1, 21_virg_sp_12_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"21, 12\n"));/**<Teste que verifica se está processando caracteres invalidos depois de um delimitador*/
}
TEST (Calculadora_Trab1, del1_del2_ql_2_INV_1_INV_3_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"//[**][%%%]\n2***1%%3\n"));/**<Teste que verifica se está invalidando palavras que se parecem com delimitadores**/
}
TEST (Calculadora_Trab1, del1_del2_ql_2_del1_1_INV_3_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"//[**][%%]\n2**1%3\n"));/**<Teste que verifica se está invalidando uma palavra que se parece com delimitador mas não o é*/
}
TEST (Calculadora_Trab1, del_ql_2_del_3_del_4_del_5_ql){ 
	ASSERT_EQ (-1, soma_string((char*)"//[;]\n2;3;4;5\n"));/**<Teste que verifica se o processamento dos delimitadores é independente da contagem de inteiros por linha (1)*/
}
TEST (Calculadora_Trab1, del_ql_2_del_3_ql_del_4_del_5_ql){ 
	ASSERT_EQ (14, soma_string((char*)"//[;]\n2;3\n;4;5\n"));/**<Teste que verifica se o processamento dos delimitadores é independente da contagem de inteiros por linha(2)*/
}
TEST (Calculadora_Trab1, del_ql_2_del_3_del){ 
	ASSERT_EQ (-1, soma_string((char*)"//[;]\n2;3;"));/**<Teste que verifica se o processamento dos delimitadores é independente do processamento da quebra de linha*/
}
TEST (Calculadora_Trab1, del_ql_1_del_2_ql){ 
	ASSERT_EQ (3, soma_string((char*)"//[**]\n1**2\n"));/**<Teste que verifica o processamento de apenas um delimitador*/
}
TEST (Calculadora_Trab1, INVALID){ 
	ASSERT_EQ (-1, soma_string((char*)"//[**\n1**2\n"));/**<Teste que verifica se a sentença de inscrição de delimitadores esta completa*/
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}