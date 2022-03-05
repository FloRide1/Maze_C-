#include <iostream>

#include "Maze.hpp"
#include "constant.hpp"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Maze simple_empty = Maze(2, 2);
    simple_empty.print_cli();

    return 0;
}
