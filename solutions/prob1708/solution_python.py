"""
Baekjoon Online Judge #1708
https://www.acmicpc.net/problem/1708
"""

from sys import stdin
from typing import List, Tuple

infast = lambda: stdin.readline().strip()


def cross(o: Tuple[int, int], a: Tuple[int, int], b: Tuple[int, int]) -> int:
    return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])


N = int(infast())

points: List[Tuple[int, int]] = []
for _ in range(N):
    X, Y = map(int, infast().split())
    points.append((X, Y))
points.sort()

lower_hull = []
for p in points:
    while len(lower_hull) >= 2 and cross(lower_hull[-2], lower_hull[-1], p) <= 0:
        lower_hull.pop()
    lower_hull.append(p)

upper_hull = []
for p in reversed(points):
    while len(upper_hull) >= 2 and cross(upper_hull[-2], upper_hull[-1], p) <= 0:
        upper_hull.pop()
    upper_hull.append(p)

print(len(lower_hull) + len(upper_hull) - 2)
