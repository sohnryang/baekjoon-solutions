"""
Baekjoon Online Judge #2442
https://www.acmicpc.net/problem/2442
"""

in_n = int(input())
for i in range(1, in_n + 1):
    print(' ' * (in_n - i), end='')
    print('*' * (i * 2 - 1))
