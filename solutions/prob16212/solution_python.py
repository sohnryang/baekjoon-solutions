"""Baekjoon Online Judge #16212
https://www.acmicpc.net/problem/16212
"""

from sys import stdin

infast = lambda: stdin.readline().strip()
_ = infast()
arr = [int(x) for x in infast().split()]
arr.sort()
print(*arr)
