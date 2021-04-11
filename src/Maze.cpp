#include "Maze.hpp"
#include <vector>


/**
 * Create an Null Maze (it mean nothing, just for avoiding bug)
 *
 */
Maze::Maze()
{
	type = Null;
}
/**
 * Create an Square Maze with a "size" columns and "size" rows
 *
 * @param size The size you want for your square maze (in height or width)
 */
Maze::Maze(unsigned int size)
{
	if (size == 0)
	{
		type = Null;
		return;
	}
	type = Square;
	width = size;
	height = size;
	fillMaze();
}

/**
 * Create an Rectangle Maze with a specified numbers of columns and rows
 *
 * @param width_size The numbers of columns you want for your maze
 * @param height_size The numbers of rows you want for your maze
 */
Maze::Maze(unsigned int width_size, unsigned int height_size)
{
	if (width_size == 0 || height_size == 0)
	{
		type = Null;
		return;
	}

	if (width_size == height_size)
	{
		type = Square;
	} 
	else 
	{
		type = Rectangle;
	}

	width = width_size;
	height = height_size;
	fillMaze();
}


/**
 * Fill your Maze with wall
 */
void Maze::fillMaze()
{
	if (type == Null)
	{
		return;
	}
	
	content = std::vector<bool> ((2 * height + 1) * (2 * width + 1));
	std::fill(content.begin(), content.end(), true);
}

/**
 * Return the width of the Maze
 */
unsigned int Maze::getWidth()
{
	return width;
}

/**
 * Return the height of the Maze
 */
unsigned int Maze::getHeight()
{
	return height;
}

/**
 * Return the type of te Maze
 */
MazeType Maze::getTypeOfMaze()
{
	return type;
}

/**
 * Return the content of te Maze
 */
std::vector<bool> Maze::getContent()
{
	return content;
}

/**
 * Print the Raw Content (1 -> Wall, 0 -> Free) 
 */
void Maze::printRawContent()
{
	unsigned int i;
	for (i = 0; i < content.size(); i++)
	{
		if (i != 0 && i % (2 * height + 1) == 0)
		{
			std::cout << std::endl;
		}
		std::cout << content[i];
	}
	std::cout << std::endl;
}
