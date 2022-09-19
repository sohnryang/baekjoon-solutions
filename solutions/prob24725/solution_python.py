"""
Baekjoon Online Judge #24725
https://www.acmicpc.net/problem/24725
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())
board = []
for _ in range(N):
    board.append(infast())


def check(s):
    for c, l in zip(s, ["EI", "NS", "FT", "PJ"]):
        if c not in l:
            return False
    return True


res = 0
for y in range(N):
    for x in range(M - 3):
        word = board[y][x : x + 4]
        if check(word) or check(word[::-1]):
            res += 1
for y in range(N - 3):
    for x in range(M):
        word = "".join([board[y + i][x] for i in range(4)])
        if check(word) or check(word[::-1]):
            res += 1
for y in range(N - 3):
    for x in range(M - 3):
        word = "".join([board[y + i][x + i] for i in range(4)])
        if check(word) or check(word[::-1]):
            res += 1
        word = "".join([board[y + 3 - i][x + i] for i in range(4)])
        if check(word) or check(word[::-1]):
            res += 1
print(res)
