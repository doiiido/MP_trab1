all:
	g++ testa_soma_string_stdin.c -o test -lgtest -pthread
	
test:
	g++ testa_string_soma.c -o test -lgtest -pthread
	./test
	
gcov: 
	g++ testa_string_soma.c -o test -lgtest -pthread -ftest-coverage -fprofile-arcs
	./test
	gcov -r testa_string_soma.c
	
check:
	cppcheck testa_string_soma.c --enable=warning
	
clean:
	rm *.gc*
	rm test