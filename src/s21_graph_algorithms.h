#ifndef _S21_GRAPH_ALGORITHMS_H_
#define _S21_GRAPH_ALGORITHMS_H_

#include <vector>
#include "s21_graph.h"

namespace s21 {
    class GraphAlgorithms {
       public:
        static std::vector<int> DepthFirstSearch(const Graph& graph, int start_vertex);
        static std::vector<int> BreadthFirstSearch(const Graph& graph, int start_vertex);
    };
} // namespace s21


#endif  // _S21_GRAPH_ALGORITHMS_H_
