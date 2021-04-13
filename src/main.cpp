#include <iostream>
#include "Maze.hpp"

using namespace std;

int main()
{
	Maze maze(8);
	Maze maze2(2, 3);
	maze.makeGrid();
	
	cout << maze.getcorrectedprintableBeautifyContent();
	cout << endl;
	cout << maze2.getcorrectedprintableBeautifyContent();
	return 0;
}

