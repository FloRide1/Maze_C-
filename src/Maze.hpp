#ifndef MAZE_OBJECT
#define MAZE_OBJECT
#include <iostream>
#include <vector>

/// For now only for Maze_UI ...
#include "Color.hpp"

/// For now only for Maze_Gen ...
#include <numeric>
#include <random>
#include <bit>
#include <algorithm>

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
		unsigned char getPathConnectedEdge(unsigned int, std::vector<unsigned int>);
		std::string getUnicodeEdge(unsigned char);

		// Generator Utils
		bool MergerIsEnded(std::vector<unsigned int>);
		std::vector<unsigned char> getPossibleMergerEdge(std::vector<unsigned int>, unsigned int);
		unsigned int convertMergerDirectionToOffset(unsigned char);
		void deleteMergerDirectionWall(unsigned int , unsigned char);
		std::string getprintableMergerArray(std::vector<unsigned int>);

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
		std::string getprintablePath(std::vector<unsigned int>);

		// Generator
		void genMazeByMergerMethod();
};

#endif
