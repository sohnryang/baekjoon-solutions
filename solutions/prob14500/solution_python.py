"""
Baekjoon Online Judge #14500
https://www.acmicpc.net/problem/14500
"""

from sys import stdin

input_fast = lambda: stdin.readline().strip()

def flip_right(tetro):
    return [line[::-1] for line in tetro]

def flip_up(tetro):
    return tetro[::-1]

def rotate_90deg(tetro):
    result = []
    for x in range(len(tetro[0]) - 1, -1, -1):
        line = []
        for y in range(len(tetro)):
            line.append(tetro[y][x])
        result.append(line)
    return result

def all_tetroes(tetro):
    sources = [flip_up(tetro), flip_right(tetro), flip_right(flip_up(tetro))]
    result = []
    for source in sources:
        for d in range(4):
            rotated = source
            for _ in range(d):
                rotated = rotate_90deg(rotated)
            result.append(rotated)
    return result

N, M = map(int, input_fast().split())
paper = []
for y in range(N):
    line = list(map(int, input_fast().split()))
    paper.append(line)

tetroes = [
    [[1],
     [1],
     [1],
     [1]],

    [[1, 1],
     [1, 1]],

    [[1, 0],
     [1, 0],
     [1, 1]],

    [[1, 0],
     [1, 1],
     [0, 1]],

    [[1, 1, 1],
     [0, 1, 0]]
]
available_tetroes = []

for tetro in tetroes:
    available_tetroes += all_tetroes(tetro)

maximum = 0
for tetro in available_tetroes:
    for y in range(N - len(tetro) + 1):
        for x in range(M - len(tetro[0]) + 1):
            result = 0
            for y_t in range(len(tetro)):
                for x_t in range(len(tetro[y_t])):
                    result += (tetro[y_t][x_t] * paper[y + y_t][x + x_t])
            maximum = max(maximum, result)

print(maximum)
