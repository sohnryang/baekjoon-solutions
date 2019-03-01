"""
Baekjoon Online Judge #15482
https://www.acmicpc.net/problem/15482
"""
 
in_a = input()
in_b = input()
dp = [[None] * (len(in_b) + 1) for i in range(len(in_a) + 1)]
 
for n in range(len(in_a) + 1):
    for m in range(len(in_b) + 1):
        if n == 0 or m == 0:
            dp[n][m] = 0
        elif in_a[n - 1] == in_b[m - 1]:
            dp[n][m] = dp[n - 1][m - 1] + 1
        else:
            dp[n][m] = max(dp[n][m - 1], dp[n - 1][m])
print(dp[len(in_a)][len(in_b)])
