#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string>
#include "s21_graph_node.h"

namespace s21 {
    class Graph {
       public:
        void LoadGraphFromFile(const std::string& filename);
        void ExportGraphToDot(const std::string& filename);
       
    //    private:
        std::vector<GraphNode*> nodes_;
        size_t size_;
    };
}

#endif  // _GRAPH_H_
