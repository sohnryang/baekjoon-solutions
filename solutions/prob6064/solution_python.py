"""
Baekjoon Online Judge #6064
https://www.acmicpc.net/problem/6064
"""

from math import gcd
from sys import stdin
from typing import Tuple

infast = lambda: stdin.readline().strip()


def xgcd(a: int, b: int) -> Tuple[int, int]:
    r1, r2 = a, b
    s1, s2 = 1, 0
    while r2 != 0:
        q = r1 // r2
        r1, r2 = r2, r1 % r2
        s1, s2 = s2, s1 - q * s2
    if b == 0:
        t = 0
    else:
        t = (r1 - s1 * a) // b
    return (s1, t)


T = int(infast())
for _ in range(T):
    M, N, X, Y = map(int, infast().split())
    G = gcd(M, N)
    if (X - Y) % G != 0:
        print(-1)
        continue
    m = M // G
    n = N // G
    sol = xgcd(n, m)
    coeff = (X - Y) // G
    b_norm = sol[0]
    a_norm = -sol[1]
    if a_norm < 0:
        c = -(a_norm // n)
        a_norm += c * n
        b_norm += c * m
    if b_norm < 0:
        c = -(b_norm // m)
        a_norm += c * n
        b_norm += c * m
    a = a_norm * coeff
    b = b_norm * coeff
    period = m * n * G
    k = (X + a * M) % period
    if k == 0:
        k += period
    print(k)
