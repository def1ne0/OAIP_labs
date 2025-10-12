#pragma once

#include <iostream>
#include <limits>
#include <string>

using namespace std;

template <typename T> struct cin_info {
    T arg;
    bool is_error;
    
    cin_info<T>(T arg, bool is_error) {
        this->arg = arg;
        this->is_error = is_error;
    }
};

template <class T> cin_info<T> check_cin() {
    T input;
   
   if (cin >> input) {
       cin_info<T> input_info(input, false);
       
       return input_info;
   } else {
       cin.clear();
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       cin_info<T> input_info(T{}, true);
       
       return input_info;
   }
}

template <class T> T input_value(string input_text, string error_text = "Ошибка, попробуйте снова") {
    bool exit = false;
    cout << input_text << endl;
    cin_info<T> input_info(0, 0);

    while (!exit) {
        input_info = check_cin<T>();

        if (input_info.is_error) {
            cout << error_text << endl;
        } else {
            exit = true;
        }

    }

    return input_info.arg;
}