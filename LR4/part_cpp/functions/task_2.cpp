#include <iostream>
#include <random>

#include "task_2.h"

namespace t2 {
    void do_task_2() {
        std::random_device my_rand;
        std::mt19937 range(my_rand());
        std::uniform_int_distribution<std::mt19937::result_type> dist(1, 9);

        int m = dist(range);
        int n = dist(range);


        std::cout << m << std::endl;
        std::cout << n << std::endl;
        int arr[m][n];
        int min_columns[n];

        for (unsigned i = 0; i < m; i++) {
            for (unsigned j = 0; j < n; j++) {
                arr[i][j] = dist(range);
            }
        }

        for (unsigned i = 0; i < n; i++) {
            int value = arr[0][i];
            
            for (unsigned j = 1; j < m; j++) {
                if (value > arr[j][i]) {
                    value = arr[j][i]; 
                }
            }

            min_columns[i] = value;
        }  
        
        for (unsigned i = 0; i < m; i++) {
            for (unsigned j = 0; j < n; j++) {
                std::cout << arr[i][j] << " ";
            }

            std::cout << std::endl;
        }

        for (unsigned i = 0; i < n; i++) {
            std::cout << "В столбце " << i + 1 << " минимальный элемент: " << min_columns[i] << std::endl;
        }
    }
}