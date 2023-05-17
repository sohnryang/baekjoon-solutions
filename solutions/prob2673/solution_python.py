"""
Baekjoon Online Judge #2673
https://www.acmicpc.net/problem/2673
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N = int(infast())
A: list[tuple[int, int]] = list()
for _ in range(N):
    A.append(tuple(sorted(int(x) for x in infast().split())))
dp: list[list[int]] = []
for _ in range(101):
    dp.append([0] * 101)


def contained_intervals(start: int, end: int):
    for interval in A:
        int_start, int_end = interval
        if start <= int_start and int_end <= end:
            yield interval


for l in range(1, 101):
    for start in range(100, 0, -1):
        end = min(start + l, 100)
        for interval in contained_intervals(start, end):
            int_start, int_end = interval
            dp[start][end] = max(
                dp[start][end],
                1
                + dp[int_start + 1][int_end - 1]
                + (dp[int_end + 1][end] if int_end + 1 <= end else 0),
            )
print(dp[1][100])
