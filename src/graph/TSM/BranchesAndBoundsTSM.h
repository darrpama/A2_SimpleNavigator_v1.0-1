#ifndef _BRANCHESANDBOUNDSTSM_H_
#define _BRANCHESANDBOUNDSTSM_H_

#include "../../containers/queue.h"
#include "TravelingSalesman.h"


namespace s21 {
class BranchesAndBoundsTSM : public TravelingSalesman {
    struct Node {
        int city_number;
        int calculated_cost;

        std::vector<int> current_path;
        std::vector<std::vector<int>> calculated_matrix;

        bool operator>(const Node &other) const {
            return calculated_cost > other.calculated_cost;
        }
    };

   public:
    using Matrix = std::vector<std::vector<int>>;
    TsmResult solve(const Graph &graph) override;

   private:
    std::vector<int> getPossibleWays(const Graph &graph, const Node& node);

    std::pair<int, Matrix> reduceMatrix(Matrix m);

    void subRow(int row_num, int value, Matrix &m);
    void subColumn(int row_num, int value, Matrix &m);

    int findMinInRow(int row_num, Matrix &m);
    int findMinInColumn(int column_num, Matrix &m);
    
    void makeInfinitiesInMatrix(Matrix &m, int from, int to, int first_city);
    bool containsZeroOrInf(Matrix m, int index, bool is_row);

    void prepareMatrix(Matrix& m);
};

}  // namespace s21

#endif  // _BRANCHESANDBOUNDSTSM_H_
