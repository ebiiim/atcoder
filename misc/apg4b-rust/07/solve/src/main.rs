extern crate proconio;

fn main() {
    proconio::input! {
        a: i32,
        b: i32,
    }
    println!("{}", a + b);
}