"""
Baekjoon Online Judge #2096
https://www.acmicpc.net/problem/2096
"""

import sys
from math import inf

infast = lambda: sys.stdin.readline()

N = int(infast())
dp = [[[-inf] * 3, [-inf] * 3], [[-inf] * 3, [-inf] * 3]]

for i in range(N):
    line = [int(x) for x in infast().split()]
    A = [line, [-x for x in line]]
    if i == 0:
        dp[0][0] = A[0]
        dp[1][0] = A[1]
        continue
    for j in range(2):
        dp[j][i % 2][0] = A[j][0] + max(dp[j][(i - 1) % 2][:2])
        dp[j][i % 2][1] = A[j][1] + max(dp[j][(i - 1) % 2])
        dp[j][i % 2][2] = A[j][2] + max(dp[j][(i - 1) % 2][1:])

print(max(dp[0][(N - 1) % 2]), -max(dp[1][(N - 1) % 2]))
