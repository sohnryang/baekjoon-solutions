"""
Problem 1001
https://www.acmicpc.net/problem/1001
"""


def solve(input_1, input_2):
    """solves problem"""
    return input_1 - input_2


IN1, IN2 = [int(x) for x in input().split()]
print(solve(IN1, IN2))
