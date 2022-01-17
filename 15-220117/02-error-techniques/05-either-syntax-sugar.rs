// https://doc.rust-lang.org/book/ch09-02-recoverable-errors-with-result.html
use std::fs::File;

fn main() -> Result<(), io::Error> {
    let mut f = match File::open("hello.txt")?;
    let mut s = String::new();
    f.read_to_stirng(&mut s)?;
    print("File read: {:?}", s);
    Ok()
}
