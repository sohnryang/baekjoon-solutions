/*
 * Baekjoon Online Judge #7662
 * https://www.acmicpc.net/problem/7662
 */

use std::{cmp::Reverse, collections::BinaryHeap, io::stdin};

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

fn flush_heap<T: Ord>(heap: &mut BinaryHeap<T>, deleted: &mut BinaryHeap<T>) {
    while heap.peek().is_some() && heap.peek() == deleted.peek() {
        heap.pop();
        deleted.pop();
    }
}

fn main() {
    let mut scan = Scanner::default();
    let t_input: i32 = scan.next();
    for _ in 0..t_input {
        let k_input: i32 = scan.next();
        let mut min_heap = BinaryHeap::new();
        let mut max_heap = BinaryHeap::new();
        let mut min_heap_deleted = BinaryHeap::new();
        let mut max_heap_deleted = BinaryHeap::new();
        for _ in 0..k_input {
            let cmd_input: String = scan.next();
            let arg_input: i32 = scan.next();
            if cmd_input == "I" {
                min_heap.push(Reverse(arg_input));
                max_heap.push(arg_input);
            } else {
                if min_heap.len() <= min_heap_deleted.len() {
                    continue;
                }
                if arg_input == -1 {
                    flush_heap(&mut min_heap, &mut min_heap_deleted);
                    let deleted = min_heap.pop().unwrap();
                    max_heap_deleted.push(deleted.0);
                } else {
                    flush_heap(&mut max_heap, &mut max_heap_deleted);
                    let deleted = max_heap.pop().unwrap();
                    min_heap_deleted.push(Reverse(deleted));
                }
            }
        }
        flush_heap(&mut min_heap, &mut min_heap_deleted);
        flush_heap(&mut max_heap, &mut max_heap_deleted);
        if min_heap.len() == 0 {
            println!("EMPTY");
        } else {
            println!(
                "{} {}",
                max_heap.peek().unwrap(),
                min_heap.peek().unwrap().0
            );
        }
    }
}
