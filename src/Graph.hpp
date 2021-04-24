#ifndef GRAPH
#define GRAPH

#include <tuple>
#include <vector>
#include "Maze.hpp"

class Graph 
{
	private:
		std::vector<unsigned int> vertices;
		std::vector<unsigned int> edge;
		std::vector<std::vector<std::tuple<unsigned int, unsigned int>>> adjacency_list;
		
	public:
		Graph();
		Graph(std::vector<unsigned int>, std::vector<unsigned int>, std::vector<std::vector<std::tuple<unsigned int, unsigned int>>>);
		
		void extractGraphFromFullMaze(Maze);
		void extractGraphFromMaze(Maze);

		std::string printIncidenceMatrix();
};
#endif
