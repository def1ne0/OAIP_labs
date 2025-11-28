#include <print>

#include "run_tasks.h"

namespace tasks {
    void run_task(
        int choice,
        void (*func_array[])()
    ) {
        func_array[choice - 1]();
        std::println("*********************");

        return;
    }
}
