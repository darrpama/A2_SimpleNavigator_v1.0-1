#include <filesystem>
#include <gtest/gtest.h>
#include "../graph/s21_graph_algorithms.h"

TEST(GraphAlgorithms, DepthFirstSearch) {
    std::string test_graph_path = (std::filesystem::current_path() / "assets" / "dfs-graph.txt").string();

    s21::Graph graph;
    graph.LoadGraphFromFile(test_graph_path);

    std::vector<int> dfs_result = s21::GraphAlgorithms::DepthFirstSearch(graph, 1);
    EXPECT_EQ(dfs_result.size(), 12);
    EXPECT_TRUE((dfs_result == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}));
}

TEST(GraphAlgorithms, BreadthFirstSearch) {
    std::string test_graph_path = (std::filesystem::current_path() / "assets" / "bfs-graph.txt").string();

    s21::Graph graph;
    graph.LoadGraphFromFile(test_graph_path);

    std::vector<int> bfs_result = s21::GraphAlgorithms::BreadthFirstSearch(graph, 1);
    EXPECT_EQ(bfs_result.size(), 12);
    EXPECT_TRUE((bfs_result == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}));
}

TEST(GraphAlgorithms, GetShortestPathBetweenVertices_Dijkstra) {
    std::string test_graph_path = (std::filesystem::current_path() / "assets" / "dijkstra.txt").string();

    s21::Graph graph;
    graph.LoadGraphFromFile(test_graph_path);

    int dijkstra_result = s21::GraphAlgorithms::GetShortestPathBetweenVertices(graph, 1, 5);
    EXPECT_EQ(dijkstra_result, 20);
}
