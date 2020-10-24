"""
Baekjoon Online Judge #1764
https://www.acmicpc.net/problem/1764
"""

from sys import stdin
infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())
unheard = set()
unseen = set()
for _ in range(N):
    unheard.add(infast())
for _ in range(M):
    unseen.add(infast())

print(len(unheard & unseen))
for result in sorted(unheard & unseen):
    print(result)
