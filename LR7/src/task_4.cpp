#include "task_4.h"
#include "check_cin.h"
#include <print>

namespace task_4 {
    // 10^k == 1 (mod 3) (*)
    // возьмем N = d(n) * 10 ^ n + d(n-1) * 10 ^ (n-1) + ... + d1 * 10 ^ 1 + d0 * 10 ^ 0 (**)
    // подставим (*) в (**)
    // N == d(n) + d(n-1) + .. + d1 + d0 (mod 3)
    // значит, число делится на 3 в 10ричной системе счисления если сумма его цифр в 10ричной делится на 3
    // если взять b^k == 1 (mod l), то число делится на l, если его сумма в b-ричной системе счисления делится на l


    // 10^k == 1 (mod 3) -> 16 == 1 (mod 5) -> число делится на 5 если сумма его цифр в 16ричной системе делится на 5
    bool is_divisible_by_5(unsigned num) {
        int sum = 0;

        for (int i = 0; i < 32; i += 4) {
            sum += (num >> i) & 0xF;
        }

        while (sum > 4 || sum < -4) {
            if (sum > 0) {
                sum += (~5 + 1);
            } else {
                sum += 5;
            }
        }

        return (sum == 0);
    }
    // 10^k == 1 (mod 3) -> 16^k == 1 (mod 3) -> число делится на 3 если сумма его цифр в 16ричной системе делится на 3
    bool is_divisible_by_3(unsigned num) {
        int sum = 0;

        for (int i = 0; i < 32; i += 4) {
            sum += (num >> i) & 0xF;
        }

        while (sum > 2 || sum < -2) {
            if (sum > 0) {
                sum += (~3 + 1);
            } else {
                sum += 3;
            }
        }

        return (sum == 0);
    }

    // 10^k == 1 (mod 3) -> 8^k == 1 (mod 7) -> число делится на 7 если сумма его цифр в 8ричной системе делится на 7
    bool is_divisible_by_7(unsigned num) {
        int sum = 0;

        for (int i = 0; i < 32; i += 3) {
            sum += (num >> i) & 0x7;
        }

        while (sum > 6 || sum < -6) {
            if (sum > 0) {
                sum += (~7 + 1);
            } else {
                sum += 7;
            }
        }

        return (sum == 0);
    }


    void do_task_4() {
        int num = io::input_value<int>("Введите неотрицательное число", "Ошибка", true, 0);

        std::println("{} делится на \n{}: {} \n{}: {} \n{}: {}", num, 3, is_divisible_by_3(num), 5, is_divisible_by_5(num), 7, is_divisible_by_7(num));
    }
}
