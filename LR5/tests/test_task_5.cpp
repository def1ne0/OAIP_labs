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

    std::string print_my_array() {
        std::string res = "{ ";

        for (unsigned i = 0; i < size; i++) {
            res += std::to_string(data[i]) + " ";
        }

        res += "}";

        return res;
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
    int **arr = new int *[rows];
    int idx = 1;

    for (unsigned row = 0; row < rows; row++) {
        arr[row] = new int [columns];

        for (unsigned col = 0; col < columns; col++) {
            arr[row][col] = idx;
            idx++;
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

TEST(task_5, CheckGeneralInput) {
    int rows = 3;
    int columns = 2;

    int **arr = create_arr(rows, columns); // 1 2 | 3 4 | 5 6
    double average_of_arr = average(arr, rows, columns);

    my_array odd_elements_in_even_columns = find_odd_elements_in_even_columns(arr, rows, columns);

    EXPECT_DOUBLE_EQ(3.5L, average(arr, rows, columns));
    EXPECT_EQ("{ }", odd_elements_in_even_columns.print_my_array());

    for (unsigned row = 0; row < rows; row++) {
        delete [] arr[row];
    }

    delete [] arr;
    arr = nullptr;
}

TEST(task_5, MinSize) {
    int rows = 1;
    int columns = 1;

    int **arr = create_arr(rows, columns); // 1
    double average_of_arr = average(arr, rows, columns);

    my_array odd_elements_in_even_columns = find_odd_elements_in_even_columns(arr, rows, columns);

    EXPECT_DOUBLE_EQ(1L, average(arr, rows, columns));
    EXPECT_EQ("{ }", odd_elements_in_even_columns.print_my_array());

    for (unsigned row = 0; row < rows; row++) {
        delete [] arr[row];
    }

    delete [] arr;
    arr = nullptr;
}

TEST(task_5, OneRowFourColumns) {
    int rows = 2;
    int columns = 3;

    int **arr = create_arr(rows, columns); // 1 2 3 | 4 5 6
    double average_of_arr = average(arr, rows, columns);

    my_array odd_elements_in_even_columns = find_odd_elements_in_even_columns(arr, rows, columns);

    EXPECT_DOUBLE_EQ(3.5L, average(arr, rows, columns));
    EXPECT_EQ("{ 5 }", odd_elements_in_even_columns.print_my_array());

    for (unsigned row = 0; row < rows; row++) {
        delete [] arr[row];
    }

    delete [] arr;
    arr = nullptr;
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
