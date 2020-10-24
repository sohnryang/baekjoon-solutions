"""
Baekjoon Online Judge #9345
https://www.acmicpc.net/problem/9345
"""

from sys import stdin

class RMQ:
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

infast = lambda: stdin.readline().strip()

T = int(infast())
for _ in range(T):
    N, K = map(int, infast().split())
    arr = list(range(0, N))
    negarr = list(range(0, -N, -1))
    min_q = RMQ(arr)
    max_q = RMQ(negarr)
    for _ in range(K):
        Q, A, B = map(int, infast().split())
        if Q == 0:
            arr[A], arr[B] = arr[B], arr[A]
            min_q.update(A, arr[A])
            min_q.update(B, arr[B])
            max_q.update(A, -arr[A])
            max_q.update(B, -arr[B])
        else:
            if min_q.query(A, B) == A and -max_q.query(A, B) == B:
                print('YES')
            else:
                print('NO')
