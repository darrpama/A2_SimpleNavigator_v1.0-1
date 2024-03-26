cmake_minimum_required(VERSION 3.5)
project(s21_graph LANGUAGES CXX)

option(S21_GRAPH OFF)
option(S21_GRAPH_ALGORITHMS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_compile_options(-Wall -Werror -Wextra)


set(${PROJECT_NAME}_SOURCES 
    s21_graph.cc
    s21_graph.h
)

add_library(${PROJECT_NAME} STATIC
    ${${PROJECT_NAME}_SOURCES}
)


project(s21_graph_algorithms LANGUAGES CXX)

set(${PROJECT_NAME}_ALG_SOURCES 
    s21_graph_algorithms.cc
    s21_graph_algorithms.h
    TSM/AntColonyTSM.cc
    TSM/AntColonyTSM.h
    TSM/GeneticTSM.cc
    TSM/GeneticTSM.h
    TSM/BranchesAndBoundsTSM.cc
    TSM/BranchesAndBoundsTSM.h
    ../containers/queue.h
    ../containers/stack.h
)
    
add_library(${PROJECT_NAME} STATIC
    ${${PROJECT_NAME}_ALG_SOURCES}
    ${PROJECT_NAME}
)
   