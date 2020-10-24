"""
Baekjoon Online Judge #13163
https://www.acmicpc.net/problem/13163
"""

N = int(input())
for _ in range(N):
    name = input().split()
    name[0] = 'god'
    print(''.join(name))
