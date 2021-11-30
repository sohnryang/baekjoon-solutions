"""
Baekjoon Online Judge #7568
https://www.acmicpc.net/problem/7568
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N = int(infast())
arr = []
for i in range(0, N):
    arr.append(tuple([int(x) for x in infast().split()]) + (i,))

for pair in arr:
    rank = 1
    for another in arr:
        if another[0] > pair[0] and another[1] > pair[1]:
            rank += 1
    print(rank, end=" ")
print()
