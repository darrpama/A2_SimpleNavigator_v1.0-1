#ifndef _S21_GRAPH_ALGORITHMS_H_
#define _S21_GRAPH_ALGORITHMS_H_

#include <vector>
#include "s21_graph.h"

namespace s21 {
    class GraphAlgorithms {
       public:
        static std::vector<int> DepthFirstSearch(const Graph& graph, int start_vertex);
        static std::vector<int> BreadthFirstSearch(const Graph& graph, int start_vertex);

        static int GetShortestPathBetweenVertices(const Graph& graph, int vertex1, int vertex2);
        static std::vector<std::vector<int>> GetShortestPathsBetweenAllVertices(const Graph &graph);
        
        static std::vector<std::vector<int>> GetLeastSpanningTree(const Graph& graph);
    };
} // namespace s21


#endif  // _S21_GRAPH_ALGORITHMS_H_
