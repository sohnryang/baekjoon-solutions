"""
Baekjoon Online Judge #5615
https://www.acmicpc.net/problem/5615
"""
from random import randrange

small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]

def miller_rabin(n, k):
    if n < 2:
        return False
    for p in small_primes:
        if n < p * p:
            return True
        if n % p == 0:
            return False
    r, s = 0, n - 1
    while s % 2 == 0:
        r += 1
        s //= 2
    for _ in range(k):
        a = randrange(2, n - 1)
        x = pow(a, s, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True


N = int(input())
result = 0
for _ in range(N):
    n = int(input())
    if miller_rabin(2 * n + 1, 10):
        result += 1
print(result)
