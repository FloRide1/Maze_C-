#include <iostream>
#include "Maze.hpp"

using namespace std;

int main()
{
	Maze maze(8);
	Maze maze2(2, 3);
	maze2.makeBorder();

	maze2.setWall(7);
	maze2.setWall(11);
	maze2.setAir(4);
	
	cout << maze.getprintableBeautifyContent();
	cout << endl;
	cout << maze2.getprintableBeautifyContent();
	cout << endl;
	cout << maze2.getcorrectedprintableBeautifyContent();
	return 0;
}

