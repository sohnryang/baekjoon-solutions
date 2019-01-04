"""
Baekjoon Online Judge #11399
https://www.acmicpc.net/problem/11399
"""

in_n = int(input())
in_p = list(map(int, input().split()))
in_p.sort()
result = 0

for i in range(1, len(in_p) + 1):
    result += sum(in_p[:i])

print(result)
