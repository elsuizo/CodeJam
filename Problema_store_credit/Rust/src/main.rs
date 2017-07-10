/// Solution of Google CodeJam Problem store credit in Rust
use std::io::{BufRead, BufReader};
use std::fs::File;

#[derive(Debug)]
struct Credits {
    credit: i32,
    number_of_items: i32,
    elements:Vec<i32>
}

fn parse_numbers(line: &str) -> Vec<i32>
{
    let result: Vec<i32> = line.split_whitespace()
                                .map(|s| s.parse().unwrap())
                                .collect();
    result
}

fn parse_number(line: &str) -> i32 {
    line.parse().unwrap()
}

fn read_file_to_vector(file_path: &str) -> Vec<Credits>
{
    let file = BufReader::new(File::open(file_path).unwrap());
    let lines: Vec<String> = file.lines().skip(1).map(|line| { line.unwrap() }).collect();
    let mut credit_vec: Vec<Credits> = Vec::new();
    for cases in lines.chunks(3) {
        let credit = Credits {credit: parse_number(&cases[0]),
                              number_of_items: parse_number(&cases[1]),
                              elements: parse_numbers(&cases[2])};
        credit_vec.push(credit);
    }
    credit_vec
}

fn solve_case(case: &Credits) -> (i32, i32) {

    for num in 0..case.number_of_items{
        for index in num..case.number_of_items {
            if case.elements[num as usize] + case.elements[index as usize] == case.credit && num != index {
                return (num, index);
            }
        }
    }
    unreachable!()
}

fn main() {
    let file_path = "../Files/A-small-practice.in";
    let cases = read_file_to_vector(file_path);
    for (index, case) in cases.iter().enumerate() {
        let (x, y) = solve_case(&case);
        println!("Case#:{} {} {}", index, x, y);
    }

}
