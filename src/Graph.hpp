#ifndef GRAPH_OBJECT
#define GRAPH_OBJECT

#include <tuple>
#include <vector>
#include "Maze.hpp"

class Graph 
{
	private:
		std::vector<unsigned int> vertices;
		std::vector<unsigned int> edge;
		std::vector<std::vector<std::tuple<unsigned int, unsigned int>>> adjacency_list;

		std::string getPadding(std::string, const size_t, const char);
		
	public:
		Graph();
		Graph(std::vector<unsigned int>, std::vector<unsigned int>, std::vector<std::vector<std::tuple<unsigned int, unsigned int>>>);
		
		void extractGraphFromFullMaze(Maze);
		void extractGraphFromMaze(Maze);

		std::string printAdjacencyList();
};

#endif
