"""
Baekjoon Online Judge #16928
https://www.acmicpc.net/problem/16928
"""

from collections import deque
from sys import stdin

infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())

jump_table = {}
for _ in range(N + M):
    X, Y = map(int, infast().split())
    jump_table[X] = Y

dist = {1: 0}
q = deque([(1, 0)])
while q:
    here, here_dist = q.popleft()
    if here == 100:
        break
    for step in range(1, 7):
        there = here + step
        if there > 100:
            continue
        if there in jump_table:
            there = jump_table[there]
        if there in dist:
            continue
        there_dist = here_dist + 1
        dist[there] = there_dist
        q.append((there, there_dist))  # type: ignore
        dist[there] = there_dist

print(dist[100])
