cmake_minimum_required(VERSION 3.21)
project(DataStructure C)

set(CMAKE_C_STANDARD 99)

add_executable(
        DataStructure
        Assignment/02_NameCardList/NameCard.c
        Assignment/02_NameCardList/NameCard.h
        Assignment/02_NameCardList/ArrayList.c
        Assignment/02_NameCardList/ArrayList.h
        Assignment/02_NameCardList/NameCardMain.c
)
