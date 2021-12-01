"""Baekjoon Online Judge #23804
https://www.acmicpc.net/problem/23804
"""

N = int(input())
for _ in range(N):
    print("@" * (5 * N))
for _ in range(3 * N):
    print("@" * N)
for _ in range(N):
    print("@" * (5 * N))
