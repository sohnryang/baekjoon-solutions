"""
Baekjoon Online Judge #2164
https://www.acmicpc.net/problem/2164
"""

from collections import deque

N = int(input())
dq = deque(range(1, N + 1))

while len(dq) > 1:
    dq.popleft()
    t = dq.popleft()
    dq.append(t)

print(dq.pop())
