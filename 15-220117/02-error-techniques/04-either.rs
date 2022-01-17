// https://doc.rust-lang.org/book/ch09-02-recoverable-errors-with-result.html
use std::fs::File;

fn main() {
    let mut f = match File::open("hello.txt") {
        Ok(file) => file,
        Err(error) => {
            print!("Problem opening the file: {:?}", error);
            return
        },
    };
    let mut s = String::new();
    match f.read_to_stirng(&mut s) {
        Ok(_) => print("File read: {:?}", s),
        Err(e) => {
            print!("Problem reading the file: {:?}", error);
            return
        }
    }
}
