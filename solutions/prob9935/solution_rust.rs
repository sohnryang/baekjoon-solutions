/*
 * Baekjoon Online Judge #9935
 * https://www.acmicpc.net/problem/9935
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

    let haystack_input: Vec<u8> = scan.next::<String>().as_bytes().to_owned();
    let needle_input: Vec<u8> = scan.next::<String>().as_bytes().to_owned();

    let mut stack = vec![];
    for ch in haystack_input {
        stack.push(ch);
        if stack.len() < needle_input.len() {
            continue;
        }
        let mut buf = vec![];
        for &nch in needle_input.iter().rev() {
            if nch != *stack.last().unwrap() {
                break;
            }
            buf.push(stack.pop().unwrap());
        }
        if buf.len() != needle_input.len() {
            stack.extend(buf.iter().rev());
        }
    }
    if stack.is_empty() {
        writeln!(out, "FRULA").ok();
    } else {
        writeln!(out, "{}", String::from_utf8_lossy(&stack).into_owned()).ok();
    }
}
