/*
 * Baekjoon Online Judge #1016
 * https://www.acmicpc.net/problem/1016
 */

use std::{
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

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let min_input: i64 = scan.next();
    let max_input: i64 = scan.next();
    let max_square_rooted = (max_input as f64).sqrt() as i64;
    let mut non_squarefree = HashSet::new();
    for rooted in 2..=max_square_rooted {
        let sq = rooted * rooted;
        let lo = (min_input as f64 / sq as f64).ceil() as i64;
        let hi = max_input / sq;
        for x in lo..=hi {
            non_squarefree.insert(x * sq);
        }
    }
    writeln!(
        out,
        "{}",
        max_input - min_input + 1 - non_squarefree.len() as i64
    )
    .ok();
}
