#include <gtest/gtest.h>

#include <filesystem>

#include "../graph/s21_graph.h"

TEST(Graph, LoadGraphFromFile) {
  std::string test_graph_path =
      (std::filesystem::current_path() / "assets" / "graph.txt").string();

  s21::Graph graph;
  graph.LoadGraphFromFile(test_graph_path);

  EXPECT_EQ(graph.size(), 11);
  EXPECT_EQ(graph.getEdgeCost(7, 9), 101);

  EXPECT_TRUE((graph.getNeighbors(6) ==
               std::vector<int>{1, 2, 3, 4, 5, 7, 8, 9, 10, 11}));
}

TEST(Graph, ExportGraphToDot) {
  std::string test_graph_path =
      (std::filesystem::current_path() / "assets" / "graph.txt").string();
  std::string export_graph_path =
      (std::filesystem::current_path() / "assets" / "graph.dot").string();

  s21::Graph graph;
  graph.LoadGraphFromFile(test_graph_path);
  graph.ExportGraphToDot(export_graph_path);

  EXPECT_TRUE(std::filesystem::exists(export_graph_path));
  EXPECT_NE(std::filesystem::file_size(export_graph_path), 0);

  std::filesystem::remove(export_graph_path);
}
