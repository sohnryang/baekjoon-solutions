"""
Baekjoon Online Judge #2493
https://www.acmicpc.net/problem/2493
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N = int(infast())
A = [int(x) for x in infast().split()]
stack = []
for i, x in enumerate(A, 1):
    while stack and stack[-1][0] < x:
        stack.pop()
    if not stack:
        print(0, end=" ")
    else:
        print(stack[-1][1], end=" ")
        if stack[-1][0] == x:
            stack.pop()
    stack.append((x, i))
