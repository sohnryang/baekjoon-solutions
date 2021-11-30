/*
 * Baekjoon Online Judge #2805
 * https://www.acmicpc.net/problem/2805
 */

use std::{cmp::max, io::stdin};

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

    let n_input = scan.next();
    let m_input = scan.next();
    let mut tree_height: Vec<i64> = vec![];
    for _ in 0..n_input {
        tree_height.push(scan.next());
    }

    let mut left = 0;
    let mut right = *tree_height.iter().max().unwrap();
    while left <= right {
        let mid = (left + right) / 2;
        let gain: i64 = tree_height.iter().map(|&x| max(x - mid, 0)).sum();
        if gain >= m_input {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    println!("{}", right);
}
