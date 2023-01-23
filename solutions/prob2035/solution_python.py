"""
Baekjoon Online Judge #2035
https://www.acmicpc.net/problem/2035
"""

from collections import deque
from math import log10
from sys import stdin

infast = lambda: stdin.readline().strip()

N = infast()
q = deque([(0, 0)])
res = None
while q:
    idx, last_max = q.pop()
    if idx == len(N):
        if res == None:
            res = last_max
        else:
            res = min(res, last_max)
    if last_max == 0:
        digits = 1
    else:
        digits = int(log10(last_max)) + 1
    digits_left = len(N) - idx
    if digits_left < digits:
        continue
    for d in range(digits, digits_left + 1):
        num = int(N[idx : idx + d])
        if num <= last_max:
            continue
        q.append((idx + d, num))  # type: ignore
print(res)
