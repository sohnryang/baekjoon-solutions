"""
Baekjoon Online Judge #1753
https://www.acmicpc.net/problem/1753
"""

import heapq
from math import inf
from sys import stdin
infast = lambda: stdin.readline().strip()

V, E = map(int, infast().split())
K = int(infast())
graph = {}
for v in range(1, V + 1):
    graph[v] = list()
for _ in range(E):
    u, v, w = map(int, infast().split())
    graph[u].append((v, w))

dist = [inf] * (V + 1)
pq = [(0, K)]
while pq:
    d1, here = heapq.heappop(pq)
    if dist[here] < d1:
        continue
    for there, d2 in graph[here]:
        next_dist = d1 + d2
        if dist[there] > next_dist:
            dist[there] = next_dist
            heapq.heappush(pq, (next_dist, there))

dist[K] = 0
for d in dist[1:]:
    if d == inf:
        print('INF')
    else:
        print(d)
