"""
Baekjoon Online Judge #11054
https://www.acmicpc.net/problem/11054
"""

from sys import stdin
infast = lambda: stdin.readline().strip()

N = int(infast())
A = list(map(int, infast().split()))

lis = [1] * N
for i in range(1, N):
    lis[i] = 1
    for j in range(0, i):
        if A[i] > A[j] and lis[i] < lis[j] + 1:
            lis[i] = lis[j] + 1

lds = [1] * N
for i in range(N - 2, -1, -1):
    for j in range(N - 1, i, -1):
        if A[i] > A[j] and lds[i] < lds[j] + 1:
            lds[i] = lds[j] + 1

result = max([sum(x) - 1 for x in zip(lis, lds)])
print(result)