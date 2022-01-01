"""
Baekjoon Online Judge #1111
https://www.acmicpc.net/problem/1111
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

N = int(infast())
A = [int(x) for x in infast().split()]

if N == 1:
    print("A")
elif A[0] == A[1]:
    if len(set(A)) == 1:
        print(A[0])
    else:
        print("B")
elif N == 2:
    print("A")
else:
    det1 = A[0] - A[1]
    det2 = A[1] - A[2]
    det3 = A[0] * A[2] - A[1] ** 2
    if det2 % det1 != 0 or det3 % det1 != 0:
        print("B")
    else:
        a = det2 // det1
        b = det3 // det1
        for x, y in zip(A[:-1], A[1:]):
            if a * x + b != y:
                print("B")
                break
        else:
            print(a * A[-1] + b)
