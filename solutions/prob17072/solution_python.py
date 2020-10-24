"""
Baekjoon Online Judge #17072
https://www.acmicpc.net/problem/17072
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

def intensity_to_char(x):
    if 0 <= x < 510_000:
        return '#'
    elif 510_000 <= x < 1_020_000:
        return 'o'
    elif 1_020_000 <= x < 1_530_000:
        return '+'
    elif 1_530_000 <= x < 2_040_000:
        return '-'
    else:
        return '.'

N, M = map(int, infast().split())
for _ in range(N):
    line = list(map(int, infast().split()))
    intensity = map(lambda x, y, z: 2126 * x + 7152 * y + 722 * z,
                    line[::3], line[1::3], line[2::3])
    print(''.join(map(intensity_to_char, intensity)))
