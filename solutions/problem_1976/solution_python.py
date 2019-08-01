"""
Baekjoon Online Judge #1976
https://www.acmicpc.net/problem/1976
"""

from sys import exit, stdin

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

N = int(stdin.readline().strip())
M = int(stdin.readline().strip())
ufds = UnionFind(N + 1)

for u in range(1, N + 1):
    vs = list(map(int, stdin.readline().strip().split()))
    for v, connected in enumerate(vs, start=1):
        if connected == 1:
            ufds.union_set(u, v)

city_plan = list(map(int, stdin.readline().strip().split()))
for city in city_plan:
    if not ufds.same_set(city, city_plan[0]):
        print('NO')
        exit(0)
print('YES')
