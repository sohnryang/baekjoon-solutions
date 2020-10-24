"""
Baekjoon Online Judge #15829
https://www.acmicpc.net/problem/15829
"""

L = int(input())
S = input()
MOD = 1234567891
result = 0
for (i, c) in enumerate(S):
    result += ((31 ** i) * (ord(c) - ord('a') + 1)) % MOD
print(result % MOD)
