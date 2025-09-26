#include <iostream>
using namespace std;

int main(){
    double X, Y, res;
    cout << "Введите X, Y" << endl;
    cin >> X >> Y;
    if (X > Y){
        res = X;
    }
    else {
        res = Y;
    }
    cout << "max(" << X << ", " << Y  << ") = " << res << endl;
}