"""
Baekjoon Online Judge #1330
https://www.acmicpc.net/problem/1330
"""

A, B = map(int, input().split())
if A < B:
    print('<')
elif A == B:
    print('==')
else:
    print('>')
