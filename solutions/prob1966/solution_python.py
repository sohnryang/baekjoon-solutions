"""
Baekjoon Online Judge #1966
https://www.acmicpc.net/problem/1966
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

T = int(infast())
for _ in range(0, T):
    N, M = map(int, infast().split())
    arr = [(int(x), i) for i, x in enumerate(infast().split())]
    needle = arr[M]
    result = 0
    while arr:
        result += 1
        max_priority = max(arr, key=lambda x: x[0])
        max_priority_idx = arr.index(max_priority)
        arr = arr[max_priority_idx + 1 :] + arr[:max_priority_idx]
        if max_priority == needle:
            print(result)
            break
