#include <iostream>
#include <cmath>
using namespace std;

void do_Task_2 () {
    long double sum = 0;
    long double di = 23;
    unsigned i = 1;
    
    do {
        di = 1/(pow(2.0, i)) + 1/(pow(3.0, i));
        sum += di;
        i++;
    } while (di >= 1e-3);
    
    cout << "Сумма ряда: " << sum << endl;
    return;
}