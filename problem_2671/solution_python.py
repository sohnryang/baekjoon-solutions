"""
Baekjoon Online Judge #2671
https://www.acmicpc.net/problem/2671
"""

import re

S = input()
if re.match('^(10(0)+1+|01)+$', S):
    print('SUBMARINE')
else:
    print('NOISE')
