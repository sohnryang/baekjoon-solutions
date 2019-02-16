"""
Baekjoon Online Judge #1793
https://www.acmicpc.net/problem/1793
"""

while True:
    try:
        in_n = int(input())
        dp = [0] * 251
        dp[0] = 1
        dp[1] = 1
        dp[2] = 3
        for n in range(3, in_n + 1):
            dp[n] = dp[n - 1] + dp[n - 2] * 2
        print(dp[in_n])
    except EOFError:
        break
