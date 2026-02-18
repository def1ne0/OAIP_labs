#include <gtest/gtest.h>
#include <set>

double **create_arr(int rows, int columns) {
    double **arr = new double *[rows];

    for (int row = 0; row < rows; row++) {
        arr[row] = new double [columns];

        for (int col = 0; col < columns; col++) {
            arr[row][col] = row * col - row + col;
        }
    }

    return arr;
}

std::multiset<std::pair<int, int>> find_zeroes(double **arr, int rows, int columns) {
    const double EPS = 1e-9;
    std::multiset<std::pair<int, int>> res;

    for (unsigned row = 0; row < rows; row++) {
        for (unsigned col = 0; col < columns; col++) {
            if (std::abs(arr[row][col]) < EPS) {
                    res.insert(std::pair(row, col));
            }
        }
    }

    return res;
}

std::string print_info_zeros(std::multiset<std::pair<int, int>> zeroes) {
    if (zeroes.size() == 0) {
        return "-1";
    } else {
        std::string res = "{ ";

        for (const auto &item : zeroes) {
            res += "[" + std::to_string(item.first) + "][" + std::to_string(item.second) + "] ";
        }

        res += "} // " + std::to_string(zeroes.size());

        return res;
    }
}

void reverse_array(double **arr, int rows, int columns) {
    double **orig_arr = new double *[rows];

    for (unsigned row = 0; row < rows; row++) {
        orig_arr[row] = new double [columns];

        for (unsigned col = 0; col < columns; col++) {
            orig_arr[row][col] = arr[row][col];
        }
    }

    for (int row = rows - 1; row >= 0; row--) {
        for (int col = columns - 1; col >= 0; col--) {
            arr[rows - 1 - row][columns - 1 - col] = orig_arr[row][col];
        }
    }

    for (unsigned row = 0; row < rows; row++) {
        delete [] orig_arr[row];
    }

    delete [] orig_arr;
    orig_arr = nullptr;
}

std::string print_arr(double **arr, int rows, int columns) {
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

TEST(task_4, CheckGeneralInput) {
    int rows = 3;
    int columns = 2;

    double **arr = create_arr(rows, columns); // 0 1 | -1 1 | -2 1
    double rev_arr[3][2] = {{1, -2}, {1, -1}, {1, 0}};

    std::multiset<std::pair<int, int>> zeroes = find_zeroes(arr, rows, columns);

    EXPECT_EQ("{ [0][0] } // 1", print_info_zeros(zeroes));
    reverse_array(arr, rows, columns);

    for (unsigned row = 0; row < rows; row++) {
        for (unsigned col = 0; col < columns; col++) {
            EXPECT_DOUBLE_EQ(arr[row][col], rev_arr[row][col]);
        }
    }

    for (unsigned row = 0; row < rows; row++) {
        delete [] arr[row];
    }

    delete [] arr;
    arr = nullptr;
}

TEST(task_4, MinSize) {
    int rows = 1;
    int columns = 1;

    double **arr = create_arr(rows, columns); // 0
    double rev_arr[1][1] = {{0}};

    std::multiset<std::pair<int, int>> zeroes = find_zeroes(arr, rows, columns);

    EXPECT_EQ("{ [0][0] } // 1", print_info_zeros(zeroes));
    reverse_array(arr, rows, columns);

    for (unsigned row = 0; row < rows; row++) {
        for (unsigned col = 0; col < columns; col++) {
            EXPECT_DOUBLE_EQ(arr[row][col], rev_arr[row][col]);
        }
    }

    for (unsigned row = 0; row < rows; row++) {
        delete [] arr[row];
    }

    delete [] arr;
    arr = nullptr;
}

TEST(task_4, OneRowTwoColumns) {
    int rows = 1;
    int columns = 2;

    double **arr = create_arr(rows, columns); // 0 1
    double rev_arr[1][2] = {{1, 0}};

    std::multiset<std::pair<int, int>> zeroes = find_zeroes(arr, rows, columns);

    EXPECT_EQ("{ [0][0] } // 1", print_info_zeros(zeroes));
    reverse_array(arr, rows, columns);

    for (unsigned row = 0; row < rows; row++) {
        for (unsigned col = 0; col < columns; col++) {
            EXPECT_DOUBLE_EQ(arr[row][col], rev_arr[row][col]);
        }
    }

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
