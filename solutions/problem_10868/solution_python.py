"""
Baekjoon Online Judge #10868
https://www.acmicpc.net/problem/10868
"""

from sys import stdin

class SegmentTree:
    def __init__(self, arr):
        self.length = len(arr)
        self.tree = [None] * (self.length * 4)
        self.init_tree(arr, 0, self.length - 1, 1)

    def init_tree(self, arr, lo, hi, node):
        if lo == hi:
            self.tree[node] = arr[lo]
            return self.tree[node]
        mid = (lo + hi) // 2
        left = self.init_tree(arr, lo, mid, node * 2)
        right = self.init_tree(arr, mid + 1, hi, node * 2 + 1)
        self.tree[node] = min(left, right)
        return self.tree[node]

    def query_rec(self, lo, hi, node, node_lo, node_hi):
        if hi < node_lo or node_hi < lo:
            return 2 ** 63
        if (lo <= node_lo and node_hi <= hi):
            return self.tree[node]
        mid = (node_lo + node_hi) // 2
        return min(self.query_rec(lo, hi, node * 2, node_lo, mid),
                   self.query_rec(lo, hi, node * 2 + 1, mid + 1, node_hi))

    def query(self, lo, hi):
        return self.query_rec(lo, hi, 1, 0, self.length - 1)

    def update_rec(self, idx, newval, node, node_lo, node_hi):
        if idx < node_lo or node_hi < idx:
            return self.tree[node]
        if node_lo == node_hi:
            self.tree[node] = newval
            return self.tree[node]
        mid = (node_lo + node_hi) // 2
        self.tree[node] = min(
            self.update_rec(idx, newval, node * 2, node_lo, mid),
            self.update_rec(idx, newval, node * 2 + 1, mid + 1, node_hi)
        )
        return self.tree[node]

    def update(self, idx, newval):
        return self.update_rec(idx, newval, 1, 0, self.length - 1)

input_fast = lambda: stdin.readline().strip()
N, M = map(int, input_fast().split())
arr = []
for _ in range(N):
    n = int(input_fast())
    arr.append(n)

segtree = SegmentTree(arr)
for _ in range(M):
    a, b = map(int, input_fast().split())
    print(segtree.query(a - 1, b - 1))
