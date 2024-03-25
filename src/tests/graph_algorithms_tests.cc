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

TEST(GraphAlgorithms, GetShortestPathsBetweenAllVertices_FloydWarshall) {
    std::string test_graph_path = (std::filesystem::current_path() / "assets" / "floyd-warshall.txt").string();

    s21::Graph graph;
    graph.LoadGraphFromFile(test_graph_path);

    auto result = s21::GraphAlgorithms::GetShortestPathsBetweenAllVertices(graph);

    EXPECT_EQ(result.size(), 4);
    EXPECT_TRUE((result[0] == std::vector<int>{ 0, -1, -2, 0}));
    EXPECT_TRUE((result[1] == std::vector<int>{ 4,  0,  2, 4}));
    EXPECT_TRUE((result[2] == std::vector<int>{ 5,  1,  0, 2}));
    EXPECT_TRUE((result[3] == std::vector<int>{ 3, -1,  1, 0}));
}

TEST(GraphAlgorithms, GetLeastSpanningTree_Prim) {
    std::string test_graph_path = (std::filesystem::current_path() / "assets" / "prim.txt").string();

    s21::Graph graph;
    graph.LoadGraphFromFile(test_graph_path);

    auto result = s21::GraphAlgorithms::GetLeastSpanningTree(graph);
    
    EXPECT_EQ(result.size(), 5);
    EXPECT_TRUE((result[0] == std::vector<int>{ 0, 3, 4, 0, 1}));
    EXPECT_TRUE((result[1] == std::vector<int>{ 3, 0, 0, 0, 0}));
    EXPECT_TRUE((result[2] == std::vector<int>{ 4, 0, 0, 2, 0}));
    EXPECT_TRUE((result[3] == std::vector<int>{ 0, 0, 2, 0, 0}));
    EXPECT_TRUE((result[4] == std::vector<int>{ 1, 0, 0, 0, 0}));
}

TEST(GraphAlgorithmsTSM, AntColony) {
    std::string test_graph_path = (std::filesystem::current_path() / "assets" / "graph.txt").string();

    s21::Graph graph;
    graph.LoadGraphFromFile(test_graph_path);

    auto result = s21::GraphAlgorithms::SolveTravelingSalesmanProblem(graph);
    
    std::set<int> path;
    for (int vertex : result.vertices) {
        path.insert(vertex);
    }

    EXPECT_EQ(path.size(), graph.size());
    EXPECT_EQ(result.vertices.size(), graph.size() + 1);
    EXPECT_LT(result.distance, 260);
}

TEST(GraphAlgorithmsTSM, Genetic) {
    std::string test_graph_path = (std::filesystem::current_path() / "assets" / "graph.txt").string();

    s21::Graph graph;
    graph.LoadGraphFromFile(test_graph_path);

    auto result = s21::GraphAlgorithms::SolveTravelingSalesmanProblemGenetic(graph);
    
    std::set<int> path;
    for (int vertex : result.vertices) {
        path.insert(vertex);
    }

    EXPECT_EQ(path.size(), graph.size());
    EXPECT_EQ(result.vertices.size(), graph.size());
    EXPECT_LT(result.distance, 260);
}
