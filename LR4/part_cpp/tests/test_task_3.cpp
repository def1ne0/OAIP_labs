#include <iostream>
#include <iostream>
#include <gtest/gtest.h>

double **create_arr(int n) {
    double **arr = new double *[n];

    for (unsigned row = 0; row < n; row++) {
        arr[row] = new double [n];
    }

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            arr[i][j] = static_cast<int>(-i + j + i*j);
        }
    }

    return arr;
}

std::string print_result(int **arr, int n) {
    std::string result = "|";

    for (unsigned row = 0; row < n; row++) {
        for (unsigned col = 0; col < n; col++) {
            if (col == n - 1) {
                result += std::to_string(arr[row][col]);
            } else {
                result += std::to_string(arr[row][col]) + " ";
            }
        }
        result += "|";
    }

    return result;
}

int **new_arr(double **arr, int n) {
    int **new_arr = new int *[n];

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

TEST(task_3, check_new_matrix) {
    int n = 3;
    double **arr = create_arr(n); //|0.000000 1.000000 2.000000|-1.000000 1.000000 3.000000|-2.000000 1.000000 4.000000|

    int** new_array = new_arr(arr, n);

    EXPECT_EQ(print_result(new_array, n), "|0 1 1|0 0 1|0 0 0|");

    for (unsigned row = 0; row < n; row++) {
        delete[] arr[row];
        delete[] new_array[row];
    }

    delete[] arr;
    delete[] new_array;

    arr = nullptr;
    new_array = nullptr;

    return;
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}