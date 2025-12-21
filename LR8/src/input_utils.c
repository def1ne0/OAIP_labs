#include <stdio.h>
#include <stdbool.h>

#include "input_utils.h"

void clear_buff() {
    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

void input_unsigned(int *input) {
    while (true) {
        if (scanf("%d", input) && *input > 0) {
            clear_buff();

            return;
        } else {
            printf("Введите положительное число\n");

            clear_buff();
        }
    }
}

void input_non_negative_int(int *input) {
    while (true) {
        if (scanf("%d", input) && *input >= 0) {
            clear_buff();

            return;
        } else {
            printf("Введите неотрицательное число\n");

            clear_buff();
        }
    }
}