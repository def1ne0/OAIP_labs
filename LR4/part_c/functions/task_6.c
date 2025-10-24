#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "task_6.h"
#include "check_input.h"

void odd_square(int **square, int n) {
    int num = 1;
    int i = 0;            
    int j = n / 2;       

    while (num <= n * n) {
        square[i][j] = num++;

        int new_i = (i - 1 + n) % n;  
        int new_j = (j + 1) % n;      

        if (square[new_i][new_j] != 0) {
            i = (i + 1) % n;
        } else {
            i = new_i;
            j = new_j;
        }
    }
}

void doubly_even_square(int **square, int n) {
    unsigned i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            square[i][j] = (n * i) + j + 1;
        }
    }

    for (i = 0; i < n / 4; i++) {
        for (j = 0; j < n / 4; j++) {
            square[i][j] = (n * n + 1) - square[i][j];
        }
    }

    for (i = 0; i < n / 4; i++) {
        for (j = 3 * (n / 4); j < n; j++) {
            square[i][j] = (n * n + 1) - square[i][j];
        }
    }

    for (i = 3 * (n / 4); i < n; i++) {
        for (j = 0; j < n / 4; j++) {
            square[i][j] = (n * n + 1) - square[i][j];
        }
    }

    for (i = 3 * (n / 4); i < n; i++) {
        for (j = 3 * (n / 4); j < n; j++) {
            square[i][j] = (n * n + 1) - square[i][j];
        }
    }

    for (i = n / 4; i < 3 * (n / 4); i++) {
        for (j = n / 4; j < 3 * (n / 4); j++) {
            square[i][j] = (n * n + 1) - square[i][j];
        }
    }
}

void singly_even_square(int **square, int n) {
    int p = n / 2;

    int **M = create_square(p); 

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            square[i][j] = M[i][j];              
            square[i + p][j] = M[i][j] + 3 * p * p; 
            square[i][j + p] = M[i][j] + 2 * p * p; 
            square[i + p][j + p] = M[i][j] + p * p; 
        }
    }

    if (n == 2) return; 

    int k = (p - 1) / 2; 
    
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < k; j++) {
            int l = square[i][j];
            square[i][j] = square[i + p][j];
            square[i + p][j] = l;
        }
    }

    for (int i = 0; i < p; i++) {
        for (int j = n - k + 1; j < n; j++) { 
            int l = square[i][j];
            square[i][j] = square[i + p][j];
            square[i + p][j] = l;
        }
    }

    int s = square[k][0];
    square[k][0] = square[k + p][0];
    square[k + p][0] = s;

    int l = square[k][k];
    square[k][k] = square[k + p][k];
    square[k + p][k] = l;
}

int **create_square(int n) {
    int **square = (int **) malloc(n * sizeof(int *));

    for (unsigned row = 0; row < n; row++) {
        square[row] = (int *) malloc(n * sizeof(int));
    }

    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            square[i][j] = 0;
        }
    }

    if (n % 2 != 0) {
        odd_square(square, n);
    } else if (n % 4 == 0) {
        doubly_even_square(square, n);
    } else {
        singly_even_square(square, n);
    }

    return square;
}

void print_square(int **square, int n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n; j++) {
            printf("%d", square[i][j]);
            printf(" ");
        }

        printf("\n");
    }
}

void do_task_6() {
    int n;
    printf("Введите порядок квадрата (минмум 1)\n");
    n = input_int(1, INT_MAX);

    int **square = create_square(n);
    print_square(square, n);

    for (unsigned i = 0; i < n; i++) {
        free(square[i]);
    }

    free(square);
}