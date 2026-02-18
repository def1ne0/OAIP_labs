pub mod airport_schedule {
    use std::cmp::Ordering;
    use crate::input_utils::{input_i32, input_str};

    #[derive(Debug)]
    struct Flight {
        flight_number: i32,
        aircraft_type: String,
        destination: String,
        departure_time: i32,
    }

    impl Flight {
        fn new() -> Self {
            Flight { 
                flight_number: 0, 
                aircraft_type: String::new(), 
                destination: String::new(), 
                departure_time: 0,
            }
        }
    }

    pub struct Flights {
        flights_array: Vec<Flight>,
    }

    impl Flights {
        pub fn new() -> Self {
            Flights { flights_array: vec![] }
        }

        pub fn add(&mut self) {
            let mut count = 0;
            let size = self.flights_array.len() as i32;
            
            input_i32("Введите количество рейсов: ", &mut count);

            for i in 1..=count {
                println!(" -> Ввод рейса #{}: ", size + i);

                let mut current_flight: Flight = Flight::new();
                current_flight.flight_number = size + i;

                input_str("Введите тип самолета: ", &mut current_flight.aircraft_type);

                input_str("Введите пункт назначения: ", &mut current_flight.destination);

                input_i32("Введите время отправления: ", &mut current_flight.departure_time);

                self.flights_array.push(current_flight);
            }
        }

        pub fn show(&self) {
            println!("Рейс | Тип | Назначение | Отправление");

            for current in self.flights_array.iter() {
                println!("#{} | {} | {} | {}", 
                    current.flight_number,
                    current.aircraft_type,
                    current.destination,
                    current.departure_time,
                );
            }
        }

        pub fn clear(&mut self) {
            self.flights_array.clear();
        }

        pub fn search_by_destination(&self) {
            let mut destination = String::new();
            let mut found = false;
            input_str("Введите пункт назначения: ", &mut destination);

            for current in self.flights_array.iter() {
                if current.destination == destination {
                    println!("Рейс | Тип | Назначение | Отправление");
                    println!("#{} | {} | {} | {}",
                             current.flight_number,
                             current.aircraft_type,
                             current.destination,
                             current.departure_time,
                    );

                    found = true;
                }
            }

            if !found {
                println!("Рейс с пунктом назначения {} не найден", destination);
            }
        }

        pub fn delete_flight_by_number(&mut self) {
            let mut number = 0;
            input_i32("Введите номер рейса для удаления: ", &mut number);

            let mut found = false;

            for (i, current) in self.flights_array.iter().enumerate() {
                if current.flight_number == number {
                    found = true;
                    self.flights_array.remove(i);
                    println!("Рейс успешно удален");

                    break;
                }
            }

            if !found {
                println!("Не нашелся рейс #{}", number);
            }
        }

        pub fn update_by_number(&mut self) {
            let mut number = 0;
            input_i32("Введите номер рейса для обновления: ", &mut number);

            let mut found = false;
            let mut idx: usize = 0;

            for (i, current) in self.flights_array.iter().enumerate() {
                if current.flight_number == number {
                    found = true;
                    idx = i;

                    break;
                }
            }

            if !found {
                println!("Не нашлось рейса #{}", number);
                return;
            }

            println!(" -> Ввод рейса #{}: ", number);

            input_str("Введите тип самолета: ", &mut self.flights_array[idx].aircraft_type);

            input_str("Введите пункт назначения: ", &mut self.flights_array[idx].destination);

            input_i32("Введите время отправления: ", &mut self.flights_array[idx].departure_time);
        }

        pub fn sort_by_departure_time(&mut self) {
            if self.flights_array.is_empty() { return; }

            self.flights_array.sort_by(|a, b | -> Ordering {
                a.departure_time.cmp(&b.departure_time)
            });

            println!("Элементы успешно отсортированы по времени отправления");
        }
    }
}


