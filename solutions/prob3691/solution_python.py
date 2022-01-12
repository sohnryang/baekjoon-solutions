"""
Baekjoon Online Judge #3691
https://www.acmicpc.net/problem/3691
"""

from heapq import heappush, heappop
from sys import stdin

infast = lambda: stdin.readline().strip()

T = int(infast())
for _ in range(T):
    N, B = map(int, infast().split())
    comps = dict()
    for _ in range(N):
        comptype, name, *pair = infast().split()
        P, Q = map(int, pair)
        if comptype not in comps:
            comps[comptype] = []
        heappush(comps[comptype], (P, -Q))

    pq = []
    price = 0
    for k in comps.keys():
        P, Q = heappop(comps[k])
        Q = -Q
        heappush(pq, (Q, -P, k))
        price += P

    while True:
        lowest = pq[0]
        while comps[lowest[2]] and -comps[lowest[2]][0][1] <= lowest[0]:
            heappop(comps[lowest[2]])
        if not comps[lowest[2]]:
            break
        price += lowest[1]
        price += comps[lowest[2]][0][0]
        if price > B:
            break
        heappop(pq)
        P, Q = heappop(comps[lowest[2]])
        Q = -Q
        heappush(pq, (Q, -P, lowest[2]))

    print(pq[0][0])
