"""
Baekjoon Online Judge #5575
https://www.acmicpc.net/problem/5575
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

for _ in range(3):
    H1, M1, S1, H2, M2, S2 = map(int, infast().split())
    epoch = (H2 * 3600 + M2 * 60 + S2) - (H1 * 3600 + M1 * 60 + S1)
    print(epoch // 3600, end=" ")
    epoch %= 3600
    print(epoch // 60, end=" ")
    epoch %= 60
    print(epoch)
