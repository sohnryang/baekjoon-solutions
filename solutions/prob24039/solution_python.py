"""
Baekjoon Online Judge #24039
https://www.acmicpc.net/problem/24039
"""

from sys import stdin

infast = lambda: stdin.readline().strip()
primes = [
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97,
    101,
    103,
]
N = int(infast())
for x, y in zip(primes[:-1], primes[1:]):
    if x * y > N:
        print(x * y)
        break
