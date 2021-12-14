"""
Baekjoon Online Judge #1712
https://www.acmicpc.net/problem/1712
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

A, B, C = map(int, infast().split())
if B >= C:
    print(-1)
else:
    print(A // (C - B) + 1)
