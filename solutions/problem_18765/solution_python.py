"""
Problem 18765: Solution generator
https://www.acmicpc.net/problem/18765
"""
from collections import deque
from math import floor, log

solutions = [None] * 1001
solutions[0] = '+![]'
solutions[1] = '+!![]'
solutions[2] = '+!![]+!![]'
solutions[3] = '+!![]+!![]+!![]'
solutions[4] = '[+!![]+!![]]*[+!![]+!![]]'
solutions[5] = '+!![]+!![]+!![]+!![]+!![]'
solutions[6] = '[+!![]+!![]]*[+!![]+!![]+!![]]'
solutions[7] = '+!![]+!![]+!![]+!![]+!![]+!![]+!![]'
solutions[8] = '[+!![]+!![]]**[+!![]+!![]+!![]]'
solutions[9] = '[+!![]+!![]+!![]]**[+!![]+!![]]'

for i in range(10, 1001):
    digits = [int(d) for d in str(i)]
    per_digit_code = []
    for digit in digits:
        per_digit_code.append(f'[{solutions[digit]}]')
    solutions[i] = f'[{"+".join(per_digit_code)}]*[{solutions[1]}]'

print('\n'.join(solutions))
