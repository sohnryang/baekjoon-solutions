"""
Baekjoon Online Judge #11003
https://www.acmicpc.net/problem/11003
"""

from collections import deque
from sys import stdin

infast = lambda: stdin.readline().strip()
N, L = map(int, infast().split())
A = list(map(int, infast().split()))
dq = deque()

for i in range(N):
    while dq and dq[0][1] <= i - L:
        dq.popleft()
    while dq and dq[-1][0] > A[i]:
        dq.pop()
    dq.append((A[i], i))
    print(dq[0][0], end=' ')
print()
