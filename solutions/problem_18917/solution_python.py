"""
Baekjoon Online Judge #18917
https://www.acmicpc.net/problem/18917
"""

from sys import stdin

infast = lambda: stdin.readline().strip()
M = int(infast())
sum1 = 0
sum2 = 0
for _ in range(M):
    cmd, *args = map(int, infast().split())
    if cmd == 1:
        X = args[0]
        sum1 += X
        sum2 ^= X
    elif cmd == 2:
        X = args[0]
        sum1 -= X
        sum2 ^= X
    elif cmd == 3:
        print(sum1)
    else:
        print(sum2)
