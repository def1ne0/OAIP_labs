#include <stdio.h>

#include "airport.h"

int main() {
    Flight *flights = NULL;
    int size = 0;
    int choice;

    init_flight_array(&flights, &size);

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                input_flights(&flights, &size);
                break;
            case 2:
                display_flights(flights, size);
                break;
            case 0:
                printf("Выход из программы.\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    free_flight_array(&flights);

    return 0;
}
