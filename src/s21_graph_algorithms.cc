#include "s21_graph_algorithms.h"

#include <stdexcept>
#include <limits>
#include <stack> // replace
#include <queue> // replace

#include <iostream>

namespace s21 {
    std::vector<int> GraphAlgorithms::DepthFirstSearch(const Graph &graph, int start_vertex) {
        if (graph.size() == 0) {
            return {};
        }
        if (start_vertex < 1 || start_vertex > graph.size()) {
            throw std::invalid_argument("GraphAlgorithms::DepthFirstSearch(): Invalid start vertex");
        }

        std::vector<int> result;
        std::vector<bool> visited(graph.size(), false);

        std::stack<int> stack;
        stack.push(start_vertex - 1);
        
        while (!stack.empty()) {
            int top = stack.top();
            stack.pop();

            if (!visited[top]) {
                result.push_back(top + 1);
                visited[top] = true;
                
                auto nb = graph.getNeighbors(top);
                for (int i = static_cast<int>(nb.size()) - 1; i >= 0; i--) {
                    if (!visited[nb[i]])
                        stack.push(nb[i]);
                }
            }
        }

        return result;
    }
    
    std::vector<int> GraphAlgorithms::BreadthFirstSearch(const Graph &graph, int start_vertex) {
        if (graph.size() == 0) {
            return {};
        }
        if (start_vertex < 1 || start_vertex > graph.size()) {
            throw std::invalid_argument("GraphAlgorithms::BreadthFirstSearch(): Invalid start vertex");
        }
        
        std::vector<int> result;
        std::vector<bool> visited(graph.size(), false);

        std::queue<int> queue;
        queue.push(start_vertex - 1);
        result.push_back(start_vertex);

        while (!queue.empty()) {
            int front = queue.front();
            queue.pop();

            visited[front] = true;
            auto nb = graph.getNeighbors(front);

            for (int i = 0; i < static_cast<int>(nb.size()); i++) {
                if (!visited[nb[i]]) {
                    queue.push(nb[i]);
                    visited[nb[i]] = true;

                    result.push_back(nb[i] + 1);
                }
            }
        }
        
        return result;
    }
    
    int GraphAlgorithms::GetShortestPathBetweenVertices(const Graph &graph, int vertex1, int vertex2) {
        if (graph.size() == 0)
            return 0;
        
        if (vertex1 < 1 || vertex1 > graph.size())
            throw std::invalid_argument("GraphAlgorithms::GetShortestPathBetweenVertices(): Invalid vertex1.");
        
        if (vertex2 < 1 || vertex2 > graph.size())
            throw std::invalid_argument("GraphAlgorithms::GetShortestPathBetweenVertices(): Invalid vertex2.");
        
        std::vector<int> dist(graph.size(), std::numeric_limits<int>::max());
        std::vector<bool> visited(graph.size(), false);
        dist[vertex1 - 1] = 0;

        std::queue<int> queue;
        queue.push(vertex1 - 1);
        
        while (!queue.empty()) {
            int front = queue.front();
            queue.pop();

            visited[front] = true;
            auto nb = graph.getNeighbors(front);

            for (int i = 0; i < static_cast<int>(nb.size()); i++) {
                if (!visited[nb[i]]) {
                    queue.push(nb[i]);
                    visited[nb[i]] = true;
                }
                dist[nb[i]] = std::min(dist[front] + graph.getEdgeCost(front, nb[i]), dist[nb[i]]);
            }
        }

        return dist[vertex2 - 1];
    }
} // namespace s21
