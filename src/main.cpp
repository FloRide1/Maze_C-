#include "Color.hpp"
#include "Maze.hpp"
#include "Graph.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Maze maze(10);
	maze.genMazeByMergerMethod();

	cout << "Main: " << endl;

	string maze_print = maze.getcorrectedprintableBeautifyContent();
	cout << maze_print << endl;

	Graph graph;
	graph.extractGraphFromFullMaze(maze);

	cout << graph.printAdjacencyList() << endl;

	return 0;
}
