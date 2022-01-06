"""
Baekjoon Online Judge #2642
https://www.acmicpc.net/problem/2642
"""

from sys import stdin

infast = lambda: stdin.readline().strip()

grid = []
start = (0, 0)
for y in range(6):
    line = [int(x) for x in infast().split()]
    grid.append(line)
    if 1 in line:
        start = (y, line.index(1))

faces = tuple(range(6))
stack = [(start, faces)]
cover = dict()


def avail(y, x):
    return 0 <= y < 6 and 0 <= x < 6 and grid[y][x] != 0


dys = [-1, 0, 0, 1]
dxs = [0, -1, 1, 0]
rot_idx = [
    (5, 4, 2, 3, 0, 1),
    (3, 2, 0, 1, 4, 5),
    (2, 3, 1, 0, 4, 5),
    (4, 5, 2, 3, 1, 0),
]
rot = lambda x, i: tuple([x[j] for j in rot_idx[i]])
fail = False

while stack:
    p, f = stack.pop()
    cover[f[0]] = p
    y, x = p
    for i, (dy, dx) in enumerate(zip(dys, dxs)):
        np = (y + dy, x + dx)
        nf = rot(f, i)
        if avail(*np) and nf[0] not in cover:
            stack.append((np, nf))

if len(cover) != 6:
    print(0)
else:
    y, x = cover[1]
    print(grid[y][x])
