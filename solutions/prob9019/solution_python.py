"""
Baekjoon Online Judge #9019
https://www.acmicpc.net/problem/9019
"""

import sys
from collections import deque

infast = lambda: sys.stdin.readline().strip()

N = int(infast())
for _ in range(N):
    A, B = [int(x) for x in infast().split()]
    q = deque([A])
    visited = set()
    gen = dict()
    gen[A] = ""
    while q:
        x = q.popleft()
        if x == B:
            break
        s = gen[x]
        theres = [
            ((x * 2) % 10000, s + "D"),
            ((x - 1) % 10000, s + "S"),
            (x * 10 % 10000 + x // 1000, s + "L"),
            (x // 10 + x % 10 * 1000, s + "R"),
        ]
        for there in theres:
            if there[0] not in gen or len(there[1]) < len(gen[there[0]]):
                gen[there[0]] = there[1]
                q.append(there[0])
    print(gen[B])
