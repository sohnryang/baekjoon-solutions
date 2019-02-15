"""
Baekjoon Online Judge #1026
https://www.acmicpc.net/problem/1026
"""

in_n = int(input())
in_a = list(map(int, input().split()))
in_b = list(map(int, input().split()))
in_a.sort(reverse=True)
in_b.sort()
print(sum([in_a[i] * in_b[i] for i in range(len(in_a))]))
