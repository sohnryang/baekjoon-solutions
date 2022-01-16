/*
 * Baekjoon Online Judge #24230
 * https://www.acmicpc.net/problem/24230
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

    let n_input = scan.next();
    let mut c_input = vec![0];
    for _ in 0..n_input {
        c_input.push(scan.next());
    }
    let mut tree = HashMap::new();
    for _ in 1..n_input {
        let a_input: i32 = scan.next();
        let b_input: i32 = scan.next();
        tree.entry(a_input)
            .or_insert(HashSet::new())
            .insert(b_input);
        tree.entry(b_input)
            .or_insert(HashSet::new())
            .insert(a_input);
    }
    if n_input == 1 {
        tree.insert(1, HashSet::new());
    }
    let mut stack = vec![(1, 0)];
    let mut visited = HashSet::new();
    let mut res = 0;
    while !stack.is_empty() {
        let (v, color) = stack.pop().unwrap();
        let new_color = c_input[v as usize];
        res += (color != new_color) as i32;
        visited.insert(v);
        for &u in tree[&v].iter() {
            if visited.contains(&u) {
                continue;
            }
            stack.push((u, new_color));
        }
    }
    writeln!(out, "{}", res).ok();
}
