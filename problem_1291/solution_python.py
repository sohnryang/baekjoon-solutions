"""
Baekjoon Online Judge #1291
https://www.acmicpc.net/problem/1291
"""

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

in_n = int(input())
result1 = (in_n == 4 or in_n >= 6) and \
          sum([int(d) for d in str(in_n)]) % 2 == 1
result2 = in_n == 2 or in_n == 4 or \
          len(set(prime_factors(in_n))) > 1 and \
          len(set(prime_factors(in_n))) % 2 == 0
if result1 and result2:
    print(4)
elif (not result1) and (not result2):
    print(3)
elif result1:
    print(1)
else:
    print(2)
