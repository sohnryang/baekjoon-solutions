"""
Problem 18765: Solution generator
https://www.acmicpc.net/problem/18765
"""
def clear_long_str():
    for i in range(1001):
        if solutions[i] is None:
            continue
        if len(solutions[i]) > 75:
            solutions[i] = None
            phase_table[i] = None

solutions = [None] * 1001
phase_table = [None] * 1001
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

# Phase 0: create numbers using string concat
for i in range(10, 1001):
    digits = [int(d) for d in str(i)]
    per_digit_code = []
    for digit in digits:
        per_digit_code.append(f'[{solutions[digit]}]')
    solutions[i] = f'[{"+".join(per_digit_code)}]*[{solutions[1]}]'
    phase_table[i] = 0

clear_long_str()

# Phase 1: interpolate by substracting 1 from phase 0 numbers
for i in range(1, 1001):
    if phase_table[i] != 0:
        continue
    if solutions[i - 1] is not None:
        continue
    solutions[i - 1] = f'{solutions[i][:-5]}-{solutions[i][-4:]}'
    phase_table[i - 1] = 1
