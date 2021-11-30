"""
Baekjoon Online Judge #10773
https://www.acmicpc.net/problem/10773
"""

from sys import stdin

infast = lambda: stdin.readline().strip()
K = int(infast())
arr = []
for _ in range(K):
    x = int(infast())
    if x == 0:
        del arr[-1]
    else:
        arr.append(x)
print(sum(arr))
