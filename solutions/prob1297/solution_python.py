"""
Baekjoon Online Judge #1297
https://www.acmicpc.net/problem/1297
"""

from math import sqrt
from sys import stdin

infast = lambda: stdin.readline().strip()

D, H, W = map(int, infast().split())
print(
    int(sqrt(D ** 2 * H ** 2 / (H ** 2 + W ** 2))),
    int(sqrt(D ** 2 * W ** 2 / (H ** 2 + W ** 2))),
)
