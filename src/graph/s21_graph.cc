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

    void Graph::ExportGraphToDot(const std::string &filename) const {
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

    int Graph::getEdgeCost(const int from, const int to) const {
        return adj_matrix_[from - 1][to - 1];
    }

    std::vector<int> Graph::getNeighbors(const int vertex) const {
        if (size_ == 0) return {};

        if (vertex < 1 || vertex > size_) {
            throw std::invalid_argument("Graph::getNeighbors(): Invalid vertex");
        }

        std::vector<int> neighbors;
        for (int i = 0; i < size_; ++i) {
            if (adj_matrix_[vertex - 1][i] >= 1) {
                neighbors.push_back(i + 1);
            }
        }

        return neighbors;
    }

    size_t Graph::size() const {
        return size_;
    }
}
