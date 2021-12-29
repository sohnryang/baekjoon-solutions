/*
 * Baekjoon Online Judge #1095
 * https://www.acmicpc.net/problem/1095
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

fn factorize(n: i64, primes: &Vec<i64>) -> HashMap<i64, i64> {
    let mut res = HashMap::new();
    for &p in primes {
        if p > n {
            break;
        }
        let mut exp = 1;
        let mut q = n / p.pow(exp);
        while q > 0 {
            *res.entry(p).or_default() += q;
            exp += 1;
            q = n / p.pow(exp);
        }
    }
    res
}

fn dec(x: &mut HashMap<i64, i64>, y: &HashMap<i64, i64>) {
    for (k, &v) in y.iter() {
        *x.get_mut(k).unwrap() -= v;
        if x[k] == 0 {
            x.remove(k);
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let s_input = scan.next();
    let f_input = scan.next();
    let m_input = scan.next();
    let mut prime_lookup = vec![true; m_input as usize + 1];
    let mut minfac = (0..=m_input).collect::<Vec<_>>();
    prime_lookup[0] = false;
    prime_lookup[1] = false;
    let sqrt = (m_input as f64).sqrt() as i64;
    for n in 2..=sqrt {
        if !prime_lookup[n as usize] {
            continue;
        }
        for x in (n.pow(2)..=m_input).step_by(n as usize) {
            prime_lookup[x as usize] = false;
            minfac[x as usize] = n;
        }
    }
    let primes = prime_lookup
        .iter()
        .enumerate()
        .filter(|&(_, &x)| x)
        .map(|(i, _)| i as i64)
        .collect::<Vec<_>>();
    let sfacto = factorize(s_input, &primes);
    let ffacto = factorize(f_input, &primes);
    let mut spffacto = factorize(s_input + f_input, &primes);
    dec(&mut spffacto, &sfacto);
    dec(&mut spffacto, &ffacto);
    if spffacto.is_empty() || *spffacto.keys().min().unwrap() > m_input {
        writeln!(out, "1").ok();
    } else {
        for x in (2..=m_input).rev() {
            let mut factors = HashMap::new();
            let mut n = x;
            while n > 1 {
                *factors.entry(minfac[n as usize]).or_default() += 1;
                n /= minfac[n as usize];
            }
            let mut divided = true;
            for (p, c) in factors {
                if *spffacto.entry(p).or_default() < c {
                    divided = false;
                    break;
                }
            }
            if divided {
                writeln!(out, "{}", x).ok();
                break;
            }
        }
    }
}
