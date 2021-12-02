/*
 * Baekjoon Online Judge #2568
 * https://www.acmicpc.net/problem/2568
 */

use std::{
    collections::{HashMap, HashSet},
    io::{stdin, stdout, BufWriter, Write},
    process::exit,
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

    let n_input: usize = scan.next();
    let mut pairs_input: Vec<(i32, i32)> = vec![];
    let mut b_to_a = HashMap::new();
    for _ in 0..n_input {
        let line = (scan.next(), scan.next());
        pairs_input.push(line);
        b_to_a.insert(line.1, line.0);
    }
    pairs_input.sort();
    let a_input: Vec<i32> = pairs_input.iter().map(|&x| x.1).collect();
    if n_input == 1 {
        println!("0");
        exit(0);
    }

    let mut d = vec![i32::MAX; n_input + 1];
    let mut d_idx = vec![-1; n_input + 1];
    let mut p = HashMap::new();
    d[0] = i32::MIN;
    for i in 0..n_input {
        let j = d.partition_point(|&x| x <= a_input[i]);
        if d[j - 1] < a_input[i] && a_input[i] < d[j] {
            d[j] = a_input[i];
            d_idx[j] = i as i32;
            *p.entry(a_input[i]).or_default() = d_idx[j - 1]
        }
    }

    let lis_len = d.partition_point(|&x| x < i32::MAX) - 1;
    writeln!(out, "{}", n_input - lis_len).ok();

    let mut seq = vec![];
    let mut pos: i32 = d_idx[lis_len];
    while pos != -1 {
        seq.push(a_input[pos as usize]);
        pos = p[&a_input[pos as usize]];
    }
    let wires_left: HashSet<i32> = seq.iter().map(|x| b_to_a[x]).collect();
    for wire in pairs_input
        .iter()
        .map(|&x| x.0)
        .filter(|x| !wires_left.contains(x))
    {
        writeln!(out, "{}", wire).ok();
    }
}
