"""
Baekjoon Online Judge #15969
https://www.acmicpc.net/problem/15969
"""

in_n = int(input())
in_scores = list(map(int, input().split()))
print(max(in_scores) - min(in_scores))
