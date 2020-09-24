"""
Problem 18765: Solution generator
https://www.acmicpc.net/problem/18765
"""
from collections import deque
from math import floor, log

solutions = {
    0: '+![]', 1: '+!![]', 2: '+!![]+!![]', 3: '+!![]+!![]+!![]',
    4: '[+!![]+!![]]*[+!![]+!![]]', 5: '+!![]+!![]+!![]+!![]+!![]',
    6: '[+!![]+!![]]*[+!![]+!![]+!![]]',
    7: '+!![]+!![]+!![]+!![]+!![]+!![]+!![]',
    8: '[+!![]+!![]]**[+!![]+!![]+!![]]', 9: '[+!![]+!![]+!![]]**[+!![]+!![]]'
}

for i in range(10, 1001):
    digits = [int(d) for d in str(i)]
    per_digit_code = []
    for digit in digits:
        per_digit_code.append(f'[{solutions[digit]}]')
    solutions[i] = f'[{"+".join(per_digit_code)}]*[{solutions[1]}]'

too_long = {}
keys = list(solutions.keys())
for key in keys:
    if len(solutions[key]) >= 75:
        too_long[key] = solutions[key]
        del solutions[key]
