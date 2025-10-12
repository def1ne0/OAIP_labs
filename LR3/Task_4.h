#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "check_cin_func.h"

using namespace std;

bool check_interval(long double& arg, long double min, long double max) {
    if (arg >= min && arg <= max) {
        return true;
    } else {
        return false;
    }
}

void do_Task_4() {
    int n, count_x;
    n = input_value<int>("Введите количество членов ряда n", "Ошибка, попробуйте снова 52");
    count_x = input_value<int>("Введите количество чисел x, от которых хотите посчитать функцию");

    cout << "n: " << n << "; count_x: " << count_x << endl;
    return;
}