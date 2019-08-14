"""
Baekjoon Online Judge #2042
https://www.acmicpc.net/problem/2042
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
N, M, K = map(int, input_fast().split())
ft = FenwickTree(N)
arr = []

for i in range(N):
    n = int(input_fast())
    ft.update(i, n)
    arr.append(n)

for _ in range(M + K):
    a, b, c = map(int, input_fast().split())
    if a == 1:
        ft.update(b - 1, -arr[b - 1] + c)
        arr[b - 1] = c
    else:
        print(ft.range_sum(c - 1) - ft.range_sum(b - 2))
