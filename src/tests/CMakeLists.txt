cmake_minimum_required(VERSION 3.5)
project(GraphTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_compile_options(-Wall -Werror -Wextra)
enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_definitions(-DGTEST_LANGUAGE_CXX17)

set(TEST_SOURCES
    main_tests.cc
    graph_tests.cc
    graph_algorithms_tests.cc
)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})

target_link_libraries(${PROJECT_NAME}
    s21_graph
    s21_graph_algorithms
    ${GTEST_LIBRARIES}
)

