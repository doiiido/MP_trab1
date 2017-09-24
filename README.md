# MP_trab1
Programa Calculadora Trabalho1
Aluno: Lincoln Abreu Barbosa, Matricula: 140045023

Github: https://github.com/doiiido/MP_trab1

Para executar os testes da função soma_string() basta digitar make e a opção desejada:

all: roda os testes do gtest e compila o arquivo testa_string_soma_stdin.c para testa_soma_string_stdin
	
	testa_soma_string_stdin	recebe entradas de stdin, repassa-as a soma_string() e escreve o retorna em stdout.
	para executa-lo: ./testa_soma_string_stdin < entrada.txt > saida.txt 
	
test: roda os testes do gtest
	
gcov: roda os testes do gtest e o gcov verificando testa_string_soma.c e soma_string.c
	
cppcheck:roda o cppcheck em testa_string_soma.c, soma_string.c
	
valgrind:roda o valgrind em soma_string.c e testa_string_soma_stdin.c
	
clean:limpa os arquivos gerados pelos programas anteriores


