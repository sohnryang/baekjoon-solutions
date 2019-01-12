"""
Baekjoon Online Judge #10990
https://www.acmicpc.net/problem/10990
"""

in_n = int(input())
for i in range(1, in_n + 1):
    print(' ' * (in_n - i), end='')
    if i != 1:
        print('*', end='')
        print(' ' * (2 * (i - 1) - 1), end='')
        print('*')
    else:
        print('*')
