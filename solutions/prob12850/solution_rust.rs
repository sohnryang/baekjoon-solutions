/*
 * Baekjoon Online Judge #12850
 * https://www.acmicpc.net/problem/12850
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

fn matmul(a: &Vec<Vec<i64>>, b: &Vec<Vec<i64>>) -> Vec<Vec<i64>> {
    let mut result = vec![vec![0; a.len()]; b.len()];
    for i in 0..a.len() {
        for j in 0..b.len() {
            for k in 0..a[i].len() {
                result[i][j] += a[i][k] * b[k][j] % MOD;
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let d_input: u32 = scan.next();

    let mat = vec![
        vec![0, 1, 1, 0, 0, 0, 0, 0],
        vec![1, 0, 1, 1, 0, 0, 0, 0],
        vec![1, 1, 0, 1, 1, 0, 0, 0],
        vec![0, 1, 1, 0, 1, 1, 0, 0],
        vec![0, 0, 1, 1, 0, 1, 0, 1],
        vec![0, 0, 0, 1, 1, 0, 1, 0],
        vec![0, 0, 0, 0, 0, 1, 0, 1],
        vec![0, 0, 0, 0, 1, 0, 1, 0],
    ];
    let mut multiplied = vec![vec![0; 8]; 8];
    for i in 0..8 {
        multiplied[i][i] = 1;
    }
    let mut offset = (d_input as f64).log2() as i32;
    while offset >= 0 {
        multiplied = matmul(&multiplied, &multiplied);
        let bit = (d_input >> offset) & 1;
        if bit == 1 {
            multiplied = matmul(&multiplied, &mat);
        }
        offset -= 1;
    }
    writeln!(out, "{}", multiplied[0][0]).ok();
}
