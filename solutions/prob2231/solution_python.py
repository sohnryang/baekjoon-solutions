"""
Baekjoon Online Judge #2231
https://www.acmicpc.net/problem/2231
"""

from sys import exit

def check(gen, n):
    return gen + sum([int(d) for d in str(gen)]) == n

N = int(input())
result = 0
while not check(result, N):
    if result == N:
        print(0)
        exit(0)
    result += 1
print(result)
