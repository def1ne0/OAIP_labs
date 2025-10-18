#include <iostream>
#include <vector>

#include "run_tasks.h"

namespace tasks {
    void run_task(
        int &choice, 
        void (*func_array[])(), 
        const std::vector<std::string> essence, 
        const std::string compl_by
    ) {
        std::cout << "Суть задания:\n " << essence[choice - 1] << compl_by << std::endl;
        func_array[choice - 1]();
        std::cout << "*****************" << std::endl;
    }
}