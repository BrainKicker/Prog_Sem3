cmake_minimum_required(VERSION 3.20)
project(OOP_Lab1_Final)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP_Lab1_Final main.cpp utils/containers/vector/vector.h game/field/field.cpp game/field/field.h utils/containers/matrix/matrix.h utils/containers/vector/vector_iterator.h game/items/artifact.cpp game/items/artifact.h game/field/cell.cpp game/field/cell.h utils/containers/pair/pair.h)
