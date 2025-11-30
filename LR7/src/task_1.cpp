#include <climits>
#include <print>

#include "task_1.h"
#include "check_cin.h"


namespace task_1 {
    std::string to_sign_magnitude_code(int num) {
        if (num == 0) return "00000000000000000000000000000000";

        std::string res(32, '0');
        unsigned unum;

        if (num < 0) {
            res[0] = '1';

            if (num == INT_MIN) {
                unum = static_cast<unsigned>(INT_MAX) + 1U;
            } else {
                unum = static_cast<unsigned>(-num);
            }
        } else {
            unum = static_cast<unsigned>(num);
        }

        for (int i = res.length() - 1; i >= 1; i--) {
            res[i] = (unum & 1) ? '1' : '0';
            unum >>= 1;
        }

        return res;
    }

    std::string to_ones_complement(const std::string &sign_magnituted) {
        if (sign_magnituted[0] == '0') return sign_magnituted;

        std::string result = sign_magnituted;

        for (int i = sign_magnituted.length() - 1; i >= 1; i--) {
            result[i] = sign_magnituted[i] == '0' ? '1' : '0';
        }

        return result;
    }

    void do_task_1() {
        int num = io::input_value<int>("Введите число");
        std::string sign_magnitude_num = to_sign_magnitude_code(num);
        std::string ones_complement_num = to_ones_complement(sign_magnitude_num);

        std::println("Прямой код: {}, обратный: {}", sign_magnitude_num, ones_complement_num);

        return;
    }
}
