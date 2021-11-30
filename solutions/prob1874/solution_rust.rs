/*
 * Baekjoon Online Judge #1874
 * https://www.acmicpc.net/problem/1874
 */

use std::io::stdin;
use std::process::exit;

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
    let n_input: i32 = scan.next();
    let mut stack = vec![0];
    let mut last_used = 0;
    let mut result: Vec<&str> = vec![];

    for _ in 0..n_input {
        let num: i32 = scan.next();
        let top = *stack.last().unwrap();
        if top < num {
            if last_used >= num {
                println!("NO");
                exit(0);
            }
            while last_used < num {
                last_used += 1;
                stack.push(last_used);
                result.push("+");
            }
            stack.pop();
            result.push("-");
        } else if top == num {
            result.push("-");
            stack.pop();
        } else {
            println!("NO");
            exit(0);
        }
    }
    println!("{}", result.join("\n"));
}
