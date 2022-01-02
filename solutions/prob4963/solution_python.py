"""
Baekjoon Online Judge #4963
https://www.acmicpc.net/problem/4963
"""

from sys import stdin

infast = lambda: stdin.readline().strip()
dys = [-1, -1, -1, 0, 0, 1, 1, 1]
dxs = [-1, 0, 1, -1, 1, -1, 0, 1]

while True:
    W, H = map(int, infast().split())
    if W == 0 and H == 0:
        break
    grid = []
    for _ in range(H):
        line = [int(x) for x in infast().split()]
        grid.append(line)
    flooded = []
    for _ in range(H):
        flooded.append([-1] * W)
    c = 0

    def in_range(y, x):
        return 0 <= y < H and 0 <= x < W

    for y in range(H):
        for x in range(W):
            found = False
            stack = [(y, x)]
            while stack:
                cy, cx = stack.pop()
                if not in_range(cy, cx) or grid[cy][cx] == 0 or flooded[cy][cx] != -1:
                    continue
                flooded[cy][cx] = c
                found = True
                nexts = [(cy + dy, cx + dx) for dy, dx in zip(dys, dxs)]
                stack.extend(nexts)
            if found:
                c += 1
    print(c)
