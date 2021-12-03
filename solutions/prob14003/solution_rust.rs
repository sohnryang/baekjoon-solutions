/*
 * Baekjoon Online Judge #14003
 * https://www.acmicpc.net/problem/14003
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
    let mut a_input = vec![];
    for _ in 0..n_input {
        a_input.push(scan.next::<i32>());
    }

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
    writeln!(out, "{}", lis_len).ok();

    let mut len: i32 = lis_len as i32;
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
    writeln!(
        out,
        "{}",
        seq.iter()
            .rev()
            .map(|&x| x.to_string())
            .collect::<Vec<String>>()
            .join(" ")
    )
    .ok();
}
