"""Baekjoon Online Judge #23805
https://www.acmicpc.net/problem/23805
"""

N = int(input())
for _ in range(N):
    print("@@@" * N, end="")
    print(" " * N, end="")
    print("@" * N)
for _ in range(N * 3):
    for _ in range(2):
        print("@" * N, end="")
        print(" " * N, end="")
    print("@" * N)
for _ in range(N):
    print("@" * N, end="")
    print(" " * N, end="")
    print("@@@" * N)
