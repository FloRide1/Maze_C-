#include "Color.hpp"
#include "Maze.hpp"
#include <iostream>

using namespace std;

int main()
{
	Maze maze(20);
	maze.genMazeByMergerMethod();

	// cout << maze.getprintableBeautifyContent();
	cout << FBLU("I'm blue.") << endl;
	string maze_print = maze.getcorrectedprintableBeautifyContent();
	cout << KRED << maze_print << RST;

	return 0;
}
