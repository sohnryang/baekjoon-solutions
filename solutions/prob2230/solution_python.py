"""
Baekjoon Online Judge #2230
https://www.acmicpc.net/problem/2230
"""
from math import inf
from sys import exit, stdin
infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())
A = []
for _ in range(N):
    A.append(int(infast()))
A.sort()

lo = 0
hi = 0
result = inf

while lo <= hi < N:
    diff = A[hi] - A[lo]
    if diff == M:
        result = diff
        break
    elif diff < M:
        hi += 1
    else:
        result = min(result, diff)
        lo += 1

print(result)
