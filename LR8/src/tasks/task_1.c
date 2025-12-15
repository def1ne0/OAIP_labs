#include <stdio.h>

#include "airport.h"

int main() {
    Flight *flights = NULL;
    int size = 0;
    int choice;

    init_flight_array(&flights, &size);

    do {
        print_menu();
        input_non_negative_int(&choice);

        switch (choice) {
            case 1:
                input_flights(&flights, &size);
                break;
            case 2:
                display_flights(flights, size);
                break;
            case 3:
                destroy_flight_array(&flights, &size);
                input_flights(&flights, &size);
                break;
            case 4:
                search_by_destination(flights, size);
                break;
            case 5:
                delete_flight_by_number(&flights, &size);
                break;
            case 6:
                update_flight_by_number(flights, size);
                break;
            case 7:
                sort_flights_by_departure_time(flights, size);
                break;
            case 8:
                save_flights_to_binary_file(flights, size);
                break;
            case 9:
                load_flights_from_binary_file(&flights, &size);
                break;
            case 10:
                update_flight_in_binary_file();
                break;
            case 0:
                printf("Выход из программы.\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    destroy_flight_array(&flights, &size);

    return 0;
}
