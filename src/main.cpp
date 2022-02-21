#include <iostream>

#include "Maze.hpp"
#include "constant.hpp"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Maze simple_empty = Maze(10, 10);
    simple_empty.print();

    return 0;
}
