"""
Baekjoon Online Judge #12865
https://www.acmicpc.net/problem/12865
"""

from sys import stdin

INF = 2**32

def knapsack():
    dp = []
    for _ in range(N + 1):
        dp.append([0] * (K + 1))
    for w in range(1, K + 1):
        for i in range(N - 1, -1, -1):
            if w >= W[i]:
                dp[i][w] = max(V[i] + dp[i + 1][w - W[i]], dp[i + 1][w])
            else:
                dp[i][w] = dp[i + 1][w]
    return dp[0][K]

infast = lambda: stdin.readline().strip()
N, K = map(int, infast().split())
W = []
V = []
cache = []
for _ in range(N):
    w, v = map(int, infast().split())
    W.append(w)
    V.append(v)
for _ in range(N):
    cache.append([None] * (K + 1))
print(knapsack())
