"""
Baekjoon Online Judge #10026
https://www.acmicpc.net/problem/10026
"""

from collections import deque
from sys import stdin
from typing import Callable, List, Tuple

infast = lambda: stdin.readline().strip()

DELTAS = [(-1, 0), (0, -1), (0, 1), (1, 0)]


def in_range(size: int, coord: Tuple[int, int]) -> bool:
    y, x = coord
    return 0 <= y < size and 0 <= x < size


def count_regions(grid: List[str], identify_fn: Callable[[str], int]) -> int:
    count = 0
    filled = []
    for _ in range(len(grid)):
        filled.append([None] * len(grid))
    for y, row in enumerate(grid):
        for x, cell in enumerate(row):
            if filled[y][x] is not None:
                continue
            cell_id = identify_fn(cell)
            q = deque([(y, x)])
            while q:
                here_y, here_x = q.popleft()
                for delta in DELTAS:
                    dy, dx = delta
                    there_y, there_x = here_y + dy, here_x + dx
                    if not in_range(len(grid), (there_y, there_x)):
                        continue
                    if cell_id != identify_fn(grid[there_y][there_x]):
                        continue
                    if filled[there_y][there_x] is not None:
                        continue
                    filled[there_y][there_x] = count
                    q.append((there_y, there_x))
            count += 1
    return count


N = int(infast())
grid = []
for _ in range(N):
    grid.append(infast())
print(
    count_regions(grid, lambda c: "RGB".index(c)),
    count_regions(grid, lambda c: 0 if c in "RG" else 1),
)
