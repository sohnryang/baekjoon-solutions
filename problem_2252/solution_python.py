"""
Baekjoon Online Judge #2252
https://www.acmicpc.net/problem/2252
"""

from collections import deque

N, M = map(int, input().split())
graph = dict()
in_degree = dict()

for i in range(1, N + 1):
    graph[i] = []
    in_degree[i] = 0

for i in range(M):
    A, B = map(int, input().split())
    graph[A].append(B)
    in_degree[B] += 1

visit_q = deque()
sort_result = deque()
for v, deg in in_degree.items():
    if deg == 0:
        visit_q.append(v)
for _ in range(N):
    if not visit_q:
        break
    here = visit_q.popleft()
    sort_result.append(here)
    for there in graph[here]:
        in_degree[there] -= 1
        if in_degree[there] == 0:
            visit_q.append(there)

left_v = set(range(1, N + 1))
for v in sort_result:
    print(v, end=' ')
    left_v.remove(v)
for v in left_v:
    print(v, end=' ')

print()
