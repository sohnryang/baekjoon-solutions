"""
Baekjoon Online Judge #2935
https://www.acmicpc.net/problem/2935
"""

A = int(input())
operator = input()
B = int(input())
if operator == '+':
    print(A + B)
else:
    print(A * B)
