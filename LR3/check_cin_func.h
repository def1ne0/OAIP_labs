#pragma once

#include <iostream>
#include <limits>
#include <string>

using namespace std;

template <typename T> struct cin_info {
    T arg;
    bool is_error;
    
    cin_info<T>(const T& arg, bool is_error) {
        this->arg = arg;
        this->is_error = is_error;
    }
};

template <class T> cin_info<T> check_cin() {
    T input;
   
    if (cin >> input) {
        cin_info<T> input_info(input, false);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
       
        return input_info;
    } else {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin_info<T> input_info(T{}, true);
       
        return input_info;
    }
}

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

template <class T> T input_value(string input_text, string error_text = "Ошибка, попробуйте снова", bool interval_checking = false, T a = numeric_limits<T>::min(), T b = numeric_limits<T>::max()) {
    bool exit = false;
    cout << input_text << endl;
    cin_info<T> input_info(0, 0);

    while (!exit) {
        input_info = check_cin<T>();

        if (input_info.is_error) {
            cout << error_text << endl;
        } else if (!interval_checking) {
            exit = true;
        } else if (check_interval_type(input_info.arg, a, b)) {
            exit = true;
        } else {
            cout << "Выход из диапазона данного типа" << endl;
        }

    }

    return input_info.arg;
}

