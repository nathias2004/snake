Snake: main.o maze.o function.o
	g++ main.o maze.o function.o -o Snake

main.o: main.cpp
	g++ -c main.cpp

maze.o: maze.cpp maze.h
	g++ -c maze.cpp

function.o: function.cpp function.h
	g++ -c function.cpp

clean:
	rm *.o Snake
