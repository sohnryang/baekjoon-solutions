"""
Baekjoon Online Judge #1193
https://www.acmicpc.net/problem/1193
"""

from math import ceil, sqrt
from sys import stdin

infast = lambda: stdin.readline().strip()

X = int(infast())
group = ceil((sqrt(1 + 8 * X) - 1) / 2)
offset = X - group * (group - 1) // 2
if group % 2 == 0:
    print(f"{offset}/{group + 1 - offset}")
else:
    print(f"{group + 1 - offset}/{offset}")
