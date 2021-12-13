/*
 * Baekjoon Online Judge #15824
 * https://www.acmicpc.net/problem/15824
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

fn modpow(a: i64, b: i64) -> i64 {
    let mut result = 1;
    let mut offset = 31;
    while offset >= 0 {
        result = result * result % MOD;
        let bit = (b >> offset) & 1;
        if bit == 1 {
            result = result * a % MOD;
        }
        offset -= 1;
    }
    result
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let n_input: i64 = scan.next();
    let mut a_input = vec![];
    for _ in 0..n_input {
        a_input.push(scan.next::<i64>());
    }
    a_input.sort();
    a_input.iter_mut().for_each(|x| *x %= MOD);

    let mut result = 0;
    for j in 1..=(n_input - 1) {
        result += a_input[j as usize] * (modpow(2, j) - 1);
        result %= MOD;
    }
    for i in 0..=(n_input - 2) {
        result -= a_input[i as usize] * (modpow(2, n_input - i - 1) - 1);
        result = result.rem_euclid(MOD);
    }
    writeln!(out, "{}", result).ok();
}
