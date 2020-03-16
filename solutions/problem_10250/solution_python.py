"""
Baekjoon Online Judge #10250
https://www.acmicpc.net/problem/10250
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

T = int(infast())
for _ in range(T):
    H, W, N = map(int, infast().split())
    if H == 1:
        room = N
        floor = 1
    else:
        if N % H == 0:
            room = N // H
        else:
            room = N // H + 1
        floor = N % H
        if floor == 0:
            floor = H
    print('%d%02d' % (floor, room))
