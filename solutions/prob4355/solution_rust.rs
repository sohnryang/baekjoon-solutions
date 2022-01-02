/*
 * Baekjoon Online Judge #4355
 * https://www.acmicpc.net/problem/4355
 */

use std::{
    collections::HashMap,
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

    loop {
        let n_input: usize = scan.next();
        if n_input == 0 {
            break;
        }
        let bound = (n_input as f64).sqrt() as usize;
        let mut is_prime = vec![true; bound as usize + 1];
        is_prime[0] = false;
        is_prime[1] = false;
        for n in 2..=bound {
            if !is_prime[n] {
                continue;
            }
            for x in (n.pow(2)..=bound).step_by(n) {
                is_prime[x] = false;
            }
        }
        let primes = is_prime
            .iter()
            .enumerate()
            .filter(|&(_, &x)| x)
            .map(|(i, _)| i)
            .collect::<Vec<_>>();
        let mut factorized = HashMap::new();
        let mut n = n_input;
        for p in primes {
            while n % p == 0 {
                *factorized.entry(p).or_insert(0) += 1;
                n /= p;
            }
            if n == 1 {
                break;
            }
        }
        if n != 1 {
            *factorized.entry(n).or_insert(0) += 1;
        }

        let mut phi = 1;
        for (p, k) in factorized {
            phi *= p.pow(k - 1) * (p - 1);
        }
        writeln!(out, "{}", phi).ok();
    }
}
