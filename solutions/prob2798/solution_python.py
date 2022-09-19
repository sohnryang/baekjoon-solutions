"""
Baekjoon Online Judge #2798
https://www.acmicpc.net/problem/2798
"""

import itertools
from sys import stdin

infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())
A = list(map(int, infast().split()))

res = None
for perm in itertools.permutations(A, 3):
    s = sum(perm)
    if s > M:
        continue
    if res is None or res < s:
        res = s
print(res)
