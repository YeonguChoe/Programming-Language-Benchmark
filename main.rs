/**
 * Production compile command
 * rustc -C opt-level=3 -C debuginfo=0 main.rs -o Rust_program
 * ./Rust_program 100
 */

// Biggest data type: u128
use std::env;
use std::time::Instant;

// Factorial
fn factorial(num: u64) -> u64 {
    if num == 0 || num == 1 {
        return 1;
    }
    let mut result = 1;
    for i in 2..=num {
        result *= i as u64;
    }
    result
}
fn main() {

        // Getting argument
        let args: Vec<String> = env::args().collect();
        if args.len() != 2 {
            eprintln!("Usage: cargo run <number>");
            std::process::exit(1);
        }
    
        // Assign argument to iteration
        let iteration: u64 = match args[1].parse() {
            Ok(num) => num,
            Err(_) => {
                eprintln!("Invalid argument: not a number");
                std::process::exit(1);
            }
        };

    

    let loop_count:u64 = (iteration - 2) as u64;
    let final_value:u64 = loop_count * loop_count * loop_count * loop_count;
    let factorial_input:u64 = 20;
    let mut count: u64 = 0;

    // Start timer
    let start = Instant::now();

    for _ in 2..iteration {
        for _ in 2..iteration {
            for _ in 2..iteration {
                for _ in 2..iteration {
                    let _result = factorial(factorial_input);
                    count += 1;
                    if count == final_value {
                        println!("==================================================");
                        println!("Result count: {}", count);
                    }
                }
            }
        }
    }

    // End timer
    let elapsed_time = start.elapsed().as_secs_f64();
    
    println!("Expected count:{}", final_value);
    println!("==================================================");

    println!("Rust Runtime: {} seconds", elapsed_time);
    println!("==================================================");
}
