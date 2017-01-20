#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <unistd.h>
#include <cstdio>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <vector>
#include "maze.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define m 40 	// No. of rows
#define n 100 	// No. of columns

using namespace std;

Maze::Maze(int starting_length){
	int head_x = m/2;
	int head_y = n/2;
	for(int i=0;i<starting_length;i++){
		X.push_back(head_x-i);
		Y.push_back(head_y-i);
	}
	rand_x = rand()%(m-2) + 1;
	rand_y = rand()%(n-2) + 1;
	direction = 1;
	score = 0;
}

void Maze::print(){
	int top_margin = 5;
	int left_margin = 10;
	for(int i=0;i<top_margin;i++) cout<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<left_margin;j++) cout<<" ";
		for(int j=0;j<n;j++){
			if(A[i][j]=='@') cout<<BOLDRED<<A[i][j]<<RESET;
			else if(A[i][j]=='#') cout<<BOLDCYAN<<A[i][j]<<RESET;
			else if(A[i][j]=='o') cout<<BOLDGREEN<<A[i][j]<<RESET;
			else cout<<A[i][j];		
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl<<BOLDGREEN<<"\t\t\t\t\t\tSCORE = "<<score<<RESET<<endl;
	return;
}

void Maze::clear(){
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) A[i][j] = ' ';
	for(int i=0;i<m;i++) A[i][0] = '#', A[i][n-1] = '#';
	for(int j=0;j<n;j++) A[0][j] = '#', A[m-1][j] = '#';
	return;
}

void Maze::make(){
	for(int i=0;i<X.size();i++) A[X[i]][Y[i]] = '@';
	A[rand_x][rand_y] = 'o';
}

void Maze::increment(){
	for(int i=X.size()-1;i>0;i--) X[i]=X[i-1],Y[i]=Y[i-1];
}

void Maze::adjust_head(){
	if(direction==1) Y[0]++;
	else if(direction==2) Y[0]--;
	else if(direction==3) X[0]--;
	else if(direction==4) X[0]++;
}

bool Maze::exit(){
	if(X[0]==rand_x && Y[0]==rand_y){
		rand_x = rand()%(m-2) + 1;
		rand_y = rand()%(n-2) + 1;
		X.push_back(X.size()-1);
		Y.push_back(Y.size()-1);
		score += 10;
		return false;
	}
	else if(A[X[0]][Y[0]]!=' '){
		cout<<"GAME OVER\n";
		return true;
	}
	return false;
}

void Maze::direct(){
	char c = getchar();
	int new_direction;
	if(c=='6' || c=='d'){
		new_direction = 1;
	}
	else if(c=='4' || c=='a'){
		new_direction = 2;
	}
	else if(c=='8' || c=='w'){
		new_direction = 3;
	}
	else if(c=='2' || c=='s'){
		new_direction = 4;
	}

	if(!((direction<=2 && new_direction<=2) || (direction>2 && new_direction>2))) direction = new_direction;
}

