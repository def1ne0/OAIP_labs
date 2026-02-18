#include <print>

#include "task_2.h"

namespace task_2 {
    int find_x_sum(int *arr, int size, int start, int end) {
        if (size == 0) return 0;

        if (start == end) {
            return arr[start - 1] * arr[start - 1];
        } else if (start + 1 == end) {
            return arr[start - 1] * arr[start - 1] + arr[start] * arr[start];
        } else {
            return arr[start - 1] * arr[start - 1] + find_x_sum(arr, size, start + 1, end);
        }
    }

    void do_task_2() {
        int arr[6] = {1, 2, 3, 4, 5, 6};

        std::println("Сумма квадратов для 1/3: {}", find_x_sum(arr, 6, 1, 2));
        std::println("Сумма квадратов для оставшейся 2/3: {}", find_x_sum(arr, 6, 3, 6));
    }
}
