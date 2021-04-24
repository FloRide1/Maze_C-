#include "Color.hpp"
#include "Maze.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Maze maze(10);
	maze.genMazeByMergerMethod();

	cout << "Main: " << endl;

	// cout << maze.getprintableBeautifyContent();
	vector<unsigned int> my_path;
	my_path.push_back(13);
	my_path.push_back(12);
	my_path.push_back(23);

	string maze_print = maze.getcorrectedprintableBeautifyContent();
	cout << maze_print << endl;
	

	return 0;
}
