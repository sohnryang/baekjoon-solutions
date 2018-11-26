"""
Baekjoon Online Judge #15781
https://www.acmicpc.net/problem/15781
"""

[in_n, in_m] = [int(x) for x in input().split()]
in_helmets = [int(x) for x in input().split()]
in_chestplates = [int(x) for x in input().split()]
print(max(in_helmets) + max(in_chestplates))
