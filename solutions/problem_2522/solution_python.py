"""
Baekjoon Online Judge #2522
https://www.acmicpc.net/problem/2522
"""

in_n = int(input())
for i in range(1, in_n + 1):
    print(' ' * (in_n - i), end='')
    print('*' * i)
for i in range(in_n - 1, 0, -1):
    print(' ' * (in_n - i), end='')
    print('*' * i)
