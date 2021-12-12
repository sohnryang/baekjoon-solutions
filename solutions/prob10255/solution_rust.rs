/*
 * Baekjoon Online Judge #10255
 * https://www.acmicpc.net/problem/10255
 */

use std::{
    cmp::{max, min},
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

#[derive(PartialEq, Eq, Clone, Copy)]
enum ResultType {
    NoCross,
    Mid,
    Min,
    Max,
    Inifinite,
}

fn xaxis_crossings(segment: ((i32, i32), (i32, i32)), interval: (i32, i32)) -> ResultType {
    let ((x1, y1), (x2, y2)) = segment;
    let (x_min, x_max) = interval;
    if y1 * y2 > 0 {
        return ResultType::NoCross;
    }
    if y1 == 0 && y2 == 0 {
        if max(x1, x2) < x_min || min(x1, x2) > x_max {
            return ResultType::NoCross;
        } else if max(x1, x2) == x_min {
            return ResultType::Min;
        } else if min(x1, x2) == x_max {
            return ResultType::Max;
        }
        return ResultType::Inifinite;
    }
    let x_div_multed = y1.abs() * x2 + y2.abs() * x1;
    let denom = y1.abs() + y2.abs();
    if x_min * denom < x_div_multed && x_div_multed < x_max * denom {
        return ResultType::Mid;
    } else if x_min * denom == x_div_multed {
        return ResultType::Min;
    } else if x_div_multed == x_max * denom {
        return ResultType::Max;
    }
    return ResultType::NoCross;
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let t_input: i32 = scan.next();
    for _ in 0..t_input {
        let x_min_input = scan.next();
        let y_min_input = scan.next();
        let x_max_input = scan.next();
        let y_max_input = scan.next();
        let x1_input = scan.next();
        let y1_input = scan.next();
        let x2_input = scan.next();
        let y2_input = scan.next();
        let top_crossing = xaxis_crossings(
            (
                (x1_input, y1_input - y_max_input),
                (x2_input, y2_input - y_max_input),
            ),
            (x_min_input, x_max_input),
        );
        let left_crossing = xaxis_crossings(
            (
                (y1_input, x1_input - x_min_input),
                (y2_input, x2_input - x_min_input),
            ),
            (y_min_input, y_max_input),
        );
        let bottom_crossing = xaxis_crossings(
            (
                (x1_input, y1_input - y_min_input),
                (x2_input, y2_input - y_min_input),
            ),
            (x_min_input, x_max_input),
        );
        let right_crossing = xaxis_crossings(
            (
                (y1_input, x1_input - x_max_input),
                (y2_input, x2_input - x_max_input),
            ),
            (y_min_input, y_max_input),
        );
        let crossings = vec![top_crossing, left_crossing, bottom_crossing, right_crossing];
        if crossings.iter().any(|&x| x == ResultType::Inifinite) {
            writeln!(out, "4").ok();
            continue;
        }
        let mut result = crossings.iter().filter(|&&x| x == ResultType::Mid).count();
        if top_crossing == ResultType::Min && left_crossing == ResultType::Max {
            result += 1;
        }
        if top_crossing == ResultType::Max && right_crossing == ResultType::Max {
            result += 1;
        }
        if left_crossing == ResultType::Min && bottom_crossing == ResultType::Min {
            result += 1;
        }
        if right_crossing == ResultType::Min && bottom_crossing == ResultType::Max {
            result += 1;
        }
        writeln!(out, "{}", result).ok();
    }
}
