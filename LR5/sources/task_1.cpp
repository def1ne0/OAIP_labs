#include <unordered_map>
#include <print>

#include "check_cin.h"
#include "task_1.h"

namespace task_1 {
    int **create_A(int rows, int columns) {
        int **A = new int *[rows];

        for (int row = 0; row < rows; row++) {
            A[row] = new int [columns];

            for (int col = 0; col < columns; col++) {
                A[row][col] = row <= 3 ? 2 * row * col * col - 2 * col : 2 * row * col - 2;
            }
        }

        return A;
    }

    int **create_B(int **A, int rows, int columns) {
        int **B = new int *[rows];

        for (unsigned row = 0; row < rows; row++) {
            B[row] = new int [columns];

            for (unsigned col = 0; col < columns; col++) {
                B[row][col] = A[row][col] * A[row][col];
            }
        }

        return B;
    }

    std::unordered_map<int, int> sum_even(int **arr, int rows, int columns) {
        std::unordered_map<int, int> res;

        for (unsigned col = 1; col < columns; col += 2) {
            int sum = 0;

            for (unsigned row = 0; row < rows; row++) {
                sum += arr[row][col];
            }

            res.insert({col + 1, sum});
        }

        return res;
    }

    void print_arr(int **arr, int rows, int columns, std::string comments) {
        std::println("{}", comments);

        for (unsigned row = 0; row < rows; row++) {
            for (unsigned col = 0; col < columns; col++) {
                std::print("{} ", arr[row][col]);
            }

            std::println("");
        }
    }

    void print_sum(std::unordered_map<int, int> sum, std::string comments) {
        std::println("{}", comments);

        for (const auto &item : sum) {
            std::println("столбец: {}, сумма: {}", item.first, item.second);
        }
    }

    void do_task_1() {
        int rows = io::input_value<int>("Введите количество строк", "Ошибка", true, 1);
        int columns = io::input_value<int>("Введите количество столбцов", "Ошибка", true, 1);

        int **A = create_A(rows, columns);
        std::unordered_map<int, int> sum_A = sum_even(A, rows, columns);
        print_arr(A, rows, columns, "Массив А:");
        print_sum(sum_A, "Сумма элементов четных столбцов массива А");

        int **B = create_B(A, rows, columns);
        std::unordered_map<int, int> sum_B = sum_even(B, rows, columns);
        print_arr(B, rows, columns, "Массив B: ");
        print_sum(sum_B, "Сумма элементов четных столбцов массива B");

        for (unsigned row = 0; row < rows; row++) {
            delete [] A[row];
            delete [] B[row];
        }

        delete [] A;
        delete [] B;

        A = nullptr;
        B = nullptr;
    }
}
