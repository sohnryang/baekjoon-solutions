"""
Baekjoon Online Judge #1219
https://www.acmicpc.net/problem/1219
"""

from collections import defaultdict, deque
from math import inf
from sys import stdin
from typing import DefaultDict, List, Set, Tuple, Union

infast = lambda: stdin.readline().strip()

EdgeLen = Union[int, float]
EdgeInfo = Tuple[int, EdgeLen]

N, S, T, M = map(int, infast().split())
graph: DefaultDict[int, List[EdgeInfo]] = defaultdict(list)
for _ in range(M):
    U, V, C = map(int, infast().split())
    graph[U].append((V, C))
P = list(map(int, infast().split()))
for vertex in range(N):
    for i in range(len(graph[vertex])):
        there, there_len = graph[vertex][i]
        graph[vertex][i] = (there, there_len - P[there])
graph[-1].append((S, -P[S]))

dist: DefaultDict[int, EdgeLen] = defaultdict(lambda: inf)
dist[-1] = 0


def update(here: int, there: int, weight: EdgeLen) -> None:
    if dist[there] > dist[here] + weight:
        dist[there] = dist[here] + weight


for _ in range(N):
    for here, edges in graph.items():
        for edge in edges:
            there, weight = edge
            update(here, there, weight)

cycle_nodes: Set[int] = set()
for here, edges in graph.items():
    for edge in edges:
        there, weight = edge
        if there in cycle_nodes or here in cycle_nodes:
            continue
        if dist[there] > dist[here] + weight:
            cycle_nodes.add(there)
            cycle_nodes.add(here)
    newly_added: Set[int] = set()
    for start in cycle_nodes:
        q = deque([start])
        while q:
            here = q.popleft()
            for there, _ in graph[here]:
                if there in newly_added or there in cycle_nodes:
                    continue
                newly_added.add(there)
                q.append(there)
    cycle_nodes = cycle_nodes | newly_added

if T in cycle_nodes:
    print("Gee")
elif dist[T] == inf:
    print("gg")
else:
    print(-dist[T])
