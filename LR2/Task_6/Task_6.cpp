#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double D, x;
    cout << "Введите D, x" << endl;
    cin >> D >> x;
    double b = x + D;
    double A = D*x/b;
    double S = (pow(A, 2) + b*cos(x))/(pow(D, 3) + (A + D - b));
    cout << "S = " << S << endl;

}