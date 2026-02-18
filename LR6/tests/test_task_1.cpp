#include "MyStr.h"
#include <cstddef>
#include <utility>
#include <gtest/gtest.h>

std::pair<std::string, std::string> exp_res(str::MyStr input, int k) {
    size_t len = input.length();

    if (k >= len) {
        return { std::string(input.c_str()), "" };
    } else {
        int breakpoint = -1;

        for (int i = k; i >= 0; i--) {

            if (input[i] == ' ') {
                breakpoint = i;
                break;
            }
        }

        if (breakpoint == -1) {
            return { "", std::string(input.c_str()) };
        }

        return { std::string(input.cut_out_str(0, breakpoint - 1).c_str()), std::string(input.cut_out_str(breakpoint + 1, len - 1).c_str())};
    }
}

TEST(Task1Test, NormalCase1) {
    auto result = exp_res((char *) "hello world test", 8);
    EXPECT_EQ(result.first, "hello");
    EXPECT_EQ(result.second, "world test");
}

TEST(Task1Test, NormalCase2) {
    auto result = exp_res((char *) "a b c d e", 4);
    EXPECT_EQ(result.first, "a b");
    EXPECT_EQ(result.second, "c d e");
}

TEST(Task1Test, NormalCase3) {
    auto result = exp_res((char *) "one two three", 5);
    EXPECT_EQ(result.first, "one");
    EXPECT_EQ(result.second, "two three");
}

TEST(Task1Test, NormalCase4) {
    auto result = exp_res((char *) "word", 10);
    EXPECT_EQ(result.first, "word");
    EXPECT_EQ(result.second, "");
}

TEST(Task1Test, NormalCase5) {
    auto result = exp_res((char *) "a b", 1);
    EXPECT_EQ(result.first, "a");
    EXPECT_EQ(result.second, "b");
}

TEST(Task1Test, NormalCase6) {
    auto result = exp_res((char *) "x y z w", 6);
    EXPECT_EQ(result.first, "x y z");
    EXPECT_EQ(result.second, "w");
}

TEST(Task1Test, NormalCase7) {
    auto result = exp_res((char *) "test string", 3);
    EXPECT_EQ(result.first, "");
    EXPECT_EQ(result.second, "test string");
}

TEST(Task1Test, NormalCase8) {
    auto result = exp_res((char *) "alpha beta gamma", 10);
    EXPECT_EQ(result.first, "alpha beta");
    EXPECT_EQ(result.second, "gamma");
}

TEST(Task1Test, EdgeCase_EmptyString) {
    auto result = exp_res((char *) "", 5);
    EXPECT_EQ(result.first, "");
    EXPECT_EQ(result.second, "");
}

TEST(Task1Test, EdgeCase_NoSpaceBeforeK) {
    auto result = exp_res((char *) "hello", 2);
    EXPECT_EQ(result.first, "");
    EXPECT_EQ(result.second, "hello");
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
