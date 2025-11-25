#include <print>

#include "MyStr.h"

namespace task_2 {
    size_t find_biggest(int *arr, size_t size) {
        int max = arr[0];
        size_t max_idx = 0;

        for (size_t i = 1; i < size; i++) {
            if (max < arr[i]) {
                max = arr[i];
                max_idx = i;
            }
        }

        return max_idx;
    }

    void execute_task_2(str::MyStr text) {
        int frequencies[128] {0};

        for (size_t i = 0; text[i] != '\0'; i++) {
            unsigned char element = text[i];
            frequencies[static_cast<int>(element)]++;
        }

        for (size_t i = 0; i < 3; i++) {
            size_t idx_biggest = find_biggest(frequencies, 128);
            std::println("{} по частоте: {}", i + 1, static_cast<char>(idx_biggest));
            frequencies[idx_biggest] = 0;
        }
    }

    void execute_task_2(char *text) {
        int frequencies[128] {0};

        for (size_t i = 0; text[i] != '\0'; i++) {
            unsigned char element = text[i];
            frequencies[static_cast<int>(element)]++;
        }

        for (size_t i = 0; i < 3; i++) {
            size_t idx_biggest = find_biggest(frequencies, 128);
            std::println("{} по частоте: {}", i + 1, static_cast<char>(idx_biggest));
            frequencies[idx_biggest] = 0;
        }
    }

    void do_task_2() {
        //char *text = (char *) "SIGMA PENCIL AAAAAAAAAA BBBBB dddddd";
        str::MyStr text = (char *) "SIGMA PENCIL AAAAAAAAAA BBBBB dddddd";
        str::MyStr sigma = (char *) " ultrasigma";

        text.concat(sigma);

        text += (char *) "pencil";

        std::println("{}", text.c_str());

        return;
    }
}
