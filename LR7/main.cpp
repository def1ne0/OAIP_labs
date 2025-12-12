#include <print>
#include <string>
#include <dlfcn.h>

#include "check_cin.h"
#include "run_tasks.h"
#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
#include "task_4.h"
#include "task_5.h"

void menu();

int main(int argc, char **argv) {
    menu();
}

void menu() {
    bool exit = false;

    void (*tasks_list[5]) () = {
        task_1::do_task_1,
        task_2::do_task_2,
        task_3::do_task3,
        task_4::do_task_4,
        task_5::do_task_5
    };

    while (!exit) {
        std::println(" 0 -> Выход\n n -> Запуск n задания (1-5)");

        int choice = io::input_value<int>("Введите пункт меню", "Неверный пункт меню", true, 0, 5);

        switch (choice) {
            case 0:
                exit = true;
                break;
            default:
                tasks::run_task(choice, tasks_list);
        }
    }
}
