#include <algorithm>
#include <cmath>
#include <random>

#include "AntColonyTSM.h"

namespace s21 {
    TravelingSalesman::TsmResult AntColonyTSM::solve(const Graph& graph) {
        Matrix pheromones(graph.size(), std::vector<double>(graph.size()));
        initPheromones(graph, pheromones);

        TsmResult result;
        for (size_t i = 0; i < constant::ITERATIONS_COUNT; ++i) {
            evaporatePheromones(graph, pheromones);
            TsmResult tmp_res = runAnts(graph, pheromones);
            
            if (result.distance > tmp_res.distance) {
                result = tmp_res;
            }
        }

        return result;
    }

    void AntColonyTSM::initPheromones(const Graph& graph, Matrix& pheromones) {
        for (size_t i = 0; i < pheromones.size(); ++i) {
            for (size_t j = 0; j < pheromones.size(); ++j) {
                if (graph.IsWayExists(i + 1, j + 1))
                    pheromones[i][j] = constant::DEFAULT_PHEROMONE;
            }
        }
    }
    
    void AntColonyTSM::evaporatePheromones(const Graph &graph, Matrix &pheromones) {
        for (size_t i = 0; i < pheromones.size(); ++i) {
            for (size_t j = 0; j < pheromones.size(); ++j) {
                if (graph.IsWayExists(i + 1, j + 1))
                    pheromones[i][j] *= constant::EVAPORATION_COEF;
            }
        }
    }

    void AntColonyTSM::updatePheromones(const Graph &graph, Matrix &pheromones, const std::vector<int> &visited, double way_length) {
        for (size_t i = 0; i < visited.size() - 1; ++i) {
            pheromones[visited[i] - 1][visited[i + 1] - 1] += constant::Q / graph.size() / way_length;
            pheromones[visited[i + 1] - 1][visited[i] - 1] += constant::Q / graph.size() / way_length;
        }
    }

    TravelingSalesman::TsmResult AntColonyTSM::runAnts(const Graph &graph, Matrix &pheromones) {
        TsmResult result;

        for (size_t ant = 0; ant < graph.size(); ++ant) {
            size_t current_pos = ant;
            std::vector<int> visited;
            visited.push_back(current_pos + 1);

            auto possible_ways = graph.getNeighbors(current_pos + 1);
            double way_length = 0;

            while (possible_ways.size() != 0) {
                current_pos = selectNextWay(graph, pheromones, current_pos, possible_ways);
                way_length += graph.getEdgeCost(visited.back(), current_pos + 1);
                visited.push_back(current_pos + 1);

                possible_ways = graph.getNeighbors(current_pos + 1);
                filterWays(possible_ways, visited);
            }

            if (graph.IsWayExists(visited.back(), visited.front())) {
                way_length += graph.getEdgeCost(visited.back(), visited.front());
                visited.push_back(visited.front());
            }

            evaporatePheromones(graph, pheromones);
            updatePheromones(graph, pheromones, visited, way_length);

            if (visited.size() == graph.size() + 1 && result.distance > way_length) {
                result.distance = way_length;
                result.vertices = visited;
            }
        }

        return result;
    }

    size_t AntColonyTSM::selectNextWay(const Graph &graph, Matrix &pheromones, size_t current_pos, const std::vector<int> &possible_ways) {
        double sum = 0;
        for (auto way : possible_ways) {
            sum += std::pow(pheromones[current_pos][way - 1], constant::ALPHA) *
                   std::pow(1.0 / graph.getEdgeCost(current_pos + 1, way), constant::BETA);
        }

        std::vector<double> probabilities(possible_ways.size(), 0);
        for (size_t i = 0; i < possible_ways.size(); ++i) {
            probabilities[i] = std::pow(pheromones[current_pos][possible_ways[i] - 1], constant::ALPHA) *
                               std::pow(1.0 / graph.getEdgeCost(current_pos + 1, possible_ways[i]), constant::BETA) /
                               sum;
        }

        return possible_ways[getProbabilityMatch(probabilities)] - 1;
    }
    
    size_t AntColonyTSM::getProbabilityMatch(const std::vector<double> &probabilities) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(0, 1);

        double sum = 0, choice = dis(gen);
        size_t selected_pos = -1;

        for (size_t i = 0; i < probabilities.size(); ++i) {
            sum += probabilities[i];

            if (sum >= choice) {
                selected_pos = i;
                break;
            }
        }

        return selected_pos;
    }

    void AntColonyTSM::filterWays(std::vector<int> &possible_ways, const std::vector<int> &visited) {
        size_t erased = 0;
        for (auto it = visited.begin(); it != visited.end(); ++it) {
            if (std::binary_search(possible_ways.begin(), possible_ways.end(), *it)) {
                std::remove(possible_ways.begin(), possible_ways.end(), *it);
                erased++;
            }
        }

        possible_ways.erase(possible_ways.end() - erased, possible_ways.end());
    }
}
