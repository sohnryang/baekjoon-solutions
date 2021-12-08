"""Baekjoon Online Judge #1271
https://www.acmicpc.net/problem/1271
"""

from sys import stdin

infast = lambda: stdin.readline().strip()
N, M = map(int, infast().split())
print(N // M)
print(N % M)
