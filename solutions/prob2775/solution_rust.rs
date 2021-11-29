/*
 * Baekjoon Online Judge #2775
 * https://www.acmicpc.net/problem/2775
 */

use std::io::stdin;

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
    let t_input: i32 = scan.next();
    for _ in 0..t_input {
        let k_input: i32 = scan.next();
        let n_input: i32 = scan.next();
        let mut level: Vec<i32> = (1..=n_input).collect();
        for _ in 0..k_input {
            let next = level
                .iter()
                .scan(0, |state, &x| {
                    *state += x;
                    Some(*state)
                })
                .collect();
            level = next
        }
        println!("{}", level.last().unwrap());
    }
}
