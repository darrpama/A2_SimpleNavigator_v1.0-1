#include <iostream>
#include <iomanip>
#include "s21_graph.h"
#include "s21_graph_algorithms.h"

int main(int argc, char const *argv[]) {
    s21::Graph graph;

    graph.LoadGraphFromFile("./bfs-graph.txt");
    std::cout << "loaded\n";

    std::cout << "    ";
    for (size_t i = 0; i < graph.adj_matrix_.size(); i++) {
        std::cout << std::setw(3) << i + 1 << " ";
    }
    std::cout << "\n";

    for (size_t i = 0; i < graph.adj_matrix_.size(); i++) {
            std::cout << std::setw(3) << i + 1 << ":";
        for (size_t j = 0; j < graph.adj_matrix_[i].size(); j++) {
            std::cout << std::setw(3) << graph.adj_matrix_[i][j] << " ";
        }
        std::cout << "\n";
    }

    // graph.ExportGraphToDot("dot.dt");

    // auto result = s21::GraphAlgorithms::DepthFirstSearch(graph, 1);
    auto result = s21::GraphAlgorithms::BreadthFirstSearch(graph, 1);
    std::cout << "DepthFirstSearch result:\n\t";
    for (auto i : result) {
        std::cout << i << " ";
    }
}
