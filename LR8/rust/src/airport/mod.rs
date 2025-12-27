pub mod airport_schedule {
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
                aircraft_type: "".to_string(), 
                destination: "".to_string(), 
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
    }
}


