"""Baekjoon Online Judge #23803
https://www.acmicpc.net/problem/23803
"""

N = int(input())
for _ in range(4 * N):
    print("@" * N)
for _ in range(N):
    print("@" * (5 * N))
