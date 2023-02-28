/*
 * Baekjoon Online Judge #13970
 * https://www.acmicpc.net/problem/13970
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

fn euler_phi(x: i32, smallest_factor: &[i32]) -> i32 {
    let mut res = 1;
    let mut current_factor = smallest_factor[x as usize];
    let mut factor_count = 0;
    let mut n = x;
    while n > 1 {
        if smallest_factor[n as usize] != current_factor {
            res *= current_factor.pow(factor_count - 1) * (current_factor - 1);
            factor_count = 0;
            current_factor = smallest_factor[n as usize];
        }
        n /= current_factor;
        factor_count += 1;
    }
    if factor_count > 0 {
        res *= current_factor.pow(factor_count - 1) * (current_factor - 1);
    }
    res
}

fn mod_pow(base: i32, exponent: i32, modulo: i32) -> (i32, bool) {
    let mut res: i64 = 1;
    let mut exceeded = false;
    for shift in (0..32).rev() {
        res *= res;
        if res >= modulo as i64 {
            exceeded = true;
        }
        res %= modulo as i64;
        if ((exponent >> shift) & 1) == 1 {
            res *= base as i64;
            if res >= modulo as i64 {
                exceeded = true;
            }
            res %= modulo as i64;
        }
    }
    (res as i32, exceeded)
}

fn main() {
    const BOUND: usize = 1_000_000;
    let mut is_prime = [true; BOUND + 1];
    is_prime[0] = false;
    is_prime[1] = false;
    let mut smallest_factor = [BOUND as i32; BOUND + 1];
    smallest_factor[1] = 1;
    for n in 2..=BOUND {
        if !is_prime[n] {
            continue;
        }
        smallest_factor[n] = n as i32;
        for x in (n.pow(2)..=BOUND).step_by(n) {
            is_prime[x] = false;
            smallest_factor[x] = smallest_factor[x].min(n as i32);
        }
    }
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let t_input = scan.next();
    let m_input = scan.next();
    let mut mods = vec![m_input];
    for _ in 0..BOUND {
        let phi = euler_phi(*mods.last().unwrap(), &smallest_factor);
        if phi == 1 {
            break;
        }
        mods.push(phi);
    }
    for _ in 0..t_input {
        let n_input = scan.next();
        let mut powers = vec![];
        for _ in 0..n_input {
            powers.push(scan.next::<i32>());
        }
        if n_input == 1 {
            writeln!(out, "{}", powers[0] % m_input).ok();
            continue;
        }
        let mut res = *powers.last().unwrap();
        let mut exceeded;
        for (i, &power) in powers.iter().enumerate().skip(1).rev().skip(1) {
            let modulo = *mods.get(i).unwrap_or(&1);
            (res, exceeded) = mod_pow(power, res, modulo);
            if exceeded {
                res += modulo;
            }
        }
        writeln!(out, "{}", mod_pow(powers[0], res, mods[0]).0).ok();
    }
}
