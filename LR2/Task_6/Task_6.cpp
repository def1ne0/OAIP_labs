#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double x, z, k, C, D;
    cout << "Введите x, z, k, C, D" << endl;
    cin >> x >> z >> k >> C >> D;
    double A = log(x) -k;
    double B = sqrt(z);
    cout << "Y = " << D*D + C*C/(0.75*A) + B << endl;

}