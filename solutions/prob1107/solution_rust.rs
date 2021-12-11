/*
 * Baekjoon Online Judge #1107
 * https://www.acmicpc.net/problem/1107
 */

use std::{
    cmp::min,
    collections::HashSet,
    io::{stdin, stdout, BufWriter, Write},
};

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

const MAX_START: i32 = 1_000_000;

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let n_input: i32 = scan.next();
    let m_input: i32 = scan.next();
    let mut broken_buttons_input = HashSet::new();
    for _ in 0..m_input {
        broken_buttons_input.insert(scan.next::<i32>());
    }
    let mut dist = (n_input - 100).abs();
    for x in 0..=MAX_START {
        let len = match x {
            0 => 1,
            _ => (x as f64).log10() as i32 + 1,
        };
        let x_str = x.to_string();
        if broken_buttons_input
            .iter()
            .any(|&d| x_str.contains(&*d.to_string()))
        {
            continue;
        }
        dist = min(dist, len + (n_input - x).abs());
    }
    writeln!(out, "{}", dist).ok();
}
