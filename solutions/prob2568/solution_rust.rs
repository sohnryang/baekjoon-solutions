/*
 * Baekjoon Online Judge #2568
 * https://www.acmicpc.net/problem/2568
 */

use std::{
    collections::{HashMap, HashSet},
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

    let mut d = vec![i32::MAX; n_input + 1];
    let mut p = vec![0; n_input];
    d[0] = i32::MIN;
    for i in 0..n_input {
        let j = d.partition_point(|&x| x <= a_input[i]);
        if d[j - 1] < a_input[i] && a_input[i] < d[j] {
            d[j] = a_input[i];
            p[i] = j;
        }
    }

    let lis_len = d.partition_point(|&x| x < i32::MAX) - 1;
    writeln!(out, "{}", n_input - lis_len).ok();

    let mut len = lis_len as i32;
    let mut seq = vec![];
    for (i, &x) in p.iter().enumerate().rev() {
        if len <= 0 {
            break;
        }
        if x == len as usize {
            seq.push(a_input[i]);
            len -= 1;
        }
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
