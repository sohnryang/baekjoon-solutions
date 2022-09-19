"""
Baekjoon Online Judge #25556
https://www.acmicpc.net/problem/25556
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N = int(infast())
A = list(map(int, infast().split()))
stacks = []
for _ in range(4):
    stacks.append([])

for x in A:
    for i in range(4):
        if not stacks[i] or stacks[i][-1] < x:
            stacks[i].append(x)
            break
    else:
        print("NO")
        exit(0)
print("YES")
