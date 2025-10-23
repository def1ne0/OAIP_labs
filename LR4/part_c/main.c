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
        printf("Введите:\n 0. Для выхода\n n. Для выбора n - номера задания (4-6)\n");

        void (*tasks_array[3]) () = {
            do_task_4
        };

        int choice = input_int(4, 6);

        switch (choice) {
            case 0:
                exit = 1;
                break;
            default:
                run_task(tasks_array, choice - 3);
                break;
        }
    }
}