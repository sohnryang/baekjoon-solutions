"""
Baekjoon Online Judge #14648
https://www.acmicpc.net/problem/14648
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

class FenwickTree:
    def __init__(self, n):
        self.tree = [0] * (n + 1)

    def range_sum(self, pos):
        pos += 1
        ret = 0
        while pos > 0:
            ret += self.tree[pos]
            pos &= (pos - 1)
        return ret

    def update(self, pos, val):
        pos += 1
        while pos < len(self.tree):
            self.tree[pos] += val
            pos += (pos & -pos)

N, Q = map(int, infast().split())
ft = FenwickTree(N)
seq = list(map(int, infast().split()))
for i, n in enumerate(seq):
    ft.update(i, n)
for _ in range(Q):
    query, *args = map(int, infast().split())
    if query == 1:
        a, b = args
        print(ft.range_sum(b - 1) - ft.range_sum(a - 2))
        t = seq[a - 1]
        seq[a - 1] = seq[b - 1]
        seq[b - 1] = t
        ft.update(a - 1, seq[a - 1] - seq[b - 1])
        ft.update(b - 1, seq[b - 1] - seq[a - 1])
    else:
        a, b, c, d = args
        print((ft.range_sum(b - 1) - ft.range_sum(a - 2)) - \
              (ft.range_sum(d - 1) - ft.range_sum(c - 2)))
