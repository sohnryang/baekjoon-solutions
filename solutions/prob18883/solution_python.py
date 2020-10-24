"""
Baekjoon Online Judge #18883
https://www.acmicpc.net/problem/18883
"""

N, M = map(int, input().split())
for i in range(N * M):
    ending = ' ' if i % M != M - 1 else '\n'
    print(i + 1, end=ending)
