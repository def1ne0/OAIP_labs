#pragma once

#include <iostream>
#include <vector>
#include <limits>

#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"

#define SEP cout << "************************" << endl;
#define PRE_ESSENCE "Суть задания:\n "
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
    SEP
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
        "Используя цикл while вычислить сумму (от i = 1 до i = 30) N(i) = (ai - bi)^2, где ai и bi определяются по определенной формуле",
        "Используя цикл do while найти сумму ряда с точностью 𝜀 = 10^(-3), di = 1/(2^n) + 1/(3^n)",
        "Используя цикл for составить программу вычисления значений функции y = sin(x) - cos(x) на отрезке [A, B] в точках Xi = A + i*H"
    };
    bool exit = false;
    while (!exit) {
        int selected_choice;
        cout << "Выберите пункт меню (число):\n -> 0. Выйти из программы\n -> n. Выберите номер задания для запуска, введя n, где n - номер задания" << endl;
        selected_choice = select_choice();

        switch (selected_choice) {
        case -1:
            cout << "Ошибка. Введите ЧИСЛО, соответствующее пункту меню!!!" << endl;
            SEP
            break;

        case 0:
            exit = true;
            break;
        case 1:
            cout << PRE_ESSENCE << essence[0] << COMPL_BY << endl;
            do_Task_1();
            SEP
            break;
        case 2:
            cout << PRE_ESSENCE << essence[1] << COMPL_BY << endl;
            do_Task_2();
            SEP
            break;
        case 3:
            cout << PRE_ESSENCE << essence[2] << COMPL_BY << endl;
            do_Task_3();
            SEP
            break;
        default:
            cout << "Ошибка. Введите число, соответствующее пункту меню" << endl;
            SEP
            break;
        }
    }
    return;
}