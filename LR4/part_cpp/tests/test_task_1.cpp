#include <iostream>
#include <gtest/gtest.h>

int get_inversions(int arr[], int k) {
    int inversions = 0;

    for (unsigned i = 0; i < k - 1; i++) {
        for (unsigned j = i + 1; j < k; j++) {
            if (arr[i] > arr[j]) {
                inversions++;
            }
        }
    }

    return inversions;

}

TEST(task_1, check_inversions) {
    int arr[6] = {3, 6, 4, 5, 2, 1};

    int result = get_inversions(arr, 6);

    EXPECT_EQ(result, 11);
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}