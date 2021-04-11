#ifndef MAZE_OBJECT
#define MAZE_OBJECT
#include <iostream>
#include <vector>

enum MazeType
{
	Null,
	Square,
	Rectangle
};


class Maze {
	private:
		MazeType type;
		unsigned int width, height;
		std::vector<bool> content;

	public:
		Maze();
		Maze(unsigned int);
		Maze(unsigned int, unsigned int);

		void fillMaze();

		// Getters
		unsigned int getWidth();
		unsigned int getHeight();
		MazeType getTypeOfMaze();
		std::vector<bool> getContent();

		// Printings
		void printRawContent();
		
};

#endif
