/*
 * Baekjoon Online Judge #1074
 * https://www.acmicpc.net/problem/1074
 */

use std::{
    convert::TryInto,
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

fn traverse(n: i32, y: i32, x: i32) -> i32 {
    if n == 0 {
        return 0;
    }
    let size = 2_i32.pow((n - 1).try_into().unwrap());
    if 0 <= y && y < size {
        if 0 <= x && x < size {
            traverse(n - 1, y, x)
        } else {
            traverse(n - 1, y, x - size) + 1 * size * size
        }
    } else {
        if 0 <= x && x < size {
            traverse(n - 1, y - size, x) + 2 * size * size
        } else {
            traverse(n - 1, y - size, x - size) + 3 * size * size
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let n_input = scan.next::<i32>();
    let r_input = scan.next::<i32>();
    let c_input = scan.next::<i32>();

    let res = traverse(n_input, r_input, c_input);
    writeln!(out, "{res}").ok();
}
