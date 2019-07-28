"""
Baekjoon Online Judge #10991
https://www.acmicpc.net/problem/10991
"""

in_n = int(input())
for i in range(1, in_n + 1):
    print(' ' * (in_n - i), end='')
    for j in range(i):
        if j != 0:
            print(' ', end='')
        print('*', end='')
    print()
