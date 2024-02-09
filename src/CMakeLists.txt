cmake_minimum_required(VERSION 3.5)
project(SimpleNavigator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(${PROJECT_NAME}_SOURCES 
    graph/s21_graph.cc
    graph/s21_graph.h
    graph/s21_graph_algorithms.cc
    graph/s21_graph_algorithms.h
    graph/TSM/AntColonyTSM.cc
    graph/TSM/AntColonyTSM.h
)

add_executable(${PROJECT_NAME} main.cc ${${PROJECT_NAME}_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
