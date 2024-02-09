#include <iostream>

#include "ConsoleInterface.h"

namespace s21 {
    void ConsoleInterface::run() {
        helloMsg();
        int option = 0;
        while (option != -1) {
            if (graph == nullptr) {
                loadGraph();
                continue;
            }
            menuMsg(option);
            decisionOption(option);
        }
        byeMsg();
    }
    
    void ConsoleInterface::helloMsg() const {
        std::cout << "Hello, this is a console interface of SimpleNavigator." << std::endl;
        std::cout << "The project about few graph algorithms." << std::endl;
        std::cout << "To use this program load graph from adjacency matrix and enter any number from menu." << std::endl;
        std::cout << "To exit enter -1." << std::endl;
    }

    void ConsoleInterface::loadGraph() {
        std::cout << "You need to load a graph from adjacency matrix." << std::endl;
        std::cout << "Please enter a path to file." << std::endl;

        std::string path;
        std::cin >> path;

        while (path != "-1") {
            try {
                auto g = std::make_unique<Graph>();
                g->LoadGraphFromFile(path);
                std::cout << "Graph loaded successfully." << std::endl;

                graph = std::move(g);
                return;
            } catch (std::exception &e) {
                std::cout << "An error occured: " << e.what() << std::endl;
                std::cout << "Please try again or enter -1 to exit." << std::endl;
                std::cin >> path;
            }
        }
        std::cout << "You denied operation of loading graph." << std::endl;
    }

    void ConsoleInterface::menuMsg(int& option) const {
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Load other graph." << std::endl;
        std::cout << "2. Export the graph to the DOT format." << std::endl;
        std::cout << "3. Depth First Search way of graph." << std::endl;
        std::cout << "4. Breadth First Search way of graph." << std::endl;
        std::cout << "5. Dijkstra's algorithm for finding shortest path." << std::endl;
        std::cout << "6. Floyd-Warshall algorithm for finding shortest paths between all combinations." << std::endl;
        std::cout << "7. Prim's algorithm for finding least spanning tree of graph." << std::endl;
        std::cout << "8. Ant-Colony algorithm for solving the Traveling Salesman Problem." << std::endl;
        std::cout << "9. <NAME> algorithm for solving the Traveling Salesman Problem." << std::endl;
        std::cout << "10. <NAME> algorithm for solving the Traveling Salesman Problem." << std::endl;
        std::cout << "11. Research between Traveling Salesman Problem solving algorithms." << std::endl;

        std::cout << "-1. Exit." << std::endl;

        std::cin >> option;
        if (option == -1) return;

        while ((option < 1 || option > 11) && option != -1) {
            std::cout << "Please enter a valid option." << std::endl;
            std::cin >> option;
        }
    }

    void ConsoleInterface::decisionOption(int& option) {
        switch (option) {
            case -1:
                return;

            case 1:
                loadGraph();
                break;
                
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
        }
    }

    void ConsoleInterface::byeMsg() const {
        std::cout << "Goodbye!" << std::endl;
    }
}