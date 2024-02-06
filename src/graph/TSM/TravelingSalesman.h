#ifndef _TRAVELINGSALESMAN_H_
#define _TRAVELINGSALESMAN_H_

#include <vector>
#include "../s21_graph.h"

namespace s21 {
    class TravelingSalesman {
       public:
        struct TsmResult {
            std::vector<int> vertices;
            double distance;  
        };

        virtual TsmResult solve(const Graph& graph) = 0; 
    };
}

#endif  // _TRAVELINGSALESMAN_H_
