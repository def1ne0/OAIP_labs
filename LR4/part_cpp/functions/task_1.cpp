#include <iostream>

#include "check_cin_func.h"
#include "task_1.h"

namespace t1 {
    void do_task_1() {
        int inversions = 0;

        int k = io::input_value<int>(
            "Введите количество элементов массива k (минимум 2)", 
            "Ошибка, попробуйте снова", 
            true, 
            2
        );

        int arr[k];

        for (unsigned i = 0; i < k; i++) {
            arr[i] = io::input_value<int>("Введите элемент массива с индексом " + std::to_string(i));
        }

        for (unsigned i = 0; i < k - 1; i++) {
            for (unsigned j = i + 1; j < k; j++) {
                if (arr[i] > arr[j]) {
                    inversions++;
                }
            }
        }

        std::cout << "Число инверсий: " << inversions << std::endl;
    }
}