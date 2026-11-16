cmake_minimum_required(VERSION 3.16)
project(tiny_dungeon LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(tiny_dungeon src/main.cpp)
