"""
Baekjoon Online Judge #10828
https://www.acmicpc.net/problem/10828
"""
from collections import deque
from sys import stdin

in_n = int(input())
stack = deque()
for _ in range(in_n):
    cmd = stdin.readline().strip()
    if cmd == 'size':
        print(len(stack))
    elif cmd == 'empty':
        print(int(not bool(stack)))
    elif cmd == 'top':
        if stack:
            print(stack[-1])
        else:
            print(-1)
    elif cmd == 'pop':
        if stack:
            print(stack.pop())
        else:
            print(-1)
    else:
        val = int(cmd.split()[1])
        stack.append(val)
