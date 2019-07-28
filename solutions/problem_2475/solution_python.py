"""
Baekjoon Online Judge #2475
https://www.acmicpc.net/problem/2475
"""

in_numbers = map(int, input().split())
print(sum([x ** 2 for x in in_numbers]) % 10)