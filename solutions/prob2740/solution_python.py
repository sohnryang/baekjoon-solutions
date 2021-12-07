"""Baekjoon Online Judge 2740
https://www.acmicpc.net/problem/2740
"""

from copy import deepcopy
from operator import neg
from sys import stdin
from typing import List, Tuple


class Matrix:
    def __init__(self, raw_list: List[List[int]]):
        self.raw_list = raw_list

    def dim(self):
        return (len(self.raw_list), len(self.raw_list[0]))

    def __repr__(self) -> str:
        return str(self.raw_list)

    def __getitem__(self, index: Tuple[int, int]) -> int:
        y, x = index
        return self.raw_list[y][x]

    def __add__(self, another: "Matrix") -> "Matrix":
        copied = deepcopy(self.raw_list)
        for i, row in enumerate(another.raw_list):
            for j, elem in enumerate(row):
                copied[i][j] += elem
        return Matrix(copied)

    def __neg__(self) -> "Matrix":
        copied = []
        for row in self.raw_list:
            copied.append(list(map(neg, row)))
        return Matrix(copied)

    def transpose(self) -> "Matrix":
        result = []
        for _ in range(len(self.raw_list[0])):
            row = []
            for _ in range(len(self.raw_list)):
                row.append(0)
            result.append(row)

        for i in range(len(self.raw_list)):
            for j in range(len(self.raw_list[i])):
                result[j][i] = self.raw_list[i][j]

        return Matrix(result)

    def __mul__(self, another: "Matrix") -> "Matrix":
        result = []
        transposed = another.transpose()
        for _ in range(len(self.raw_list)):
            row = []
            for _ in range(len(transposed.raw_list)):
                row.append(0)
            result.append(row)

        for i in range(len(result)):
            for j in range(len(result[i])):
                result[i][j] = sum(
                    map(
                        lambda x: x[0] * x[1],
                        zip(self.raw_list[i], transposed.raw_list[j]),
                    )
                )

        return Matrix(result)


infast = lambda: stdin.readline().strip()

N, M = map(int, infast().split())
mat1_raw = []
for _ in range(N):
    mat1_raw.append([int(x) for x in infast().split()])
mat1 = Matrix(mat1_raw)
_, K = map(int, infast().split())
mat2_raw = []
for _ in range(M):
    mat2_raw.append([int(x) for x in infast().split()])
mat2 = Matrix(mat2_raw)
result = mat1 * mat2

for row in result.raw_list:
    print(*row)
