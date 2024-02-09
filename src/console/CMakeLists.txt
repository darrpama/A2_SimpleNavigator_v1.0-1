cmake_minimum_required(VERSION 3.5)
project(GraphApplication LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_compile_options(-Wall -Werror -Wextra)

add_subdirectory(../graph ${CMAKE_BINARY_DIR}/graph)

set(INTERFACE_SOURCES
    main.cc
    ConsoleInterface.h
    ConsoleInterface.cc
)

add_executable(${PROJECT_NAME}
    ${INTERFACE_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    s21_graph
    s21_graph_algorithms
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)
