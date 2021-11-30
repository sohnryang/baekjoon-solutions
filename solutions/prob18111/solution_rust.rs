/*
 * Baekjoon Online Judge #18111
 * https://www.acmicpc.net/problem/18111
 */

use std::{
    cmp::{max, min},
    io::stdin,
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
    let input_n: i32 = scan.next();
    let input_m: i32 = scan.next();
    let input_b: i32 = scan.next();
    let mut ground: Vec<Vec<i32>> = vec![];
    let mut lowest = 256;
    let mut highest = 0;
    for _ in 0..input_n {
        let mut line: Vec<i32> = vec![];
        for _ in 0..input_m {
            line.push(scan.next());
        }
        lowest = min(lowest, *line.iter().min().unwrap());
        highest = max(highest, *line.iter().max().unwrap());
        ground.push(line);
    }
    let mut result: Option<(i32, i32)> = None;
    for level in lowest..=highest {
        let broken_blocks: i32 = ground
            .iter()
            .map(|line| line.iter().map(|&x| max(x - level, 0)).sum::<i32>())
            .sum();
        let needed_blocks: i32 = ground
            .iter()
            .map(|line| line.iter().map(|&x| max(level - x, 0)).sum::<i32>())
            .sum();
        if needed_blocks > broken_blocks + input_b {
            continue;
        }
        let cost = needed_blocks + broken_blocks * 2;
        if result == None {
            result = Some((cost, -level));
        } else {
            result = Some(min(result.unwrap(), (cost, -level)));
        }
    }
    println!("{} {}", result.unwrap().0, -result.unwrap().1);
}
