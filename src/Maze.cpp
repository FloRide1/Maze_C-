#include "Maze.hpp"

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
}
