"""
Baekjoon Online Judge #2908
https://www.acmicpc.net/problem/2908
"""

[in_a, in_b] = [int(x[::-1]) for x in input().split()]
print(max(in_a, in_b))
