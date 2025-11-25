#include "MyStr.h"
#include "check_cin.h"
#include <cstddef>
#include "task_1.h"

namespace task_1 {
    void execute_task_1(str::MyStr input, int k) {
        size_t len = input.length();

        if (k >= len) {
            std::println("Первая подстрока: {}", input.c_str());
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
                std::println("Вторая подстрока: ");

                return;
            }

            std::println("Первая подстрока: {}", input.cut_out_str(0, breakpoint - 1).c_str());
            std::println("Вторая подстрока: {}", input.cut_out_str(breakpoint + 1, len - 1).c_str());
        }
    }

    char *cut_c_str(char *input, int start, int end) { // НЕ ЗАБУДЬ ОСВОБОДИТЬ ПАМЯТЬ
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

    void execute_task_1(char *input, int k) {
        size_t len = find_length(input);

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
                std::println("Вторая подстрока: ");

                return;
            }

            char *first = cut_c_str(input, 0, breakpoint - 1);
            char *second = cut_c_str(input, breakpoint + 1, len - 1);

            std::println("Первая подстрока: {}", first);
            std::println("Вторая подстрока: {}", second);

            delete [] first;
            delete [] second;
        }
    }

    void do_task_1() {
        str::MyStr some_str = (char *) "Hello world this is a test string";
        int k = io::input_value("Введите k", "Ошибка", true, 1);
        //char *some_str = (char *) "Hello world this is a test string";

        execute_task_1(some_str, k);

        return;
    }
}
