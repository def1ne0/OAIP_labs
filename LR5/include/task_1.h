#pragma once

#include <string>
#include <unordered_map>

namespace task_1 {
    int **create_A(int, int);

    int **create_B(int **, int, int);

    std::unordered_map<int, int> sum_even(int **, int, int);

    void print_arr(int **, int, int, std::string);

    void print_sum(std::unordered_map<int, int>, std::string);

    void do_task_1();
}
