"""
Baekjoon Online Judge #4153
https://www.acmicpc.net/problem/4153
"""

from math import hypot

while True:
    sides = list(map(int, input().split()))
    if all([side == 0 for side in sides]):
        break
    else:
        longest = max(sides)
        sides.remove(longest)
        if longest == hypot(sides[0], sides[1]):
            print('right')
        else:
            print('wrong')
