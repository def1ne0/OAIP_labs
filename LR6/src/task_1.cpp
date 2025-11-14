#include <print>

#include "MyStr.h"
#include "check_cin.h"
#include "task_1.h"

namespace task_1 {
    void do_task_1() {
        str::MyStr some_str((char *)"Hello world this is a test string");
        int k = io::input_value("Введите k", "Ошибка", true, 1);

        some_str.execute_task_1(k);
        return;
    }
}
