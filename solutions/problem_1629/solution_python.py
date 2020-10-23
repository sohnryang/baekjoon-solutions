"""
Baekjoon Online Judge #1629
https://www.acmicpc.net/problem/1629
"""

from sys import stdin
infast = lambda: stdin.readline().strip()

A, B, C = map(int, infast().split())
def mod_pow(A, B, C):
    if B == 0:
        return 1
    if B % 2 == 0:
        return mod_pow(A, B // 2, C) ** 2 % C
    else:
        return A * mod_pow(A, B - 1, C) % C

print(mod_pow(A, B, C))
