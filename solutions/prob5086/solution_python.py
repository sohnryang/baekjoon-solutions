"""
Baekjoon Online Judge #5086
https://www.acmicpc.net/problem/5086
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

while True:
    A, B = map(int, infast().split())
    if A == 0:
        break
    if A % B == 0:
        print("multiple")
    elif B % A == 0:
        print("factor")
    else:
        print("neither")
