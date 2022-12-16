/*
 * Baekjoon Online Judge #11662
 * https://www.acmicpc.net/problem/11662
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

fn pos(start: (f64, f64), end: (f64, f64), time: f64) -> (f64, f64) {
    (
        (1.0 - time) * start.0 + time * end.0,
        (1.0 - time) * start.1 + time * end.1,
    )
}

fn dist(seg1: ((f64, f64), (f64, f64)), seg2: ((f64, f64), (f64, f64)), time: f64) -> f64 {
    let pos1 = pos(seg1.0, seg1.1, time);
    let pos2 = pos(seg2.0, seg2.1, time);
    let diff = (pos1.0 - pos2.0, pos1.1 - pos2.1);
    diff.0.hypot(diff.1)
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let ax_input = scan.next::<f64>();
    let ay_input = scan.next::<f64>();
    let a_input = (ax_input, ay_input);
    let bx_input = scan.next::<f64>();
    let by_input = scan.next::<f64>();
    let b_input = (bx_input, by_input);
    let cx_input = scan.next::<f64>();
    let cy_input = scan.next::<f64>();
    let c_input = (cx_input, cy_input);
    let dx_input = scan.next::<f64>();
    let dy_input = scan.next::<f64>();
    let d_input = (dx_input, dy_input);
    let eps = 1e-9;
    let mut lo = 0.0;
    let mut hi = 1.0;
    while hi - lo > eps {
        let m1 = lo + (hi - lo) / 3.0;
        let m2 = hi - (hi - lo) / 3.0;
        let d1 = dist((a_input, b_input), (c_input, d_input), m1);
        let d2 = dist((a_input, b_input), (c_input, d_input), m2);
        if d1 < d2 {
            hi = m2;
        } else {
            lo = m1;
        }
    }
    writeln!(out, "{}", dist((a_input, b_input), (c_input, d_input), lo)).ok();
}
