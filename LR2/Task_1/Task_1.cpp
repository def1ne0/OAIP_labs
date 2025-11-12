#include <iostream>
using namespace std;

int main(){
    float x;
    cout << "Введите число x: " << endl;
    cin >> x;
    float a = x * x;
    float b = 23 * a;
    float c = b + 32;
    float d = c * x;
    float e = 69 * a;
    float f = e + 8;
    cout << "23*x^3 + 69*x^2 + 32*x + 8 = " << d + f << endl;
    cout << "-23*x^3 + 69*x^2 - 32*x + 8 = " << f - d << endl;

    return 0;
}
