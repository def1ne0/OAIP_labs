#pragma once

#include <iostream>

#include "check_cin_func.h"

void do_Task_8() {
    long long a, n;
    long long sum = 0;
    long long delta = 1;
    n = input_value<long long>("Введите n (минимум n=1)", "Ошибка, попробуйте снова", true, 1);

    for (long long i = 0; i < n; i++) {
        a = input_value<long long>("Введите a" + to_string(i), "Ошибка, попробуйте снова");
        
        if (i % 2 == 0) {
            sum += delta*a;
        } else {
            sum -= delta*a;
        }

        delta *= 2;
    }

    cout << "Сумма: " << sum << endl;

    return;
}