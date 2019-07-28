"""
Baekjoon Online Judge #2562
https://www.acmicpc.net/problem/2562
"""

in_numbers = []
for _ in range(9):
    in_numbers.append(int(input()))
print(max(in_numbers))
print(in_numbers.index(max(in_numbers)) + 1)
