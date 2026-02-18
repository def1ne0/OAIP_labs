#include <print>
#include <set>

#include "task_4.h"
#include "check_cin.h"

namespace task_4 {
    double **create_arr(int rows, int columns) {
        double **arr = new double *[rows];

        for (int row = 0; row < rows; row++) {
            arr[row] = new double [columns];

            for (int col = 0; col < columns; col++) {
                arr[row][col] = row * col - row + col;
            }
        }

        return arr;
    }

    std::multiset<std::pair<int, int>> find_zeroes(double **arr, int rows, int columns) {
        const double EPS = 1e-9;
        std::multiset<std::pair<int, int>> res;

        for (unsigned row = 0; row < rows; row++) {
            for (unsigned col = 0; col < columns; col++) {
                if (std::abs(arr[row][col]) < EPS) {
                    res.insert(std::pair(row, col));
                }
            }
        }

        return res;
    }

    void print_info_zeros(std::multiset<std::pair<int, int>> zeroes) {
        if (zeroes.size() == 0) {
            std::println("В массиве нет нулей");
        } else {
            for (const auto &item : zeroes) {
                std::println("строка: {}, колонка: {}", item.first, item.second);
            }

            std::println("Общее количество: {}", zeroes.size());
        }
    }

    void reverse_array(double **arr, int rows, int columns) {
        double **orig_arr = new double *[rows];

        for (unsigned row = 0; row < rows; row++) {
            orig_arr[row] = new double [columns];

            for (unsigned col = 0; col < columns; col++) {
                orig_arr[row][col] = arr[row][col];
            }
        }

        for (int row = rows - 1; row >= 0; row--) {
            for (int col = columns - 1; col >= 0; col--) {
                arr[rows - 1 - row][columns - 1 - col] = orig_arr[row][col];
            }
        }

        for (unsigned row = 0; row < rows; row++) {
            delete [] orig_arr[row];
        }

        delete [] orig_arr;
        orig_arr = nullptr;
    }

    void print_matrix(double **A, int rows, int columns) {
        std::println("/////////////////////////");

        for (unsigned row = 0; row < rows; row++) {
            for (unsigned col = 0; col < columns; col++) {
                std::print("{} ", A[row][col]);
            }

            std::println("");
        }

        std::println("/////////////////////////");
    }

    void do_task_4() {
        int rows = io::input_value<int>("Введите количество строк", "Ошибка", true, 1);
        int columns = io::input_value<int>("Введите количество столбцов", "Ошибка", true, 1);

        double **arr = create_arr(rows, columns);
        print_matrix(arr, rows, columns);

        std::multiset<std::pair<int, int>> zeroes = find_zeroes(arr, rows, columns);

        print_info_zeros(zeroes);
        reverse_array(arr, rows, columns);
        print_matrix(arr, rows, columns);

        for (unsigned row = 0; row < rows; row++) {
            delete [] arr[row];
        }

        delete [] arr;
        arr = nullptr;
    }
}
