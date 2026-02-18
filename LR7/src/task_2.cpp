#include <print>
#include <string>
#include <cassert>

#include "check_cin.h"
#include "task_1.h"
#include "task_2.h"

namespace task_2 {
    int to_default_number(const std::string &ones_complement) {
        int res{};
        char ch = ones_complement[0] == '1' ? '0' : '1';
        int diff = 1;

        for (int i = 31; i >= 1; i--) {
            if (ones_complement[i] == ch) {
                res += diff;
            }

            diff <<= 1;
        }

        return ch == '1' ? res : -res;
    }

    int find_sum(const int &first, const int &second) {
        std::string first_number = task_1::to_ones_complement(task_1::to_sign_magnitude_code(first));
        std::string second_number = task_1::to_ones_complement(task_1::to_sign_magnitude_code(second));
        std::string result(32, '0');
        int carry{};

        for (int i = 31; i >= 0; i--) {
            int sum = (first_number[i] - '0') + (second_number[i] - '0') + carry;
            result[i] = (sum & 1) + '0';
            carry = (sum >> 1);
        }

        if (carry) {
            int num = 1;

            for (int i = 31; i >= 0 && num; i--) {
                if (result[i] == '0') {
                    result[i] = '1';
                    num = 0;
                } else {
                    result[i] = '0';
                }
            }
        }

        std::println("fst: {} \nsnd: {} \ncarry: {} \nthd: {}", first_number, second_number, carry, result);

        return to_default_number(result);
    }

    void do_task_2() {
        int first = io::input_value<int>("Введите первое число");
        int second = io::input_value<int>("Введите второе число");

        std::println("Сумма: {}", find_sum(first, second));

        return;
    }
}
