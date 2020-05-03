"""
Baekjoon Online Judge #1280
https://www.acmicpc.net/problem/1280
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

MOD = 1_000_000_007
MAX_X = 200_000
N = int(infast())
coords = FenwickTree(MAX_X)
existence = FenwickTree(MAX_X)
result = 1
first = True
for _ in range(N):
    X = int(infast())
    if first:
        first = False
    else:
        left_trees = existence.range_sum(X - 1)
        left_cost = X * left_trees - coords.range_sum(X - 1)
        right_trees = existence.range_sum(MAX_X - 1) - existence.range_sum(X)
        right_cost = coords.range_sum(MAX_X - 1) - coords.range_sum(X) - \
                     X * right_trees
        result *= left_cost + right_cost
        result %= MOD
    existence.update(X, 1)
    coords.update(X, X)
print(result)
