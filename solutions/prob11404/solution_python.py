"""
Baekjoon Online Judge #11404
https://www.acmicpc.net/problem/11404
"""

from math import inf
from sys import stdin
infast = lambda: stdin.readline().strip()

N = int(infast())
M = int(infast())
dist = []
for _ in range(N + 1):
    dist.append([inf] * (N + 1))
for _ in range(M):
    a, b, c = map(int, infast().split())
    dist[a][b] = min(dist[a][b], c)
for i in range(N + 1):
    dist[i][i] = 0
for k in range(1, N + 1):
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
for line in dist[1:]:
    for d in line[1:]:
        print(d if d != inf else 0, end=' ')
    print()
