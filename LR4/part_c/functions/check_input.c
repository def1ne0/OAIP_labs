#include <stdio.h>

#include "check_input.h"

int input_int() {
    int exit = 0;
    int input;
    char c;

    while(!exit) {
        if (!scanf("%d", &input)) {
            printf("%s", "Ошибка, повторите попытку\n");
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            exit = 1;
        }
    }

    return input;
}
