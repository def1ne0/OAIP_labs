#include <iostream>
#include <random>

#include "task_3.h"

namespace t3 {
    double **create_arr(int n) {
        std::random_device my_rand;
        std::mt19937 range(my_rand());
        std::uniform_real_distribution<double> dist(1.0, 9.0);

        double **arr = new double *[n];

        for (unsigned row = 0; row < n; row++) {
            arr[row] = new double [n];
        }

        for (unsigned row = 0; row < n; row++) {
            for (unsigned col = 0; col < n; col++) {
                arr[row][col] = dist(range);
            }
        }

        return arr;
    }

    void print_arr(double **arr, int n) {
        for (unsigned row = 0; row < n; row++) {
            for (unsigned col = 0; col < n; col++) {
                std::cout << arr[row][col] << " ";
            }

            std::cout << std::endl;
        }
    }

    void print_arr(int **arr, int n) {
        for (unsigned row = 0; row < n; row++) {
            for (unsigned col = 0; col < n; col++) {
                std::cout << arr[row][col] << " ";
            }

            std::cout << std::endl;
        }
    }

    int **new_arr(double **arr, int n) {
        int **new_arr = new int* [n];

        for (unsigned row = 0; row < n; row++) {
            new_arr[row] = new int [n];
        }

        for (unsigned row = 0; row < n; row++) {
            for (unsigned col = 0; col < n; col++) {
                new_arr[row][col] = arr[row][col] > arr[row][row] ? 1 : 0;
            }
        }

        return new_arr;
    }

    void do_task_3() {
        int n = 5;
        double **arr = create_arr(n);

        print_arr(arr, n);

        int **new_array = new_arr(arr, n);

        std::cout << "Новая целочисленная матрица: " << std::endl;

        print_arr(new_array, n);

        for (unsigned row = 0; row < n; row++) {
            delete[] arr[row];
            delete[] new_array[row];
        }

        delete[] arr;
        delete[] new_array;

        return;
    }
}