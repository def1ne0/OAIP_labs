#include <string>
#include <unordered_map>
#include <gtest/gtest.h>

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

std::string print_sum(std::unordered_map<int, int> sum) {
    std::string res = "";

    for (const auto &item : sum) {
        res += std::to_string(item.first) + ": " + std::to_string(item.second) + ";";
    }

    return res;
}

TEST(task_1, CheckGeneralInput) {
    int rows = 3;
    int columns = 2;

    int **A = create_A(rows, columns);
    std::unordered_map<int, int> sum_A = sum_even(A, rows, columns);

    int **B = create_B(A, rows, columns);
    std::unordered_map<int, int> sum_B = sum_even(B, rows, columns);

    EXPECT_EQ("{ | 0 -2 | 0 0 | 0 2 | }", print_arr(A, rows, columns));
    EXPECT_EQ("{ | 0 4 | 0 0 | 0 4 | }", print_arr(B, rows, columns));

    EXPECT_EQ("2: 0;", print_sum(sum_A));
    EXPECT_EQ("2: 8;", print_sum(sum_B));

    for (unsigned row = 0; row < rows; row++) {
        delete [] A[row];
        delete [] B[row];
    }

    delete [] A;
    delete [] B;

    A = nullptr;
    B = nullptr;
}

TEST(task_1, MinSize) {
    int rows = 1;
    int columns = 1;

    int **A = create_A(rows, columns);
    std::unordered_map<int, int> sum_A = sum_even(A, rows, columns);

    int **B = create_B(A, rows, columns);
    std::unordered_map<int, int> sum_B = sum_even(B, rows, columns);

    EXPECT_EQ("{ | 0 | }", print_arr(A, rows, columns));
    EXPECT_EQ("{ | 0 | }", print_arr(B, rows, columns));

    EXPECT_EQ("", print_sum(sum_A));
    EXPECT_EQ("", print_sum(sum_B));

    for (unsigned row = 0; row < rows; row++) {
        delete [] A[row];
        delete [] B[row];
    }

    delete [] A;
    delete [] B;

    A = nullptr;
    B = nullptr;
}

TEST(task_1, OneBigColumn) {
    int rows = 1;
    int columns = 200;

    int **A = create_A(rows, columns);
    std::unordered_map<int, int> sum_A = sum_even(A, rows, columns);

    int **B = create_B(A, rows, columns);
    std::unordered_map<int, int> sum_B = sum_even(B, rows, columns);

    for (int col = 1; col < columns; col += 2) {
        EXPECT_EQ(sum_A[col + 1], A[0][col]);
    }

    for (int col = 1; col < columns; col += 2) {
        EXPECT_EQ(sum_B[col + 1], B[0][col]);
    }

    for (unsigned row = 0; row < rows; row++) {
        delete [] A[row];
        delete [] B[row];
    }

    delete [] A;
    delete [] B;

    A = nullptr;
    B = nullptr;
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
