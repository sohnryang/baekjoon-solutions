"""
Baekjoon Online Judge #24268
https://www.acmicpc.net/problem/24268
"""

from sys import stdin
import itertools

infast = lambda: stdin.readline().strip()

N, D = map(int, infast().split())
base_d = []
n = N
while n:
    base_d.append(n % D)
    n //= D
base_d = base_d[::-1]
if len(base_d) < D:
    res = "10"
    for x in range(2, D):
        res += str(x)
    print(int(res, D))
elif len(base_d) > D:
    print(-1)
else:
    for digits in itertools.permutations(range(D), D):
        if digits[0] == 0:
            continue
        n = 0
        for d in digits:
            n *= D
            n += d
        if n > N:
            print(int("".join([str(d) for d in digits]), D))
            break
    else:
        print(-1)
