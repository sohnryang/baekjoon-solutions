"""
Baekjoon Online Judge #5988
https://www.acmicpc.net/problem/5988
"""

in_n = int(input())
for _ in range(in_n):
    last_num = int(input()[-1])
    print('even' if last_num % 2 == 0 else 'odd')
