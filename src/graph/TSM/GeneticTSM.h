#ifndef _GENETICTSM_H_
#define _GENETICTSM_H_

#include <random>

#include "TravelingSalesman.h"

namespace s21 {
    class GeneticTSM : public TravelingSalesman {
       public:
        TsmResult solve(const Graph& graph) override;
    
       private:
        void initPopulation(std::vector<TsmResult>& population, const Graph& graph);

        TsmResult generateRandomRoute();
        void calculateFitness(TsmResult& individ, const Graph& graph);
        void mutate(TsmResult& individ);

        size_t vertices_;
        std::mt19937 generator_;
    };

    namespace constants {
        constexpr int    MAX_GENERATIONS = 200;
        constexpr size_t POPULATION_SIZE = 30;
        constexpr double MUTATION_RATE   = 0.1;
        constexpr double ACCEPT_RATE     = 0.05;
    }
}

#endif  // _GENETICTSM_H_

