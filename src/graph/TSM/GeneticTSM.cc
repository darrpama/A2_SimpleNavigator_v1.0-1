#include "GeneticTSM.h"

#include <algorithm>

namespace s21 {
TravelingSalesman::TsmResult GeneticTSM::solve(const Graph &graph) {
  std::random_device rd;
  generator_ = std::mt19937(rd());
  vertices_ = graph.size();

  std::vector<TsmResult> population;
  initPopulation(population, graph);

  TsmResult best_tsm;

  for (int generation = 0; generation < constants::MAX_GENERATIONS;
       generation++) {
    std::vector<TsmResult> new_population;

    for (size_t parent = 0; parent < constants::POPULATION_SIZE; parent++) {
      while (true) {
        TsmResult child = population[parent];

        mutate(child);
        calculateFitness(child, graph);

        if (child.distance < population[parent].distance) {
          new_population.push_back(child);

          if (best_tsm.distance > child.distance) {
            best_tsm = child;
          }

          break;

        } else {
          std::uniform_real_distribution<double> dist(0, 1);

          if (dist(generator_) < constants::ACCEPT_RATE) {
            new_population.push_back(child);
            break;
          }
        }
      }
    }

    population = new_population;
  }

  best_tsm.vertices.push_back(best_tsm.vertices.front());

  return best_tsm;
}

void GeneticTSM::initPopulation(std::vector<TsmResult> &population,
                                const Graph &graph) {
  population.resize(constants::POPULATION_SIZE);

  for (size_t i = 0; i < constants::POPULATION_SIZE; i++) {
    population[i] = generateRandomRoute();
    calculateFitness(population[i], graph);
  }
}

TravelingSalesman::TsmResult GeneticTSM::generateRandomRoute() {
  TsmResult route;
  route.distance = 0;
  route.vertices.resize(vertices_);

  for (size_t i = 0; i < vertices_; i++) {
    route.vertices[i] = i + 1;
  }

  std::shuffle(route.vertices.begin(), route.vertices.end(), generator_);

  return route;
}

void GeneticTSM::calculateFitness(TsmResult &individ, const Graph &graph) {
  individ.distance = 0;
  for (size_t i = 0; i < individ.vertices.size() - 1; i++) {
    individ.distance +=
        graph.getEdgeCost(individ.vertices[i], individ.vertices[i + 1]);
  }

  individ.distance +=
      graph.getEdgeCost(individ.vertices.back(), individ.vertices.front());
}

void GeneticTSM::mutate(TsmResult &individ) {
  std::uniform_real_distribution<double> dist(0, 1);
  std::uniform_int_distribution<int> int_dist(0, vertices_ - 1);

  for (size_t i = 0; i < vertices_; i++) {
    if (dist(generator_) < constants::MUTATION_RATE) {
      std::swap(individ.vertices[i], individ.vertices[int_dist(generator_)]);
    }
  }
}
}  // namespace s21
