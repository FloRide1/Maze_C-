#include <iostream>
#include "Maze.hpp"

using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	Maze maze(4);
	Maze maze2(5, 5);
	
	maze.printRawContent();
	return 0;
}

