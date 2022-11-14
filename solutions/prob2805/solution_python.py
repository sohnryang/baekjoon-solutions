"""
Baekjoon Online Judge #2805
https://www.acmicpc.net/problem/2805
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())
A = list(map(int, infast().split()))

lo = 0
hi = max(A)
while lo <= hi:
    mid = (lo + hi) // 2
    gain = sum([max(x - mid, 0) for x in A])
    if gain >= M:
        lo = mid + 1
    else:
        hi = mid - 1
print(hi)
