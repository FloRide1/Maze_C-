#ifndef MAZE_OBJECT
#define MAZE_OBJECT

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

	public:
		Maze();
		Maze(unsigned int);
		Maze(unsigned int, unsigned int);
};

#endif
