#include <limits>
#include <queue>
#include <algorithm>

#include "BranchesAndBoundsTSM.h"

namespace s21 {
TravelingSalesman::TsmResult BranchesAndBoundsTSM::solve(const Graph &graph) {
    Matrix mat = graph.getAdjMatrix();
    prepareMatrix(mat);
    auto initial = reduceMatrix(mat);

    Node node;
    node.city_number = 1;
    node.current_path.push_back(1);
    node.calculated_cost = initial.first;
    node.calculated_matrix = initial.second;
  
    TsmResult result;
    int problem_upper_bound = std::numeric_limits<int>::max();
  
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> candidate_queue;
    candidate_queue.push(node);

    while (!candidate_queue.empty()) {
        auto current_node = candidate_queue.top();
        candidate_queue.pop();

        if (current_node.current_path.size() == graph.size()) {
            if (current_node.calculated_cost < problem_upper_bound) {
                problem_upper_bound = current_node.calculated_cost;
                result.vertices = current_node.current_path;
                result.distance = current_node.calculated_cost;
            }

            while(!candidate_queue.empty() && candidate_queue.top().calculated_cost > problem_upper_bound) {
                candidate_queue.pop();
            }
        }

        std::vector<int> possible_ways = getPossibleWays(graph, current_node);

        for (auto way : possible_ways) {
            Node next;
            next.city_number = way;
            next.current_path = current_node.current_path;
            next.current_path.push_back(way);

            auto next_matrix = current_node.calculated_matrix;
            makeInfinitiesInMatrix(next_matrix, current_node.city_number - 1, way - 1, current_node.current_path.front() - 1);
            auto reduced = reduceMatrix(next_matrix);

            next.calculated_cost = current_node.calculated_matrix[current_node.city_number - 1][way - 1] + reduced.first + current_node.calculated_cost;
            next.calculated_matrix = reduced.second;

            candidate_queue.push(next);
        }
    }
    
    result.vertices.push_back(result.vertices.front());
    
    return result;
}

std::vector<int> BranchesAndBoundsTSM::getPossibleWays(const Graph &graph,
                                                       const Node &node) {
    std::vector<int> neighbors = graph.getNeighbors(node.city_number);
    std::vector<int> possible_ways;

    for (int i : neighbors) {
        if (std::find(node.current_path.begin(), node.current_path.end(), i) == node.current_path.end()) {
            possible_ways.push_back(i);
        }
    }

    return possible_ways;
}

std::pair<int, BranchesAndBoundsTSM::Matrix> BranchesAndBoundsTSM::reduceMatrix(
    Matrix m) {
    int rows_min_sum = 0;
    int cols_min_sum = 0;

    for (size_t i = 0; i < m.size(); i++) {
        if (!containsZeroOrInf(m, i, true)) {
            int min_in_row = findMinInRow(i, m);
            rows_min_sum += min_in_row;
            subRow(i, min_in_row, m);
        }
    }

    for (size_t i = 0; i < m.size(); i++) {
        if (!containsZeroOrInf(m, i, false)) {
            int min_in_col = findMinInColumn(i, m);
            cols_min_sum += min_in_col;
            subColumn(i, min_in_col, m);
        }
    }

    return std::make_pair(rows_min_sum + cols_min_sum, m);
}

int BranchesAndBoundsTSM::findMinInRow(int row_num, Matrix &m) {
    int min = std::numeric_limits<int>::max();

    for (size_t i = 0; i < m[row_num].size(); i++) {
        if (m[row_num][i] < min && m[row_num][i] > 0) {
            min = m[row_num][i];
        }
    }

    return min;
}

int BranchesAndBoundsTSM::findMinInColumn(int column_num, Matrix &m) {
    int min = std::numeric_limits<int>::max();

    for (size_t i = 0; i < m.size(); i++) {
        if (m[i][column_num] < min && m[i][column_num] > 0) {
            min = m[i][column_num];
        }
    }

    return min;
}

void BranchesAndBoundsTSM::subRow(int row_num, int value, Matrix &m) {
    for (size_t i = 0; i < m[row_num].size(); i++) {
        if (m[row_num][i] > 0) {
            m[row_num][i] -= value;
        }
    }
}

void BranchesAndBoundsTSM::subColumn(int column_num, int value, Matrix &m) {
    for (size_t i = 0; i < m.size(); i++) {
        if (m[i][column_num] > 0) {
            m[i][column_num] -= value;
        }
    }
}

void BranchesAndBoundsTSM::makeInfinitiesInMatrix(Matrix &m, int from, int to, int first_city) {
    for (size_t i = 0; i < m.size(); i++) {
        for (size_t j = 0; j < m[i].size(); j++) {
            if (i == (size_t)from || j == (size_t)to) {
                m[i][j] = -1;
            }
        }
    }

    m[to][from] = -1;
    m[to][first_city] = -1;
}

bool BranchesAndBoundsTSM::containsZeroOrInf(Matrix m, int index, bool is_row) {
    bool result = false;
    size_t counter = 0;

    for (size_t i = 0; i < m.size(); i++) {
        int num = is_row ? m[index][i] : m[i][index];
    
        if (num == 0) {
            return true;
        }
    
        if (num == -1) {
            counter += 1;
        }
    }

    if (counter == m.size()) {
        result = true;
    }

    return result;
}

void BranchesAndBoundsTSM::prepareMatrix(Matrix& m) {
    for (size_t i = 0; i < m.size(); i++) {
        for (size_t j = 0; j < m[i].size(); j++) {
            if (m[i][j] == 0) {
                m[i][j] = -1;
            }
        }
    }
}
}  // namespace s21
