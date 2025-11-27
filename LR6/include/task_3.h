#pragma once

#include <cstddef>
#include "MyStr.h"

namespace task_3 {
    void do_task_3();

    bool is_number(char c);

    size_t find_length(char *input);

    void input_str(char *str);

    void execute_task_3(str::MyStr input);

    void execute_task_3(char *input);
}
