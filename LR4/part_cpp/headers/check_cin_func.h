#pragma once

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
        std::cout << input_text << std::endl;

        while (!exit) {
            if (!(std::cin >> input)) {
                std::cout << error_text << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (!interval_checking) {
                exit = true;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else if (check_interval_type(input, a, b)) {
                exit = true;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cout << "Выход из диапазона данного типа" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        
        }
        
        return input;
    }
}
