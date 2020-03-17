"""
Baekjoon Online Judge #14681
https://www.acmicpc.net/problem/14681
"""

X = int(input())
Y = int(input())
if X > 0 and Y > 0:
    print(1)
elif X < 0 and Y > 0:
    print(2)
elif X < 0 and Y < 0:
    print(3)
else:
    print(4)
