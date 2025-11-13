#pragma once

namespace task_3 {
    struct my_array {
        int *data;
        int size;
        int capacity;

        my_array();

        ~my_array();

        void push_back(int element);

        my_array(my_array &&other_array);

        my_array(const my_array &) = delete;
        my_array &operator=(my_array &&) = delete;
        my_array &operator=(const my_array &) = delete;
    };

    int **input_arr(int, int);

    my_array even_diag_elements(int **, int, int);

    int product_of_arr_elements(int *, int size);

    void print_default_arr(int *, int);

    void print_matrix(int **, int, int);

    void do_task_3();
}
