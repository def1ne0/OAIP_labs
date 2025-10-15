#pragma once

#include <iostream>

#include "check_cin_func.h"

#define EPS 1e-9
#define PI 3.14159265358979323846L

using namespace std;

long double my_abs(long double arg) {
    if (arg < 0) {
        return -arg;
    } else {
        return arg;
    }
}

long double my_pow(long double num, int deg) {
    long double result = 1;
    if (num == 0 && deg == 0) {
        return 1;
    } else if(num == 0) {
        return 0;
    }
    else if (num == 1) {
       return 1;
    }
    else if (deg == 1) {
        return num;
    }
    else {
        for (int i = 0; i < deg; i++) {
            result *= num;
        }
        return result;
    }

}

int factorial(int num) {
    if (num == 0) {
        return 1;
    }
    else if (num == 1) {
        return 1;
    }
    else {
        return num*factorial(num - 1);
    }
}

long double normilize(long double arg) {
    while (my_abs(arg) > 2*PI) {
        if (arg < 0) {
            arg += 2*PI;
        }
        else {
            arg -= 2*PI;
        }
    }
    return arg;
}

long double my_sin(long double arg) {
    arg = normilize(arg);
    long double result = arg;
    long double delta = arg;
    int i = 0;

    if (arg == 0) {
        return 0;
    }
    else {
        do {
            delta *= -arg*arg/((2*i + 2)*(2*i + 3));
            result += delta;
            i++;
        } while (my_abs(delta) > EPS);
    }

    return result;
}

long double my_cos(long double arg) {
    arg = normilize(arg);
    long double result = 1.0L;
    long double delta = 1.0L;
    int i = 0;

    if (arg == 0) {
        return 1;
    }
    else {
        do {
            delta *= -arg*arg/((2*i + 1)*(2*i + 2));
            result += delta;
            i++;
        } while (my_abs(delta) > EPS);
    }

    return result;
}

long double my_exp(long double arg) {
    long double res = 1.0L;
    long double delta = 1.0L;
    int i = 1;

    do {
        delta *= arg/i;
        res += delta;
        i++;
    } while (my_abs(delta) > EPS);

    return res;
}

long double my_log(long double arg) {
    arg = my_abs(arg);
    long double res = arg > 1 ? 1.0L : arg - 1;

    do {
        res = res - 1 + arg/my_exp(res);
    } while (my_abs(arg - my_exp(res)) > EPS);

    return res;
}

void do_Task_6() {
    long double x, a, b, c;

    bool exit = false;
    
    while (!exit) {
        x = input_value<long double>("Введите значение х");

        if (x != 0) {
            exit = true;
        } else {
            cout << "х не может быть нулем" << endl;
        }
    }
    
    a = my_sin(x);
    b = my_cos(x);
    c = my_log(x);

    if (a < b) {
        if (a < c) {
            cout << "min = sin(" << x << ") = " << a << endl;
        } else if (a == c) {
            cout << "min = sin(" << x << ") = " << "ln(|" << x << "|) = " << a << endl;
        } else {
            cout << "min = ln(|" << x << "|) = " << c << endl;
        }
    } else if (a == b) {
        if (a < c) {
            cout << "min = sin(" << x << ") = " << "cos(" << x << ") = "<< a << endl;
        } else if (a == c) {
            cout << "min = sin(" << x << ") = " << "cos(" << x << ") = " << "ln(|" << x << "|) = " << a << endl;
        } else {
            cout << "min = ln(|" << x << "|) = " << c << endl;
        }
    } else {
        if (c < b) {
            cout << "min = ln(|" << x << "|) = " << c << endl;
        } else if (c == b) {
            cout << "min = " << "cos(" << x << ") = " << "ln(|" << x << "|) = " << c << endl;
        } else {
            cout << "min = " << "cos(" << x << ") = " << b << endl;
        }
    }
    return;
}