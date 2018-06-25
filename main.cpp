#include <iostream>
#include <cstdlib>
#include "maze.h"
#include "function.h"

using namespace std;
//sdfsdfsfsdda
int main(){
	int starting_length_of_snake = 5;
	Maze M(starting_length_of_snake);
	M.clear();
	M.make();
	M.print();
	while(true){
		while(!kbhit()){
			M.increment();
			M.adjust_head();
			if(M.exit()==true) return 0;
			M.clear();
			M.make();
			usleep(100000);
			system("clear");
			M.print();
		}
		M.clear();
		M.make();
		M.direct();
	}
	return 0;
}
