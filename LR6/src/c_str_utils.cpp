#include "c_str_utils.h"
#include <cstdio>
#include <optional>

namespace c_str {
    char *cut_c_str(const char *input, const int start, const int end) {
        char *res = new char [end - start + 2];
        size_t idx = 0;

        for (int i = start; i <= end; i++) {
            res[idx] = input[i];
            idx++;
        }

        res[end - start + 1] = '\0';

        return res;
    }

    size_t find_length(const char *input) {
        size_t res = 0;

        for (; input[res] != '\0'; res++) {};

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

    void clear(char *str) {
        size_t len = find_length(str);

        for (size_t i = 0; i < len; i++) {
            str[i] = 0;
        }

        str[0] = '\0';
    }

    std::optional<int> to_unsigned_int(char *str) {
        size_t len = find_length(str);

        if (len == 0) return std::nullopt;

        int num {};

        for (size_t i = 0; i < len; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + (str[i] - '0');
            } else {
                return std::nullopt;
            }
        }

        return num;
    }

    bool is_number(char c) {
        return c >= '0' && c <= '9';
    }
}
