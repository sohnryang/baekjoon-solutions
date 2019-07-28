"""
Baekjoon Online Judge #11650
https://www.acmicpc.net/problem/11650
"""

N = int(input())
points = []
for _ in range(N):
    point = tuple(map(int, input().split()))
    points.append(point)
points.sort()
for point in points:
    print(point[0], point[1])
