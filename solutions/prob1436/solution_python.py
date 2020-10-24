"""
Baekjoon Online Judge #1436
https://www.acmicpc.net/problem/1436
"""

doomsday_number = []
n = 1
while len(doomsday_number) < 10000:
    if '666' in str(n):
        doomsday_number.append(n)
    n += 1
N = int(input())
print(doomsday_number[N - 1])
