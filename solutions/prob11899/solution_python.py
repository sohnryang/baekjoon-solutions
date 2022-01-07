"""
Baekjoon Online Judge #11899
https://www.acmicpc.net/problem/11899
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

S = infast()
openings = 0
left_needed = 0
for ch in S:
    if ch == "(":
        openings += 1
    else:
        if openings == 0:
            left_needed += 1
            continue
        openings -= 1
print(openings + left_needed)
