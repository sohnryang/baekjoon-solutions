"""
Baekjoon Online Judge #1655
https://www.acmicpc.net/problem/1655
"""

from sys import stdin
import heapq

infast = lambda: stdin.readline().strip()
N = int(infast())
min_heap = []
max_heap = []
for _ in range(N):
    if len(min_heap) == len(max_heap):
        heapq.heappush(max_heap, -int(infast()))
    else:
        heapq.heappush(min_heap, int(infast()))
    if min_heap and max_heap and min_heap[0] < -max_heap[0]:
        a = -heapq.heappop(max_heap)
        b = heapq.heappop(min_heap)
        heapq.heappush(max_heap, -b)
        heapq.heappush(min_heap, a)
    print(-max_heap[0])
