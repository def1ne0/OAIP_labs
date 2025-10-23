#include <stdlib.h>
#include <stdio.h>

#include "task_5.h"

char **create_field(int rows, int columns) {
    char **field = (char **) malloc(rows * sizeof(char *));

    for (unsigned row = 0; row < rows; row++) {
        field[row] = (char *) malloc(columns * sizeof(int)); 
    }

    for (unsigned row = 0; row < rows; row++) {
        for (unsigned col = 0; col < columns; col++) {
            field[row][col] = '.';
        }
    }

    field[0][1] = '*';
    field[3][2] = '*';

    return field;
}

void print_field(char **field, int rows, int columns) {
    for (unsigned row = 0; row < rows; row++) {
        for (unsigned col = 0; col < columns; col++) {
            printf("%c", field[row][col]);
            printf(" ");
        }

        printf("\n");
    }
}

char **set_numbers(char **field, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {
            if (field[row][col] == '*') {
                field[row][col] = '1';
            }
        }
    }

    return field;
}

void do_task_5() {
    const int rows = 5;
    const int columns = 5;
    char **field = create_field(rows, columns);

    field = set_numbers(field, rows, columns);

    print_field(field, rows, columns);

    for (unsigned row = 0; row < rows; row++) {
        free(field[row]);
    }

    free(field);
}