/*
 * Baekjoon Online Judge #10986
 * https://www.acmicpc.net/problem/10986
 */

use std::{
    collections::HashMap,
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

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let n_input = scan.next::<i64>();
    let m_input = scan.next::<i64>();
    let mut a_input = vec![];
    for _ in 0..n_input {
        a_input.push(scan.next::<i64>());
    }
    let psum_mod = a_input
        .iter()
        .scan(0i64, |s, &x| {
            *s += x;
            *s %= m_input;
            Some(*s)
        })
        .collect::<Vec<_>>();
    let mut counts = HashMap::new();
    for x in psum_mod {
        *counts.entry(x).or_insert(0i64) += 1;
    }
    let mut res = *counts.get(&0).unwrap_or(&0);
    for v in counts.values() {
        res += (v - 1) * v / 2;
    }
    writeln!(out, "{res}").ok();
}
