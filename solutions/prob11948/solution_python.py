"""
Baekjoon Online Judge #11948
https://www.acmicpc.net/problem/11948
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

A = []
for _ in range(4):
    A.append(int(infast()))
B = []
for _ in range(2):
    B.append(int(infast()))

print(sum(A) - min(A) + sum(B) - min(B))
