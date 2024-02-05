#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <string>
#include <vector>

namespace s21 {
    class Graph {
       public:
        void LoadGraphFromFile(const std::string& filename);
        void ExportGraphToDot(const std::string& filename);
       
    //    private:
        std::vector<std::vector<int>> adj_matrix_;
        size_t size_;
    };
}

#endif  // _GRAPH_H_
