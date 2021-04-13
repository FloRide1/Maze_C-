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

		// Printings Utils
		unsigned char getConnectedEdge(unsigned int);
		std::string getUnicodeEdge(unsigned char);

	public:
		Maze();
		Maze(unsigned int);
		Maze(unsigned int, unsigned int);

		void fillMaze();
		void makeGrid();
		void makeBorder();

		void setWall(unsigned int);
		void setAir(unsigned int);

		// Getters
		unsigned int getWidth();
		unsigned int getHeight();
		MazeType getTypeOfMaze();
		std::vector<bool> getContent();

		// Printings
		std::string getprintableRawContent();
		std::string getprintableEdgeContent();
		std::string getprintableBeautifyContent();
		std::string getcorrectedprintableBeautifyContent();

		// Generator
		void genMazeByMergerMethod();
};

#endif
