Nim.exe: game.o nim.o
	g++ -std=c++11 -Wall -o Nim game.o nim.o

game.o: game.cpp nim.hpp
	g++ -std=c++11 -Wall -c -o game.o game.cpp

nim.o: nim.cpp nim.hpp
	g++ -std=c++11 -Wall -c -o nim.o nim.cpp

clean:
	erase *.o

cleanAll:
	erase *.o
	erase *.exe

build: Nim.exe

compile: game.o nim.o

rebuild: clean compile build
