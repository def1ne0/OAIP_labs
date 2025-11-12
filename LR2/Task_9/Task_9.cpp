#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int choice;
    double z, x, f_x, a, b;
    cout << "Введите число z, a, b" << endl;
    cin >> z >> a >> b;
    cout << "Выберите функцию f(x):\n 1. 2x\n 2. x^3\n 3. x/3" << endl;
    cin >> choice;

    if(z > 0){
        x = 1/(z*z + 2*z);
        cout << "Выполняется при условии z > 0" << endl;
    }
    else {
        x = 1 - pow(z, 3);
        cout << "Выполняется при условии z <= 0" << endl;
    }

    switch (choice){
    case 1:
        f_x = 2*x;
        cout << "Вычисления производятся с функцией f(x) = 2x" << endl;
        break;
    case 2:
        f_x = pow(x, 3);
        cout << "Вычисления производятся с функцией f(x) = x^3" << endl;
        break;
    case 3:
        f_x =  x/3;
        cout << "Вычисления производятся с функцией f(x) = x/3" << endl;
        break;
    default:
        cout << "надо было ввести числа от 1 до 3, анлак" << endl;
        break;
    }



    cout << "y = " << (2.5*a*exp(-3*x) - 4*b*x*x)/(log(fabs(x)) + f_x) << endl;

}