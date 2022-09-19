"""
Baekjoon Online Judge #11068
https://www.acmicpc.net/problem/11068
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

T = int(infast())
for _ in range(T):
    N = int(infast())
    for b in range(2, 65):
        n = N
        digits = []
        while n > 0:
            digits.append(n % b)
            n //= b
        rev = list(reversed(digits))
        if digits == rev:
            print(1)
            break
    else:
        print(0)
