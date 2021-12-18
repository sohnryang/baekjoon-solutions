"""
Baekjoon Online Judge #10162
https://www.acmicpc.net/problem/10162
"""

from sys import stdin

infast = lambda: stdin.readline().strip()
T = int(infast())
if T % 10 != 0:
    print(-1)
else:
    A = T // 300
    T %= 300
    B = T // 60
    T %= 60
    C = T // 10
    print(A, B, C)
