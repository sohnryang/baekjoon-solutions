"""
Baekjoon Online Judge #4195
https://www.acmicpc.net/problem/4195
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
        self.set_size[y] += self.set_size[x]
        self.set_size[x] = 1
        return self.set_size[y]

T = int(stdin.readline().strip())
for _ in range(T):
    F = int(stdin.readline().strip())
    names = dict()
    ufds = UnionFind(F * 2)
    index = 0
    for i in range(F):
        name1, name2 = stdin.readline().strip().split()
        if name1 not in names:
            names[name1] = index
            index += 1
        if name2 not in names:
            names[name2] = index
            index += 1
        ufds.union_set(names[name1], names[name2])
        print(ufds.set_size[ufds.find_set(names[name1])])
