#include <stdio.h>

#include "run_tasks_c.h"

void run_task(void (*tasks[]) (), int choice) {
    printf("******************************\n");
    tasks[choice - 1]();
    printf("******************************\n");
}

