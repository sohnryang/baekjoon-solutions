"""
Baekjoon Online Judge #1781
https://www.acmicpc.net/problem/1781
"""

import heapq
import sys

infast = lambda: sys.stdin.readline().strip()

N = int(infast())
homeworks = []
for _ in range(N):
    homeworks.append(tuple([int(x) for x in infast().split()]))
homeworks.sort()

time = 0
total_reward = 0
selected = []
for homework in homeworks:
    due, reward = homework
    heapq.heappush(selected, reward)
    while due < len(selected):
        heapq.heappop(selected)

print(sum(selected))
