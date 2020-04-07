"""
Baekjoon Online Judge #1699
https://www.acmicpc.net/problem/1699
"""

from math import sqrt, inf

MAX_N = 100001
dp = [inf] * MAX_N
for i in range(1, MAX_N):
    if int(sqrt(i)) ** 2 == i:
        dp[i] = 1
    delta = 1
    while i + delta ** 2 < MAX_N:
        dp[i + delta ** 2] = min(dp[i] + 1, dp[i + delta ** 2])
        delta += 1
N = int(input())
print(dp[N])
