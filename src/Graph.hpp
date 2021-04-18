#ifndef GRAPH
#define GRAPH

#include <vector>
#include "Maze.hpp"

class Graph 
{
	private:
		std::vector<unsigned int> vertex;
		std::vector<unsigned int> edge;
		std::vector<std::vector<bool>> matrix;
		
	public:
		Graph();
		Graph(std::vector<unsigned int>, std::vector<unsigned int>, std::vector<std::vector<bool>>);
		
		void extractGraphFromFullMaze(Maze);
		void extractGraphFromMaze(Maze);

		std::string printIncidenceMatrix();
};
#endif
