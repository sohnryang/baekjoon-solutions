"""
Baekjoon Online Judge #11505
https://www.acmicpc.net/problem/11505
"""

from sys import stdin

MOD = 1000000007
class RangeProd:
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
        self.tree[node] = (left * right) % MOD;
        return self.tree[node]

    def query_rec(self, lo, hi, node, node_lo, node_hi):
        if hi < node_lo or node_hi < lo:
            return 1
        if (lo <= node_lo and node_hi <= hi):
            return self.tree[node]
        mid = (node_lo + node_hi) // 2
        return self.query_rec(lo, hi, node * 2, node_lo, mid) * \
               self.query_rec(lo, hi, node * 2 + 1, mid + 1, node_hi) % MOD

    def query(self, lo, hi):
        return self.query_rec(lo, hi, 1, 0, self.length - 1)

    def update_rec(self, idx, newval, node, node_lo, node_hi):
        if idx < node_lo or node_hi < idx:
            return self.tree[node]
        if node_lo == node_hi:
            self.tree[node] = newval
            return self.tree[node]
        mid = (node_lo + node_hi) // 2
        self.tree[node] = \
            self.update_rec(idx, newval, node * 2, node_lo, mid) * \
            self.update_rec(idx, newval, node * 2 + 1, mid + 1, node_hi) % MOD
        return self.tree[node]

    def update(self, idx, newval):
        return self.update_rec(idx, newval, 1, 0, self.length - 1)

infast = lambda: stdin.readline().strip()
N, M, K = map(int, infast().split())
arr = []
for i in range(N):
    arr.append(int(infast()))
rp = RangeProd(arr)
for _ in range(M + K):
    a, b, c = map(int, infast().split())
    if a == 1:
        rp.update(b - 1, c)
        arr[b - 1] = c
    else:
        print(rp.query(b - 1, c - 1) % MOD)
