#include <gtest/gtest.h>

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
    my_array &operator=(my_array &&) = delete;
    my_array &operator=(const my_array &) = delete;
};

int **create_arr(int rows, int columns) {
    int **A = new int *[rows];
    int idx = 1;

    for (int row = 0; row < rows; row++) {
        A[row] = new int [columns];

        for (int col = 0; col < columns; col++) {
            A[row][col] = idx;
            idx++;
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

std::string print_arr(int **arr, int rows, int columns) {
    std::string res = "{ | ";

    for (unsigned row = 0; row < rows; row++) {
        for (unsigned col = 0; col < columns; col++) {
            res +=  std::to_string(arr[row][col]) + " ";
        }

        res += "| ";
    }

    res += "}";

    return res;
}

std::string print_deault_arr(int *arr, int size) {
    std::string res = "{ ";

    for (unsigned i = 0; i < size; i++) {
        res += std::to_string(arr[i]) + " ";
    }

    res += "}";

    return res;
}

TEST(task_3, CheckGeneralInput) {
    int rows = 3;
    int columns = 2;

    int **A = create_arr(rows, columns);

    my_array even_diag_A_comp = even_diag_elements(A, rows, columns);

    EXPECT_EQ("{ | 1 2 | 3 4 | 5 6 | }", print_arr(A, rows, columns));
    EXPECT_EQ("{ 4 }", print_deault_arr(even_diag_A_comp.data, even_diag_A_comp.size));
    EXPECT_EQ(4, product_of_arr_elements(even_diag_A_comp.data, even_diag_A_comp.size));

    for (unsigned row = 0; row < rows; row++) {
        delete [] A[row];
    }

    delete [] A;
    A = nullptr;
}

TEST(task_3, MinSize) {
    int rows = 1;
    int columns = 1;

    int **A = create_arr(rows, columns);

    my_array even_diag_A_comp = even_diag_elements(A, rows, columns);

    EXPECT_EQ("{ | 1 | }", print_arr(A, rows, columns));
    EXPECT_EQ("{ }", print_deault_arr(even_diag_A_comp.data, even_diag_A_comp.size));
    EXPECT_EQ(0, product_of_arr_elements(even_diag_A_comp.data, even_diag_A_comp.size));

    for (unsigned row = 0; row < rows; row++) {
        delete [] A[row];
    }

    delete [] A;
    A = nullptr;
}

TEST(task_3, OneRowTwoColumns) {
    int rows = 1;
    int columns = 2;

    int **A = create_arr(rows, columns);

    my_array even_diag_A_comp = even_diag_elements(A, rows, columns);

    EXPECT_EQ("{ | 1 2 | }", print_arr(A, rows, columns));
    EXPECT_EQ("{ }", print_deault_arr(even_diag_A_comp.data, even_diag_A_comp.size));
    EXPECT_EQ(0, product_of_arr_elements(even_diag_A_comp.data, even_diag_A_comp.size));

    for (unsigned row = 0; row < rows; row++) {
        delete [] A[row];
    }

    delete [] A;
    A = nullptr;
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
