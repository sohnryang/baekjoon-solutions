"""
Baekjoon Online Judge #1717
https://www.acmicpc.net/problem/1717
"""

from sys import stdin

input_fast = lambda: stdin.readline().strip()

class UnionFind:
    def __init__(self, N):
        self.set_size = [1] * N
        self.num_sets = N
        self.rank = [0] * N
        self.parents = [0] * N
        for i in range(N):
            self.parents[i] = i

    def find_set(self, i):
        if self.parents[i] != i:
            self.parents[i] = self.find_set(self.parents[i])
            return self.parents[i]
        return i

    def same_set(self, i, j):
        return self.find_set(i) == self.find_set(j)

    def union_set(self, i, j):
        if self.same_set(i, j):
            return
        self.num_sets -= 1
        x = self.find_set(i)
        y = self.find_set(j)
        if self.rank[x] > self.rank[y]:
            self.parents[x] = y
            self.set_size[x] += self.set_size[y]
        else:
            self.parents[y] = x
            self.set_size[y] += self.set_size[x]
            if self.rank[x] == self.rank[y]:
                self.rank[y] += 1

N, M = map(int, input_fast().split())
ufds = UnionFind(N + 1)
for _ in range(M):
    cmd, a, b = map(int, input_fast().split())
    if cmd == 0:
        ufds.union_set(a, b)
    else:
        print('YES' if ufds.same_set(a, b) else 'NO')
