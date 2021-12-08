"""Baekjoon Online Judge #16430
https://www.acmicpc.net/problem/16430
"""

from math import gcd

A, B = map(int, input().split())
C = B - A
g = gcd(C, B)
print(C // g, B // g)
