#include <iostream>
#include "Maze.hpp"

using namespace std;

int main()
{
	Maze maze(20);
	maze.genMazeByMergerMethod();
	
	cout << maze.getcorrectedprintableBeautifyContent();
	return 0;
}

