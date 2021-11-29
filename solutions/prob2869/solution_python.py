"""
Baekjoon Online Judge #2869
https://www.acmicpc.net/problem/2869
"""
from math import ceil

A, B, V = map(int, input().split())
if A >= V:
    print(1)
    exit(0)
print(1 + ceil((V - A) / (A - B)))
