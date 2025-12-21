#include <stdio.h>

#include "railway_station.h"

int main() {
    Bus *buses = NULL;
    int size = 0;
    int choice;

    init_bus_array(&buses, &size);

    do {
        print_menu();
        input_non_negative_int(&choice);

        switch (choice) {
            case 1:
                destroy_bus_array(&buses, &size);
                input_buses(&buses, &size);
                break;
            case 2:
                display_buses(buses, size);
                break;
            case 3:
                input_buses(&buses, &size);
                break;
            case 4:
                search_by_destination(buses, size);
                break;
            case 5:
                delete_bus_by_number(&buses, &size);
                break;
            case 6:
                update_bus_by_number(buses, size);
                break;
            case 7:
                sort_buses_by_departure_time(buses, size);
                break;
            case 8:
                search_buses_before_time(buses, size);
                break;
            case 9:
                save_buses_to_binary_file(buses, size);
                break;
            case 10:
                load_buses_from_binary_file(&buses, &size);
                break;
            case 11:
                update_bus_in_binary_file();
                break;
            case 0:
                printf("Выход из программы.\n");
                break;
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    } while (choice != 0);

    destroy_bus_array(&buses, &size);

    return 0;
}
