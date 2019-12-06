"""
Baekjoon Online Judge #1075
https://www.acmicpc.net/problem/1075
"""

N = int(input()[:-2]) * 100
F = int(input())
print('%02d' % ((F - N % F) if N % F != 0 else 0))
