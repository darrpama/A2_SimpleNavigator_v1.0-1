#include <limits>
#include <iostream>

#include "../graph/s21_graph_algorithms.h"
#include "ConsoleInterface.h"

namespace s21 {
    void ConsoleInterface::run() {
        helloMsg();
        option_ = InterfaceOption::MENU;
        while (option_ != InterfaceOption::EXIT) {
            if (graph_ == nullptr) {
                loadGraph();
                continue;
            }
            menuMsg();
            decisionOption();
        }
        byeMsg();
    }
    
    void ConsoleInterface::helloMsg() const {
        std::cout << "Hello, this is a console interface of SimpleNavigator." << std::endl;
        std::cout << "The project about few graph algorithms." << std::endl;
        std::cout << "To use this program load graph from adjacency matrix and enter any number from menu." << std::endl;
        std::cout << "To exit enter -1." << std::endl;
    }

    void ConsoleInterface::menuMsg() {
        std::cout << "\nAvailable options:" << std::endl;
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

        std::cout << "Please select an option." << std::endl;
        while ((option_ < InterfaceOption::LOAD_GRAPH || option_ > InterfaceOption::TSM_RESEARCH) && option_ != InterfaceOption::EXIT) {
            int tmp_opt;
            std::cin >> tmp_opt;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid option, please enter correct value." << std::endl;
                continue;
            }

            option_ = static_cast<InterfaceOption>(tmp_opt);
        }
    }

    void ConsoleInterface::decisionOption() {
        switch (option_) {
            case InterfaceOption::EXIT:
                return;

            case InterfaceOption::MENU:
                return;

            case InterfaceOption::LOAD_GRAPH:
                loadGraph();
                break;

            case InterfaceOption::EXPORT_GRAPH:
                exportGraph();
                break;

            case InterfaceOption::DFS:
                dfs();
                break;
                
            case InterfaceOption::BFS:
                bfs();
                break;
                
            case InterfaceOption::DIJKSTRA:
                break;
                
            case InterfaceOption::FLOYD_WARSHALL:
                break;
                
            case InterfaceOption::PRIM:
                break;
                
            case InterfaceOption::ANT_COLONY:
                break;
                
            case InterfaceOption::TSM2:
                break;
                
            case InterfaceOption::TSM3:
                break;
                
            case InterfaceOption::TSM_RESEARCH:
                break;
        }
    }

    void ConsoleInterface::loadGraph() {
        std::cout << "\n[LOADING GRAPH]" << std::endl;
        std::cout << "You need to load a graph from adjacency matrix." << std::endl;
        std::cout << "Please enter a path to file." << std::endl;

        std::string path;
        std::cin >> path;

        option_ = InterfaceOption::MENU;
        while (path != std::to_string(static_cast<int>(InterfaceOption::EXIT))) {
            try {
                auto g = std::make_unique<Graph>();
                g->LoadGraphFromFile(path);
                std::cout << "[SUCCESS] Graph loaded successfully." << std::endl;

                graph_ = std::move(g);
                return;
            } catch (std::exception &e) {
                std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
                std::cout << "[FAIL] Please try again or enter -1 to exit." << std::endl;
                std::cin >> path;
            }
        }

        std::cout << "You denied operation of loading graph." << std::endl;
    }

    void ConsoleInterface::exportGraph() {
        std::cout << "\n[EXPORTING GRAPH]" << std::endl;
        std::cout << "Please enter a path to file." << std::endl;

        std::string path;
        std::cin >> path;

        try {
            graph_->ExportGraphToDot(path);
        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Graph has not been exported." << std::endl;
            return;
        }

        std::cout << "[SUCCESS] Graph exported successfully." << std::endl;
        option_ = InterfaceOption::MENU;
    }

    void ConsoleInterface::dfs() {
        std::cout << "[DEPTH FIRST SEARCH]" << std::endl;
        std::cout << "[START VERTEX] ";

        int start_vertex = readVertex();
        option_ = InterfaceOption::MENU;
        if (start_vertex == -1) return;

        try {
            auto way = s21::GraphAlgorithms::DepthFirstSearch(*graph_.get(), start_vertex);
            std::cout << "[SUCCESS] Depth first search completed successfully." << std::endl;
            std::cout << "Way of depth first search:" << std::endl;
            printWay(way);
            wait();
        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
    }

    void ConsoleInterface::bfs() {
        std::cout << "[BREADTH FIRST SEARCH]" << std::endl;
        std::cout << "[START VERTEX] ";
        
        int start_vertex = readVertex();
        option_ = InterfaceOption::MENU;
        if (start_vertex == -1) return;

        try {
            auto way = s21::GraphAlgorithms::BreadthFirstSearch(*graph_.get(), start_vertex);
            std::cout << "[SUCCESS] Breadth first search completed successfully." << std::endl;
            std::cout << "Way of breadth first search:" << std::endl;
            printWay(way);
            wait();
        } catch (std::exception &e) {
            std::cout << "[FAIL] An error occured: " << e.what() << std::endl;
            std::cout << "[FAIL] Operation denied." << std::endl;
        }
    }

    void ConsoleInterface::byeMsg() const {
        std::cout << "Goodbye!" << std::endl;
    }
    
    int ConsoleInterface::readVertex() {
        std::cout << "Please enter a vertex." << std::endl;

        int start_vertex;
        std::cin >> start_vertex;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[FAIL] Invalid vertex value, operation denied." << std::endl;

            return -1;
        }

        return start_vertex;
    }
    
    void ConsoleInterface::printWay(std::vector<int> &way) {
        for (size_t i = 0; i < graph_->size() - 1; i++) {
            std::cout << way[i] << " -> ";
        }

        std::cout << way.back() << std::endl;
    }
    
    void ConsoleInterface::wait() {
        std::cout << "Press enter to continue..." << std::endl;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        std::string line;
        std::getline(std::cin, line);
    }
}
