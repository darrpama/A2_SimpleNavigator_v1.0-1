#include "s21_graph.h"
#include <fstream>
#include <iostream>

namespace s21 {
    void Graph::LoadGraphFromFile(const std::string &filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::invalid_argument("File not found");
        }

        file >> size_;
        nodes_.resize(size_);
        
        for (int i = 0; i < size_; i++) {
            nodes_[i] = new GraphNode();
        }

        for (int i = 0; i < size_; i++) {
            for (int j = 0; j < size_; j++) {
                int cost;
                file >> cost;
                if (cost == 0) continue;

                nodes_[i]->neighbors.insert(nodes_[j]);
                nodes_[i]->neighbors_values.emplace(nodes_[j], cost);
            }
        }
    }

    void Graph::ExportGraphToDot(const std::string &filename) {
        
    }
}