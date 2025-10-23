#include <stdio.h>

#include "check_input.h"
#include "run_tasks_c.h"
#include "task_4.h"

void menu(void);

int main() {
    menu();
}

void menu() {
    int exit = 0;

    while (!exit) {
        printf("Введите:\n 0. Для выхода\n n. Для выбора n - номера задания на C (1-3)\n");

        void (*tasks_array[3]) () = {
            do_task_4
        };

        int choice = input_int(1, 3);

        switch (choice) {
            case 0:
                exit = 1;
                break;
            default:
                run_task(tasks_array, choice);
                break;
        }
    }
}