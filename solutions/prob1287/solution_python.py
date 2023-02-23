"""
Baekjoon Online Judge #1287
https://www.acmicpc.net/problem/1287
"""

from sys import stdin
from typing import List

infast = lambda: stdin.readline().strip()

expr_str = infast()
num_buf: List[str] = []
expr_lexed: List[str] = []
if expr_str.count("(") != expr_str.count(")") or "()" in expr_str:
    print("ROCK")
    exit(0)
for ch in expr_str:
    if ch.isnumeric():
        num_buf.append(ch)
    else:
        if num_buf:
            expr_lexed.append("".join(num_buf))
            num_buf = []
        expr_lexed.append(ch)
if num_buf:
    expr_lexed.append("".join(num_buf))

operand_stack: List[str] = []
operator_stack: List[str] = []
for token in expr_lexed:
    if token.isnumeric():
        operand_stack.append(token)
    elif token == "(":
        operator_stack.append(token)
    elif token == ")":
        if not operator_stack:
            print("ROCK")
            exit(0)
        while operator_stack and operator_stack[-1] != "(":
            operand_stack.append(operator_stack.pop())
        if not operator_stack or operator_stack[-1] != "(":
            print("ROCK")
            exit(0)
        operator_stack.pop()
    elif token in "+-":
        while operator_stack and operator_stack[-1] in "+-*/":
            operand_stack.append(operator_stack.pop())
        operator_stack.append(token)
    else:
        while operator_stack and operator_stack[-1] in "*/":
            operand_stack.append(operator_stack.pop())
        operator_stack.append(token)
while operator_stack:
    operand_stack.append(operator_stack.pop())

stack: List[int] = []
for token in operand_stack:
    if token.isnumeric():
        stack.append(int(token))
        continue
    if not stack:
        print("ROCK")
        exit(0)
    x1 = stack.pop()
    if not stack:
        print("ROCK")
        exit(0)
    x2 = stack.pop()
    if token == "+":
        stack.append(x2 + x1)
    elif token == "-":
        stack.append(x2 - x1)
    elif token == "*":
        stack.append(x2 * x1)
    elif token == "/":
        if x1 == 0:
            print("ROCK")
            exit(0)
        stack.append(x2 // x1)
if len(stack) != 1:
    print("ROCK")
    exit(0)
print(stack[0])
