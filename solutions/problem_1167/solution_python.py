"""
Baekjoon Online Judge #1167
https://www.acmicpc.net/problem/1167
"""

from collections import deque
from operator import itemgetter
from sys import stdin
infast = lambda: stdin.readline().strip()

V = int(infast())
tree = dict()
for _ in range(1, V + 1):
    v, *data = list(map(int, infast().split()))[:-1]
    tree[v] = list()
    for i in range(0, len(data), 2):
        tree[v].append((data[i], data[i + 1]))

start = 1
max_node = None
for _ in range(2):
    visited = set([start])
    dist = {start: 0}
    q = deque([start])
    while q:
        here = q.popleft()
        for there, d in tree[here]:
            if there not in visited:
                visited.add(there)
                dist[there] = dist[here] + d
                q.append(there)
    max_node = max(dist.items(), key=itemgetter(1))
    start = max_node[0]
print(max_node[1])
