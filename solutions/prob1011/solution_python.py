"""
Baekjoon Online Judge #1011
https://www.acmicpc.net/problem/1011
"""

from sys import stdin
from math import ceil, sqrt

infast = lambda: stdin.readline().strip()

T = int(infast())
for _ in range(T):
    X, Y = map(int, infast().split())
    D = Y - X
    a_idx = sqrt(D)
    if int(a_idx) ** 2 == D:
        print(2 * int(a_idx) - 1)
        continue
    b_idx = (sqrt(1 + 4 * D) - 1) / 2
    if int(b_idx) ** 2 + int(b_idx) == D:
        print(2 * int(b_idx))
        continue
    if int(a_idx) == ceil(b_idx):
        print(2 * ceil(b_idx))
    else:
        print(2 * ceil(a_idx) - 1)
