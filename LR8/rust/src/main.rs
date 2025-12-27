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
            2 => {
                my_flights.show();
            },
            3 => {
                my_flights.add();
            },
            _ => {
                println!("Неверный пункт меню.")
            }
        }
    }

    Ok(())

}
