#ifndef AIRPORT_H
#define AIRPORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct {
    int flight_number;      // Номер рейса (целое число)
    char aircraft_type[50]; // Тип самолета (строка)
    char destination[100];  // Пункт назначения (строка)
    int departure_time;     // Время вылета в минутах с начала суток (целое число)

    union {
        int time_minutes;   // Время в минутах (как в departure_time)
        char time_string[10]; // Время в формате "HH:MM" (например, "13:50")
    } time_data;
} Flight;

// *flights - указатель на первый элемент массива flights
// **flights - указатель на указатель на первый элемент массива flights, чтобы изменять массив исходный,
// ведь Flight *flights копируется

void input_non_negative_int(int *input);

void init_flight_array(Flight **flights, int *size);
void destroy_flight_array(Flight **flights, int *size);
void input_flights(Flight **flights, int *size);
void display_flights(Flight *flights, int size);
void search_by_destination(Flight *flights, int size);
void delete_flight_by_number(Flight **flights, int *size);
void update_flight_by_number(Flight *flights, int size);
void sort_flights_by_departure_time(Flight *flights, int size);
void print_menu();

void save_flights_to_binary_file(Flight *flights, int size);
void load_flights_from_binary_file(Flight **flights, int *size);
void update_flight_in_binary_file(void);

#ifdef __cplusplus
}
#endif

#endif // AIRPORT_H
