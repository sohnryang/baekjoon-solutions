"""
Baekjoon Online Judge #6591
https://www.acmicpc.net/problem/6591
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

while True:
    N, K = map(int, infast().split())
    if N == K == 0:
        break
    K = min(N - K, K)
    result = 1
    for x in range(N - K + 1, N + 1):
        result *= x
    for x in range(1, K + 1):
        result //= x
    print(result)
