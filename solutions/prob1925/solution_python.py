"""
Baekjoon Online Judge #1925
https://www.acmicpc.net/problem/1925
"""

from math import isclose, sqrt

x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())
x3, y3 = map(int, input().split())
d1 = sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
d2 = sqrt((x2 - x3) ** 2 + (y2 - y3) ** 2)
d3 = sqrt((x3 - x1) ** 2 + (y3 - y1) ** 2)
sides = [d1, d2, d3]
sides.sort()

if sides[0] + sides[1] == sides[2]:
    print('X')
elif isclose(sides[0], sides[1], rel_tol=1e-5) and \
        isclose(sides[1], sides[2], rel_tol=1e-5):
    print('JungTriangle')
elif isclose(sides[0], sides[1], rel_tol=1e-5):
    if isclose(sides[2] ** 2, sides[0] ** 2 + sides[1] ** 2, rel_tol=1e-5):
        print('Jikkak2Triangle')
    elif sides[2] ** 2 > sides[0] ** 2 + sides[1] ** 2:
        print('Dunkak2Triangle')
    else:
        print('Yeahkak2Triangle')
elif isclose(sides[1], sides[2], rel_tol=1e-5):
    print('Yeahkak2Triangle')
else:
    if isclose(sides[2] ** 2, sides[0] ** 2 + sides[1] ** 2, rel_tol=1e-5):
        print('JikkakTriangle')
    elif sides[2] ** 2 > sides[0] ** 2 + sides[1] ** 2:
        print('DunkakTriangle')
    else:
        print('YeahkakTriangle')
