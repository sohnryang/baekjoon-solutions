"""Baekjoon Online Judge #5430
https://www.acmicpc.net/problem/5430
"""

from collections import deque
from sys import stdin

infast = lambda: stdin.readline().strip()
T = int(infast())
for _ in range(T):
    P = infast()
    _ = infast()
    dq_str = infast()
    if dq_str == "[]":
        dq = deque()
    else:
        dq = deque([int(x) for x in dq_str[1:-1].split(",")])
    rev = False
    for ch in P:
        if ch == "R":
            rev = not rev
        else:
            if not dq:
                print("error")
                break
            if rev:
                dq.pop()
            else:
                dq.popleft()
    else:
        if rev:
            print(f"[{','.join([str(x) for x in reversed(dq)])}]")
        else:
            print(f"[{','.join([str(x) for x in dq])}]")
