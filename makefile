build:
	rm -f program.exe
	g++ -g -std=c++11 -Wall main.cpp -o program.exe

test:
	rm -f program.exe
	g++ -g -std=c++11 -Wall maincatch.cpp ./tests/test07.cpp -o program.exe

testall:
	rm -f program.exe
	g++ -g -std=c++11 -Wall maincatch.cpp ./tests/test*.cpp -o program.exe
	
run:
	./program.exe

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./program.exe
