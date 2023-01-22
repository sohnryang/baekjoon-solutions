/*
 * Baekjoon Online Judge #16236
 * https://www.acmicpc.net/problem/16236
 */

use std::{
    collections::VecDeque,
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

fn adjacent(pos: (usize, usize), size: usize) -> Vec<(usize, usize)> {
    let mut res = vec![];
    if 1 <= pos.0 && pos.0 < size && pos.1 < size {
        let up = (pos.0 - 1, pos.1);
        res.push(up);
    }
    if pos.0 < size && 1 <= pos.1 && pos.1 < size {
        let left = (pos.0, pos.1 - 1);
        res.push(left);
    }
    if pos.0 < size && pos.1 < size - 1 {
        let right = (pos.0, pos.1 + 1);
        res.push(right);
    }
    if pos.0 < size - 1 && pos.1 < size {
        let down = (pos.0 + 1, pos.1);
        res.push(down);
    }
    res
}

fn find_prey(
    grid: &Vec<Vec<i32>>,
    start_pos: (usize, usize),
    shark_size: i32,
) -> Option<(i32, (usize, usize))> {
    let mut q = VecDeque::new();
    let mut dist: Vec<Vec<Option<i32>>> = vec![vec![None; grid.len()]; grid.len()];
    let mut res: Option<(i32, (usize, usize))> = None;
    dist[start_pos.0][start_pos.1] = Some(0);
    q.push_back((start_pos, 0));
    while !q.is_empty() {
        let (here, here_dist) = q.pop_front().unwrap();
        for there in adjacent(here, grid.len()) {
            if dist[there.0][there.1].is_some() {
                continue;
            }
            let there_cell = grid[there.0][there.1];
            if there_cell > shark_size {
                continue;
            }
            let there_dist = here_dist + 1;
            dist[there.0][there.1] = Some(there_dist);
            q.push_back((there, there_dist));
            if there_cell == 0 || there_cell == shark_size {
                continue;
            }
            let current_res = (there_dist, there);
            res = Some(match res {
                Some(old_res) => old_res.min(current_res),
                None => current_res,
            });
        }
    }
    res
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let n_input: usize = scan.next();
    let mut grid = vec![vec![0; n_input]; n_input];
    let mut start_pos = (0, 0);
    for y in 0..n_input {
        for x in 0..n_input {
            let cell = scan.next();
            if cell == 9 {
                start_pos = (y, x);
            } else {
                grid[y][x] = cell;
            }
        }
    }

    let mut size = 2;
    let mut eaten_fish_phase = 0;
    let mut result = 0;
    while let Some((prey_dist, prey_pos)) = find_prey(&grid, start_pos, size) {
        grid[prey_pos.0][prey_pos.1] = 0;
        result += prey_dist;
        eaten_fish_phase += 1;
        start_pos = prey_pos;
        if eaten_fish_phase == size {
            size += 1;
            eaten_fish_phase = 0;
        }
    }
    writeln!(out, "{result}").ok();
}
