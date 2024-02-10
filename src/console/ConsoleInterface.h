#ifndef _CONSOLEINTERFACE_H_
#define _CONSOLEINTERFACE_H_

#include <memory>
#include "../graph/s21_graph.h"

namespace s21 {
    class ConsoleInterface {
       public:
        void run();

        virtual void helloMsg() const;
        virtual void menuMsg();
        virtual void decisionOption();
        virtual void byeMsg() const;

       protected:
        std::unique_ptr<Graph> graph_;
    
       private:
        enum class InterfaceOption {
            EXIT = -1,
            MENU = 0,
            LOAD_GRAPH = 1,
            EXPORT_GRAPH = 2,
            DFS = 3,
            BFS = 4,
            DIJKSTRA = 5,
            FLOYD_WARSHALL = 6,
            PRIM = 7,
            ANT_COLONY = 8,
            TSM2 = 9,
            TSM3 = 10,
            TSM_RESEARCH = 11
        } option_;
        
        void loadGraph();
        void exportGraph();
        void dfs();
        void bfs();
        void dijkstra();
        void floydWarshall();
        void prim();
        void antColony();
        // void tsm2();
        // void tsm3();
        // void tsmResearch();

        int readVertex();
        void printWay(const std::vector<int> &way);
        void printAdjacencyMatrix(const std::vector<std::vector<int>> &matrix);
        void wait();
    };
} // namespace s21


#endif  // _CONSOLEINTERFACE_H_
