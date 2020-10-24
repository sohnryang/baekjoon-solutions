"""
Baekjoon Online Judge #1275
https://www.acmicpc.net/problem/1275
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
arr = list(map(int, infast().split()))
ft = FenwickTree(N)
for i, elem in enumerate(arr):
    ft.update(i, elem)

for _ in range(Q):
    x, y, a, b = map(int, infast().split())
    x, y = sorted((x, y))
    print(ft.range_sum(y - 1) - ft.range_sum(x - 2))
    ft.update(a - 1, b - arr[a - 1])
    arr[a - 1] = b
