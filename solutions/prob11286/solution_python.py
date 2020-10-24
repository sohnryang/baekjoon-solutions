"""
Baekjoon Online Judge #1927
https://www.acmicpc.net/problem/1927
"""

from heapq import heappush, heappop
from sys import stdin

N = int(stdin.readline().strip())
pq = []
for _ in range(N):
    X = int(stdin.readline().strip())
    if X == 0:
        if not pq:
            print(0)
        else:
            print(heappop(pq)[1])
    else:
        heappush(pq, (abs(X), X))
