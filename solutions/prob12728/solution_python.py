"""
Baekjoon Online Judge #12728
https://www.acmicpc.net/problem/12728
"""

from sys import stdin
from typing import Tuple

MatTwoByTwo = Tuple[Tuple[int, int], Tuple[int, int]]
MOD = 1000
M = ((3, 5), (1, 3))


def matmul(a: MatTwoByTwo, b: MatTwoByTwo) -> MatTwoByTwo:
    return (
        (
            (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD,
            (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD,
        ),
        (
            (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD,
            (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD,
        ),
    )


def matpow(a: MatTwoByTwo, n: int) -> MatTwoByTwo:
    res = ((1, 0), (0, 1))
    for shift in range(64, -1, -1):
        res = matmul(res, res)
        b = (n >> shift) & 1
        if b:
            res = matmul(res, a)
    return res


infast = lambda: stdin.readline().strip()

T = int(infast())
for t in range(1, T + 1):
    N = int(infast())
    mat = matpow(M, N - 1)
    print(f"Case #{t}: {(2 * (3 * mat[0][0] + mat[0][1]) + 999) % MOD:03d}")
