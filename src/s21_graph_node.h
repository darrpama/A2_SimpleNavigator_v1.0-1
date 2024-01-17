#ifndef _GRAPHNODE_H_
#define _GRAPHNODE_H_

#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace s21 {
    struct GraphNode {
        std::unordered_map<GraphNode*, int> neighbors_values;
        std::unordered_set<GraphNode*> neighbors;
    };
}

#endif  // _GRAPHNODE_H_
