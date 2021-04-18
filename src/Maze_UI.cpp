#include "Maze.hpp"
#include <string>
#include <vector>

/**
 * Print the Raw Content (1 -> Wall, 0 -> Free) 
 */
std::string Maze::getprintableRawContent()
{
	unsigned int i;
	std::string output = "";

	for (i = 0; i < content.size(); i++)
	{
		if (i != 0 && i % (2 * width + 1) == 0)
		{
			output += "\n";
		}
		output += std::to_string(content[i]);
		output += " ";
	}
	output += "\n";
	return output;
}

std::string Maze::getprintableEdgeContent()
{
	std::string output = "";

	unsigned int i;
	for (i = 0; i < content.size(); i++)
	{
		if (i != 0 && i % (2 * width + 1) == 0)
		{
			output += "\n";
		}

		std::string output_char = "0";
		if (content[i])
		{
			unsigned int edge = getConnectedEdge(i);
			if (edge >= 10)
			{
				switch(edge)
				{
					case 10:
						output_char = "A";
						break;
					case 11:
						output_char = "B";
						break;
					case 13:
						output_char = "C";
						break;
					case 14:
						output_char = "D";
						break;
					case 15:
						output_char = "E";
						break;
					case 16:
						output_char = "F";
						break;
					default:
						output_char = "0";
						break;
				}
			}
			else 
			{
				output_char = std::to_string(edge);
			}
		}
		output += output_char + " ";
	}
	output += "\n";
	return output;
}

/**
 * Print the Maze in a user-friendly way
 */
std::string Maze::getprintableBeautifyContent()
{
	std::string output = "";

	unsigned int i;
	for (i = 0; i < content.size(); i++)
	{
		if (i != 0 && i % (2 * width + 1) == 0)
		{
			output += "\n";
		}

		std::string output_char = " ";
		if (content[i])
		{
			unsigned int edge = getConnectedEdge(i);
			output_char = getUnicodeEdge(edge);
		}

		output += output_char;
	}
	output += "\n";
	return output;
}
std::string Maze::getcorrectedprintableBeautifyContent()
{
	std::string output = "";
	std::string bonus_char = "─";

	unsigned int i;
	for (i = 0; i < content.size(); i++)
	{
		bool bonus = false;
		if (i != 0 && i % (2 * width + 1) == 0)
		{
			output += "\n";
		}

		std::string output_char = " ";
		if (content[i])
		{
			unsigned int edge = getConnectedEdge(i);
			output_char = getUnicodeEdge(edge);
			bonus = (edge == 15 || edge == 13 || edge == 11 || edge == 9 || edge == 7 || edge == 5 || edge == 3 || edge == 1);
		}

		output += output_char;
		output += (bonus)?bonus_char:" ";
	}
	output += "\n";
	return output;
}

std::string Maze::getprintableMergerArray(std::vector<unsigned int> merge_array)
{
	unsigned int i;
	std::string output = "";

	for (i = 0; i < merge_array.size(); i++)
	{
		if (i != 0 && i % width == 0)
		{
			output += "\n";
		}
		output += std::to_string(merge_array[i]);
		output += " ";
	}
	output += "\n";
	return output;
}

std::string Maze::getprintablePath(std::vector<unsigned int> path)
{
	std::string output = "";
	std::string bonus_char = "─";

	unsigned int i;
	for (i = 0; i < content.size(); i++)
	{
		bool bonus = false;
		if (i != 0 && i % (2 * width + 1) == 0)
		{
			output += "\n";
		}

		std::string output_char = " ";
		if (content[i])
		{
			unsigned int edge = getConnectedEdge(i);
			output_char = getUnicodeEdge(edge);
			bonus = (edge == 15 || edge == 13 || edge == 11 || edge == 9 || edge == 7 || edge == 5 || edge == 3 || edge == 1);
		}
		else if (std::find(path.begin(), path.end(), i) != path.end())
		{
			unsigned int edge = getPathConnectedEdge(i, path);
			bonus = (edge == 15 || edge == 13 || edge == 11 || edge == 9 || edge == 7 || edge == 5 || edge == 3 || edge == 1);
			std::string edge_char = "╳";
			output_char = KRED + getUnicodeEdge(edge);
			if (i != path[0] && i != path[path.size() - 1])
			{
				edge_char = getUnicodeEdge(edge);
			}
			output_char = KRED + edge_char;
		}

		output += output_char;
		output += (bonus)?bonus_char:" ";
		output += RST;
	}
	output += "\n";
	return output;
}
