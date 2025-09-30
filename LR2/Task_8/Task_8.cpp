#include <iostream>
using namespace std;

double pow(double num, int deg){
    double result = 1;
    if(num == 0){
        return 0;
    }
    else if(num == 1){
       return 1;
    }
    else if(deg == 1){
        return num;
    }
    else{
        for(int i = 0; i < deg; i++){
            result *= num;
        }
        return result;
    }

}

int factorial(int num){
    if(num == 0){
        return 1;
    }
    else if(num == 1){
        return 1;
    }
    else{
        return num*factorial(num - 1);
    }
}

double sqrt(double num){
    double result = 0;
    num -= 1;
    for(int i = 0; i < 20; i++){
        result += pow(-1, i)*factorial(2*i)/((1 - 2*i)*(pow(factorial(i), 2))*pow(4, i))*pow(num, i);
    }

    return result;
}

int main(){
    /*double x1, y1, x2, y2, x3, y3;
    cout << "Введите координаты вершины A(x1, y1), B(x2, y2), C(x3, y3)" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = */
    double x, a;
    int y, z;
    cin >> x >> y >> z >> a;
    cout << "x^y = " << pow(x, y) << endl;
    cout << "z! = " << factorial(z) << endl;
    cout <<"sqrt(a) = " << sqrt(a) << endl;
}