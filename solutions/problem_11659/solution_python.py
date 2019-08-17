"""
Baekjoon Online Judge #11659
https://www.acmicpc.net/problem/11659
"""

from sys import stdin

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
        while (pos < len(self.tree)):
            self.tree[pos] += val
            pos += (pos & -pos)

input_fast = lambda: stdin.readline().strip()
N, M = map(int, input_fast().split())
arr = list(map(int, input_fast().split()))
ft = FenwickTree(N)
for i, val in enumerate(arr):
    ft.update(i, val)
for _ in range(M):
    i, j = map(int, input_fast().split())
    print(ft.range_sum(j - 1) - ft.range_sum(i - 2))
