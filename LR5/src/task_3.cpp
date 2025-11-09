#include "task_3.h"
#include "check_cin.h"
#include <print>
#include <string>

namespace task_3 {
    struct some_array {
        int *arr;
        int size;

        some_array(int *other_arr, int other_size) {
            arr = other_arr;
            size = other_size;
        }

        ~some_array() {
            delete [] arr;
            arr = nullptr;
        }

        some_array(some_array &&other_array) {
            arr = other_array.arr;
            size = other_array.size;

            other_array.arr = nullptr;
        }

        some_array(const some_array &) = delete;
        some_array &operator=(const some_array &) = delete;
    };

    int **input_arr(int rows, int columns) {
        int **A = new int *[rows];

        for (unsigned row = 0; row < rows; row++) {
            A[row] = new int [columns];

            for (unsigned col = 0; col < columns; col++) {
                A[row][col] = io::input_value<int>("Введите элемент [" + std::to_string(row) + "][" + std::to_string(col) + "]");
            }
        }

        return A;
    }

    some_array even_diag_elements(int **A, int rows, int columns) {
        int current_size = 0;
        int max_size = rows > columns ? columns : rows;
        int *max_arr = new int [max_size];

        for (unsigned row = 0; row < max_size; row++) {
            if (!(A[row][row] % 2)) {
                max_arr[current_size] = A[row][row];
                current_size++;
            }
        }

        int *res = new int [current_size];
        std::copy(max_arr, max_arr + current_size, res);

        some_array arr_components(res, current_size);

        delete [] max_arr;
        max_arr = nullptr;

        return arr_components;
    }

    int product_of_arr_elements(int *arr, int size) {
        if (size == 0) return 0;

        int res = 1;

        for (unsigned i = 0; i < size; i++) {
            res *= arr[i];
        }

        return res;
    }

    void print_default_arr(int *arr, int size) {
        for (unsigned i = 0; i < size; i++) {
            std::print("{} ", arr[i]);
        }

        std::println("");
    }

    void print_matrix(int **A, int rows, int columns) {
        std::println("/////////////////////////");

        for (unsigned row = 0; row < rows; row++) {
            for (unsigned col = 0; col < columns; col++) {
                std::print("{} ", A[row][col]);
            }

            std::println("");
        }

        std::println("/////////////////////////");
    }

    void do_task_3() {
        int rows = io::input_value<int>("Введите количество строк", "Ошибка", true, 1);
        int columns = io::input_value<int>("Введите количество столбцов", "Ошибка", true, 1);

        int **A = input_arr(rows, columns);
        print_matrix(A, rows, columns);

        some_array even_diag_A_comp = even_diag_elements(A, rows, columns);

        int *diag_elements_in_A = even_diag_A_comp.arr;
        int size_diag = even_diag_A_comp.size;

        print_default_arr(diag_elements_in_A, size_diag);

        std::println("Произведение: {}", product_of_arr_elements(diag_elements_in_A, size_diag));

        for (unsigned row = 0; row < rows; row++) {
            delete A[row];
        }

        delete [] A;
        A = nullptr;
    }
}
