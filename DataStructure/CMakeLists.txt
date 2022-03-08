cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_library(DataStructure ADT.c LinkedList/PointListMain.c)
