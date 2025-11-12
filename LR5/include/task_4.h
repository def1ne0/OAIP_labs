#pragma once

#include <set>

namespace task_4 {
    double **create_arr(int, int);

    std::multiset<std::pair<int, int>> find_zeroes(double **, int, int);

    void print_info_zeros(std::multiset<std::pair<int, int>>);

    void reverse_array(double **, int, int);

    void print_matrix(double **, int, int);

    void do_task_4();
}
