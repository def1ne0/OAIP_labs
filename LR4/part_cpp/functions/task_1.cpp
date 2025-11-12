#include <iostream>

#include "check_cin_func.h"
#include "task_1.h"

namespace t1 {
    int get_inversions(int arr[], int k) {
        int inversions = 0;

        for (unsigned i = 0; i < k - 1; i++) {
            for (unsigned j = i + 1; j < k; j++) {
                if (arr[i] > arr[j]) {
                    inversions++;
                }
            }
        }

        return inversions;

    }

    void do_task_1() {
        int k = 5;

        int arr[5];

        for (unsigned i = 0; i < k; i++) {
            arr[i] = io::input_value<int>("Введите элемент массива с индексом " + std::to_string(i));
        }

        std::cout << "Число инверсий: " << get_inversions(arr, k) << std::endl;

        return;
    }
}
