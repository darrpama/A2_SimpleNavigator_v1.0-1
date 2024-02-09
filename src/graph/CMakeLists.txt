cmake_minimum_required(VERSION 3.5)
project(s21_graph LANGUAGES CXX)

option(S21_GRAPH OFF)
option(S21_GRAPH_ALGORITHMS OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(${PROJECT_NAME}_SOURCES 
    s21_graph.cc
    s21_graph.h
)

set(${PROJECT_NAME}_ALG_SOURCES 
    s21_graph_algorithms.cc
    s21_graph_algorithms.h
    TSM/AntColonyTSM.cc
    TSM/AntColonyTSM.h
)

if (S21_GRAPH OR S21_GRAPH_ALGORITHMS)
    add_library(${PROJECT_NAME} STATIC
        ${${PROJECT_NAME}_SOURCES}
    )

    set_target_properties(${PROJECT_NAME} PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
endif()
    
if (S21_GRAPH_ALGORITHMS)
    add_library(${PROJECT_NAME}_algorithms STATIC
        ${${PROJECT_NAME}_ALG_SOURCES}
        ${PROJECT_NAME}
    )

    set_target_properties(${PROJECT_NAME}_algorithms PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
endif()
    