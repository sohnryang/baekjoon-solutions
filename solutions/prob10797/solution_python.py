"""
Baekjoon Online Judge #10797
https://www.acmicpc.net/problem/10797
"""

N = int(input())
numbers = list(map(int, input().split()))
result = sum(map(int, [n == N for n in numbers]))
print(result)
