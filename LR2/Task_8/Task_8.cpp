#include <iostream>
#define epsilon 1e-9
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
    /*double result = 0;
    num -= 1;
    for(int i = 0; i < 20; i++){
        result += pow(-1, i)*factorial(2*i)/((1 - 2*i)*(pow(factorial(i), 2))*pow(4, i))*pow(num, i);
    }

    return result;*/ //для x < 1
    

    /*do{
        result = (result + num/result)/2;
    } while (result*result - num > epsilon || result*result - num < -epsilon);*/ // с точность epsilon

    double result = 1;
    if(num == 0){
        return 0;
    }
    else if(num == 1){
        return 1;
    }
    else{
        for(int i = 0; i < 20; i++){
            result = (result + num/result)/2;
        }
    }
    
    return result;
}

double cos(double arg){
    double result = 0;

    if(arg == 0){
        return 1;
    }
    else{
        for(int i = 0; i < 15; i++){
            result += pow(-1, i)*pow(arg, 2*i)/(factorial(2*i));
        }
    }

    return result;
}

double sin(double arg){
    double result = 0;

    if(arg == 0){
        return 1;
    }
    else{
        for(int i = 0; i < 15; i++){
            result += pow(-1, i)*pow(arg, 2*i + 1)/(factorial(2*i+1));
        }
    }

    return result;
}

double arccos(double arg){
    double result = 1;

    for(int i = 0; i < 20; i++){
        result = result + (cos(result) - arg)/sin(result);
    }

    return result;
}

int main(){
    /*double x1, y1, x2, y2, x3, y3;
    cout << "Введите координаты вершины A(x1, y1), B(x2, y2), C(x3, y3)" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double a = */
    double x, a, b, c;
    int y, z;
    cin >> a >> b >> c;

    cout <<"cos(a) = " << cos(a) << endl;
    cout <<"sin(b) = " << sin(b) << endl;
    cout <<"arccos(c) = " << arccos(c) << endl;

}