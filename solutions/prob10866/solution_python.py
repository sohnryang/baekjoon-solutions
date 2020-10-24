"""
Baekjoon Online Judge #10866
https://www.acmicpc.net/problem/10866
"""

from collections import deque
from sys import stdin
infast = lambda: stdin.readline().strip()

N = int(infast())
dq = deque([])
for _ in range(N):
    cmd, *args = infast().split()
    if cmd == 'push_front':
        dq.appendleft(args[0])
    elif cmd == 'push_back':
        dq.append(args[0])
    elif cmd == 'pop_front':
        if dq:
            print(dq.popleft())
        else:
            print(-1)
    elif cmd == 'pop_back':
        if dq:
            print(dq.pop())
        else:
            print(-1)
    elif cmd == 'size':
        print(len(dq))
    elif cmd == 'empty':
        print(int(not bool(dq)))
    elif cmd == 'front':
        if dq:
            print(dq[0])
        else:
            print(-1)
    else:
        if dq:
            print(dq[-1])
        else:
            print(-1)
