/*
 * Baekjoon Online Judge #1167
 * https://www.acmicpc.net/problem/1167
 */

use std::{
    collections::{HashMap, VecDeque},
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

fn bfs(graph: &HashMap<i32, Vec<(i32, i32)>>, start: i32) -> HashMap<i32, i32> {
    let mut q = VecDeque::new();
    q.push_back(start);
    let mut dist = HashMap::new();
    dist.insert(start, 0);
    while !q.is_empty() {
        let here = q.pop_front().unwrap();
        for &(there, d) in graph.get(&here).unwrap() {
            if !dist.contains_key(&there) {
                dist.insert(there, dist.get(&here).unwrap() + d);
                q.push_back(there);
            }
        }
    }
    dist
}

fn main() {
    let mut scan = Scanner::default();

    let v_input: i32 = scan.next();
    let mut graph = HashMap::new();
    for _ in 0..v_input {
        let vertex: i32 = scan.next();
        loop {
            let another_vertex: i32 = scan.next();
            if another_vertex == -1 {
                break;
            }
            let dist: i32 = scan.next();
            graph
                .entry(vertex)
                .or_insert(vec![])
                .push((another_vertex, dist));
        }
    }

    let dist_from_start = bfs(&graph, 1);
    let &farthest_vertex = dist_from_start.iter().max_by_key(|x| x.1).unwrap().0;
    let dist = bfs(&graph, farthest_vertex);
    println!("{}", *dist.iter().max_by_key(|x| x.1).unwrap().1);
}
