#include "MyStr.h"
#include <print>
#include "task_1.h"
#include "c_str_utils.h"

namespace task_1 {
    void execute_task_1(const str::MyStr &input, const int k) {
        const size_t len = input.length();

        if (k >= len - 1) {
            std::println("Первая подстрока: {}", input.c_str());
            std::println("Вторая подстрока: ");

        } else {
            int breakpoint = -1;

            for (int i = k; i >= 0; i--) {

                if (input[i] == ' ') {
                    breakpoint = i;
                    break;
                }
            }

            if (breakpoint == -1) {
                std::println("Первая подстрока: ");
                std::println("Вторая подстрока: {}", input.c_str());

                return;
            }

            std::println("Первая подстрока: {}", input.cut_out_str(0, breakpoint - 1).c_str());
            std::println("Вторая подстрока: {}", input.cut_out_str(breakpoint + 1, len - 1).c_str());
        }
    }

    void execute_task_1(char *input, int k) {
        size_t len = c_str::find_length(input);

        if (k >= len) {
            std::println("Первая подстрока: {}", input);
            std::println("Вторая подстрока: ");

            return;
        } else {
            int breakpoint = -1;

            for (int i = k; i >= 0; i--) {

                if (input[i] == ' ') {
                    breakpoint = i;
                    break;
                }
            }

            if (breakpoint == -1) {
                std::println("Первая подстрока: ");
                std::println("Вторая подстрока: {}", input);

                return;
            }

            char *first = c_str::cut_c_str(input, 0, breakpoint - 1);
            char *second = c_str::cut_c_str(input, breakpoint + 1, static_cast<int>(len - 1));

            std::println("Первая подстрока: {}", first);
            std::println("Вторая подстрока: {}", second);

            delete [] first;
            delete [] second;
        }
    }

    void do_task_1() {
        //str::MyStr some_str;
        //some_str.input_by_getchar();
        char some_str[80];
        char input_k[80];

        std::println("Введите строку");
        c_str::input_str(some_str);

        std::println("Введите целое число k");
        c_str::input_str(input_k);

        auto k = c_str::to_unsigned_int(input_k);

        if (k.has_value()) {
            execute_task_1(some_str, k.value());
        } else {
            std::println("Ошибка при вводе k");
        }
    }
}
