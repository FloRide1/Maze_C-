#include "../Graph.hpp"
#include <algorithm>
#include <vector>
#include <tuple>

Graph::Graph()
{
	vertices = std::vector<unsigned int>();
	edge = std::vector<unsigned int>();
	adjacency_list = std::vector<std::vector<std::tuple<unsigned int, unsigned int>>>();
}

Graph::Graph(std::vector<unsigned int> vertices, std::vector<unsigned int> edge, std::vector<std::vector<std::tuple<unsigned int, unsigned int>>> adjacency_list)
{
	this->vertices = vertices;
	this->edge = edge;
	this->adjacency_list = adjacency_list;
}

///
// Construct an unweighted graph from a maze as each case is one node (or vertex) connected to nearby case
//
///
void Graph::extractGraphFromFullMaze(Maze maze)
{
	vertices = std::vector<unsigned int>();
	edge = std::vector<unsigned int>();
	adjacency_list = std::vector<std::vector<std::tuple<unsigned int, unsigned int>>>();

	MazeType type = maze.getTypeOfMaze();
	unsigned int width = maze.getWidth();
	unsigned int height = maze.getHeight();
	std::vector<bool> content = maze.getContent();

	unsigned int i = 0;
	unsigned int number_of_vertex = std::count(content.begin(), content.end(), false);
	adjacency_list = std::vector<std::vector<std::tuple<unsigned int, unsigned int>>>(number_of_vertex, std::vector<std::tuple<unsigned int, unsigned int>>());
	while (vertices.size() < number_of_vertex)
	{
		if (!content[i])
		{
			vertices.push_back(i);
		}
		i++;
	}
	
	for (unsigned int vertex : vertices)
	{
		std::vector<unsigned int> list_of_choices = maze.listAllPathChoices(vertex);
		for (unsigned int choice : list_of_choices)
		{
			if (vertex < choice)
			{
				// DON'T WORK I DUNNO WHY
				// std::tuple<unsigned int, unsigned int> choice_tuple = std::tuple<unsigned int, unsigned int>(choice , 1);
				// std::tuple<unsigned int, unsigned int> vertex_tuple = std::tuple<unsigned int, unsigned int>(vertex , 1);

				// adjacency_list[vertex].push_back(choice_tuple);
				// adjacency_list[choice].push_back(vertex_tuple);
				//
			}
		}
	}
}
