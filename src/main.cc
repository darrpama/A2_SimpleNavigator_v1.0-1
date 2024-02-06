#include <iostream>
#include <iomanip>
#include "graph/s21_graph.h"
#include "graph/s21_graph_algorithms.h"

int main(int argc, char const *argv[]) {
    s21::Graph graph;

    graph.LoadGraphFromFile("./assets/prim.txt");
    std::cout << "loaded\n";

    std::cout << "    ";
    for (size_t i = 0; i < graph.size(); i++) {
        std::cout << std::setw(3) << i + 1 << " ";
    }
    std::cout << "\n";

    for (size_t i = 0; i < graph.size(); i++) {
        std::cout << std::setw(3) << i + 1 << ":";
        for (size_t j = 0; j < graph.size(); j++) {
            std::cout << std::setw(3) << graph.getEdgeCost(i + 1, j + 1) << " ";
        }
        std::cout << "\n";
    }

    // graph.ExportGraphToDot("dot.dt");

    // auto result = s21::GraphAlgorithms::DepthFirstSearch(graph, 1);
    // auto result = s21::GraphAlgorithms::BreadthFirstSearch(graph, 1);
    // std::cout << "DepthFirstSearch result:\n\t";
    // for (auto i : result) {
    //     std::cout << i << " ";
    // }

    // int cost = s21::GraphAlgorithms::GetShortestPathBetweenVertices(graph, 1, 6);
    // std::cout << "cost: " << cost << "\n";

    // auto res = s21::GraphAlgorithms::GetShortestPathsBetweenAllVertices(graph);
    // std::cout << "FloydWarshall result:\n";
    // for (auto i : res) {
    //     for (auto j : i) {
    //         std::cout << std::setw(3) << j << " ";
    //     }
    //     std::cout << "\n";
    // }
    // std::cout << "\n";

    auto lst = s21::GraphAlgorithms::GetLeastSpanningTree(graph);
    std::cout << "LeastSpanningTree result:\n";
    for (auto i : lst) {
        for (auto j : i) {
            std::cout << std::setw(3) << j << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // 0 3 4 0 1
    // 3 0 0 0 0
    // 4 0 0 2 0
    // 0 0 2 0 0
    // 1 0 0 0 0
}
