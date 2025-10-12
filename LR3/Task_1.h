#pragma once

#include <iostream>
using namespace std;

void do_Task_1 () {
    unsigned i = 0;
    int a, b;
    int sum = 0;
    while (i < 31) {
        if (i % 2 == 0) {
            a = i/2;
            b = i*i*i;
        } else {
            a = i;
            b = i*i;
        }

        sum += (a - b)*(a - b);
        i++;
    }

    cout << "Сумма: " << sum << endl;
    return;

}
