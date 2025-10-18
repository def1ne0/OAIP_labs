#include <iostream>

#include "check_cin_func.h"

int main () {
    int n = io::input_value<int>("input", "error", true, 1, 4);

    std::cout << n << std::endl;
}