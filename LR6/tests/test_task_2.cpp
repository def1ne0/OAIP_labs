#include <gtest/gtest.h>

#include "MyStr.h"

size_t find_biggest(int *arr, size_t size) {
    int max = arr[0];
    size_t max_idx = -1;

    for (size_t i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
            max_idx = i;
        }
    }

    return max_idx;
}

std::string exp_res(str::MyStr text) {
    std::string res;
    int frequencies[256] {0};

    for (size_t i = 0; i < text.length(); i++) {
        unsigned char element = text[i];
        frequencies[static_cast<int>(element)]++;
    }

    for (size_t i = 0; i < 3; i++) {
        size_t idx_biggest = find_biggest(frequencies, 256);

        if (idx_biggest == -1) break;

        res += static_cast<char>(idx_biggest);
        frequencies[idx_biggest] = 0;
    }

    return res;
}

TEST(Task2Test, NormalCase1) {
    auto res = exp_res((char *) "aabbcc");
    EXPECT_EQ(res.length(), 3);
    EXPECT_EQ(res[0], 'a');
    EXPECT_EQ(res[1], 'b');
    EXPECT_EQ(res[2], 'c');
}

TEST(Task2Test, NormalCase2) {
    auto res = exp_res((char *) "hello world");
    EXPECT_EQ(res[0], 'l');
    EXPECT_EQ(res[1], 'o');
}

TEST(Task2Test, NormalCase3) {
    auto res = exp_res((char *) "aaa");
    EXPECT_EQ(res.length(), 1);
    EXPECT_EQ(res[0], 'a');
}

TEST(Task2Test, NormalCase4) {
    auto res = exp_res((char *) "abcabcabc");
    EXPECT_EQ(res[0], 'a');
    EXPECT_EQ(res[1], 'b');
    EXPECT_EQ(res[2], 'c');
}

TEST(Task2Test, NormalCase5) {
    auto res = exp_res((char *) "abcaaaaaaa");
    EXPECT_EQ(res, "abc");
}

TEST(Task2Test, NormalCase6) {
    auto res = exp_res((char *) "a");
    ASSERT_EQ(res.length(), 1);
    EXPECT_EQ(res[0], 'a');
}

TEST(Task2Test, NormalCase7) {
    auto res = exp_res((char *) "aabbccddee");
    EXPECT_EQ(res.length(), 3);
}

TEST(Task2Test, NormalCase8) {
    auto res = exp_res((char *) "1122334455");
    EXPECT_EQ(res.length(), 3);
}

TEST(Task2Test, EdgeCase_EmptyString) {
    auto res = exp_res((char *) "");
    EXPECT_EQ(res, "");
}

TEST(Task2Test, EdgeCase_AllSameChar) {
    auto res = exp_res((char *) "xxxxxxxxxx");
    EXPECT_EQ(res.length(), 1);
    EXPECT_EQ(res[0], 'x');
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
