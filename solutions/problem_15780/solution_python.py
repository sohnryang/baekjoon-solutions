"""
Baekjoon Online Judge #15780
https://www.acmicpc.net/problem/15780
"""

import math

[in_n, in_k] = map(int, input().split())
in_a = list(map(int, input().split()))
max_plugs = 0
for plugs in in_a:
    max_plugs += math.ceil(plugs / 2)
print('YES' if max_plugs >= in_n else 'NO')
