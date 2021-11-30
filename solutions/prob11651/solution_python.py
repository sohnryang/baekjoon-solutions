"""
Baekjoon Online Judge #11651
https://www.acmicpc.net/problem/11651
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N = int(infast())
arr = []
for _ in range(N):
    arr.append(tuple([int(x) for x in infast().split()])[::-1])
arr.sort()
for coord in arr:
    print(" ".join([str(x) for x in reversed(coord)]))
