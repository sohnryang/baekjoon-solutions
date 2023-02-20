"""
Baekjoon Online Judge #17623
https://www.acmicpc.net/problem/17623
"""

from math import floor, log10
from sys import stdin

infast = lambda: stdin.readline().strip()


def digit_len(x: int) -> int:
    return floor(log10(x)) + 1


dp = [0] * 1001
dp[1] = 12
dp[2] = 34
dp[3] = 56
for x in range(4, 1001):
    for y in range(1, x):
        dmap_curr = dp[y] * 10 ** digit_len(dp[x - y]) + dp[x - y]
        if dp[x] == 0 or dmap_curr < dp[x]:
            dp[x] = dmap_curr
    opening_dmap = {2: 1, 3: 3, 5: 5}
    closing_dmap = {2: 2, 3: 4, 5: 6}
    for t in (2, 3, 5):
        if x % t != 0:
            continue
        y = x // t
        dmap_curr = (
            opening_dmap[t] * 10 ** (digit_len(dp[y]) + 1)
            + dp[y] * 10
            + closing_dmap[t]
        )
        if dmap_curr < dp[x]:
            dp[x] = dmap_curr

T = int(infast())
lookup = {1: "(", 2: ")", 3: "{", 4: "}", 5: "[", 6: "]"}
for _ in range(T):
    N = int(infast())
    print("".join(lookup[int(d)] for d in str(dp[N])))
