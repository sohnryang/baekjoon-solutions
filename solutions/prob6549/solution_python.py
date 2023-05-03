"""
Baekjoon Online Judge #6549
https://www.acmicpc.net/problem/6549
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

while True:
    N, *S = list(map(int, infast().split()))
    if N == 0:
        break
    S.append(0)
    stack: list[int] = []
    res = 0
    for i, y in enumerate(S):
        while stack and S[stack[-1]] > S[i]:
            highest = stack.pop()
            if stack:
                lo = stack[-1]
            else:
                lo = -1
            res = max(res, (i - lo - 1) * S[highest])
        stack.append(i)
    print(res)
