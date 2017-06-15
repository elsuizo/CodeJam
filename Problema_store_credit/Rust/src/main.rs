struct Cases {
    c:i32,
    I:i32,
    L:Vec<i32>
}
use std::fs::File;
use std::io::prelude::*;
fn read_text_file(filename: &str) -> String {

    let mut f = File::open(filename).expect("file not found");

    let mut contents = String::new();
    f.read_to_string(&mut contents).expect("something went wrong reading the file");
    contents
}

// fn create_cases(file_name:&str) -> Vec<Cases> {
//     data = read_text_file(file_name);
//
// }


fn main() {
    let filename = "../Files/A-ssmall-practice.in";
    // let mut contents = String::new();
    let contents = read_text_file(filename);
    println!("{}", contents);
    println!("{}", contents.chars().nth(2).unwrap());

}
