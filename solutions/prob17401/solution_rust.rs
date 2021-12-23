/*
 * Baekjoon Online Judge #17401
 * https://www.acmicpc.net/problem/17401
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
    let mut res = vec![vec![0; b[0].len()]; a.len()];
    for i in 0..a.len() {
        for j in 0..b[i].len() {
            for k in 0..a[i].len() {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= MOD;
            }
        }
    }
    res
}

fn modpow(m: &Vec<Vec<i64>>, exp: i64) -> Vec<Vec<i64>> {
    let mut offset = 31;
    let mut res = vec![vec![0; m[0].len()]; m.len()];
    for x in 0..m.len() {
        res[x][x] = 1;
    }
    while offset >= 0 {
        let b = (exp >> offset) & 1;
        res = matmul(&res, &res);
        if b == 1 {
            res = matmul(&res, m);
        }
        offset -= 1;
    }
    res
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let t_input = scan.next();
    let n_input = scan.next();
    let d_input: i64 = scan.next();
    let mut matrices: Vec<Vec<Vec<i64>>> = vec![vec![vec![0i64; n_input]; n_input]; t_input];
    for t in 0..t_input {
        let m_input: i64 = scan.next();
        for _ in 0..m_input {
            let a_input: usize = scan.next();
            let b_input: usize = scan.next();
            let c_input = scan.next();
            matrices[t][a_input - 1][b_input - 1] = c_input;
        }
    }

    let mut id = vec![vec![0; n_input]; n_input];
    for x in 0..n_input {
        id[x][x] = 1;
    }
    let cycle = matrices.iter().fold(id.clone(), |acc, m| matmul(&acc, m));
    let cycle_count = d_input / t_input as i64;
    let mut res = modpow(&cycle, cycle_count);
    let rem = d_input as usize % t_input;
    res = matrices[..rem].iter().fold(res, |acc, m| matmul(&acc, m));
    for row in res {
        for x in row {
            write!(out, "{} ", x).ok();
        }
        writeln!(out, "").ok();
    }
}
