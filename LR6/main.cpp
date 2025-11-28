#include <cstdio>
#include <print>
#include <pthread.h>

#include "MyStr.h"
#include "c_str_utils.h"
#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
#include "run_tasks.h"

void menu();

int main(int argc, char **argv) {
    menu();
}

void menu() {
    bool exit = false;

    while (!exit) {
        std::println(" 0 -> Выход\n n -> Запуск n задания (1-3)");

        str::MyStr input;
        int choice;
        bool is_correct = false;

        while (!is_correct) {
            std::println("Введите пункт меню");
            input.input_by_getchar();

            if (input.length() == 1 && input[0] <= '3' && input[0] >= '0') {
                is_correct = true;
            } else {
                std::println("Неверный пункт меню");
                input.clear();
            }
        }

        choice = input.to_unsigned_int();

        void (*tasks_list[5]) () = {
            task_1::do_task_1,
            task_2::do_task_2,
            task_3::do_task_3
        };

        switch (choice) {
            case 0:
                exit = true;
                break;
            default:
                tasks::run_task(choice, tasks_list);
        }
    }
}
