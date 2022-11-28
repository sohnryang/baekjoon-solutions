/*
 * Baekjoon Online Judge #2436
 * https://www.acmicpc.net/problem/2436
 */

use std::io::{stdin, stdout, BufWriter, Write};

fn gcd(first: i32, second: i32) -> i32 {
    let mut max = first;
    let mut min = second;
    if min > max {
        let val = max;
        max = min;
        min = val;
    }

    loop {
        let res = max % min;
        if res == 0 {
            return min;
        }

        max = min;
        min = res;
    }
}

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
    let g_input = scan.next::<i32>();
    let l_input = scan.next::<i32>();
    let ab = l_input / g_input;
    let sqrt_ab = (ab as f64).sqrt() as i32;
    let mut a = 0;
    for x in 1..=sqrt_ab {
        if ab % x != 0 {
            continue;
        }
        let y = ab / x;
        if gcd(x, y) != 1 {
            continue;
        }
        a = a.max(x);
    }
    let b = ab / a;
    writeln!(out, "{} {}", a * g_input, b * g_input).ok();
}
