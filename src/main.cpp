#include <iostream>
#include "Maze.hpp"

using namespace std;

int main()
{
	cout << "Hello World!" << endl;
	Maze maze(4);
	Maze maze2(2, 4);
	maze2.makeBorder();

	maze2.setWall(7);
	maze2.setWall(11);
	maze2.setAir(4);
	
	cout << maze.getprintableRawContent();
	cout << maze.getprintableBeautifyContent();

	cout << maze2.getprintableRawContent();
	cout << maze2.getprintableBeautifyContent();
	return 0;
}

