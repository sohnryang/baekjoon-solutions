"""
Baekjoon Online Judge #15651
https://www.acmicpc.net/problem/15651
"""

from itertools import product
from sys import stdin

infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())
for p in product(range(1, N + 1), repeat=M):
    print(*p)
