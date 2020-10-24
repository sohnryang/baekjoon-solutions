"""
Baekjoon Online Judge #16975
https://www.acmicpc.net/problem/16975
"""

from sys import stdin

class FenwickTree:
    def __init__(self, n):
        self.tree = [0] * (n + 1)

    def range_sum(self, pos):
        pos += 1
        ret = 0
        while pos > 0:
            ret += self.tree[pos]
            pos &= (pos - 1)
        return ret

    def update(self, pos, val):
        pos += 1
        while pos < len(self.tree):
            self.tree[pos] += val
            pos += (pos & -pos)

infast = lambda: stdin.readline().strip()
N = int(infast())
A = list(map(int, infast().split()))
B = [A[0]]
ft = FenwickTree(N)
ft.update(0, B[0])
for i in range(1, N):
    B.append(A[i] - A[i - 1])
    ft.update(i, B[i])

M = int(infast())
for _ in range(M):
    Q, *args = map(int, infast().split())
    if Q == 1:
        i, j, k = args
        i -= 1
        j -= 1
        ft.update(i, k)
        if j != N - 1:
            ft.update(j + 1, -k)
    else:
        x = args[0] - 1
        print(ft.range_sum(x))
