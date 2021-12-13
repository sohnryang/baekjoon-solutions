/*
 * Baekjoon Online Judge #23827
 * https://www.acmicpc.net/problem/23827
 */

use std::io::{stdin, stdout, BufWriter, Write};

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

const MOD: i64 = 1_000_000_007;

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let n_input: i64 = scan.next();
    let mut a_input = vec![];
    for _ in 0..n_input {
        a_input.push(scan.next::<i64>());
    }
    let psum = a_input
        .iter()
        .scan(0, |s, &x| {
            *s += x;
            Some(*s)
        })
        .collect::<Vec<i64>>();
    let mut result = 0;
    for (i, &x) in a_input.iter().enumerate() {
        result += x * (*psum.last().unwrap() - psum[i]);
        result %= MOD;
    }
    writeln!(out, "{}", result).ok();
}
