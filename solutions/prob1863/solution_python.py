"""
Baekjoon Online Judge #1863
https://www.acmicpc.net/problem/1863
"""

from collections import deque
from sys import stdin

infast = lambda: stdin.readline().strip()

N = int(infast())
stack = deque([0])
count = 0
for _ in range(N):
    X, Y = map(int, infast().split())
    if not stack or stack[-1] < Y:
        stack.append(Y)
        count += 1
    elif stack[-1] == Y:
        continue
    while stack and stack[-1] > Y:
        stack.pop()
    if Y == 0:
        continue
    if not stack or stack[-1] != Y:
        stack.append(Y)
        count += 1

print(count)
