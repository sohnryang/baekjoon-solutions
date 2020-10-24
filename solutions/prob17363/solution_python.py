"""
Baekjoon Online Judge #17363
https://www.acmicpc.net/problem/17363
"""

N, M = map(int, input().split())
picture = []
for _ in range(N):
    line = input()
    picture.append(line)

conversion = {'.': '.', 'O': 'O', '-': '|', '|': '-', '/': '\\', '\\': '/',
              '^': '<', '<': 'v', 'v': '>', '>': '^'}
rotated = []
for x in range(M - 1, -1, -1):
    line = []
    for y in range(N):
        line.append(conversion[picture[y][x]])
    rotated.append(line)

for line in rotated:
    print(''.join(line))
