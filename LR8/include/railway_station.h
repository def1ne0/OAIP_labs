#ifndef RAILWAY_STATION_H
#define RAILWAY_STATION_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdbool.h>

typedef struct {
    int bus_number; // Номер рейса 
    char bus_type[50]; // Тип самолета 
    char destination[100];  // Пункт назначения 
    int departure_time; // Время вылета в минутах с начала суток 
    int arrival_time; // Время прибытия в минутах с начала суток 

    union {
        int time_minutes;   // Время в минутах (как в departure_time)
        char time_string[10]; // Время в формате "HH:MM" (например, "13:50")
    } time_data;
} Bus;

// Bus *buses- указатель на первый элемент массива flights
// Bus **buses - указатель на указатель на первый элемент массива flights, чтобы изменять массив исходный,
// ведь Bus *buses копируется

void input_non_negative_int(int *input);

void init_bus_array(Bus **buses, int *size);
void destroy_bus_array(Bus **buses, int *size);
void input_buses(Bus **buses, int *size);
void display_buses(Bus *buses, int size);
void search_by_destination(Bus *buses, int size);
void delete_bus_by_number(Bus **buses, int *size);
void update_bus_by_number(Bus *buses, int size);
void sort_buses_by_departure_time(Bus *buses, int size);
void search_buses_before_time(Bus *buses, int size);

void save_buses_to_binary_file(Bus *buses, int size);
void load_buses_from_binary_file(Bus **buses, int *size);
void update_bus_in_binary_file(void);

void print_menu();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // RAILWAY_STATION_H
