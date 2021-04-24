#include "../Graph.hpp"
#include <string>
#include <tuple>

std::string Graph::printAdjacencyList()
{
	std::string output = "";
	unsigned int max_vertex_lenght = std::to_string(vertices[vertices.size() - 1]).size();
	unsigned int vertices_padding = max_vertex_lenght + 2;

	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		std::vector<std::tuple<unsigned int, unsigned int>> vertex = adjacency_list[i];

		/// Padding the string
		output += getPadding(std::to_string(vertices[i]), vertices_padding, ' ') + " | ";
		for (unsigned int j = 0; j < vertex.size(); j++)
		{
			std::tuple<unsigned int, unsigned int> connected_vertex = vertex[j];
			output += getPadding(std::to_string(std::get<0> (connected_vertex)), vertices_padding, ' ') + " | ";
		}
		output += "\n";
	}

	return output;
}

std::string Graph::getPadding(std::string str, const size_t num, const char paddingChar = ' ')
{
	std::string output = "";
	output.insert(0, num - str.size(), paddingChar);
	output += str;
	return output;
}
