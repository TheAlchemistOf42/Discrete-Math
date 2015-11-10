Nim.exe: game.o
	g++ -std=c++11 -Wall -o Nim game.o

game.o: game.cpp
	g++ -std=c++11 -Wall -c -o game.o game.cpp

clean:
	erase *.o
