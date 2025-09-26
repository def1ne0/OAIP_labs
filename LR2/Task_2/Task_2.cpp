#include <iostream>
using namespace std;

int main(){
    double a, b, c;
    cout << "Введите стороны треугольника" << endl;
    cin >> a >> b >> c;
    if (a > 0 && c > 0 && b > 0){
        if (a < b + c && b < a + c && c < a + b){
            cout << "Существует" << endl;
        }
        else {
            cout << "Не существует" << endl;
        }
    }
    else {
        cout << "пашел нахуй" << endl;
    }

    return 0;
}