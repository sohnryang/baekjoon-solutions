/*
 * Baekjoon Online Judge #2108
 * https://www.acmicpc.net/problem/2108
 */

use std::collections::HashMap;
use std::io::stdin;

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
    let n_input: usize = scan.next();
    let mut nums: Vec<i32> = vec![];

    for _ in 0..n_input {
        nums.push(scan.next());
    }
    nums.sort();

    println!(
        "{}",
        (nums.iter().sum::<i32>() as f64 / n_input as f64).round() as i64
    );
    println!("{}", nums[n_input / 2]);

    let mut counts = HashMap::new();
    for num in &nums {
        let count = counts.entry(*num).or_insert(0);
        *count += 1;
    }
    let max_count: i32 = *counts.iter().max_by_key(|x| x.1).unwrap().1;
    let mut cand: Vec<i32> = counts
        .iter()
        .filter(|x| *x.1 == max_count)
        .map(|x| *x.0)
        .collect();
    cand.sort();
    println!(
        "{}",
        match cand.get(1) {
            Some(x) => *x,
            None => cand[0],
        }
    );

    println!("{}", nums[n_input - 1] - nums[0]);
}
