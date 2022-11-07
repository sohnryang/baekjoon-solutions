/*
 * Baekjoon Online Judge #1449
 * https://www.acmicpc.net/problem/1449
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

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let n_input: usize = scan.next();
    let l_input: usize = scan.next();
    let mut arr = vec![false; 1001];
    for _ in 0..n_input {
        let idx: usize = scan.next();
        arr[idx] = true;
    }
    let mut tape_start = None;
    let mut res = 0;
    for i in 0..=1000 {
        if !arr[i] {
            continue;
        }
        if tape_start.is_some() {
            let offset = i - tape_start.unwrap();
            if offset + 1 > l_input {
                tape_start = Some(i);
                res += 1;
            }
        } else {
            tape_start = Some(i);
            res += 1;
        }
    }
    writeln!(out, "{res}").ok();
}
