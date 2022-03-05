#include "Maze.hpp"

#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>

#include "constant.hpp"

Maze::Maze()
{
    size_x = 0;
    size_y = 0;
}

Maze::Maze(size_t size_x, size_t size_y)
{
    this->size_x = size_x;
    this->size_y = size_y;

    maze = std::vector<std::vector<bool>>(size_y,
                                          std::vector<bool>(size_x, M_FULL));
}

std::string Maze::to_string()
{
    std::string output = "";
    for (size_t y = 0; y != maze.size(); y++)
    {
        for (size_t x = 0; x != maze[y].size(); x++)
        {
            bool current = maze[y][x];
            if (current == M_FULL)
                output.append("+");
            else if (current == M_VOID)
                output.append(" ");
        }
        output.append(S_NEW_LINE);
    }

    return output;
}

std::string Maze::to_cli_string()
{
    std::string out;
    for (size_t y = 0; y != maze.size(); y++)
    {
        for (size_t x = 0; x != maze[y].size(); x++)
        {
            unsigned char dir = get_direction(x, y);
            out.append(convert_dir_to_wall(dir));

            // Width correction
            if (GET_RIGHT(dir))
                out.append(convert_dir_to_wall(DIR_LR));
            else
                out.append(convert_dir_to_wall(DIR_NONE));
        }
        out.append(S_NEW_LINE);
    }

    return out;
}
std::string Maze::convert_dir_to_wall(unsigned char dir)
{
    switch (dir)
    {
    case DIR_NONE:
        return S_NONE;
    case DIR_L:
        return S_L;
    case DIR_R:
        return S_R;
    case DIR_U:
        return S_U;
    case DIR_D:
        return S_D;
    case DIR_LR:
        return S_LR;
    case DIR_LU:
        return S_LU;
    case DIR_RU:
        return S_RU;
    case DIR_LD:
        return S_LD;
    case DIR_RD:
        return S_RD;
    case DIR_UD:
        return S_UD;
    case DIR_RUD:
        return S_RUD;
    case DIR_LUD:
        return S_LUD;
    case DIR_LRD:
        return S_LRD;
    case DIR_LRU:
        return S_LRU;
    case DIR_LRUD:
        return S_LRUD;
    }
    return S_OTHER;
}

void Maze::print()
{
    std::cout << this->to_string();
}

void Maze::print_cli()
{
    std::cout << this->to_cli_string();
}

unsigned char Maze::get_direction(size_t x, size_t y)
{
    if (size_x == 0 || size_y == 0)
        throw std::length_error("The maze is too small");
    bool state = maze[y][x];
    unsigned char output = 0;

    if (x > 0 && maze[y][x - 1] == state)
        output = SET_LEFT(output);
    if (y > 0 && maze[y - 1][x] == state)
        output = SET_UP(output);
    if (x < maze[0].size() - 1 && maze[y][x + 1] == state)
        output = SET_RIGHT(output);
    if (y < maze.size() - 1 && maze[y + 1][x] == state)
        output = SET_DOWN(output);

    return output;
}
