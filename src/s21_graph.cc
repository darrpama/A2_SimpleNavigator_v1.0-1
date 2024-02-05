#include "s21_graph.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace s21 {
    void Graph::LoadGraphFromFile(const std::string &filename) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            throw std::invalid_argument("File not found");
        }

        file >> size_;
        adj_matrix_ = std::vector<std::vector<int>>(size_, std::vector<int>(size_, 0));

        for (int i = 0; i < size_; ++i) {
            for (int j = 0; j < size_; ++j) {
                file >> adj_matrix_[i][j];
            }
        }
    }

    void Graph::ExportGraphToDot(const std::string &filename) {
        std::stringstream ss;
        ss << "digraph G {\n";
        for (int i = 0; i < size_; ++i) {
            for (int j = 0; j < size_; ++j) {
                if (adj_matrix_[i][j] >= 1) {
                    ss << "\t" << i << " -> " << j << ";\n";
                }
            }
        }
        ss << "}\n";

        std::ofstream file(filename);
        file << ss.str();
    }
}
