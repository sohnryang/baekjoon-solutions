"""
Baekjoon Online Judge #5543
https://www.acmicpc.net/problem/5543
"""

in_burgers = [int(input()), int(input()), int(input())]
in_beverages = [int(input()), int(input())]
print(min(in_burgers) + min(in_beverages) - 50)
