"""
Baekjoon Online Judge #10820
https://www.acmicpc.net/problem/10820
"""

lower = 'abcdefghijklmnopqrstuvwxyz'
upper = lower.upper()
numeric = '0123456789'

while True:
    try:
        S = input()
        out = [0] * 4
        for c in S:
            if c in lower:
                out[0] += 1
            if c in upper:
                out[1] += 1
            if c in numeric:
                out[2] += 1
            if c in [' ', '\t']:
                out[3] += 1
        for o in out:
            print(o, end=' ')
        print()
    except EOFError:
        break
