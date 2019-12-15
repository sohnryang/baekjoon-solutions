"""
Baekjoon Online Judge #2268
https://www.acmicpc.net/problem/2268
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

N, M = map(int, infast().split())
arr = [0] * N
ft = FenwickTree(N)

for _ in range(M):
    c, *a = map(int, infast().split())
    if c == 0:
        a.sort()
        print(ft.range_sum(a[1] - 1) - ft.range_sum(a[0] - 2))
    else:
        delta = a[1] - arr[a[0] - 1]
        ft.update(a[0] - 1, delta)
        arr[a[0] - 1] += delta
