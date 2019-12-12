"""
Baekjoon Online Judge #5554
https://www.acmicpc.net/problem/5554
"""

t = 0
for _ in range(4):
    t += int(input())
print(t // 60)
print(t % 60)
