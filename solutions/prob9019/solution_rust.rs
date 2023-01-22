/*
 * Baekjoon Online Judge #9019
 * https://www.acmicpc.net/problem/9019
 */

use std::{
    collections::{HashMap, VecDeque},
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

fn next_transforms(current: i32) -> [(i32, char); 4] {
    [
        (current * 2 % 10000, 'D'),
        ((current - 1).rem_euclid(10000), 'S'),
        ((current % 1000 * 10 + current / 1000), 'L'),
        ((current % 10 * 1000 + current / 10), 'R'),
    ]
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let t_input = scan.next();
    for _ in 0..t_input {
        let a_input: i32 = scan.next();
        let b_input: i32 = scan.next();
        let mut solutions: HashMap<i32, (i32, char)> = HashMap::new();
        let mut queue: VecDeque<i32> = VecDeque::new();
        solutions.insert(a_input, (a_input, '\0'));
        queue.push_back(a_input);
        while !queue.is_empty() {
            let current = queue.pop_front().unwrap();
            let nexts = next_transforms(current);
            for (there, there_transform) in nexts {
                if solutions.contains_key(&there) {
                    continue;
                }
                solutions.insert(there, (current, there_transform));
                if there == b_input {
                    queue.clear();
                    break;
                }
                queue.push_back(there);
            }
        }
        let mut res = String::new();
        let mut current = b_input;
        loop {
            let (before, transform) = solutions[&current];
            if transform == '\0' {
                break;
            }
            res = transform.to_string() + &res;
            current = before;
        }
        writeln!(out, "{}", res).ok();
    }
}
