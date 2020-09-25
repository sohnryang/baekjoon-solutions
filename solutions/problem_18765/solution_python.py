"""
Problem 18765: Solution generator
https://www.acmicpc.net/problem/18765
"""
import sys
import subprocess

def check_code():
    code_template = 'require("assert").strict.deepEqual(%d, "%s")'
    for i in range(1001):
        if solutions[i] is None:
            continue
        exit_code = subprocess.run([
            'node',
            '-e',
            f"'{code_template % (i, solutions[i])}'"
        ]).returncode
        if exit_code != 0:
            print(f'Failed at {i}')
            return False
    return True

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
    solutions[i - 1] = f'{solutions[i][:-8]}-{solutions[i][-7:]}'
    phase_table[i - 1] = 1

# Phase 2: interpolate by multiplying phase 0 numbers
for mult in range(2, 1000):
    for i in range(2, 1000 // mult):
        if phase_table[mult] != 0:
            continue
        if solutions[i] is None:
            continue
        if solutions[mult * i] is not None:
            continue
        solutions[mult * i] = f'[{solutions[mult][:-8]}]*[{solutions[i]}]'

clear_long_str()
