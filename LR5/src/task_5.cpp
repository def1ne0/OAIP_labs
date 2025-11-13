#include <print>

#include "check_cin.h"
#include "task_5.h"

namespace task_5 {
    my_array::my_array() {
        data = nullptr;
        size = 0;
        capacity = 0;
    }

    my_array::~my_array() {
        delete [] data;
    }

    void my_array::push_back(int element) {
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

    my_array::my_array(my_array &&other_array) {
        data = other_array.data;
        size = other_array.size;
        capacity = other_array.capacity;

        other_array.data = nullptr;
    }

    int **input_arr(int rows, int columns) {
        int **arr = new int *[rows];

        for (unsigned row = 0; row < rows; row++) {
            arr[row] = new int [columns];

            for (unsigned col = 0; col < columns; col++) {
                arr[row][col] = io::input_value<int>("Введите элемент [" + std::to_string(row) + "][" + std::to_string(col) + "]");
            }
        }

        return arr;
    }

    my_array find_odd_elements_in_even_columns(int **arr, int rows, int columns) {
        my_array res;

        for (unsigned col = 1; col < columns; col += 2) {
            for (unsigned row = 0; row < rows; row++) {
                if (arr[row][col] % 2) {
                    res.push_back(arr[row][col]);
                }
            }
        }

        return res;
    }

    double average(int **arr, int rows, int columns) {
        double sum = 0L;

        for (unsigned row = 0; row < rows; row++) {
            for (unsigned col = 0; col < columns; col++) {
                sum += static_cast<double>(arr[row][col]);
            }
        }

        return sum / (rows * columns);
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

    void do_task_5() {
        int rows = io::input_value<int>("Введите количество строк", "Ошибка", true, 1);
        int columns = io::input_value<int>("Введите количество столбцов", "Ошибка", true, 1);

        int **arr = input_arr(rows, columns);
        double average_of_arr = average(arr, rows, columns);

        print_matrix(arr, rows, columns);
        std::println("Среднее арифметическое: {}", average_of_arr);

        my_array odd_elements_in_even_columns = find_odd_elements_in_even_columns(arr, rows, columns);

        std::println("Нечетные элементы в четных столбцах: ");
        print_default_arr(odd_elements_in_even_columns.data, odd_elements_in_even_columns.size);

        for (unsigned row = 0; row < rows; row++) {
            delete [] arr[row];
        }

        delete [] arr;
        arr = nullptr;
    }
}
