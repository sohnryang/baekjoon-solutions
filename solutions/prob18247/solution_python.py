"""
Baekjoon Online Judge #18247
https://www.acmicpc.net/problem/18247
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

T = int(infast())
for _ in range(T):
    N, M = map(int, infast().split())
    if N < 12 or M < 4:
        print(-1)
        continue
    print(M * 11 + 4)
