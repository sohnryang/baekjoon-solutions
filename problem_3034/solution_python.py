"""
Baekjoon Online Judge #3034
https://www.acmicpc.net/problem/3034
"""

from math import hypot

[in_n, in_w, in_h] = map(int, input().split())
max_len = hypot(in_w, in_h)
for i in range(in_n):
    in_len = int(input())
    print('DA' if in_len <= max_len else 'NE')
