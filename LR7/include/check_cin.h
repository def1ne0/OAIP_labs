#ifndef CHECK_CIN_H
#define CHECK_CIN_H

#include <print>
#include <iostream>
#include <string>
#include <limits>

namespace io {
    template <class T> bool check_interval_type(T arg, T a, T b) {
        T min, max;

        if (a > b) {
            min = b;
            max = a;
        } else if (a < b) {
            min = a;
            max = b;
        }

        return (arg >= min && arg <= max);
    }

    template <class T> T input_value(
        std::string input_text,
        std::string error_text = "Ошибка, попробуйте снова",
        bool interval_checking = false,
        T a = std::numeric_limits<T>::min(),
        T b = std::numeric_limits<T>::max()
    ) {
        bool exit = false;
        T input;
        std::println("{}", input_text);

        while (!exit) {
            if (!(std::cin >> input)) {
                std::println("{}", error_text);
            } else if (!interval_checking) {
                exit = true;
            } else if (check_interval_type(input, a, b)) {
                exit = true;
            } else {
                std::println("Выход из диапазона данного типа");
            }

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }

        return input;
    }
}

#endif // CHECK_CIN_H
