mod airport;
mod input_utils;

use std::error::Error;

use airport::airport_schedule::Flights;

use crate::input_utils::input_i32;

fn main() -> Result<(), Box<dyn Error>>{
    let mut my_flights = Flights::new();

        loop {
            println!(" -> 0. Выход");
            println!(" -> 1. Ввести данные о рейсах");
            println!(" -> 2. Просмотреть все рейсы");
            println!(" -> 3. Добавить новый рейс");
            println!(" -> 4. Найти рейсы по пункту назначения");
            println!(" -> 5. Удалить рейс по номеру");
            println!(" -> 6. Изменить данные рейса по номеру");
            println!(" -> 7. Отсортировать рейсы по времени вылета");
            println!(" -> 8. Сохранить данные в бинарный файл");
            println!(" -> 9. Загрузить данные из бинарного файла");
            println!(" -> 10. Изменить данные в бинарном файле");

            let mut choice = 0;

            input_i32("Введите выбор: ", &mut choice);

            match choice {
                0 => {
                    break;
                },
                1 => {
                    my_flights.clear();
                    my_flights.add();
                },
                2 => { my_flights.show(); },
                3 => { my_flights.add(); },
                4 => {  my_flights.search_by_destination(); },
                5 => {  my_flights.delete_flight_by_number(); },
                6 => {  my_flights.update_by_number(); },
                7 => {  my_flights.sort_by_departure_time(); },
                _ => { println!("Неверный пункт меню.") },
            }
        }

    Ok(())
}
