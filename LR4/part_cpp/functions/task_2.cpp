#include <iostream>
#include <random>

#include "task_2.h"

namespace t2 {
    void do_task_2() {
        std::random_device my_rand;
        std::mt19937 range(my_rand());
        std::uniform_int_distribution<std::mt19937::result_type> dist(1, 9);

        int arr[5][4];
        int min_columns[4];

        for (unsigned i = 0; i < 5; i++) {
            for (unsigned j = 0; j < 4; j++) {
                arr[i][j] = dist(range);
            }
        }

        for (unsigned i = 0; i < 4; i++) {
            int value = arr[0][i];

            for (unsigned j = 1; j < 5; j++) {
                if (value > arr[j][i]) {
                    value = arr[j][i];
                }
            }

            min_columns[i] = value;
        }

        for (unsigned i = 0; i < 5; i++) {
            for (unsigned j = 0; j < 4; j++) {
                std::cout << arr[i][j] << " ";
            }

            std::cout << std::endl;
        }

        for (unsigned i = 0; i < 4; i++) {
            std::cout << "В столбце " << i + 1 << " минимальный элемент: " << min_columns[i] << std::endl;
        }

        return;
    }
}
