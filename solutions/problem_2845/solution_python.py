"""
Baekjoon Online Judge #2845
https://www.acmicpc.net/problem/2845
"""

L, P = map(int, input().split())
l = list(map(int, input().split()))
for n in l:
    print(n - L * P, end=' ')
