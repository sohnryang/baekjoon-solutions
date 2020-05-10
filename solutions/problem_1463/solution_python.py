"""
Baekjoon Online Judge #1463
https://www.acmicpc.net/problem/1463
"""

from math import inf
MAX_N = int(1e6)
N = int(input())
dp = [inf] * (MAX_N * 3 + 1)
dp[1] = 0
for i in range(1, N + 1):
    dp[i + 1] = min(dp[i + 1], dp[i] + 1)
    dp[i * 2] = min(dp[i * 2], dp[i] + 1)
    dp[i * 3] = min(dp[i * 3], dp[i] + 1)
print(dp[N])
