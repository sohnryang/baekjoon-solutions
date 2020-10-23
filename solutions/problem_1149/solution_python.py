"""
Baekjoon Online Judge #1149
https://www.acmicpc.net/problem/1149
"""

from sys import stdin
infast = lambda: stdin.readline()

N = int(infast())
costs = []
for _ in range(N):
    costs.append(tuple(map(int, infast().split())))

dp = []
for _ in range(N):
    dp.append([None] * 3)
dp[0] = list(costs[0])
for i in range(1, N):
    for j in range(3):
        dp[i][j] = costs[i][j] + min(dp[i - 1][(j + 1) % 3],
                                     dp[i - 1][(j + 2) % 3])
print(min(dp[-1]))
