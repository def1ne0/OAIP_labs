#pragma once

#include <iostream>
#include <cmath> 

#include "check_cin_func.h"

using namespace std;

void do_Task_5() {
    int n;
    long double value = fabs(sinh(0) + acos(0) - 1.5);
    long double arg = 0;
    n = input_value<int>("На сколько частей разделить область поиска корня?", "Ошибка, повторите попытку", true, 1);
    long double step = 1.0/n;

    for (long double i = step; i <= 1; i += step) {
        long double v1 = fabs(sinh(i) + acos(i) - 1.5);

        if (value > v1) {
            value = v1;
            arg = i;
        }

        //cout << "val: " << value << " arg: " << i << endl; 
    }

    cout << "Приближенный корень уравнения sinh(x) + arccos(x) - 1.5 = 0: " << arg << endl;
    return;
}