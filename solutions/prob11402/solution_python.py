"""
Baekjoon Online Judge #11402
https://www.acmicpc.net/problem/11402
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N, K, M = map(int, infast().split())
N_expansion = []
K_expansion = []

while N > 0 or K > 0:
    N_expansion.append(N % M)
    N //= M
    K_expansion.append(K % M)
    K //= M

dp = []
for _ in range(M):
    dp.append([1] + [0] * (M - 1))
for i in range(1, M):
    for j in range(1, M):
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % M

res = 1
for n, k in zip(N_expansion, K_expansion):
    res *= dp[n][k]
    res %= M
print(res)
