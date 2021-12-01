"""Baekjoon Online Judge #23802
https://www.acmicpc.net/problem/23802
"""

N = int(input())
for _ in range(N):
    print("@" * (5 * N))
for _ in range(N * 4):
    print("@" * N)
