#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "input_utils.h"
#include "railway_station.h"

void init_bus_array(Bus **buses, int *size) {
    *size = 0;
    *buses = NULL;
}

void destroy_bus_array(Bus **buses, int *size) {
    free(*buses);
    *buses = NULL;
    *size = 0;
}

void input_buses(Bus **buses, int *size) {
    int count;

    printf("Введите количество рейсов: ");
    input_unsigned(&count);

    *buses = realloc(*buses, (*size + count) * sizeof(Bus));

    if (*buses == NULL) {
        printf("\nОшибка при выделении памяти\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        printf("\n -> Ввод рейса #%d \n", *size + i + 1);

        (*buses)[*size + i].bus_number = *size + i + 1;

        printf("\nТип автобуса: ");
        scanf("%49s", (*buses)[*size + i].bus_type);
        clear_buff();

        printf("\nПункт назначения: ");
        scanf("%99s", (*buses)[*size + i].destination);
        clear_buff();

        printf("\nВремя отправления (в минутах с начала суток, например, 830 для 13:50): ");
        input_unsigned(&(*buses)[*size + i].departure_time);
        
        printf("\nВремя прибытия (в минутах с начала суток, например, 830 для 13:50): ");
        input_unsigned(&(*buses)[*size + i].arrival_time);

        int hours = (*buses)[*size + i].departure_time / 60;
        int minutes = (*buses)[*size + i].departure_time % 60;
        sprintf((*buses)[*size + i].time_data.time_string, "%02d:%02d", hours, minutes);
    }

    *size += count;

    printf("Рейсы успешно добавлены\n");
}

void display_buses(Bus *buses, int size) {
    if (size == 0) {
        printf("Массив пуст\n");
        return;
    }

    printf("*** Список всеzх рейсов ***\n");

    for (int i = 0; i < size; i++) {
        printf("Рейс #%d | Автобус: %s | Назначение: %s | Время отправления: %d мин | Время прибытия: %d мин \n",
            buses[i].bus_number,
            buses[i].bus_type,
            buses[i].destination,
            buses[i].departure_time,
            buses[i].arrival_time
        );
    }
}

void search_by_destination(Bus *buses, int size) {
    char target_dest[100];
    printf("Введите пункт назначения для поиска: ");
    scanf("%99s", target_dest);
    clear_buff();

    bool found = false;
    printf("\n *** Рейсы в пункт назначения %s ***\n", target_dest);

    for (int i = 0; i < size; i++) {
        if (strcmp(buses[i].destination, target_dest) == 0) {
            printf("Рейс #%d | Автобус: %s | Назначение: %s | Время отправления: %d мин | Время прибытия: %d мин \n",
                buses[i].bus_number,
                buses[i].bus_type,
                buses[i].destination,
                buses[i].departure_time,
                buses[i].arrival_time
            );

            found = true;
        }
    }

    if (!found) printf("Рейсы в пункт %s не найдены\n", target_dest);
}

void delete_bus_by_number(Bus **buses, int *size) {
    int inputed_index;
    printf("Введите рейс для удаления: ");
    input_unsigned(&inputed_index);

    int index = -1;

    for (int i = 0; i < *size; i++) {
        if ((*buses)[i].bus_number == inputed_index) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Рейс #%d не найден\n", inputed_index);
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        (*buses)[i] = (*buses)[i + 1];
    }

    (*size)--;

    *buses = realloc(*buses, *size * sizeof(Bus));

    if (*size > 0 && *buses == NULL) {
        printf("realloc вернул NULL");
        exit(1);
    }

    printf("Рейс #%d успешно удален\n", inputed_index);
}

void update_bus_by_number(Bus *buses, int size) {
    int inputed_index;
    printf("Введите номер рейса для изменения: ");
    input_unsigned(&inputed_index);

    int index = -1;

    for (int i = 0; i < size; i++) {
        if (buses[i].bus_number == inputed_index) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Рейс #%d не найден\n", inputed_index);
        return;
    }

    printf("*** Текущие данные рейса ***\n");
    printf("Рейс #%d | Автобус: %s | Назначение: %s | Время отправления: %d мин | Время прибытия: %d мин \n",
        buses[index].bus_number,
        buses[index].bus_type,
        buses[index].destination,
        buses[index].departure_time,
        buses[index].arrival_time
    );

    printf("*** Введите новые данные ***\n");

    printf("Рейс #%d \n", inputed_index);

    printf("\nТип автобуса: ");
    scanf("%49s", buses[index].bus_type);
    clear_buff();

    printf("\nПункт назначения: ");
    scanf("%99s", buses[index].destination);
    clear_buff();

    printf("\nВремя отправления (в минутах с начала суток, например, 830 для 13:50): ");
    input_unsigned(&buses[index].departure_time);

    printf("\nВремя прибытия (в минутах с начала суток, например, 830 для 13:50): ");
    input_unsigned(&buses[index].arrival_time);

    int hours = buses[index].departure_time / 60;
    int minutes = buses[index].departure_time % 60;
    sprintf(buses[index].time_data.time_string, "%02d:%02d", hours, minutes);

    printf("Данные рейса #%d обновлены\n", inputed_index);
}

static int compare(const void *a, const void *b) {
    Bus *first = (Bus *) a;
    Bus *second = (Bus *) b;

    return first->departure_time - second->departure_time;
}

static void quick_sort_buses(Bus *buses, int low, int high) {
    if (low < high) {
        int item = buses[high].departure_time;
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (buses[j].departure_time <= item) {
                i++;
                Bus temp = buses[i];
                buses[i] = buses[j];
                buses[j] = temp;
            }
        }

        Bus temp = buses[i + 1];
        buses[i + 1] = buses[high];
        buses[high] = temp;

        quick_sort_buses(buses, low, i);
        quick_sort_buses(buses, i + 2, high);
    }
}

void sort_buses_by_departure_time(Bus *buses, int size) {
    if (size <= 1) {
        printf("Недостаточно элементов (всего элементов %d) для сортировки\n", size);
        return;
    }

    quick_sort_buses(buses, 0, size - 1);
    //qsort(buses, size, sizeof(Bus), compare);
    printf("Массив успешно отсортирован по времени отправления по возрастанию\n");
}

void search_buses_before_time(Bus *buses, int size) {
    bool found = false;
    int inputed_time;
    char inputed_destination[100];

    printf("Введите время: ");
    input_non_negative_int(&inputed_time);

    printf("Введите пункт назначения: ");
    scanf("%99s", inputed_destination);
    clear_buff();

    for (int i = 0; i < size; i++) {
        if (strcmp(buses[i].destination, inputed_destination) == 0 && buses[i].arrival_time < inputed_time) {
            printf("Рейс #%d | Автобус: %s | Назначение: %s | Время отправления: %d мин | Время прибытия: %d мин \n",
                buses[i].bus_number,
                buses[i].bus_type,
                buses[i].destination,
                buses[i].departure_time,
                buses[i].arrival_time
            );
            
            found = true;
        }
    }

    if (!found) {
        printf("Нет подходящих рейсов в '%s' до %02d:%02d\n",
            inputed_destination,
            inputed_time / 60,
            inputed_time % 60
        );
    }
}

void save_buses_to_binary_file(Bus *buses, int size) {
    char filename[100];
    printf("Введите название файла, в который буду записаны данные: ");
    scanf("%99s", filename);
    clear_buff();

    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Произошла ошибка при записи в двоичный файл\n");
        return;
    }

    fwrite(&size, sizeof(int), 1, file);

    if (size > 0) {
        fwrite(buses, sizeof(Bus), size, file);
    }

    fclose(file);

    printf("Данные были успешно записаны в файл %s\n", filename);
}

void load_buses_from_binary_file(Bus **buses, int *size) {
    destroy_bus_array(buses, size);

    char filename[100];
    printf("Введите название бинарного файла, который хотите загрузить: ");
    scanf("%99s", filename);
    clear_buff();

    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    fread(size, sizeof(int), 1, file);

    *buses = realloc(*buses, *size * sizeof(Bus));

    if (*size > 0 && *buses == NULL) {
        printf("realloc вернул NULL\n");
        fclose(file);
        exit(1);
    }

    if (*size > 0) {
        fread(*buses, sizeof(Bus), *size, file);
    }

    fclose(file);

    printf("Данные успешно загружены из файла %s\n", filename);
}

void update_bus_in_binary_file() {
    int bus_number_to_correct;
    char filename[100];
    printf("Введите название файла для корректровки: ");
    scanf("%99s", filename);
    clear_buff();

    printf("Введите номер рейса для корректировки: ");
    input_unsigned(&bus_number_to_correct);

    FILE *file = fopen(filename, "r+b");

    if (file == NULL) {
        printf("Не удалось открыть файл\n");
        return;
    }

    int size;
    fread(&size, sizeof(int), 1, file);

    bool found = false;

    for (int i = 0; i < size; i++) {
        fseek(file, sizeof(int) + i * sizeof(Bus), SEEK_SET);

        Bus current_bus;
        fread(&current_bus, sizeof(Bus), 1, file);

        if (current_bus.bus_number == bus_number_to_correct) {
            printf("*** Текущие данные рейса ***\n");
            printf("Рейс #%d | Автобус: %s | Назначение: %s | Время отправления: %d мин | Время прибытия: %d мин \n",
                current_bus.bus_number,
                current_bus.bus_type,
                current_bus.destination,
                current_bus.departure_time,
                current_bus.arrival_time
            );
            printf("*** Введите новые данные ***\n");

            printf("\nТип автобуса: ");
            scanf("%49s", current_bus.bus_type);
            clear_buff();

            printf("\nПункт назначения: ");
            scanf("%99s", current_bus.destination);
            clear_buff();

            printf("\nВремя отправления (в минутах с начала суток, например, 830 для 13:50): ");
            input_unsigned(&current_bus.departure_time);

            printf("\nВремя прибытия (в минутах с начала суток, например, 830 для 13:50): ");
            input_unsigned(&current_bus.arrival_time);

            int hours = current_bus.departure_time / 60;
            int minutes = current_bus.departure_time % 60;
            sprintf(current_bus.time_data.time_string, "%02d:%02d", hours, minutes);

            fseek(file, sizeof(int) + i * sizeof(Bus), SEEK_SET);
            fwrite(&current_bus, sizeof(Bus), 1, file);

            printf("Рейс #%d успешно скорректирован в файле %s\n", bus_number_to_correct, filename);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Не найден рейс #%d\n", bus_number_to_correct);
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
    printf(" -> 7. Отсортировать рейсы по времени отправления\n");
    printf(" -> 8. Вывести информацию о рейсах, которыми можно воспользоваться для прибытия в пункт назначения раньше заданного времени\n");
    printf(" -> 9. Сохранить данные в бинарный файл\n");
    printf(" -> 10. Загрузить данные из бинарного файла\n");
    printf(" -> 11. Изменить данные в бинарном файле\n");
    printf("Выберите действие (0-11): ");
}