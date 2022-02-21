cmake_minimum_required(VERSION 3.00)

# Set the project name
project(Maze_Cpp VERSION 0.1)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)

# Set the CXXFLAGS
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic")

file(GLOB SRC src/*.cpp)

# Ouput Executable
add_executable(maze.out ${SRC})
