pub fn input_i32(text: &str, input: &mut i32) {
    loop {
        println!("{}", text);

        let mut buffer: String = String::new();

        if std::io::stdin().read_line(&mut buffer).is_err() {
            println!("Ошибка. Не удалось ввести строку");
            continue;
        } 

        match buffer.trim().parse::<i32>() {
            Ok(val) => {
                *input = val;
                break;
            },
            Err(_) => { 
                println!("Ошибка. Введите целое число");
            },
        }
    }
}

pub fn input_str(text: &str, input: &mut String) {
    loop {
        println!("{}", text);
        
        let mut buffer = String::new();

        match std::io::stdin().read_line(&mut buffer) {
            Ok(_) => {
                *input = buffer.trim().to_string();
                break;
            },
            Err(_) => {
                println!("Ошибка. Не удалось ввести строку");
            }
        }
    }
}