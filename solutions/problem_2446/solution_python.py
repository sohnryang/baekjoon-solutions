"""
Baekjoon Online Judge #2446
https://www.acmicpc.net/problem/2446
"""

in_n = int(input())
for i in range(in_n):
    print(' ' * i, end='')
    print('*' * ((in_n - i) * 2 - 1), end='')
    print()
for i in range(1, in_n):
    print(' ' * (in_n - i - 1), end='')
    print('*' * (i * 2 + 1), end='')
    print()