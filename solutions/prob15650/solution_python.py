"""Baekjoon Online Judge #15650
https://www.acmicpc.net/problem/15650
"""

from itertools import combinations

N, M = map(int, input().split())
for seq in combinations(range(1, N + 1), M):
    print(" ".join([str(x) for x in seq]))
