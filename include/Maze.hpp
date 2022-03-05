#pragma once

#include <string>
#include <vector>

#define M_VOID 0
#define M_FULL 1

#define INDEX_UP 0
#define INDEX_LEFT 1
#define INDEX_RIGHT 2
#define INDEX_DOWN 3

#define SET_UP(x) SET_BIT_ON(x, INDEX_UP)
#define SET_LEFT(x) SET_BIT_ON(x, INDEX_LEFT)
#define SET_RIGHT(x) SET_BIT_ON(x, INDEX_RIGHT)
#define SET_DOWN(x) SET_BIT_ON(x, INDEX_DOWN)

#define GET_UP(x) GET_BIT(x, INDEX_UP)
#define GET_LEFT(x) GET_BIT(x, INDEX_LEFT)
#define GET_RIGHT(x) GET_BIT(x, INDEX_RIGHT)
#define GET_DOWN(x) GET_BIT(x, INDEX_DOWN)

#define DIR_NONE 0
#define DIR_L SET_LEFT(0)
#define DIR_R SET_RIGHT(0)
#define DIR_U SET_UP(0)
#define DIR_D SET_DOWN(0)
#define DIR_LR SET_LEFT(SET_RIGHT(0))
#define DIR_LU SET_LEFT(SET_UP(0))
#define DIR_RU SET_RIGHT(SET_UP(0))
#define DIR_LD SET_LEFT(SET_DOWN(0))
#define DIR_RD SET_RIGHT(SET_DOWN(0))
#define DIR_UD SET_UP(SET_DOWN(0))
#define DIR_RUD SET_RIGHT(SET_UP(SET_DOWN(0)))
#define DIR_LUD SET_LEFT(SET_UP(SET_DOWN(0)))
#define DIR_LRD SET_LEFT(SET_RIGHT(SET_DOWN(0)))
#define DIR_LRU SET_LEFT(SET_RIGHT(SET_UP(0)))
#define DIR_LRUD SET_LEFT(SET_RIGHT(SET_UP(SET_DOWN(0))))

#define S_NONE " "
#define S_L "╴"
#define S_R "╶"
#define S_U "╵"
#define S_D "╷"
#define S_LR "─"
#define S_LU "┘"
#define S_RU "└"
#define S_LD "┐"
#define S_RD "┌"
#define S_UD "│"
#define S_RUD "├"
#define S_LUD "┤"
#define S_LRD "┬"
#define S_LRU "┴"
#define S_LRUD "┼"

#define S_OTHER "·"

class Maze
{
private:
    size_t size_x_;
    size_t size_y_;
    std::vector<std::vector<bool>> maze;
    unsigned char get_direction(size_t x, size_t y);
    std::string convert_dir_to_wall(unsigned char);

public:
    Maze();
    Maze(size_t size_x, size_t size_y);
    std::string to_string();
    std::string to_cli_string();
    void print();
    void print_cli();
};
