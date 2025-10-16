#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

#include "check_cin_func.h"

using namespace std;

bool check_interval(long double& arg, long double min, long double max) {
    if (arg >= min && arg <= max) {
        return true;
    } else {
        return false;
    }
}

long double with_cmath(long double& arg) {
    return 2*(cos(arg)*cos(arg) - 1);
}

/*long double with_decomposition(long double& arg, unsigned& n) {
    long double sum = 0;

    for (unsigned i = 1; i <= n; i++) {
        sum += pow(-1, i)*pow(2*arg, 2*i)/tgamma(2*i + 1);
    }

    return sum;
}*/

long double with_decomposition(long double& arg, int& n) {
    long double sum = 0;
    long double delta = 1;

    for (int i = 0; i < n; i++) {
        delta *= -4*arg*arg/((2*i + 2)*(2*i + 1));
        sum += delta;
    }

    return sum;
}

string null_str(long double& arg) {
    if (arg < 0) {
        return "          ";
    } else {
        return "           ";
    }
}

void do_Task_4() {
    int n, count_x;
    n = input_value<int>("Введите количество членов ряда n", "Ошибка, попробуйте снова", true, 0);


    count_x = input_value<int>("Введите количество чисел x, от которых хотите посчитать функцию", "Ошибка, попробуйте снова", true, 0);
    
    vector<long double> x_values(count_x);
    vector<long double> f_x_cmath(count_x);
    vector<long double> f_x_decompostion(count_x);

    for (unsigned i = 0; i < count_x; i++) {
        bool exit = false;
        long double x;

        while (!exit) {
            x = input_value<long double>("Введите х в интервале [0.1; 1]");

            if (check_interval(x, 0.1L, 1L)) {
                x_values[i] = x;
                exit = true;
            } else {
                cout << "x не в интервале [0.1; 1]";
            }
        }
    }

    for (unsigned i = 0; i < count_x; i++) {
        f_x_cmath[i] = with_cmath(x_values[i]);
        f_x_decompostion[i] = with_decomposition(x_values[i], n);
    }

    cout << "        X         |    f(x) cmath    |f(x) decomposition|" << endl;

    for (unsigned i = 0; i < count_x; i++) {
        cout << fixed << setprecision(5) << x_values[i] << null_str(x_values[i]) << "|" << f_x_cmath[i] << null_str(f_x_cmath[i]) << "|" << f_x_decompostion[i] << null_str(f_x_decompostion[i]) << "|" << endl;
    }
    
    return;
}