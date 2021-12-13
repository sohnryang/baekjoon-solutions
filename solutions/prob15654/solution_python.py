"""
Baekjoon Online Judge #15654
https://www.acmicpc.net/problem/15654
"""

from sys import stdin
from itertools import permutations

infast = lambda: stdin.readline().strip()
N, M = map(int, infast().split())
A = [int(x) for x in infast().split()]
A.sort()

for c in permutations(A, M):
    if len(set(c)) < M:
        continue
    print(*c)
