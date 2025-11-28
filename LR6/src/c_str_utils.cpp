#include "c_str_utils.h"
#include <cstdio>
#include <print>
#include <stdexcept>

namespace c_str {
    char *cut_c_str(char *input, int start, int end) {
        char *res = new char [end - start + 2];
        size_t idx = 0;

        for (int i = start; i <= end; i++) {
            res[idx] = input[i];
            idx++;
        }

        res[end - start + 1] = '\0';

        return res;
    }

    size_t find_length(char *input) {
        size_t res = 0;

        for (; input[res] != '\0'; res++);

        return res;
    }

    void input_str(char *str, bool int_needed) {
        int c;
        int i {};

        if (!int_needed) {
            while (i < 79 && (c = getchar()) != EOF && c != '\n') {
                str[i] = static_cast<char>(c);
                i++;
            }
        } else {
            while (i < 79 && (c = getchar()) != EOF && c != '\n') {
                if (!is_number(c)) {
                    std::println("Был введен символ, не являющийся цифрой. Символы после него были проигнорированы");
                    break;
                }

                str[i] = static_cast<char>(c);
                i++;
            }
        }

        str[i] = '\0';
    }

    void clear(char *str) {
        size_t len = find_length(str);

        for (size_t i = 0; i < len; i++) {
            str[i] = 0;
        }

        str[0] = '\0';
    }

    int to_unsigned_int(char *str) {
        size_t len = find_length(str);

        if (len == 0) return 0;

        int num {};

        for (size_t i = 0; i < len; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + (str[i] - '0');
            } else {
                throw std::invalid_argument("далбаеб это не число");
            }
        }

        return num;
    }

    bool is_number(char c) {
        return c >= '0' && c <= '9';
    }
}
