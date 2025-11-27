#include <print>

#include "MyStr.h"

namespace task_2 {
    void input_str(char *str) {
        int c;
        int i {};

        while (i < 79 && (c = getchar()) != EOF && c != '\n') {
            str[i] = static_cast<char>(c);
            i++;
        }

        str[i] = '\0';
    }

    size_t find_biggest(int *arr, size_t size) {
        int max = arr[0];
        size_t max_idx = -1;

        for (size_t i = 1; i < size; i++) {
            if (max < arr[i]) {
                max = arr[i];
                max_idx = i;
            }
        }

        return max_idx;
    }

    void execute_task_2(str::MyStr text) {
        int frequencies[256] {0};

        for (size_t i = 0; i < text.length(); i++) {
            unsigned char element = text[i];
            frequencies[static_cast<int>(element)]++;
        }

        for (size_t i = 0; i < 3; i++) {
            size_t idx_biggest = find_biggest(frequencies, 256);

            if (idx_biggest == -1) break;

            std::println("{} по частоте: {}", i + 1, static_cast<char>(idx_biggest));
            frequencies[idx_biggest] = 0;
        }
    }

    void execute_task_2(char *text) {
        int frequencies[256] {0};

        for (size_t i = 0; text[i] != '\0'; i++) {
            unsigned char element = text[i];
            frequencies[static_cast<int>(element)]++;
        }

        for (size_t i = 0; i < 3; i++) {
            size_t idx_biggest = find_biggest(frequencies, 256);

            if (idx_biggest == -1) break;

            std::println("{} по частоте: {}", i + 1, static_cast<char>(idx_biggest));
            frequencies[idx_biggest] = 0;
        }
    }

    void do_task_2() {
        //char text[80];
        str::MyStr text;

        std::println("Введите текст");

        //input_str(text);

        text.input_by_getchar();

        execute_task_2(text);

        return;
    }
}
