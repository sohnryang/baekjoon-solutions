/*
 * Baekjoon Online Judge #12100
 * https://www.acmicpc.net/problem/12100
 */

use std::{
    cmp::max,
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

fn push_board(stack: &mut Vec<(i32, Vec<Vec<i32>>, i32)>, board: &Vec<Vec<i32>>, depth: i32) {
    if depth >= 5 {
        return;
    }
    for dir in 0..4 {
        stack.push((dir, board.clone(), depth));
    }
}
fn push_left(board: &mut Vec<Vec<i32>>) {
    for line in board {
        let mut last_num = None;
        let mut merged = vec![];
        for &num in line.iter() {
            if num == 0 {
                continue;
            }
            if Some(num) == last_num {
                merged.push(num * 2);
                last_num = None;
            } else {
                match last_num {
                    Some(x) => merged.push(x),
                    None => (),
                }
                last_num = Some(num);
            }
        }
        merged.push(last_num.unwrap_or(0));
        if merged.len() < line.len() {
            merged.extend(vec![0; line.len() - merged.len()])
        }
        *line = merged;
    }
}

fn transpose(board: &mut Vec<Vec<i32>>) {
    for i in 0..board.len() {
        for j in 0..=i {
            let t = board[i][j];
            board[i][j] = board[j][i];
            board[j][i] = t;
        }
    }
}

fn push_up(board: &mut Vec<Vec<i32>>) {
    transpose(board);
    push_left(board);
    transpose(board);
}

fn push_right(board: &mut Vec<Vec<i32>>) {
    board.iter_mut().for_each(|x| x.reverse());
    push_left(board);
    board.iter_mut().for_each(|x| x.reverse());
}

fn push_down(board: &mut Vec<Vec<i32>>) {
    transpose(board);
    board.iter_mut().for_each(|x| x.reverse());
    push_left(board);
    board.iter_mut().for_each(|x| x.reverse());
    transpose(board);
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());
    let n_input = scan.next();
    let mut board_input = vec![];
    for _ in 0..n_input {
        let mut line = vec![];
        for _ in 0..n_input {
            line.push(scan.next::<i32>());
        }
        board_input.push(line);
    }

    let mut stack = vec![];
    let mut result = 0;

    push_board(&mut stack, &board_input, 0);
    while !stack.is_empty() {
        let (dir, mut board, depth) = stack.pop().unwrap();
        match dir {
            0 => push_left(&mut board),
            1 => push_up(&mut board),
            2 => push_right(&mut board),
            3 => push_down(&mut board),
            _ => panic!(),
        }
        result = max(
            result,
            board
                .iter()
                .map(|x| *x.iter().max().unwrap())
                .max()
                .unwrap(),
        );
        push_board(&mut stack, &board, depth + 1);
    }
    writeln!(out, "{}", result).ok();
}
