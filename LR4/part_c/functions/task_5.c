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
    field[2][2] = '*';

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
            if (field[row][col] != '.') continue;
            int count_bombs = 0;
            if (row - 1 >= 0) {
                if (field[row - 1][col] == '*') {
                    count_bombs++;
                }
            }
            
            if (col - 1 >= 0) {
                if (field[row][col - 1] == '*') {
                    count_bombs++;
                }
            }

            if (row - 1 >= 0 && col - 1 >= 0) {
                if (field[row - 1][col - 1] == '*') {
                    count_bombs++;
                }
            }
            
            if (row + 1 < rows) {
                if (field[row + 1][col] == '*') {
                    count_bombs++;
                }
            }

            if (col + 1 < columns) {
                if (field[row][col + 1] == '*') {
                    count_bombs++;
                }
            }

            if (row + 1 < rows && col + 1 < columns) {
                if (field[row + 1][col + 1] == '*') {
                    count_bombs++;
                }
            }

            if (row + 1 < rows && col - 1 >=0) {
                if (field[row + 1][col - 1] == '*') {
                    count_bombs++;
                }
            }

            if (row - 1 >= 0 && col + 1 < columns) {
                if (field[row - 1][col + 1] == '*') {
                    count_bombs++;
                }
            }

            if (count_bombs) {
                field[row][col] = count_bombs + '0';
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