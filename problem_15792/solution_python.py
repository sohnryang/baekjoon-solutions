"""
Baekjoon Online Judge #15792
https://www.acmicpc.net/problem/15792
"""

import decimal

[in_a, in_b] = map(int, input().split())
decimal.getcontext().prec = 1001
decimal_a = decimal.Decimal(in_a)
decimal_b = decimal.Decimal(in_b)
print(str(decimal_a / decimal_b))
