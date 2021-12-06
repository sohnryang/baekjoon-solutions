/*
 * Baekjoon Online Judge #1644
 * https://www.acmicpc.net/problem/1644
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

    let n_input: i32 = scan.next();
    let mut is_prime = vec![true; n_input as usize + 1];
    let sqrt = (n_input as f64).sqrt() as i32;
    is_prime[0] = false;
    is_prime[1] = false;
    for i in 1..=sqrt {
        if is_prime[i as usize] {
            for j in ((i * i)..=n_input).step_by(i as usize) {
                is_prime[j as usize] = false;
            }
        }
    }
    let prime_arr: Vec<i32> = is_prime
        .iter()
        .enumerate()
        .filter(|&(_, &x)| x)
        .map(|(i, _)| i as i32)
        .collect();
    let mut left = 0;
    let mut right = 0;
    let mut partial_sum = *prime_arr.get(0).unwrap_or(&0);
    let mut result = 0;
    while right < prime_arr.len() {
        if partial_sum < n_input {
            right += 1;
            if right >= prime_arr.len() {
                break;
            }
            partial_sum += prime_arr[right];
        } else if partial_sum == n_input {
            result += 1;
            left += 1;
            right = left;
            if left >= prime_arr.len() {
                break;
            }
            partial_sum = prime_arr[left];
        } else {
            left += 1;
            partial_sum -= prime_arr[left - 1];
        }
    }
    writeln!(out, "{}", result).ok();
}
