"""
Baekjoon Online Judge #2445
https://www.acmicpc.net/problem/2445
"""

in_n = int(input())
for i in range(1, in_n + 1):
    print('*' * i, end='')
    print(' ' * (in_n * 2 - i * 2), end='')
    print('*' * i)
for i in range(in_n - 1, 0, -1):
    print('*' * i, end='')
    print(' ' * (in_n * 2 - i * 2), end='')
    print('*' * i)
