"""
Baekjoon Online Judge #11401
https://www.acmicpc.net/problem/11401
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

MOD = 1_000_000_007


def mod_fac(n):
    result = 1
    for x in range(n):
        result = result * (x + 1) % MOD
    return result


N, K = map(int, infast().split())
fac_N = mod_fac(N)
fac_K = mod_fac(K)
fac_N_min_K = mod_fac(N - K)
print(fac_N * pow(fac_K * fac_N_min_K % MOD, -1, MOD) % MOD)
