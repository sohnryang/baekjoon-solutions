"""
Baekjoon Online Judge #2292
https://www.acmicpc.net/problem/2292
"""

N = int(input())
dist = 2
if N == 1:
    print(1)
    exit(0)

idx = 2
delta = 6
while idx <= N:
    idx += delta
    delta += 6
    dist += 1
print(dist - 1)
