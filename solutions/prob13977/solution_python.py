"""
Baekjoon Online Judge #13977
https://www.acmicpc.net/problem/13977
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

MOD = 1_000_000_007
MAX_N = 4_000_000

factorials = [1]
for x in range(1, MAX_N + 1):
    factorials.append(x * factorials[-1] % MOD)
last = pow(factorials[-1], -1, MOD)
factorial_invs = {MAX_N: last}
for x in range(MAX_N - 1, -1, -1):
    factorial_invs[x] = last * (x + 1) % MOD
    last = factorial_invs[x]

M = int(infast())
for _ in range(M):
    N, K = map(int, infast().split())
    print(factorials[N] * factorial_invs[K] * factorial_invs[N - K] % MOD)
