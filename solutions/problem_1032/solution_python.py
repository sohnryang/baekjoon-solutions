"""
Baekjoon Online Judge #1032
https://www.acmicpc.net/problem/1032
"""

N = int(input())
strs = []
for _ in range(N):
    strs.append(input())
for cs in zip(*strs):
    if all(c == cs[0] for c in cs):
        print(cs[0], end='')
    else:
        print('?', end='')
print()
