"""Baekjoon Online Judge #12852
https://www.acmicpc.net/problem/12852
"""

from math import inf
from sys import stdin

infast = lambda: stdin.readline().strip()

N = int(infast())
dp = [(inf, 0)] * (N + 1)
dp[1] = (0, 1)  # type: ignore
for i in range(1, N + 1):
    nexts = [i * 3, i * 2, i + 1]
    for next_val in nexts:
        if next_val <= N:
            dp[next_val] = min(dp[next_val], (dp[i][0] + 1, i))  # type: ignore
seq_len = dp[-1][0] + 1
print(seq_len - 1)
seq = [N]
here = seq[0]
while len(seq) < seq_len:
    here = dp[here][1]
    seq.append(here)
print(*seq)
