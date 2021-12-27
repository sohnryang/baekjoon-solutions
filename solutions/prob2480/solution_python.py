"""
Baekjoon Online Judge #2480
https://www.acmicpc.net/problem/2480
"""

from collections import Counter
from sys import stdin

infast = lambda: stdin.readline().strip()

A, B, C = map(int, infast().split())
c = Counter([A, B, C])
if len(c) == 1:
    print(10000 + A * 1000)
elif len(c) == 2:
    print(c.most_common(1)[0][0] * 100 + 1000)
else:
    print(max(A, B, C) * 100)
