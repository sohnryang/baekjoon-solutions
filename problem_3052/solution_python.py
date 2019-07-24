"""
Baekjoon Online Judge #3052
https://www.acmicpc.net/problem/3052
"""

mods = set()
for i in range(10):
    N = int(input())
    mods.add(N % 42)
print(len(mods))
