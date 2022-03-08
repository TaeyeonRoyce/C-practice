cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        ArrayList/Problem/Problem_2.c
        ArrayList/Problem/NameCard/ArrayList.h
        ArrayList/Problem/NameCard/ArrayList.c
        ArrayList/Problem/NameCard/NameCard.h
        ArrayList/Problem/NameCard/NameCard.c)
