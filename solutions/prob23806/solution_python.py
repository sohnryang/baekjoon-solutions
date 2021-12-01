"""
Baekjoon Online Judge #23806
https://www.acmicpc.net/problem/23806
"""

N = int(input())
for _ in range(N):
    print("@" * (5 * N))
for _ in range(3 * N):
    print("@" * N, end="")
    print(" " * (3 * N), end="")
    print("@" * N)
for _ in range(N):
    print("@" * (5 * N))
