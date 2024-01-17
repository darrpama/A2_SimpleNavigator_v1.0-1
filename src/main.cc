#include <iostream>
#include <iomanip>
#include "s21_graph.h"

int main(int argc, char const *argv[]) {
    s21::Graph graph;

    graph.LoadGraphFromFile("./graph.txt");
    std::cout << "loaded\n";

    for (size_t i = 0; i < graph.nodes_.size(); i++) {
        std::cout << "Node " << std::setw(2) << i << ":";
        for (auto& neighbs : graph.nodes_[i]->neighbors) {
            std::cout << std::setw(3) << graph.nodes_[i]->neighbors_values[neighbs] << " ";
        }
        std::cout << "\n";
    }
}
