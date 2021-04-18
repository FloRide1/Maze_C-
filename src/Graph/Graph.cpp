#include "../Graph.hpp"
#include <algorithm>
#include <vector>

Graph::Graph()
{
	vertex = std::vector<unsigned int>();
	edge = std::vector<unsigned int>();
	matrix = std::vector<std::vector<bool>>();
}

Graph::Graph(std::vector<unsigned int> vertex, std::vector<unsigned int> edge, std::vector<std::vector<bool>> matrix)
{
	this->vertex = vertex;
	this->edge = edge;
	this->matrix = matrix;
}

void Graph::extractGraphFromFullMaze(Maze maze)
{
	vertex = std::vector<unsigned int>();
	edge = std::vector<unsigned int>();
	matrix = std::vector<std::vector<bool>>();

	MazeType type = maze.getTypeOfMaze();
	unsigned int width = maze.getWidth();
	unsigned int height = maze.getHeight();
	std::vector<bool> content = maze.getContent();

	unsigned int i = 0;
	unsigned int number_of_vertex = std::count(content.begin(), content.end(), false);
	matrix = std::vector<std::vector<bool>>(number_of_vertex, std::vector<bool>());
	while (vertex.size() < number_of_vertex)
	{
		if (!content[i])
		{
			vertex.push_back(i);
		}
		i++;
	}
	
	for (unsigned int ver : vertex)
	{
		std::vector<unsigned int> list_of_choices = maze.listAllPathChoices(ver);
		for (unsigned int choice : list_of_choices)
		{
			if (ver < choice)
			{
				edge.push_back(1); /// All edge are dist 1;
				for (unsigned int i; i < number_of_vertex; i++)
				{
					if (vertex[i] == ver || vertex[i] == choice)
					{
						matrix[i].push_back(true);
					}
					else
					{
						matrix[i].push_back(false);
					}
				}
			}
		}
	}
}
