cmake_minimum_required(VERSION 3.5)
project(SimpleNavigator LANGUAGES CXX)

option(TESTING OFF)
option(APPLICATION OFF)

if (APPLICATION)
    add_subdirectory(console)
elseif (TESTING)
    add_subdirectory(tests)
else()
    add_subdirectory(graph)
endif()


# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add_subdirectory(graph)
# add_executable(${PROJECT_NAME} main.cc)

# target_link_libraries(${PROJECT_NAME}
#     s21_graph
#     s21_graph_algorithms
# )

# set_target_properties(${PROJECT_NAME} PROPERTIES
#     RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
# )
