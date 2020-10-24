"""
Baekjoon Online Judge #5597
https://www.acmicpc.net/problem/5597
"""

submitted_table = [False] * 30
for _ in range(28):
    submitted_table[int(input()) - 1] = True
for i in range(30):
    if not submitted_table[i]:
        print(i + 1)
