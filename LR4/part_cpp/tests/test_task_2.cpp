#include <iostream>
#include <random>
#include <memory>
#include <gtest/gtest.h>

template <unsigned M, unsigned N>
int *get_minimum_columns(int arr[M][N]) {
    int *min_columns = new int [N];

    for (unsigned i = 0; i < N; i++) {
        int value = arr[0][i];
        
        for (unsigned j = 1; j < M; j++) {
            if (value > arr[j][i]) {
                value = arr[j][i]; 
            }
        }

        min_columns[i] = value;
    }  

    return min_columns;
}

std::string print_result(int *arr, int n) {
    std::string result = "";

    for (unsigned i = 0; i < n; i++) {
        if (i == n - 1) {
            result += std::to_string(arr[i]);
        } else {
            result += std::to_string(arr[i]) + " ";
        }
    }

    return result;
}

TEST(task_2, check_minimum_columns) {
    const unsigned m = 2;
    const unsigned n = 3;

    int arr[m][n];

    for (unsigned i = 0; i < m; i++) {
        for (unsigned j = 0; j < n; j++) {
            arr[i][j] = i - j + i*j;
        }
    }

    /*[ 0  -1  -2 ]
      [ 1   1   1 ]*/
    
    int *min_columns = get_minimum_columns<m, n>(arr);

    EXPECT_EQ(print_result(min_columns, n), "0 -1 -2");

    delete []min_columns;
    min_columns = nullptr;
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}