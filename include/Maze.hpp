#pragma once

#include <string>
#include <vector>

#define MAZE_VOID 0
#define MAZE_FULL 1

class Maze
{
private:
    size_t size_x;
    size_t size_y;
    std::vector<std::vector<bool>> maze;

public:
    Maze();
    Maze(size_t size_x, size_t size_y);
    std::string to_string();
    void print();
};
