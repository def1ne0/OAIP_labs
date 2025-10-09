#include <iostream>
#include <vector>
#include <limits>
#include "Task_1.h"

#define COMPL_BY "\n Выполнил: Финевич Арсений"

using namespace std;

int select_choice();

void menu();

int main () {
    menu();
}

int select_choice () {
    int choice;
    cin >> choice;
    if (!cin.fail()) {
        return choice;
    } else {
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
}

void menu () {
    vector<string> essence = {
        "Суть задания:\n Используя цикл while вычислить сумму (от i = 1 до i = 30) N(i) = (ai - bi)^2, где ai и bi определяются по определенной формуле"
    };
    bool exit = false;
    while (!exit) {
        int selected_choice;
        cout << "Выберите пункт меню (число):\n 0. Выйти из программы\n 1. Выполнить задание 1" << endl;
        selected_choice = select_choice();
        cout << selected_choice << endl;

        switch (selected_choice) {
        case -1:
            cout << "Ошибка. Введите ЧИСЛО, соответствующее пункту меню!!!" << endl;
            break;

        case 0:
            exit = true;
            break;
        case 1:
            cout << essence[0] << COMPL_BY << endl;
            do_Task_1();
            break;
            
        default:
            cout << "Ошибка. Введите число, соответствующее пункту меню" << endl;
            break;
        }
    }
    return;
}