"""
Baekjoon Online Judge #1931
https://www.acmicpc.net/problem/1931
"""

from operator import itemgetter
from sys import stdin
infast = lambda: stdin.readline().strip()

N = int(infast())
meetings = []
for _ in range(N):
    meetings.append(tuple(map(int, infast().split())))

meetings.sort(key=itemgetter(1, 0))
last = 0
result = 0
for meeting in meetings:
    if last <= meeting[0]:
        result += 1
        last = meeting[1]
print(result)
