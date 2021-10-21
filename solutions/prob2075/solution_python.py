"""
Baekjoon Online Judge #2075
https://www.acmicpc.net/problem/2075
"""

import heapq

N = int(input())
table = []
for _ in range(N):
    table.append([int(x) for x in input().split()])

bigger = []

for x in table[0]:
    heapq.heappush(bigger, x)
nth = heapq.heappop(bigger)

for line in table[1:]:
    for x in line:
        if x > nth:
            heapq.heappush(bigger, x)
            nth = heapq.heappop(bigger)

print(nth)
