"""
Baekjoon Online Judge #14502
https://www.acmicpc.net/problem/14502
"""

from collections import deque
from copy import deepcopy

def vec_add(v1, v2):
    return (v1[0] + v2[0], v1[1] + v2[1])

def range_check(point):
    return 0 <= point[0] < N and 0 <= point[1] < M

N, M = map(int, input().split())
lab_map = []
for y in range(N):
    line = list(map(int, input().split()))
    lab_map.append(line)

wall_cand = []
virus_pos = []
for y in range(N):
    for x in range(M):
        if lab_map[y][x] == 0:
            wall_cand.append((y, x))
        elif lab_map[y][x] == 2:
            virus_pos.append((y, x))

result = 0
for w1 in range(len(wall_cand)):
    for w2 in range(w1 + 1, len(wall_cand)):
        for w3 in range(w2 + 1, len(wall_cand)):
            walls = [wall_cand[w1], wall_cand[w2], wall_cand[w3]]
            map_copy = deepcopy(lab_map)
            for y, x in walls:
                map_copy[y][x] = 1
            q = deque(virus_pos)
            deltas = [(-1, 0), (1, 0), (0, -1), (0, 1)]
            while q:
                u = q.popleft()
                vs = [vec_add(u, delta) for delta in deltas
                                        if range_check(vec_add(u, delta))]
                for v in vs:
                    if map_copy[v[0]][v[1]] == 0:
                        map_copy[v[0]][v[1]] = 2
                        q.append(v)
            safe_zone = 0
            for y in range(N):
                for x in range(M):
                    if map_copy[y][x] == 0:
                        safe_zone += 1
            result = max(result, safe_zone)

print(result)
