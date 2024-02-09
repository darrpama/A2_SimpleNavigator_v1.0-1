#ifndef _CONSOLEINTERFACE_H_
#define _CONSOLEINTERFACE_H_

#include <memory>
#include "../graph/s21_graph.h"

namespace s21 {
    class ConsoleInterface {
       public:
        void run();

        virtual void helloMsg() const;
        
        virtual void loadGraph();
        virtual void menuMsg(int& option) const;
        virtual void decisionOption(int& option);

        virtual void byeMsg() const;

       protected:
        std::unique_ptr<Graph> graph;
    };
} // namespace s21


#endif  // _CONSOLEINTERFACE_H_
