#include <stdio.h>
#include <limits.h>

#include "check_input.h"
#include "run_tasks_c.h"
#include "task_4.h"
#include "task_5.h"

void menu(void);

int main() {
    menu();
}

void menu() {
    int exit = 0;

    while (!exit) {
        printf("Введите:\n 0. Для выхода\n n. Для выбора n - номера задания на C (4-6)\n");

        void (*tasks_array[3]) () = {
            do_task_4,
            do_task_5
        };

        int choice = input_int(0, 6);

        switch (choice) {
            case 0:
                exit = 1;
                break;
            case 4:
            case 5:
            case 6:
                run_task(tasks_array, choice - 3);
                break;
            default:
                printf("Неверный пункт меню\n");
        }
    }
}