/*! \file */

#include "gtest/gtest.h"
#include "string_soma.h"
/**\Class testes
*\brief Função que descreve os testes 
*/
/** Testes baseados no documento de especificação
*/
TEST (Calculadora_Trab1, 1_virg_2_ql){ 
	ASSERT_EQ (3, soma_string("1,2\n"));
}
TEST (Calculadora_Trab1, 1_virg_2_virg_3_ql){ 
	ASSERT_EQ (6, soma_string("3,2,1\n")); 
}
TEST (Calculadora_Trab1, 1_virg_ql){ 
	ASSERT_EQ (-1, soma_string("1,\n"));
}
TEST (Calculadora_Trab1, virg_1_ql){ 
	ASSERT_EQ (-1, soma_string(",2\n")); 
}
TEST (Calculadora_Trab1, 1_2virg_2_ql){ 
	ASSERT_EQ (-1, soma_string("1,,2\n"));
}
TEST (Calculadora_Trab1, virg_ql){ 
	ASSERT_EQ (-1, soma_string(",\n")); 
}
TEST (Calculadora_Trab1, 1_dotvirg_2_ql){ 
	ASSERT_EQ (-1, soma_string("1;2\n"));
}
TEST (Calculadora_Trab1, 1_virg_2){ 
	ASSERT_EQ (-1, soma_string("1,2")); 
}
TEST (Calculadora_Trab1, 1_virg_2_ql_sp){ 
	ASSERT_EQ (-1, soma_string("1,2\n "));
}
TEST (Calculadora_Trab1, 1_ql_virg_2_ql){ 
	ASSERT_EQ (3, soma_string("1\n,2\n")); 
}
TEST (Calculadora_Trab1, 1_ql_ql_ql_virg_2_ql){ 
	ASSERT_EQ (5, soma_string("1\n\n\n,4\n"));
}
TEST (Calculadora_Trab1, 1_ql_ql_ql_2_ql_ql_ql_3_ql){ 
	ASSERT_EQ (4, soma_string("1\n\n\n,\n\n\n3\n")); 
}
TEST (Calculadora_Trab1, 1_virg_2_virg_3_virg_4_ql){ 
	ASSERT_EQ (-1, soma_string("1,2,3,4\n"));
}
TEST (Calculadora_Trab1, 1_virg_2_virg_3_ql_virg_4_ql){ 
	ASSERT_EQ (10, soma_string("1,2,3\n,4\n"));
}
TEST (Calculadora_Trab1, 1_virg_neg_virg_3_ql){ 
	ASSERT_EQ (-1, soma_string("1,-2,3\n"));
}
TEST (Calculadora_Trab1, 1_virg_1001_ql){ 
	ASSERT_EQ (3, soma_string("3,2000\n"));
}
TEST (Calculadora_Trab1, 1_virg_1001_virg_3_ql){ 
	ASSERT_EQ (-1, soma_string("1,2000,3\n"));
}
TEST (Calculadora_Trab1, del_ql_1_del_2_ql){ 
	ASSERT_EQ (5, soma_string("//[;]\n2;3\n"));
}
TEST (Calculadora_Trab1, del_1_del_2_del_3_ql){ 
	ASSERT_EQ (-1, soma_string("//[***]2***3***4\n"));
}
TEST (Calculadora_Trab1, del1_del2_ql_1_del1_2_del2_3_ql){ 
	ASSERT_EQ (6, soma_string("//[**][%%%]\n2**1%%%3\n"));
}

/**\Class testes_unit
		Testes de desenvolvimento
*/

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}