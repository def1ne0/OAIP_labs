#include <cstddef>
#include <print>

#include "task_3.h"
#include "MyStr.h"

namespace task_3 {
    bool is_number(char c) {
        return c >= '0' && c <= '9';
    }

    size_t find_length(char *input) {
        size_t res = 0;

        for (; input[res] != '\0'; res++);

        return res;
    }

    void input_str(char *str) {
        int c;
        int i {};

        while (i < 79 && (c = getchar()) != EOF && c != '\n') {
            str[i] = static_cast<char>(c);
            i++;
        }

        str[i] = '\0';
    }

    void execute_task_3(str::MyStr input) {
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

        std::println("Максимальное число: {}", max_num);
    }

    void execute_task_3(char *input) {
        size_t len = find_length(input);
        size_t left = 0;
        size_t right = 0;
        int max_num = -1; //-1 вернет если не найдено

        for (; left < len; left++) {
            right = left + 1;

            if (static_cast<int>(input[left]) == 46) {
                left++;

                while (left < len && is_number(input[left])) {
                    left++;
                }

                left--;

                continue;
            }

            if (!is_number(input[left])) continue;

            int num = input[left] - '0';

            while (right < len && is_number(input[right])) {
                num = num * 10 + (input[right] - '0');
                right++;
            }

            if (max_num < num) {
                max_num = num;
            }
        }

        std::println("Максимальное число: {}", max_num);
    }

    void do_task_3() {
        //char input[80];

        str::MyStr input;

        std::println("Введите строку без пробелов: ");

        //input_str(input);

        input.input_by_getchar();

        execute_task_3(input);

        return;
    }
}
