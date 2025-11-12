#include "task_3.h"
#include "check_cin.h"
#include <print>
#include <string>

namespace task_3 {
    struct my_array {
        int *data;
        int size;
        int capacity;

        my_array() {
            data = nullptr;
            size = 0;
            capacity = 0;
        }

        ~my_array() {
            delete [] data;
        }

        void push_back(int element) {
            if (size >= capacity) {
                capacity = capacity == 0 ? 1 : capacity * 2;
                int *new_data = new int [capacity];

                if (data != nullptr) {
                    std::copy(data, data + size, new_data);
                    delete [] data;
                }

                data = new_data;
                new_data = nullptr;

            }

            size++;
            data[size - 1] = element;
        }

        my_array(my_array &&other_array) {
            data = other_array.data;
            size = other_array.size;
            capacity = other_array.capacity;

            other_array.data = nullptr;
        }

        my_array(const my_array &) = delete;
        my_array & operator=(my_array &&) = delete;
        my_array &operator=(const my_array &) = delete;
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

    my_array even_diag_elements(int **A, int rows, int columns) {
        int max_size = rows > columns ? columns : rows;
        my_array res;

        for (unsigned row = 0; row < max_size; row++) {
            if (!(A[row][row] % 2)) {
                res.push_back(A[row][row]);
            }
        }

        return res;
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

        my_array even_diag_A_comp = even_diag_elements(A, rows, columns);

        print_default_arr(even_diag_A_comp.data, even_diag_A_comp.size);

        std::println("Произведение: {}", product_of_arr_elements(even_diag_A_comp.data, even_diag_A_comp.size));

        for (unsigned row = 0; row < rows; row++) {
            delete [] A[row];
        }

        delete [] A;
        A = nullptr;
    }
}
