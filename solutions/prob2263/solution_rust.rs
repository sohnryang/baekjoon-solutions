/*
 * Baekjoon Online Judge #2263
 * https://www.acmicpc.net/problem/2263
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

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let n_input: usize = scan.next();
    let mut inorder = vec![];
    let mut inorder_lookup = vec![0; n_input + 1];
    for i in 0..n_input {
        let node: usize = scan.next();
        inorder.push(node);
        inorder_lookup[node] = i;
    }
    let mut postorder = vec![];
    let mut postorder_lookup = vec![0; n_input + 1];
    for i in 0..n_input {
        let node: usize = scan.next();
        postorder.push(node);
        postorder_lookup[node] = i;
    }
    let mut stack = vec![((0_usize, n_input), (0_usize, n_input))];
    let mut preorder = vec![];
    while !stack.is_empty() {
        let (inorder_range, postorder_range) = stack.pop().unwrap();
        let (inorder_lo, inorder_hi) = inorder_range;
        let (postorder_lo, postorder_hi) = postorder_range;
        if postorder_lo == postorder_hi {
            continue;
        }
        let root = postorder[postorder_hi - 1];
        let root_idx_inorder = inorder_lookup[root];
        let left_len = root_idx_inorder - inorder_lo;
        let right_len = inorder_hi - root_idx_inorder - 1;
        let left_inorder_range = (inorder_lo, inorder_lo + left_len);
        let right_inorder_range = (inorder_hi - right_len, inorder_hi);
        let left_postorder_range = (postorder_lo, postorder_lo + left_len);
        let right_postorder_range = (postorder_hi - right_len - 1, postorder_hi - 1);
        stack.push((right_inorder_range, right_postorder_range));
        stack.push((left_inorder_range, left_postorder_range));
        preorder.push(root);
    }
    for node in preorder {
        write!(out, "{node} ").ok();
    }
    writeln!(out).ok();
}
