"""
Baekjoon Online Judge #10992
https://www.acmicpc.net/problem/10992
"""

in_n = int(input())
print(' ' * (in_n - 1), end='')
print('*')
for i in range(1, in_n - 1):
    print(' ' * (in_n - i - 1), end='')
    print('*', end='')
    print(' ' * (2 * i - 1), end='')
    print('*')
if in_n > 1:
    print('*' * (2 * in_n - 1))
