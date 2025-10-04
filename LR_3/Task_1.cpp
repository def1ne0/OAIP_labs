#include <iostream>
using namespace std;

int main() {
    bool exit = false;
    cout << "Суть задания: Используя цикл while вычислить сумму" << endl;
    cout << "Задание выполнил: Финевич Арсений 553502" << endl;
    while (!exit) {
        
        int choice;
        cout << "Введите:\n '1', чтобы начать работу программы\n '0', чтобы остановить работу программы" << endl;
        cin >> choice;
        
        switch (choice) {
        case 1:{
            unsigned int i = 1;
            int a, b;
            int sum = 0;
            while (i <= 30){
                if(i % 2 == 0){
                    a = i/2.0;
                    b = i*i*i;
                }else {
                    a = i;
                    b = i*i;
                }
                sum += (a - b)*(a - b);
                i++;
            }
            cout << "SUM = " << sum << endl;
            break;
        }
        case 0:{
            exit = true;
            break;
        }
        
        default:{
            cout << "Внимательно прочитайте текст, и введите число 1, чтобы начать программу, либо 0, чтобы выйти из программы" << endl;
            break;
        }
        }
    }
        
}