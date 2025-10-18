#pragma once

#include <iostream>
#include <vector>

namespace tasks {
    void run_task(
        int &choice, 
        void (*func_array[])(), 
        const std::vector<std::string> essence, 
        const std::string compl_by
    );
}