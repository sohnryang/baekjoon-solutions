"""
Baekjoon Online Judge #2448
https://www.acmicpc.net/problem/2448
"""

N = int(input())
result = []
for _ in range(N):
    result.append([False] * N * 2)

def stars(x, y, size):
    if size == 1:
        result[y][x] = True
        result[y + 1][x] = True
        result[y + 1][x + 2] = True
        result[y + 2][x:x+5] = [True] * 5
    else:
        offset_y = size // 2 * 3
        offset_x = offset_y * 2
        stars(x, y, size // 2)
        stars(x, y + offset_y, size // 2)
        stars(x + offset_x, y + offset_y, size // 2)

stars(0, 0, N // 3)

for i, line in enumerate(result):
    line_str = ''.join(map(lambda x: '*' if x else ' ', line[:2 * i + 1]))
    print(line_str.center(N * 2))
