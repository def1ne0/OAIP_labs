#include <stdio.h>
#include <stdlib.h>

#include "check_input.h"
#include "task_4.h"

int ***create_default_arr(int n) {
    int ***arr = (int ***) malloc(n * sizeof(int **));

    for (unsigned i = 0; i < n; i++) {
        arr[i] = (int**) malloc(n * sizeof(int *));
        for (unsigned j = 0; j < n; j++) {
            arr[i][j] = (int *) malloc(n * sizeof(int));
        }
    }

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            for (unsigned k = 0; k < n; k++) {
                arr[i][j][k] = (int) (i + j - k);
            }
        }
    }

    return arr;
}

void do_task_4() {
    int n;
    printf("Введите n\n");
    n = input_int();

    int ***arr = create_default_arr(n);

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            free(arr[i][j]);
        }

        free(arr[i]);
    }

    free(arr);
}
