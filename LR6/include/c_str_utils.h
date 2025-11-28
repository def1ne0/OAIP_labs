#pragma once

#include <cstddef>

namespace c_str {
    char *cut_c_str(char *input, int start, int end);

    size_t find_length(char *input);

    void input_str(char *str, bool int_needed = false);

    void clear(char *str);

    int to_unsigned_int(char *str);

    bool is_number(char c);
}
