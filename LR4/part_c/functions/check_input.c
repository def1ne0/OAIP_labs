#include <stdio.h>

#include "check_input.h"

int input_int(int min, int max ) {
    int exit = 0;
    int input;
    char c;

    while(!exit) {
        if (scanf("%d", &input)) {
            if (input >= min && input <= max) {
                exit = 1;
            } else {
                printf("%s", "Ошибка, выход из диапазона, повторите попытку\n");
            }
        } else {
            printf("%s", "Ошибка, повторите попытку\n");
        }

        while ((c = getchar()) != '\n' && c != EOF);
    }

    return input;
}
