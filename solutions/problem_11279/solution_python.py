"""
Baekjoon Online Judge #11279
https://www.acmicpc.net/problem/11279
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
            print(-heappop(pq))
    else:
        heappush(pq, -X)
