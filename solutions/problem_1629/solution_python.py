"""
Baekjoon Online Judge #1629
https://www.acmicpc.net/problem/1629
"""

def mod_pow(A, B, C):
    if B == 0:
        return 1
    elif B % 2 != 0:
        return A * (mod_pow(A, B // 2, C)) ** 2 % C
    return (mod_pow(A, B // 2, C)) ** 2 % C

A, B, C = map(int, input().split())
print(mod_pow(A, B, C))
