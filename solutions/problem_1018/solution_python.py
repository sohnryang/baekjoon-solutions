"""
Baekjoon Online Judge #1018
https://www.acmicpc.net/problem/1018
"""

from sys import stdin
from math import inf
infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())
board = []

for _ in range(N):
    board.append([x == 'W' for x in infast()])

def fill(y, x, m):
    result = 0
    for i in range(0, 8):
        for j in range(0, 8):
            if ((i + j) % 2 == m) != board[y + i][x + j]:
                result += 1
    return result

result = inf
for y in range(N - 7):
    for x in range(M - 7):
        current = min(fill(y, x, 0), fill(y, x, 1))
        result = min(result, current)

print(result)
