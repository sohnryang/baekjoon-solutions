"""Baekjoon Online Judge #14652
https://www.acmicpc.net/problem/14652
"""

N, M, K = map(int, input().split())
print(K // M, K % M)
