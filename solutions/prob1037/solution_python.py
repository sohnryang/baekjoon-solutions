"""
Baekjoon Online Judge #1037
https://www.acmicpc.net/problem/1037
"""

_ = input()
divisors = list(map(int, input().split()))
print(min(divisors) * max(divisors))
