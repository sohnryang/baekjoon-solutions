"""
Baekjoon Online Judge #14730
https://www.acmicpc.net/problem/14730
"""

N = int(input())
result = 0
for _ in range(N):
    C, K = map(int, input().split())
    result += C * K
print(result)
