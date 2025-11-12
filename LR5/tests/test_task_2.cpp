#include <gtest/gtest.h>

int find_x_sum(int *arr, int size, int start, int end) {
    if (size == 0) return 0;

    if (start == end) {
        return arr[start - 1] * arr[start - 1];
    } else if (start + 1 == end) {
        return arr[start - 1] * arr[start - 1] + arr[start] * arr[start];
    } else {
        return arr[start - 1] * arr[start - 1] + find_x_sum(arr, size, start + 1, end);
    }
}

TEST(task_2, CheckDefaultInput) {
    int arr[6] = {1, 2, 3, 4, 5, 6};

    EXPECT_EQ(5, find_x_sum(arr, 6, 1, 2));
    EXPECT_EQ(86, find_x_sum(arr, 6, 3, 6));
}

TEST(task_2, CheckEdgeCases) {
    int arr1[0];
    int arr2[1] = {1};

    EXPECT_EQ(0, find_x_sum(arr1, 0, 0, 0));
    EXPECT_EQ(1, find_x_sum(arr2, 1, 1, 1));
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
