#include "Maze.hpp"

#include <cstddef>
#include <iostream>
#include <string>

#include "constant.hpp"

Maze::Maze(size_t size_x, size_t size_y)
{
    this->size_x = size_x;
    this->size_y = size_y;

    maze = std::vector<std::vector<bool>>(size_y,
                                          std::vector<bool>(size_x, MAZE_FULL));
}

std::string Maze::to_string()
{
    std::string output = "";
    for (size_t y = 0; y != maze.size(); y++)
    {
        for (size_t x = 0; x != maze[y].size(); x++)
        {
            bool current = maze[y][x];
            if (current == MAZE_FULL)
                output.append("+");
            else
                output.append(" ");
        }
        output.append(S_NEW_LINE);
    }

    return output;
}

void Maze::print()
{
    std::cout << this->to_string();
}
