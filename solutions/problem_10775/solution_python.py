"""
Baekjoon Online Judge #10775
https://www.acmicpc.net/problem/10775
"""

from sys import stdin

class UnionFind:
    def __init__(self, N):
        self.set_size = [1] * N
        self.num_sets = N
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
        self.parents[x] = y
        self.set_size[x] += self.set_size[y]

G = int(stdin.readline().strip())
P = int(stdin.readline().strip())
ufds = UnionFind(G + 1)
result = 0

for _ in range(P):
    G_i = int(stdin.readline().strip())
    dock = ufds.find_set(G_i)
    if dock == 0:
        break
    ufds.union_set(dock, dock - 1)
    result += 1

print(result)
