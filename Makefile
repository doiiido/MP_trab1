all:
	g++ testa_string_soma.c -o test -lgtest -pthread
	./test
	g++ testa_string_soma_stdin.c -o soma.out -lgtest -pthread
	echo "Programa compilado com sucesso,para testar execute o arquivo Soma.out"
	
test:
	g++ testa_string_soma.c -o test -lgtest -pthread
	./test
	
gcov: 
	g++ testa_string_soma.c -o test -lgtest -pthread -ftest-coverage -fprofile-arcs
	./test
	gcov -r testa_string_soma.c
	
cppcheck:
	cppcheck testa_string_soma.c --enable=warning
	
valgrind:
	g++ testa_string_soma_stdin.c -o soma.out -lgtest -pthread
	valgrind --leak-check=yes ./soma.out <entrada.txt >saida.txt
	
clean:
	rm test||	rm *.gc*||	rm soma.out