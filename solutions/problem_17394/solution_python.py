"""
Baekjoon Online Judge #17394
https://www.acmicpc.net/problem/17394
"""

from collections import deque
from sys import stdin

def in_range(x):
    return 2 <= x <= 1000000

input_fast = lambda: stdin.readline().strip()

PTABLE_SIZE = 1000005
prime_table = [True] * PTABLE_SIZE
prime_table[1] = False
for p in range(1, PTABLE_SIZE):
    if prime_table[p]:
        for q in range(p * 2, PTABLE_SIZE, p):
            prime_table[q] = False

T = int(input_fast())
for _ in range(T):
    N, A, B = map(int, input_fast().split())
    if A <= N <= B and prime_table[N]:
        print(0)
        continue
    dist = [-1] * 1000001
    dist[N] = 0
    q = deque([N])
    result = -1
    while q:
        u = q.popleft()
        V = {u // 2, u // 3, u + 1, u - 1}
        for v in V:
            if in_range(v) and dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
                if A <= v <= B and prime_table[v]:
                    result = dist[v]
                    break
        if result != -1:
            break
    print(result)
