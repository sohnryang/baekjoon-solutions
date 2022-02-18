"""
Baekjoon Online Judge #16199
https://www.acmicpc.net/problem/16199
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

A = tuple(map(int, infast().split()))
B = tuple(map(int, infast().split()))

yd = B[0] - A[0]
if B[1:] >= A[1:]:
    print(yd)
else:
    print(yd - 1)
print(yd + 1)
print(yd)
