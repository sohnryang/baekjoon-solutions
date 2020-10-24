"""
Baekjoon Online Judge #2565
https://www.acmicpc.net/problem/2565
"""

from sys import stdin
infast = lambda: stdin.readline().strip()

N = int(infast())
A = []
for _ in range(N):
    A.append(tuple(map(int, infast().split())))
A.sort()
wires = [x[1] for x in A]

dp = [1] * N
for i in range(1, N):
    for j in range(0, i):
        if wires[i] > wires[j] and dp[i] < dp[j] + 1:
            dp[i] = dp[j] + 1

print(N - max(dp))
