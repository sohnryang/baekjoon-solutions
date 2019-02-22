"""
Baekjoon Online Judge #2523
https://www.acmicpc.net/problem/2523
"""

in_n = int(input())
for i in range(1, in_n + 1):
    print('*' * i)
for i in range(in_n - 1, 0, -1):
    print('*' * i)
