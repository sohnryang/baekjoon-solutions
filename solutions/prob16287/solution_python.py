"""Baekjoon Online Judge #16287
https://www.acmicpc.net/problem/16287
"""

from sys import stdin

infast = lambda: stdin.readline().strip()
W, N = map(int, infast().split())
arr = [int(x) for x in infast().split()]
weights = set()

for i in range(N):
    for j in range(i + 1, N):
        if arr[i] + arr[j] > W:
            continue
        if W - (arr[i] + arr[j]) in weights:
            print("YES")
            exit(0)
    for j in range(i):
        if arr[i] + arr[j] < W:
            weights.add(arr[i] + arr[j])

print("NO")
