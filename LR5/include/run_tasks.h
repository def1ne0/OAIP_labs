#pragma once

#include <string>
#include <vector>

namespace tasks {
    void run_task(
        int &,
        void (*[]) (),
        const std::vector<std::string> &,
        const std::string &
    );
}
