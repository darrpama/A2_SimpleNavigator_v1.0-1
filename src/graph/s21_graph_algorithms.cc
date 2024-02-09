#include <stdexcept>
#include <limits>
#include <set>
#include <stack> // replace
#include <queue> // replace

#include "TSM/AntColonyTSM.h"
#include "s21_graph_algorithms.h"

namespace s21 {
    std::vector<int> GraphAlgorithms::DepthFirstSearch(const Graph &graph, int start_vertex) {
        if (graph.size() == 0) return {};
        CheckVertex(graph, start_vertex, "GraphAlgorithms::DepthFirstSearch(): Invalid start vertex");

        std::vector<int> result;
        std::vector<bool> visited(graph.size(), false);

        std::stack<int> stack;
        stack.push(start_vertex);
        
        while (!stack.empty()) {
            int top = stack.top() - 1;
            stack.pop();

            if (!visited[top]) {
                result.push_back(top + 1);
                visited[top] = true;
                
                auto nb = graph.getNeighbors(top + 1);
                for (int i = static_cast<int>(nb.size()) - 1; i >= 0; i--) {
                    if (!visited[nb[i] - 1])
                        stack.push(nb[i]);
                }
            }
        }

        return result;
    }
    
    std::vector<int> GraphAlgorithms::BreadthFirstSearch(const Graph &graph, int start_vertex) {
        if (graph.size() == 0) return {};
        CheckVertex(graph, start_vertex, "GraphAlgorithms::BreadthFirstSearch(): Invalid start vertex");
        
        std::vector<int> result;
        std::vector<bool> visited(graph.size(), false);

        std::queue<int> queue;
        queue.push(start_vertex);
        result.push_back(start_vertex);

        while (!queue.empty()) {
            int front = queue.front() - 1;
            queue.pop();

            visited[front] = true;
            auto nb = graph.getNeighbors(front + 1);

            for (int i = 0; i < static_cast<int>(nb.size()); i++) {
                if (!visited[nb[i] - 1]) {
                    queue.push(nb[i]);
                    visited[nb[i] - 1] = true;

                    result.push_back(nb[i]);
                }
            }
        }
        
        return result;
    }
    
    int GraphAlgorithms::GetShortestPathBetweenVertices(const Graph &graph, int vertex1, int vertex2) {
        if (graph.size() == 0) return 0;
        
        CheckVertex(graph, vertex1, "GraphAlgorithms::GetShortestPathBetweenVertices(): Invalid vertex1.");
        CheckVertex(graph, vertex2, "GraphAlgorithms::GetShortestPathBetweenVertices(): Invalid vertex2.");
        
        std::vector<int> dist(graph.size(), std::numeric_limits<int>::max());
        std::vector<bool> visited(graph.size(), false);
        dist[vertex1 - 1] = 0;

        std::queue<int> queue;
        queue.push(vertex1);
        
        while (!queue.empty()) {
            int front = queue.front() - 1;
            queue.pop();

            visited[front] = true;
            auto nb = graph.getNeighbors(front + 1);

            for (int i = 0; i < static_cast<int>(nb.size()); i++) {
                if (!visited[nb[i] - 1]) {
                    queue.push(nb[i]);
                    visited[nb[i] - 1] = true;
                }
                dist[nb[i] - 1] = std::min(dist[front] + graph.getEdgeCost(front + 1, nb[i]), dist[nb[i] - 1]);
            }
        }

        return dist[vertex2 - 1];
    }
    
    std::vector<std::vector<int>> GraphAlgorithms::GetShortestPathsBetweenAllVertices(const Graph &graph) {
        std::vector<std::vector<int>> dist(graph.size(), std::vector<int>(graph.size(), 0));

        for (size_t u = 0; u < graph.size(); u++) {
            for (size_t v = 0; v < graph.size(); v++) {
                int cost = graph.getEdgeCost(u + 1, v + 1);
                dist[u][v] = cost == 0 ? 1e9 : cost;
            }
        }

        for (size_t v = 0; v < graph.size(); v++) {
            dist[v][v] = graph.getEdgeCost(v + 1, v + 1);
        }

        for (size_t k = 0; k < graph.size(); k++) {
            for (size_t i = 0; i < graph.size(); i++) {
                for (size_t j = 0; j < graph.size(); j++) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        return dist;
    }
    
    std::vector<std::vector<int>> GraphAlgorithms::GetLeastSpanningTree(const Graph &graph) {
        std::vector<std::vector<int>> forest(graph.size(), std::vector<int>(graph.size(), 0));
        
        std::vector<int> parent(graph.size(), -1);
        std::vector<int> cheapest(graph.size(), 1e9);
        cheapest[0] = 0;

        std::set<std::pair<int, int>> edges;
        edges.insert({0, 0});

        for (size_t k = 0; k < graph.size(); k++) {
            if (edges.empty())
                return {};

            int cost = edges.begin()->first;
            int v = edges.begin()->second;
            edges.erase(edges.begin());

            if (parent[v] != -1) {
                forest[parent[v]][v] = cost;
                forest[v][parent[v]] = cost;
            }

            auto nb = graph.getNeighbors(v + 1);
            for (int i = 0; i < static_cast<int>(nb.size()); i++) {
                int to = nb[i] - 1;
                cost = graph.getEdgeCost(v + 1, to + 1);

                if (cost < cheapest[to]) {
                    edges.erase({cheapest[to], to});
                    cheapest[to] = cost;
                    parent[to] = v;
                    edges.insert({cheapest[to], to});
                }
            }
        }

        return forest;
    }
    
    TravelingSalesman::TsmResult GraphAlgorithms::SolveTravelingSalesmanProblem(const Graph &graph) {
        AntColonyTSM tsm;
        
        return tsm.solve(graph);
    }
    
    void GraphAlgorithms::CheckVertex(const Graph &graph, int vertex, const std::string& msg) {
        if (!graph.IsVertexExist(vertex)) {
            throw std::invalid_argument(msg);
        }
    }
} // namespace s21
