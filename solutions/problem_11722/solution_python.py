"""
Baekjoon Online Judge #11722
https://www.acmicpc.net/problem/11722
"""

from sys import stdin
infast = lambda: stdin.readline().strip()

N = int(infast())
A = list(map(int, infast().split()))

dp = [0] * N
dp[0] = 1
for i in range(1, N):
    dp[i] = 1
    for j in range(0, i):
        if A[i] < A[j] and dp[i] < dp[j] + 1:
            dp[i] = dp[j] + 1

print(max(dp))