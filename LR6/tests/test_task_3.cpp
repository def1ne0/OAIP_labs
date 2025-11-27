#include <cstddef>
#include <gtest/gtest.h>
#include "MyStr.h"

bool is_number(char c) {
    return c >= '0' && c <= '9';
}

int exp_res(str::MyStr input) {
    size_t left = 0;
    size_t right = 0;
    int max_num = -1; //-1 вернет если не найдено

    for (; left < input.length(); left++) {
        right = left + 1;

        if (static_cast<int>(input[left]) == 46) {
            left++;

            while (left < input.length() && is_number(input[left])) {
                left++;
            }

            left--;

            continue;
        }

        if (!is_number(input[left])) continue;

        int num = input[left] - '0';

        while (right < input.length() && is_number(input[right])) {
            num = num * 10 + (input[right] - '0');
            right++;
        }

        if (max_num < num) {
            max_num = num;
        }
    }

    return max_num;
}

TEST(Task3Test, NormalCase1) {
    EXPECT_EQ(exp_res((char *) "sdfvgsd1.9fdmjgvb15.25dnj05"), 15);
}

TEST(Task3Test, NormalCase2) {
    EXPECT_EQ(exp_res((char *)"a12b34c"), 34);
}

TEST(Task3Test, NormalCase3) {
    EXPECT_EQ(exp_res((char *)"100.50test200"), 200);
}

TEST(Task3Test, NormalCase4) {
    EXPECT_EQ(exp_res((char *)"x0y1z2"), 2);
}

TEST(Task3Test, NormalCase5) {
    EXPECT_EQ(exp_res((char *)"999"), 999);
}

TEST(Task3Test, NormalCase6) {
    EXPECT_EQ(exp_res((char *)"a.123b456"), 456);
}

TEST(Task3Test, NormalCase7) {
    EXPECT_EQ(exp_res((char *)"12.34.56.78"), 12);
}

TEST(Task3Test, NormalCase8) {
    EXPECT_EQ(exp_res((char *)"007 bond"), 7);
}

TEST(Task3Test, EdgeCase_EmptyString) {
    EXPECT_EQ(exp_res((char *)""), -1);
}

TEST(Task3Test, EdgeCase_OnlyDotsAndDigits) {
    EXPECT_EQ(exp_res((char *)".123.456.789"), -1);
}

int main() {
    testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
