#include <print>

#include "MyStr.h"
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
        std::optional<int> choice;
        bool is_correct = false;

        while (!is_correct) {
            std::println("Введите пункт меню");
            input.input_by_getchar();

            if (input.length() == 1) {
                choice = input.to_unsigned_int();

                if (choice.has_value()) {
                    is_correct = true;
                } else {
                    std::println("Неверный пункт меню, введите число");
                }
            } else {
                std::println("Неверный пункт меню");
                input.clear();
            }
        }

        void (*tasks_list[3]) () = {
            task_1::do_task_1,
            task_2::do_task_2,
            task_3::do_task_3
        };

        switch (choice.value()) {
            case 0:
                exit = true;
                break;
            default:
                tasks::run_task(choice.value(), tasks_list);
        }
    }
}
