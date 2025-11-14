#include <print>
#include <string>

#include "check_cin.h"
#include "task_1.h"
#include "run_tasks.h"

void menu();

int main(int argc, char **argv) {
    menu();
}

void menu() {
    bool exit = false;

    while (!exit) {
        std::println(" 0 -> Выход\n n -> Запуск n задания (1-5)");

        int choice = io::input_value<int>("Введите пункт меню", "Неверный пункт меню", true, 0, 5);
        const std::string compl_by = "\nВыполнил Финевич Арсений\nВариант 12";
        const std::vector<std::string> essence = {
            "Дана строка, состоящая из слов, разделенных пробелами. Разбить исходную строку на две подстроки, причем первая длиной k символов, если на k-ю позицию попадает слово, то его следует отнести ко второй строке. Значение k вводится с клавиатуры."
        };

        void (*tasks_list[5]) () = {
            task_1::do_task_1,
        };

        switch (choice) {
            case 0:
                exit = true;
                break;
            default:
                tasks::run_task(choice, tasks_list, essence, compl_by);
        }
    }
}
