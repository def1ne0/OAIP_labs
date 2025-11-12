#pragma once

#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846L

using namespace std;

void do_Task_3 () {
    long double x;
    for (unsigned i = 0; i <= 20; i++) {
        x = i*PI/40;
        cout << "При x = " << x << ", y = " << sin(x) - cos(x) << endl;
    }
    return;
}