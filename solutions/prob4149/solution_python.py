"""
Baekjoon Online Judge #4149
https://www.acmicpc.net/problem/4149
"""
from collections import deque
from math import gcd
from random import choice, randrange

small_primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]

def poly1(x, n):
    return (x ** 2 + 1) % n

def poly2(x, n):
    return (x ** 2 - 1) % n

def pollard_rho(n):
    if n > 2 and n % 2 == 0:
        return 2
    while True:
        d = 1
        x = randrange(1, n + 1)
        y = x
        poly = choice([poly1, poly2])
        while d == 1:
            x = poly(x, n)
            y = poly(poly(y, n), n)
            d = gcd(abs(x - y), n)
        if x != y:
            break
    return d

def miller_rabin(n, k):
    if n < 2:
        return False
    for p in small_primes:
        if n < p * p:
            return True
        if n % p == 0:
            return False
    r, d = 0, n - 1
    while r % 2 == 0:
        r += 1
        d //= 2
    for _ in range(k):
        a = randrange(2, n - 1)
        x = pow(a, d, n)
        if x == 1 or x == n - 1:
            continue
        for _ in range(r - 1):
            x = pow(x, 2, n)
            if x == n - 1:
                break
        else:
            return False
    return True

def factorize(n):
    composites = deque([n])
    factors = []
    while composites:
        composite = composites.popleft()
        if composite == 1:
            continue
        elif miller_rabin(composite, 10):
            factors.append(composite)
        else:
            f = pollard_rho(composite)
            composites.append(f)
            composites.append(composite // f)
    factors.sort()
    return factors

N = int(input())
factors = factorize(N)
for factor in factors:
    print(factor)
