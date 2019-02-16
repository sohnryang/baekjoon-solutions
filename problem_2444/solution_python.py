"""
Baekjoon Online Judge #2444
https://www.acmicpc.net/problem/2444
"""

in_n = int(input())
for i in range(1, in_n + 1):
    print(' ' * (in_n - i), end='')
    print('*' * (2 * i - 1))
for i in range(in_n - 1, 0, -1):
    print(' ' * (in_n - i), end='')
    print('*' * (2 * i - 1))
