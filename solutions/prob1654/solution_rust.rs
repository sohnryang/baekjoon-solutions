/*
 * Baekjoon Online Judge #1654
 * https://www.acmicpc.net/problem/1654
 */

use std::io::stdin;

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
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

fn count_wires(vec: &Vec<i64>, len: i64) -> i64 {
    vec.iter().map(|x| (x / len) as i64).sum()
}

fn main() {
    let mut scan = Scanner::default();
    let k_input: i64 = scan.next();
    let n_input: i64 = scan.next();
    let mut wires: Vec<i64> = vec![];
    for _ in 0..k_input {
        wires.push(scan.next());
    }
    let mut left = 1i64;
    let mut right = *wires.iter().max().unwrap();
    while left <= right {
        let mid: i64 = (left + right) / 2;
        let wire_count: i64 = count_wires(&wires, mid);
        if wire_count >= n_input {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    println!("{}", right);
}
