#ifndef _CONSOLEINTERFACE_H_
#define _CONSOLEINTERFACE_H_

#include <memory>
#include "../graph/s21_graph.h"

namespace s21 {
    class ConsoleInterface {
       public:
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
        };

        void run();

        virtual void helloMsg() const;
        
        virtual void menuMsg();
        virtual void decisionOption();
        
        virtual void loadGraph();
        virtual void exportGraph();
        virtual void dfs();
        virtual void bfs();
        // virtual void dijkstra();
        // virtual void floydWarshall();
        // virtual void prim();
        // virtual void antColony();

        // virtual void tsm2();
        // virtual void tsm3();
        // virtual void tsmResearch();

        virtual void byeMsg() const;

       protected:
        std::unique_ptr<Graph> graph_;
        InterfaceOption option_;
    
       private:
        int readVertex();
        void printWay(std::vector<int> &way);
        void wait();
    };
} // namespace s21


#endif  // _CONSOLEINTERFACE_H_
