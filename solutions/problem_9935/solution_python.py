"""
Baekjoon Online Judge #9935
https://www.acmicpc.net/problem/9935
"""

from sys import stdin
from collections import deque
infast = lambda: stdin.readline().strip()

haystack = infast()
needle = infast()
stack = deque()
last = deque()
for c in haystack:
    stack.append(c)
    last.append(c)
    if len(last) > len(needle):
        last.popleft()
    if ''.join(last) == needle:
        last.clear()
        for _ in range(len(needle)):
            stack.pop()
        while len(last) < len(needle) and stack:
            last.insert(0, stack.pop())
        for c in last:
            stack.append(c)

if stack:
    print(''.join(stack))
else:
    print('FRULA')
