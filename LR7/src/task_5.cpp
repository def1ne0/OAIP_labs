#include <cstddef>
#include <print>
#include <string>
#include <vector>

#include "task_5.h"
#include "check_cin.h"

namespace task_5 {
    std::vector<int> to_ternary(int n) {
        std::vector<int> digits(5, 0);

        for (auto &item : digits) {
            item = n % 3;
            n /= 3;
        }

        return digits; // [0] - младший, [4] - старший
    }

    int get_result(std::vector<int> res_vec) {
        int poisoned{};
        int power = 1;

        for (auto &item : res_vec) {
            poisoned += item * power;
            power *= 3;
        }

        return poisoned;
    }

    void do_task_5() {
        std::vector<int> round_1[5]; // за 48ч
        std::vector<int> round_2[5]; // за 24ч

        for (int barrel = 0; barrel < 240; barrel++) {
            std::vector<int> code = to_ternary(barrel);

            for (int slave = 0; slave < 5; slave++) {
                if (code[slave] == 1) {
                    round_1[slave].push_back(barrel);
                } else if (code[slave] == 2) {
                    round_2[slave].push_back(barrel);
                }
            }
        }

        for (int slave = 0; slave < 5; ++slave) {
            std::println("Раб {}:", slave);

            if (round_1[slave].empty()) {
                std::println("  День 1: ничего не пьёт.");
            } else {
                std::println("  День 1: пьёт из бочек ");

                for (const auto &barrel : round_1[slave]) {
                    std::print("{}; ", barrel);
                }

                std::println("\n");
            }

            if (round_2[slave].empty()) {
               std::println("  День 2: ничего не пьёт.");
            } else {
                std::println("  День 2: пьёт из бочек ");

                for (const auto &barrel : round_2[slave]) {
                    std::print("{}; ", barrel);
                }

                std::println("\n");
            }
        }

        std::vector<int> result(5, 0);

        for (size_t i = 0; i < 5; i++) {
            result[i] = io::input_value<int>(
                "Введите статус " + std::to_string(i) + " раба после 48 часов (0=жив, 1=умер в 1-й день, 2=умер во 2-й день)",
                "Ошибка",
                true,
                0,
                2
            );
        }

        int poisoned = get_result(result);

        if (poisoned >= 240) {
            std::println("Данные введены неверно");
        } else {
            std::println("Отравлена бочка {}", poisoned);
        }

        return;
    }
}
