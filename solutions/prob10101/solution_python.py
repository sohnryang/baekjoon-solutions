"""
Baekjoon Online Judge #10101
https://www.acmicpc.net/problem/10101
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

A = []
for _ in range(3):
    A.append(int(infast()))
if sum(A) != 180:
    print("Error")
elif all([x == 60 for x in A]):
    print("Equilateral")
elif len(set(A)) == 2:
    print("Isosceles")
else:
    print("Scalene")
