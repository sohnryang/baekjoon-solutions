"""
Baekjoon Online Judge #2443
https://www.acmicpc.net/problem/2443
"""

in_n = int(input())
for i in range(in_n, 0, -1):
    print(' ' * (in_n - i), end='')
    print('*' * (2 * i - 1))