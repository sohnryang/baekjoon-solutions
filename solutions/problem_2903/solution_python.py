"""
Problem 2903
https://www.acmicpc.net/problem/2903
"""


def count_number_of_dots(iterations):
    """Solves problem (given number of iterations)"""
    number_of_dots = (2 ** iterations + 1) ** 2
    return number_of_dots


i = int(input())
print(count_number_of_dots(i))
