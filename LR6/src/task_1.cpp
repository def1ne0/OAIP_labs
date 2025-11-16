#include "MyStr.h"
#include "check_cin.h"
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

    void do_task_1() {
        str::MyStr some_str((char *)"Hello world this is a test string");
        int k = io::input_value("Введите k", "Ошибка", true, 1);

        execute_task_1(some_str, k);

        return;
    }
}
