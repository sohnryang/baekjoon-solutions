"""
Baekjoon Online Judge #3015
https://www.acmicpc.net/problem/3015
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N = int(infast())
A = []
for _ in range(N):
    A.append(int(infast()))
stack = []

res = 0
for x in A:
    n = 1
    while stack and stack[-1][0] <= x:
        if stack[-1][0] == x:
            res += stack[-1][1]
            n = stack[-1][1] + 1
            stack.pop()
        else:
            res += stack[-1][1]
            stack.pop()
            n = 1
    if stack:
        res += 1
    stack.append((x, n))
print(res)
