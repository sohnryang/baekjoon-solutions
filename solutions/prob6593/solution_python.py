"""
Baekjoon Online Judge #6593
https://www.acmicpc.net/problem/6593
"""

from collections import deque
from sys import stdin
from typing import Tuple

infast = lambda: stdin.readline().strip()

DELTA = [(0, 0, -1), (0, 0, 1), (0, -1, 0), (0, 1, 0), (-1, 0, 0), (1, 0, 0)]

while True:
    L, R, C = map(int, infast().split())
    if L == 0 and R == 0 and C == 0:
        break
    room = []
    start_pos: Tuple[int, int, int]
    finish_pos: Tuple[int, int, int]
    for z in range(L):
        level = []
        for y in range(R):
            line = infast()
            level.append(line)
            if "S" in line:
                start_pos = (z, y, line.index("S"))
            if "E" in line:
                finish_pos = (z, y, line.index("E"))
        room.append(level)
        infast()

    def available(pos: Tuple[int, int, int]) -> bool:
        z, y, x = pos
        return 0 <= z < L and 0 <= y < R and 0 <= x < C and room[z][y][x] != "#"

    q = deque([start_pos])  # type: ignore
    dist = {start_pos: 0}  # type: ignore
    while q:
        here_pos = q.popleft()
        here_dist = dist[here_pos]
        if here_pos == finish_pos:  # type: ignore
            break
        for delta in DELTA:
            dz, dy, dx = delta
            there_pos = (dz + here_pos[0], dy + here_pos[1], dx + here_pos[2])
            if not available(there_pos):
                continue
            if there_pos in dist:
                continue
            there_dist = here_dist + 1
            dist[there_pos] = there_dist
            q.append(there_pos)

    if finish_pos not in dist:  # type: ignore
        print("Trapped!")
    else:
        print(f"Escaped in {dist[finish_pos]} minute(s).")  # type: ignore
