#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
                arr[i][j][k] = (int) (k + 1);
            }
        }
    }

    return arr;
}

int find_max_diagonal(int ***arr, int n) {
    int max_sums[4] = {0, 0, 0, 0};

    for (unsigned i = 0; i < n; i++) {
        max_sums[0] += arr[i][i][i]; 
        max_sums[1] += arr[i][n - 1 - i][i];
        max_sums[2] += arr[i][n - 1 - i][n - 1 - i];
        max_sums[3] += arr[i][i][n - 1 - i];  
    }

    int max_sum = max_sums[0];

    for (unsigned i = 1; i < 4; i++) {
        if (max_sum < max_sums[i]) {
            max_sum = max_sums[i];
        }
    }

    return max_sum;
}

void print_arr(int ***arr, int n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            printf("%d", arr[i][j][j]);
            printf(" ");
        }

        printf("\n");
    }

    printf("/////////////////////////\n");

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            printf("%d", arr[i][n - 1 - j][n - 1 - j]);
            printf(" ");
        }

        printf("\n");
    }
}

void do_task_4() {
    int n;
    printf("Введите n\n");
    n = input_int(INT_MIN, INT_MAX);

    int ***arr = create_default_arr(n);

    print_arr(arr, n);

    printf("%s", "Максимальная диагональ: ");
    printf("%d", find_max_diagonal(arr, n));
    printf("\n");

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            free(arr[i][j]);
        }

        free(arr[i]);
    }

    free(arr);
}
