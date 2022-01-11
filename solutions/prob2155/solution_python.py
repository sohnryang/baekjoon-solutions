"""
Baekjoon Online Judge #2155
https://www.acmicpc.net/problem/2155
"""

from math import ceil, sqrt
from sys import stdin

infast = lambda: stdin.readline().strip()

A, B = map(int, infast().split())
if A > B:
    A, B = B, A

a_level = ceil(sqrt(A))
b_level = ceil(sqrt(B))
if a_level == b_level:
    print(B - A)
else:
    a_over_vert = A % 2 == a_level % 2

    def solve(start):
        center = lambda x: (x ** 2 + (x - 1) ** 2 + 1) // 2
        a_level_center = center(a_level)
        a_offset = start - a_level_center
        b_level_center = center(b_level)
        level_delta = b_level - a_level
        vert_left = a_offset + b_level_center - level_delta
        vert_right = a_offset + b_level_center + level_delta
        dist = 2 * level_delta - 1
        if vert_left <= B <= vert_right:
            dist += int(B % 2 == b_level % 2)
        else:
            dist += min(abs(B - vert_left), abs(B - vert_right))
        return dist

    if a_over_vert:
        print(solve(A))
    else:
        print(1 + min(solve(A - 1), solve(A + 1)))
