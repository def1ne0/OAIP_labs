#include <iostream>
#include <vector>

#include "check_cin_func.h"
#include "task_1.h"
#include "task_2.h"
#include "run_tasks.h"

void menu() {
    bool exit = false;

    const std::vector<std::string> essence = {
            "Ввести одномерный статический массив из k чисел. Определить количество инверсий в массиве",
            "Инициализировать при объявлении статический двумерный массив целых чисел размером MxN. Найти в каждом столбце матрицы минимальный элемент."
        };
    const std::string pre_essence = "Суть задания\n ";
    const std::string compl_by = "\nВыполнил Финевич Арсений\nВариант 12";

    void (*tasks_array[3])() = {
        t1::do_task_1,
        t2::do_task_2
    };

    while (!exit) {
        int choice = io::input_value<int>(
            "Выберите пункт меню:\n 0. Выйти\n n. Введите n, где n - номер задания (1-3)", 
            "Ошибка, введите число, соответствующее пункту меню",
            true,
            0,
            3
        );

        switch (choice) {
            case 0:
                exit = true;
                break;
            default:
                tasks::run_task(choice, tasks_array, essence, compl_by);
                break;
        }
        
    }
}

int main () {
    menu();
}