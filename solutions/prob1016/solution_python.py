"""
Baekjoon Online Judge #1016
https://www.acmicpc.net/problem/1016
"""

from math import ceil, floor, sqrt
from sys import stdin
infast = lambda: stdin.readline().strip()

A, B = map(int, infast().split())
max_sq = floor(sqrt(B))
nonfree = set()
for i in range(2, max_sq + 1):
    min_coeff = ceil(A / i ** 2)
    max_coeff = B // i ** 2
    for j in range(min_coeff, max_coeff + 1):
        nonfree.add(j * i ** 2)
print(B - A + 1 - len(nonfree))
