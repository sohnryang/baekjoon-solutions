"""
Baekjoon Online Judge #2798
https://www.acmicpc.net/problem/2798
"""

from sys import stdin
infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())
cards = list(map(int, infast().split()))
result = 0

for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            current = cards[i] + cards[j] + cards[k]
            if current > M:
                continue
            if M - current < M - result:
                result = current

print(result)
