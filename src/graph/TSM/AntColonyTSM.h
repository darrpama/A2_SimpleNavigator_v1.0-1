#ifndef _ANTCOLONYTSM_H_
#define _ANTCOLONYTSM_H_

#include "TravelingSalesman.h"

namespace s21 {
    class AntColonyTSM : public TravelingSalesman {
       public:
        using Matrix = std::vector<std::vector<double>>;

        TsmResult solve(const Graph& graph) override;

       private:
        void initPheromones(const Graph&, Matrix&);
        void evaporatePheromones(const Graph&, Matrix&);
        void updatePheromones(const Graph&, Matrix&, const std::vector<int>&, double);

        TsmResult runAnts(const Graph&, Matrix&);
        size_t selectNextWay(const Graph&, Matrix&, size_t, const std::vector<int>&);
        size_t getProbabilityMatch(const std::vector<double>&);
        void filterWays(std::vector<int>&, const std::vector<int>&);
    };

    namespace constant {
        constexpr double ALPHA = 1.0;
        constexpr double BETA = 1.0;
        constexpr double EVAPORATION_COEF = 0.64;
        constexpr double Q = 100.0;
        constexpr double DEFAULT_PHEROMONE = 0.5;
        constexpr size_t ITERATIONS_COUNT = 100;
    }
} // namespace s21

#endif  // _ANTCOLONYTSM_H_
