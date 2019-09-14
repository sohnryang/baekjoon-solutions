"""
Baekjoon Online Judge #2749
https://www.acmicpc.net/problem/2749
"""

MOD = 1000000
period = MOD // 10 * 15
dp = [0] * period
dp[1] = 1
N = int(input())
for i in range(2, period):
    dp[i] = dp[i - 1] + dp[i - 2]
    dp[i] %= MOD
print(dp[N % period])
