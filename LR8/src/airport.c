#include "airport.h"
#include <stdio.h>
#include <stdlib.h>

void init_flight_array(Flight **flights, int *size) {
    *size = 0;
    *flights = NULL;
}

void free_flight_array(Flight **flights) {
    if (*flights != NULL) {
        free(*flights);
        *flights = NULL;
    }
}

void input_flights(Flight **flights, int *size) {
    int count;

    printf("Введите количество рейсов: ");
    scanf("%d", &count);

    *flights = realloc(*flights, (*size + count) * sizeof(Flight));

    if (*flights == NULL) {
        printf("\nОшибка при выделении памяти\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        printf("\n -> Ввод рейса #%d \n", *size + i + 1);

        printf("Номер рейса: ");
        scanf("%d", &(*flights)[*size + i].flight_number);

        printf("\nТип самолета: ");
        scanf("%s", (*flights)[*size + i].aircraft_type);

        printf("\nПункт назначения: ");
        scanf("%s", (*flights)[*size + i].destination);

        printf("\nВремя вылета (в минутах с начала суток, например, 830 для 13:50): ");
        scanf("%d", &(*flights)[*size + i].departure_time);
    }

    *size += count;
}

void display_flights(Flight *flights, int size) {
    if (size == 0) {
        printf("Массив пуст\n");
    }

    printf("--- Список всех рейсов ---\n");

    for (int i = 0; i < size; i++) {
        printf("Рейс #%d | Самолет: %s | Назначение: %s | Время: %d мин \n",
            flights[i].flight_number,
            flights[i].aircraft_type,
            flights[i].destination,
            flights[i].departure_time
        );
    }
}

void print_menu() {
    printf("\n===== МЕНЮ =====\n");
    printf(" -> 0. Выход\n");
    printf(" -> 1. Ввести данные о рейсах\n");
    printf(" -> 2. Просмотреть все рейсы\n");
    printf(" -> 3. Добавить новый рейс\n");
    printf(" -> 4. Найти рейсы по пункту назначения\n");
    printf(" -> 5. Удалить рейс по номеру\n");
    printf(" -> 6. Изменить данные рейса по номеру\n");
    printf(" -> 7. Отсортировать рейсы по времени вылета\n");
    printf("Выберите действие (1-8): ");
}
