"""Baekjoon Online Judge #3003
https://www.acmicpc.net/problem/3003
"""

arr = [int(x) for x in input().split()]
needed = [1, 1, 2, 2, 2, 8]
print(*map(lambda x: x[1] - x[0], zip(arr, needed)))
