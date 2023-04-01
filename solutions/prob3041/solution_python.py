"""
Baekjoon Online Judge #3041
https://www.acmicpc.net/problem/3041
"""

from sys import stdin
from typing import Tuple

infast = lambda: stdin.readline().strip()


def dist(p1: Tuple[int, int], p2: Tuple[int, int]) -> int:
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])


original_places = dict((ch, (i // 4, i % 4)) for i, ch in enumerate("ABCDEFGHIJKLMNO"))
res = 0
for y in range(4):
    res += sum(
        dist(original_places[ch], (y, x)) for x, ch in enumerate(infast()) if ch != "."
    )
print(res)
