"""
Baekjoon Online Judge #4485
https://www.acmicpc.net/problem/4485
"""

import heapq
import sys

infast = lambda: sys.stdin.readline().strip()

prob_no = 1
while True:
    N = int(infast())
    if N == 0:
        break
    grid = []
    for _ in range(N):
        grid.append([int(x) for x in infast().split()])
    dist = dict()
    dist[(0, 0)] = 0
    pq = []
    heapq.heappush(pq, (dist[(0, 0)], (0, 0)))
    dxs = [-1, 0, 0, 1]
    dys = [0, -1, 1, 0]
    while pq:
        cost, here = heapq.heappop(pq)
        if cost > dist[here]:
            continue
        for dy, dx in zip(dys, dxs):
            there = (here[0] + dy, here[1] + dx)
            if not (0 <= there[0] < N and 0 <= there[1] < N):
                continue
            there_dist = grid[there[0]][there[1]] + dist[here]
            if there not in dist or dist[there] > there_dist:
                dist[there] = there_dist
                heapq.heappush(pq, (there_dist, there))
    print(f"Problem {prob_no}: {dist[(N - 1, N - 1)] + grid[0][0]}")
    prob_no += 1
