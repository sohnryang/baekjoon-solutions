"""Baekjoon Online Judge #3874
https://www.acmicpc.net/problem/3874
"""

from copy import deepcopy
from collections import deque
from sys import stdin
from operator import neg
from typing import Deque, Dict, List, Tuple, Union
import re

infast = lambda: stdin.readline().strip()

literal_regex = re.compile(r"\d+")
unary_operator_regex = re.compile(r"[-']")
binary_operator_regex = re.compile(r"[=+*]")
separator_regex = re.compile(r"[\[\] ;.,()]")
identifier_regex = re.compile("[A-Z]")
MOD = 2 ** 15


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
                copied[i][j] %= MOD
        return Matrix(copied)

    def __neg__(self) -> "Matrix":
        copied = []
        for row in self.raw_list:
            new_row = list(map(neg, row))
            copied.append(list(map(lambda x: x % MOD, new_row)))
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
        if self.dim() == (1, 1):
            for row in another.raw_list:
                result.append(list(map(lambda x: x * self.raw_list[0][0] % MOD, row)))
            return Matrix(result)
        elif another.dim() == (1, 1):
            for row in self.raw_list:
                result.append(
                    list(map(lambda x: x * another.raw_list[0][0] % MOD, row))
                )
            return Matrix(result)

        for _ in range(len(self.raw_list)):
            row = []
            for _ in range(len(transposed.raw_list)):
                row.append(0)
            result.append(row)

        for i in range(len(result)):
            for j in range(len(result[i])):
                result[i][j] = (
                    sum(
                        map(
                            lambda x: x[0] * x[1],
                            zip(self.raw_list[i], transposed.raw_list[j]),
                        )
                    )
                    % MOD
                )

        return Matrix(result)


def lex_line(line: str) -> List[Tuple[str, str]]:
    matches = []
    matches.extend([("literal", x) for x in literal_regex.finditer(line)])
    matches.extend([("unary_op", x) for x in unary_operator_regex.finditer(line)])
    matches.extend([("binary_op", x) for x in binary_operator_regex.finditer(line)])
    matches.extend([("separator", x) for x in separator_regex.finditer(line)])
    matches.extend([("identifier", x) for x in identifier_regex.finditer(line)])
    matches.sort(key=lambda x: x[1].span())
    token_arr = [(x[0], x[1].group(0)) for x in matches]
    for i in range(1, len(token_arr)):
        if token_arr[i][1] == "-" and token_arr[i - 1][1] not in "=+-*(,[ ;":
            token_arr[i] = ("binary_op", "-")
    processed = []
    for token in token_arr:
        if token == ("binary_op", "-"):
            processed.append(("binary_op", "+"))
            processed.append(("unary_op", "-"))
        else:
            processed.append(token)
    return processed


def join_horizotally(x1: Matrix, x2: Matrix) -> Matrix:
    copied = deepcopy(x1.raw_list)
    for i, row in enumerate(x2.raw_list):
        copied[i].extend(row)
    return Matrix(copied)


def join_vertically(x1: Matrix, x2: Matrix) -> Matrix:
    copied = deepcopy(x1.raw_list)
    copied.extend(x2.raw_list)
    return Matrix(copied)


precedence_table = {
    " ": " -'*+",
    ";": " ;-'*+",
    "*": "*-'",
    "+": "*+-'",
    ",": "*+-' ;,",
}
matching_pair = {")": "(", "]": "["}


def shunting_yard(expr: List[Tuple[str, str]]) -> List[Tuple[str, str]]:
    operator_stack = deque()
    operand_stack = deque()
    for token in expr:
        if token[1] in "[('-":
            while operator_stack and operator_stack[-1][1] == "'":
                operand_stack.append(operator_stack.pop())
            operator_stack.append(token)
        elif token[0] in ("literal", "identifier"):
            operand_stack.append(token)
        elif token[1] in precedence_table.keys():
            while (
                operator_stack and operator_stack[-1][1] in precedence_table[token[1]]
            ):
                operand_stack.append(operator_stack.pop())
            operator_stack.append(token)
        elif token[1] in "])":
            while operator_stack and operator_stack[-1][1] != matching_pair[token[1]]:
                operand_stack.append(operator_stack.pop())
            operator_stack.pop()
    while operator_stack:
        operand_stack.append(operator_stack.pop())
    return list(operand_stack)


def run_rpn(
    expr: List[Tuple[str, str]], identifiers: Union[Dict[str, Matrix], None] = None
) -> Matrix:
    stack: Deque[Matrix] = deque()
    for token in expr:
        if token[0] == "literal":
            stack.append(Matrix([[int(token[1])]]))
            continue
        elif token[0] == "identifier":
            stack.append(identifiers[token[1]])  # type: ignore
            continue
        elif token[0] == "unary_op":
            x = stack.pop()
            if token[1] == "-":
                stack.append(-x)
            elif token[1] == "'":
                stack.append(x.transpose())
            continue
        x1 = stack.pop()
        x2 = stack.pop()
        if token[1] == "+":
            stack.append(x2 + x1)
        elif token[1] == "*":
            stack.append(x2 * x1)
        elif token[1] == " ":
            stack.append(join_horizotally(x2, x1))
        elif token[1] == ";":
            stack.append(join_vertically(x2, x1))
        elif token[1] == ",":
            x = stack.pop()
            result = []
            for row_index in x2.raw_list[0]:
                row = []
                for col_index in x1.raw_list[0]:
                    row.append(x.raw_list[row_index - 1][col_index - 1])
                result.append(row)
            stack.append(Matrix(result))
    return stack.pop()


while True:
    N = int(infast())
    if N == 0:
        break
    variables = dict()
    for _ in range(N):
        line = infast()
        assigned = line[0]
        evaluated = run_rpn(shunting_yard(lex_line(line[2:-1])), variables)
        variables[assigned] = evaluated
        for row in evaluated.raw_list:
            print(*row)
    print("-----")
