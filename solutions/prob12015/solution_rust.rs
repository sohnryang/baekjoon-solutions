/*
 * Baekjoon Online Judge #12015
 * https://www.acmicpc.net/problem/12015
 */

use std::{io::stdin, process::exit};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let n_input: usize = scan.next();
    if n_input == 1 {
        println!("1");
        exit(0);
    }
    let mut a_input = vec![];
    for _ in 0..n_input {
        a_input.push(scan.next::<i32>())
    }

    let mut d = vec![i32::MAX; n_input + 1];
    d[0] = i32::MIN;
    for i in 0..n_input {
        let j = d.partition_point(|&x| x <= a_input[i]);
        if d[j - 1] < a_input[i] && a_input[i] < d[j] {
            d[j] = a_input[i];
        }
    }

    println!("{}", d.partition_point(|&x| x < i32::MAX) - 1);
}
