"""
Baekjoon Online Judge #1918
https://www.acmicpc.net/problem/1918
"""

from collections import deque
from sys import stdin
infast = lambda: stdin.readline().strip()

eq = infast()
stack = deque([])
result = ''

for c in eq:
    if c == '(':
        stack.append(c)
    elif c == ')':
        while stack:
            s = stack.pop()
            if s == '(':
                break
            result += s
    elif c in ['*', '/']:
        while stack:
            s = stack.pop()
            if s in ['*', '/']:
                result += s
            else:
                stack.append(s)
                break
        stack.append(c)
    elif c in ['+', '-']:
        while stack:
            s = stack.pop()
            if s != '(':
                result += s
            else:
                stack.append(s)
                break
        stack.append(c)
    else:
        result += c

while stack:
    result += stack.pop()

print(result)
