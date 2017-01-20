#ifndef MAZE
#define MAZE
#include <vector>
#define m 40 	// No. of rows
#define n 100 	// No. of columns

class Maze{

	private:
		char A[m][n];
		std::vector <int> X;
		std::vector <int> Y;
		int rand_x;
		int rand_y;
		int direction;
		int score;
	public:
		Maze(int starting_length);
		void print();
		void clear();
		void make();
		void increment();
		void adjust_head();
		bool exit();
		void direct();
};

#endif
