#pragma once

#include <cstddef>
#include <optional>

namespace c_str {
    char *cut_c_str(const char *input, int start, int end);

    size_t find_length(const char *input);

    void input_str(char *str);

    void clear(char *str);

    std::optional<int> to_unsigned_int(char *str);

    bool is_number(char c);
}
