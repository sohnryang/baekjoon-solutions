"""
Baekjoon Online Judge #16428
https://www.acmicpc.net/problem/16428
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

A, B = map(int, infast().split())
p, r = A // B, A % B
if r < 0:
    r -= B
    p += 1
print(p)
print(r)
