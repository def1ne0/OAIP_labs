#include "airport.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    printf("Рейсы успешно добавлены\n");
}

void display_flights(Flight *flights, int size) {
    if (size == 0) {
        printf("Массив пуст\n");
    }

    printf("*** Список всех рейсов ***\n");

    for (int i = 0; i < size; i++) {
        printf("Рейс #%d | Самолет: %s | Назначение: %s | Время: %d мин \n",
            flights[i].flight_number,
            flights[i].aircraft_type,
            flights[i].destination,
            flights[i].departure_time
        );
    }
}

void search_by_destination(Flight *flights, int size) {
    char target_dest[100];
    printf("Введите пункт назначения для поиска: ");
    scanf("%s", target_dest);

    bool found = false;
    printf("\n *** Рейсы в пункт назначения %s ***\n", target_dest);

    for (int i = 0; i < size; i++) {
        if (strcmp(flights[i].destination, target_dest) == 0) {
            printf("Рейс #%d | Самолет: %s | Время: %d мин\n",
                flights[i].flight_number,
                flights[i].aircraft_type,
                flights[i].departure_time
            );

            found = true;
        }
    }

    if (!found) printf("Рейсы в пункт %s не найдены\n", target_dest);
}

void delete_flight_by_number(Flight **flights, int *size) {
    int inputed_index;
    printf("Введите рейс для удаления: ");
    scanf("%d", &inputed_index);

    int index = -1;

    for (int i = 0; i < *size; i++) {
        if ((*flights)[i].flight_number == inputed_index) {
            index = inputed_index;
            break;
        }
    }

    if (index == -1) {
        printf("Рейс #%d не найден\n", inputed_index);
    }

    for (int i = index; i < *size - 1; i++) {
        (*flights)[i] = (*flights)[i + 1];
    }

    (*size)--;

    *flights = realloc(*flights, *size * sizeof(Flight));

    if (*size > 0 && *flights == NULL) {
        printf("realloc вернул NULL");
        exit(1);
    }

    printf("Рейс #%d успешно удален\n", inputed_index);
}

void update_flight_by_number(Flight *flights, int size) {
    int inputed_index;
    printf("Введите номер рейса для изменения: ");
    scanf("%d", &inputed_index);

    int index = -1;

    for (int i = 0; i < size; i++) {
        if (flights[i].flight_number == inputed_index) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Рейс #%d не найден\n", inputed_index);
        return;
    }

    printf("*** Текущие данные рейса ***\n");
    printf("Рейс #%d | Самолет: %s | Назначение: %s | Время: %d мин \n",
        flights[index].flight_number,
        flights[index].aircraft_type,
        flights[index].destination,
        flights[index].departure_time
    );

    printf("*** Введите новые данные ***\n");

    printf("Номер рейса: ");
    scanf("%d", &flights[index].flight_number);

    printf("\nТип самолета: ");
    scanf("%s", flights[index].aircraft_type);

    printf("\nПункт назначения: ");
    scanf("%s", flights[index].destination);

    printf("\nВремя вылета (в минутах с начала суток, например, 830 для 13:50): ");
    scanf("%d", &flights[index].departure_time);

    printf("Данные рейса #%d обновлены\n", inputed_index);
}

static int compare(const void *a, const void *b) {
    Flight *first = (Flight *) a;
    Flight *second = (Flight *) b;

    return first->departure_time - second->departure_time;
}

/*static void quick_sort_flights(Flight *flights, int low, int high) {

    if (low < high) {
        int item = flights[high].departure_time;
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (flights[i].departure_time <= item) {
                i++;
                Flight temp = flights[i];
                flights[i] = flights[j];
                flights[j] = temp;
            }
        }

        Flight temp = flights[i + 1];
        flights[i + 1] = flights[high];
        flights[high] = temp;

        quick_sort_flights(flights, low, i);
        quick_sort_flights(flights, i + 2, high);
    }
} */

void sort_flights_by_departure_time(Flight *flights, int size) {
    if (size <= 1) {
        printf("Недостаточно элементов (всего элементов %d) для сортировки\n", size);
        return;
    }

    qsort(flights, size, sizeof(Flight), compare);
    printf("Массив успешно отсортирован по времени вылета по возрастанию\n");
}

void save_flights_to_binary_file(Flight *flights, int size) {
    char filename[100];
    printf("Введите название файла, в который буду записаны данные: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Произошла ошибка при записи в двоичный файл\n");
        return;
    }

    fwrite(&size, sizeof(int), 1, file);

    if (size > 0) {
        fwrite(flights, sizeof(Flight), size, file);
    }

    fclose(file);

    printf("Данные были успешно записаны в файл %s\n", filename);
}

void load_flights_from_binary_file(Flight **flights, int *size) {
    char filename[100];
    printf("Введите название бинарного файла, который хотите загрузить: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    fread(size, sizeof(int), 1, file);

    *flights = realloc(*flights, *size * sizeof(Flight));

    if (*size > 0 && *flights == NULL) {
        printf("realloc вернул NULL\n");
        fclose(file);
        exit(1);
    }

    if (*size > 0) {
        fread(*flights, sizeof(Flight), *size, file);
    }

    fclose(file);

    printf("Данные успешно загружены из файла %s\n", filename);
}

void update_flight_in_binary_file() {
    int flight_number_to_correct;
    char filename[100];
    printf("Введите название файла для корректровки: ");
    scanf("%s", filename);

    printf("Введите номер рейса для корректировки: ");
    scanf("%d", &flight_number_to_correct);

    FILE *file = fopen(filename, "r+b");

    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    int size;
    fread(&size, sizeof(int), 1, file);

    bool found = false;

    for (int i = 0; i < size; i++) {
        Flight current_flight;
        fread(&current_flight, sizeof(Flight), size, file);

        if (current_flight.flight_number == flight_number_to_correct) {
            printf("*** Текущие данные рейса ***\n");
            printf("Рейс #%d | Самолет: %s | Назначение: %s | Время: %d мин \n",
                current_flight.flight_number,
                current_flight.aircraft_type,
                current_flight.destination,
                current_flight.departure_time
            );

            printf("*** Введите новые данные ***\n");

            printf("\nТип самолета: ");
            scanf("%s", current_flight.aircraft_type);

            printf("\nПункт назначения: ");
            scanf("%s", current_flight.destination);

            printf("\nВремя вылета (в минутах с начала суток, например, 830 для 13:50): ");
            scanf("%d", &current_flight.departure_time);

            int hours = current_flight.departure_time / 60;
            int minutes = current_flight.departure_time % 60;
            sprintf(current_flight.time_data.time_string, "%02d:%02d", hours, minutes);

            fseek(file, sizeof(int) + i * sizeof(Flight), SEEK_SET);
            fwrite(&current_flight, sizeof(Flight), 1, file);

            printf("Рейс #%d успешно скорректирован в файле %s\n", flight_number_to_correct, filename);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Не найден рейс #%d\n", flight_number_to_correct);
    }

    fclose(file);
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
    printf(" -> 8. Сохранить данные в бинарный файл\n");
    printf(" -> 9. Загрузить данные из бинарного файла\n");
    printf(" -> 10. Изменить данные в бинарном файле\n");
    printf("Выберите действие (0-10): ");
}
