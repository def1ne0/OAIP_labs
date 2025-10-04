#include <iostream>
using namespace std;

double sqrt(double num){
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

int main(){
    double x1, y1, x2, y2, r1, r2;
    cout << "Введите координаты вершин кругов с центром M1(x1, y1) и M2(x2, y2) и их радиусы R1, R2 соответственно" << endl;
    cin >> x1 >> y1 >> x2 >> y2 >> r1 >> r2;

    double length = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

    if(length <= r2 - r1){
        cout << "Да" << endl;
    }
    else if(length <= r1 - r2){
        cout << "Да, но справедливо обратное для двух фигур" << endl;
    }
    else if(length < r1 + r2 || length == r1 + r2){
        cout << "Фигуры пересекаются" << endl;
    }
    else {
        cout << "Ни одно условие не выполнено" << endl;
    }

}